//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_DIR_SIZE 4096
#define MAX_FILE_SIZE 1024

typedef struct {
    char *name;
    int size;
} file_t;

void print_files(file_t *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void get_files_in_dir(char *path, file_t *files, int *count) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                char file_path[MAX_DIR_SIZE];
                strcpy(file_path, path);
                strcat(file_path, "/");
                strcat(file_path, ent->d_name);

                struct stat st;
                stat(file_path, &st);

                if (S_ISREG(st.st_mode)) {
                    if (*count >= MAX_FILE_SIZE) {
                        printf("Maximum number of files reached.\n");
                        return;
                    }

                    file_t file;
                    strncpy(file.name, ent->d_name, MAX_FILE_SIZE - 1);
                    file.name[MAX_FILE_SIZE - 1] = '\0';
                    file.size = st.st_size;

                    files[*count] = file;
                    (*count)++;
                }
            }
        }

        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char path[MAX_DIR_SIZE];
    strcpy(path, argv[1]);
    strcat(path, "/");

    file_t files[MAX_FILE_SIZE];
    int count = 0;

    get_files_in_dir(path, files, &count);
    print_files(files, count);

    return 0;
}