//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *file_name;
    char *file_ext;
    char *file_path;
    int file_size;
} file_info;

void print_files(file_info *files, int num_files) {
    printf("Files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].file_name, files[i].file_size);
    }
}

void delete_files(file_info *files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        unlink(files[i].file_path);
    }
}

void recover_files(char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    char path[1024];

    dir = opendir(dir_path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                sprintf(path, "%s/%s", dir_path, ent->d_name);
                struct stat st;
                stat(path, &st);
                int file_size = st.st_size;
                char *file_name = strdup(ent->d_name);
                char *file_ext = strrchr(file_name, '.');
                if (file_ext!= NULL) {
                    *file_ext = '\0';
                }
                char *file_path = malloc(strlen(dir_path) + strlen(file_name) + 2);
                sprintf(file_path, "%s/%s", dir_path, file_name);
                file_info *files = malloc(file_size * sizeof(file_info));
                FILE *fp = fopen(file_path, "r");
                fread(files, file_size, sizeof(file_info), fp);
                fclose(fp);
                delete_files(files, file_size);
                free(files);
                free(file_path);
                free(file_name);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    recover_files(argv[1]);

    return 0;
}