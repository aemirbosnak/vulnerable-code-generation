//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME 1024
#define MAX_PATH_NAME 4096

typedef struct {
    char name[MAX_FILE_NAME];
    unsigned long size;
} File;

void print_files(File *files, int num_files) {
    printf("File Name\t\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t\t%lu bytes\n", files[i].name, files[i].size);
    }
}

int main() {
    char path[MAX_PATH_NAME];
    printf("Enter the path of the directory to analyze: ");
    scanf("%s", path);

    DIR *dir;
    struct dirent *ent;
    File *files = NULL;
    int num_files = 0;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                if (num_files == 0) {
                    files = (File *) malloc(sizeof(File));
                } else {
                    files = (File *) realloc(files, sizeof(File) * (num_files + 1));
                }

                strncpy(files[num_files].name, ent->d_name, MAX_FILE_NAME - 1);
                files[num_files].name[MAX_FILE_NAME - 1] = '\0';
                files[num_files].size = ent->d_reclen;
                num_files++;
            }
        }

        closedir(dir);
    } else {
        perror("");
        exit(1);
    }

    print_files(files, num_files);

    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);

    return 0;
}