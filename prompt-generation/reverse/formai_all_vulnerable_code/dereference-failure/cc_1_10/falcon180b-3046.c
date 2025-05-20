//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct _file_info {
    char name[100];
    int size;
} FileInfo;

int compare_file_info(const void *a, const void *b) {
    const FileInfo *file_a = a;
    const FileInfo *file_b = b;
    return strcmp(file_a->name, file_b->name);
}

void print_file_info(FileInfo *file_info, int num_files) {
    printf("File Name\t\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t\t%d bytes\n", file_info[i].name, file_info[i].size);
    }
}

void get_file_info(char *path, FileInfo *file_info, int *num_files) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: could not open directory '%s'\n", path);
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            FileInfo current_file;
            strcpy(current_file.name, ent->d_name);
            current_file.size = ent->d_reclen;
            file_info[*num_files] = current_file;
            (*num_files)++;
        }
    }

    closedir(dir);
}

void print_dir_info(char *path) {
    FILE *fp;
    char cmd[100];

    sprintf(cmd, "df %s", path);
    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error: could not execute command '%s'\n", cmd);
        exit(1);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        printf("%s", line);
    }

    pclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }

    char path[100];
    strcpy(path, argv[1]);

    FileInfo file_info[100];
    int num_files = 0;

    get_file_info(path, file_info, &num_files);
    qsort(file_info, num_files, sizeof(FileInfo), compare_file_info);
    print_file_info(file_info, num_files);

    print_dir_info(path);

    return 0;
}