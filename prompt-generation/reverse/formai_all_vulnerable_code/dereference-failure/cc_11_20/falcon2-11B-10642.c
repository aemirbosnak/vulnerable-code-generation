//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void compare_dirs(const char* src_dir, const char* dest_dir) {
    DIR* dir_src = opendir(src_dir);
    if (dir_src == NULL) {
        perror("opendir");
        return;
    }

    DIR* dir_dest = opendir(dest_dir);
    if (dir_dest == NULL) {
        perror("opendir");
        return;
    }

    struct dirent* ent_src;
    struct stat st_src;
    struct stat st_dest;
    while ((ent_src = readdir(dir_src))!= NULL) {
        if (strcmp(ent_src->d_name, ".") == 0 || strcmp(ent_src->d_name, "..") == 0) {
            continue;
        }

        char src_path[PATH_MAX];
        snprintf(src_path, PATH_MAX, "%s/%s", src_dir, ent_src->d_name);
        stat(src_path, &st_src);

        char dest_path[PATH_MAX];
        snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, ent_src->d_name);
        stat(dest_path, &st_dest);

        if (S_ISDIR(st_src.st_mode)) {
            compare_dirs(src_path, dest_path);
        } else if (S_ISREG(st_src.st_mode) && (st_src.st_size == st_dest.st_size || st_src.st_size == 0)) {
            // File exists in both directories, nothing to do
        } else if (S_ISREG(st_src.st_mode) && st_src.st_size!= 0 &&!S_ISDIR(st_dest.st_mode)) {
            if (stat(dest_path, &st_dest)!= 0) {
                perror("stat");
            }

            if (st_dest.st_size == 0) {
                if (rename(src_path, dest_path)!= 0) {
                    perror("rename");
                }
            } else {
                FILE* fp_src = fopen(src_path, "r");
                FILE* fp_dest = fopen(dest_path, "w");

                if (fp_src!= NULL && fp_dest!= NULL) {
                    if (fstat(fileno(fp_dest), &st_dest)!= 0) {
                        perror("fstat");
                    }

                    if (fstat(fileno(fp_src), &st_src)!= 0) {
                        perror("fstat");
                    }

                    if (st_dest.st_size < st_src.st_size) {
                        fseek(fp_src, 0, SEEK_END);
                        fwrite(st_src.st_size, 1, 4, fp_dest);
                        fseek(fp_src, 0, SEEK_SET);
                        fwrite(st_src.st_size, 1, 4, fp_dest);
                        fseek(fp_src, st_dest.st_size, SEEK_SET);
                        fwrite(st_src.st_size - st_dest.st_size, 1, st_dest.st_size, fp_dest);
                    }

                    while (!feof(fp_src)) {
                        fread(st_src.st_size, 1, 4, fp_dest);
                        fread(st_src.st_size, 1, st_dest.st_size, fp_dest);
                        fwrite(st_src.st_size, 1, st_dest.st_size, fp_dest);
                        fwrite(st_src.st_size, 1, st_src.st_size - st_dest.st_size, fp_dest);
                        fseek(fp_src, st_dest.st_size, SEEK_SET);
                        fwrite(st_src.st_size - st_dest.st_size, 1, st_src.st_size - st_dest.st_size, fp_dest);
                    }

                    fclose(fp_src);
                    fclose(fp_dest);
                } else {
                    perror("fopen");
                }
            }
        }
    }

    closedir(dir_src);
    closedir(dir_dest);
}

int main() {
    const char* src_dir = "/path/to/source/dir";
    const char* dest_dir = "/path/to/destination/dir";

    compare_dirs(src_dir, dest_dir);

    return 0;
}