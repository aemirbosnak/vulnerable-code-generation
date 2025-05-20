//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct {
    char *src;
    char *dest;
    int mode;
} file_t;

void read_dir(const char *path, FILE *fp) {
    DIR *dir = opendir(path);
    struct dirent *ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char *src_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
            strcpy(src_path, path);
            strcat(src_path, "/");
            strcat(src_path, ent->d_name);

            char *dest_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
            strcpy(dest_path, path);
            strcat(dest_path, "/");
            strcat(dest_path, ent->d_name);

            file_t file = {src_path, dest_path, 0};
            fprintf(fp, "%s\n", file.src);
        }
    }

    closedir(dir);
}

void write_file(file_t file) {
    int src_fd = open(file.src, O_RDONLY);
    int dest_fd = open(file.dest, O_WRONLY | O_CREAT, 0777);

    char buf[BUF_SIZE];
    while (read(src_fd, buf, BUF_SIZE) > 0) {
        write(dest_fd, buf, strlen(buf));
    }

    close(src_fd);
    close(dest_fd);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    char *src_dir = argv[1];
    char *dest_dir = argv[2];

    FILE *fp = fopen("file_list.txt", "w");

    read_dir(src_dir, fp);
    fclose(fp);

    FILE *fp2 = fopen("file_list.txt", "r");
    char line[BUF_SIZE];

    while (fgets(line, BUF_SIZE, fp2)!= NULL) {
        file_t file = {NULL, NULL, 0};
        sscanf(line, "%s", file.src);
        strcpy(file.dest, file.src);
        strcat(file.dest, ".bak");

        write_file(file);
    }

    fclose(fp2);
    unlink("file_list.txt");

    return 0;
}