//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFSIZE 256

typedef struct {
    char name[BUFSIZE];
    time_t mtime;
} file_info;

int file_info_cmp(const void *a, const void *b) {
    file_info *f1 = (file_info*)a;
    file_info *f2 = (file_info*)b;
    return strcmp(f1->name, f2->name);
}

void synchronize(char *srcdir, char *dstdir) {
    DIR *src, *dst;
    struct dirent *entry;
    char srcpath[BUFSIZE], dstpath[BUFSIZE];
    file_info src_files[BUFSIZE], dst_files[BUFSIZE];
    int src_count = 0, dst_count = 0, i, j;

    src = opendir(srcdir);
    if (!src) {
        fprintf(stderr, "Failed to open source directory '%s'\n", srcdir);
        exit(1);
    }

    dst = opendir(dstdir);
    if (!dst) {
        fprintf(stderr, "Failed to open destination directory '%s'\n", dstdir);
        closedir(src);
        exit(1);
    }
    
    // read source directory contents
    while ((entry = readdir(src))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;
        snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, entry->d_name);
        struct stat st;
        if (stat(srcpath, &st) == -1) {
            fprintf(stderr, "Failed to stat file '%s'\n", srcpath);
            continue;
        }
        if (S_ISREG(st.st_mode)) {  // regular file
            strcpy(src_files[src_count].name, entry->d_name);
            src_files[src_count].mtime = st.st_mtime;
            src_count++;
        }
    }

    // read destination directory contents
    while ((entry = readdir(dst))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;
        snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, entry->d_name);
        struct stat st;
        if (stat(dstpath, &st) == -1) {
            fprintf(stderr, "Failed to stat file '%s'\n", dstpath);
            continue;
        }
        if (S_ISREG(st.st_mode)) {  // regular file
            strcpy(dst_files[dst_count].name, entry->d_name);
            dst_files[dst_count].mtime = st.st_mtime;
            dst_count++;
        }
    }

    // sort source and destination files by name
    qsort(src_files, src_count, sizeof(file_info), file_info_cmp);
    qsort(dst_files, dst_count, sizeof(file_info), file_info_cmp);

    // synchronize files from source to destination
    i = j = 0;
    while (i < src_count && j < dst_count) {
        int cmp = strcmp(src_files[i].name, dst_files[j].name);
        if (cmp == 0) {  // file with same name found in both directories
            if (src_files[i].mtime > dst_files[j].mtime) {  // source file is more recent
                // copy source file to destination
                snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, src_files[i].name);
                snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, dst_files[j].name);
                if (access(srcpath, F_OK) == -1) {
                    fprintf(stderr, "Failed to access source file '%s'\n", srcpath);
                    i++;
                    continue;
                }
                if (access(dstpath, F_OK) == 0) {  // destination file already exists
                    if (unlink(dstpath) == -1) {  // delete existing file
                        fprintf(stderr, "Failed to delete existing file '%s'\n", dstpath);
                        i++;
                        continue;
                    }
                }
                if (link(srcpath, dstpath) == -1) {  // link source file to destination
                    fprintf(stderr, "Failed to link file '%s' to '%s'\n", srcpath, dstpath);
                    i++;
                    continue;
                }
                printf("Copied file '%s' to '%s'\n", srcpath, dstpath);
            }
            else if (src_files[i].mtime < dst_files[j].mtime) {  // destination file is more recent
                // copy destination file to source
                snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, dst_files[j].name);
                snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, src_files[i].name);
                if (access(dstpath, F_OK) == -1) {
                    fprintf(stderr, "Failed to access destination file '%s'\n", dstpath);
                    j++;
                    continue;
                }
                if (access(srcpath, F_OK) == 0) {  // source file already exists
                    if (unlink(srcpath) == -1) {  // delete existing file
                        fprintf(stderr, "Failed to delete existing file '%s'\n", srcpath);
                        j++;
                        continue;
                    }
                }
                if (link(dstpath, srcpath) == -1) {  // link destination file to source
                    fprintf(stderr, "Failed to link file '%s' to '%s'\n", dstpath, srcpath);
                    j++;
                    continue;
                }
                printf("Copied file '%s' to '%s'\n", dstpath, srcpath);
            }
            i++;
            j++;
        }
        else if (cmp < 0) {  // file exists only in source directory
            // copy file from source to destination
            snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, src_files[i].name);
            snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, src_files[i].name);
            if (access(srcpath, F_OK) == -1) {
                fprintf(stderr, "Failed to access source file '%s'\n", srcpath);
                i++;
                continue;
            }
            if (access(dstpath, F_OK) == 0) {  // destination file already exists
                if (unlink(dstpath) == -1) {  // delete existing file
                    fprintf(stderr, "Failed to delete existing file '%s'\n", dstpath);
                    i++;
                    continue;
                }
            }
            if (link(srcpath, dstpath) == -1) {  // link source file to destination
                fprintf(stderr, "Failed to link file '%s' to '%s'\n", srcpath, dstpath);
                i++;
                continue;
            }
            printf("Copied file '%s' to '%s'\n", srcpath, dstpath);
            i++;
        }
        else {  // file exists only in destination directory
            // copy file from destination to source
            snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, dst_files[j].name);
            snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, dst_files[j].name);
            if (access(dstpath, F_OK) == -1) {
                fprintf(stderr, "Failed to access destination file '%s'\n", dstpath);
                j++;
                continue;
            }
            if (access(srcpath, F_OK) == 0) {  // source file already exists
                if (unlink(srcpath) == -1) {  // delete existing file
                    fprintf(stderr, "Failed to delete existing file '%s'\n", srcpath);
                    j++;
                    continue;
                }
            }
            if (link(dstpath, srcpath) == -1) {  // link destination file to source
                fprintf(stderr, "Failed to link file '%s' to '%s'\n", dstpath, srcpath);
                j++;
                continue;
            }
            printf("Copied file '%s' to '%s'\n", dstpath, srcpath);
            j++;
        }
    }

    while (i < src_count) {  // copy remaining files from source to destination
        snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, src_files[i].name);
        snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, src_files[i].name);
        if (access(srcpath, F_OK) == -1) {
            fprintf(stderr, "Failed to access source file '%s'\n", srcpath);
            i++;
            continue;
        }
        if (access(dstpath, F_OK) == 0) {  // destination file already exists
            if (unlink(dstpath) == -1) {  // delete existing file
                fprintf(stderr, "Failed to delete existing file '%s'\n", dstpath);
                i++;
                continue;
            }
        }
        if (link(srcpath, dstpath) == -1) {  // link source file to destination
            fprintf(stderr, "Failed to link file '%s' to '%s'\n", srcpath, dstpath);
            i++;
            continue;
        }
        printf("Copied file '%s' to '%s'\n", srcpath, dstpath);
        i++;
    }

    while (j < dst_count) {  // copy remaining files from destination to source
        snprintf(dstpath, BUFSIZE, "%s/%s", dstdir, dst_files[j].name);
        snprintf(srcpath, BUFSIZE, "%s/%s", srcdir, dst_files[j].name);
        if (access(dstpath, F_OK) == -1) {
            fprintf(stderr, "Failed to access destination file '%s'\n", dstpath);
            j++;
            continue;
        }
        if (access(srcpath, F_OK) == 0) {  // source file already exists
            if (unlink(srcpath) == -1) {  // delete existing file
                fprintf(stderr, "Failed to delete existing file '%s'\n", srcpath);
                j++;
                continue;
            }
        }
        if (link(dstpath, srcpath) == -1) {  // link destination file to source
            fprintf(stderr, "Failed to link file '%s' to '%s'\n", dstpath, srcpath);
            j++;
            continue;
        }
        printf("Copied file '%s' to '%s'\n", dstpath, srcpath);
        j++;
    }

    closedir(src);
    closedir(dst);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(1);
    }

    synchronize(argv[1], argv[2]);

    return 0;
}