//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    off_t size;
} File;

int compare_files(const void *a, const void *b) {
    const File *file1 = a;
    const File *file2 = b;

    if (file1->size > file2->size) {
        return -1;
    } else if (file1->size < file2->size) {
        return 1;
    } else {
        return 0;
    }
}

void print_files(File *files, int num_files) {
    qsort(files, num_files, sizeof(File), compare_files);

    for (int i = 0; i < num_files; i++) {
        printf("%s (%ld bytes)\n", files[i].path, files[i].size);
    }
}

int main() {
    char path[MAX_PATH];
    DIR *dir;
    struct dirent *ent;
    File files[1000];
    int num_files = 0;

    if (getcwd(path, MAX_PATH)!= NULL) {
        dir = opendir(path);

        if (dir!= NULL) {
            while ((ent = readdir(dir))!= NULL) {
                if (ent->d_type == DT_DIR) {
                    snprintf(path, MAX_PATH, "%s/%s", path, ent->d_name);
                    if (getcwd(path, MAX_PATH) == NULL) {
                        perror("getcwd");
                        exit(1);
                    }

                    if (chdir(path)!= 0) {
                        perror("chdir");
                        exit(1);
                    }

                    num_files = 0;
                    while ((ent = readdir(dir))!= NULL) {
                        if (ent->d_type == DT_REG) {
                            File file;
                            strncpy(file.path, ent->d_name, MAX_PATH - 1);
                            file.path[MAX_PATH - 1] = '\0';
                            file.size = ent->d_reclen;

                            if (num_files >= sizeof(files) / sizeof(File)) {
                                break;
                            }

                            files[num_files++] = file;
                        }
                    }

                    if (chdir("..")!= 0) {
                        perror("chdir");
                        exit(1);
                    }

                    print_files(files, num_files);
                }
            }

            closedir(dir);
        }
    }

    return 0;
}