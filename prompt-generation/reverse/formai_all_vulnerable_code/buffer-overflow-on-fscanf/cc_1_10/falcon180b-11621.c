//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char source_path[256];
    char dest_path[256];
} file_pair;

void read_directory(char *dir_path, file_pair *file_pairs, int *num_files) {
    DIR *dir = opendir(dir_path);
    struct dirent *ent;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            strcpy(file_pairs[*num_files].source_path, dir_path);
            strcat(file_pairs[*num_files].source_path, "/");
            strcat(file_pairs[*num_files].source_path, ent->d_name);

            strcpy(file_pairs[*num_files].dest_path, "");
            (*num_files)++;
        }
    }

    closedir(dir);
}

void sync_files(file_pair *file_pairs, int num_files) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(file_pairs[i].dest_path, "")!= 0) {
            printf("Synchronizing %s to %s\n", file_pairs[i].source_path, file_pairs[i].dest_path);
        } else {
            printf("Copying %s to %s\n", file_pairs[i].source_path, file_pairs[i].dest_path);
        }

        char buffer[BUFFER_SIZE];
        FILE *src_file = fopen(file_pairs[i].source_path, "rb");
        FILE *dest_file = fopen(file_pairs[i].dest_path, "wb");

        if (src_file == NULL || dest_file == NULL) {
            printf("Error opening file(s)\n");
            exit(1);
        }

        while (fread(buffer, sizeof(char), BUFFER_SIZE, src_file) > 0) {
            fwrite(buffer, sizeof(char), BUFFER_SIZE, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <source_dir> <dest_dir> <file_list>\n", argv[0]);
        exit(1);
    }

    char source_dir[256] = "";
    char dest_dir[256] = "";
    strcpy(source_dir, argv[1]);
    strcpy(dest_dir, argv[2]);

    FILE *file_list = fopen(argv[3], "r");

    if (file_list == NULL) {
        printf("Error opening file list\n");
        exit(1);
    }

    int num_files = 0;
    file_pair file_pairs[256];

    while (fscanf(file_list, "%s %s\n", file_pairs[num_files].source_path, file_pairs[num_files].dest_path)!= EOF) {
        num_files++;
    }

    fclose(file_list);

    read_directory(source_dir, file_pairs, &num_files);
    sync_files(file_pairs, num_files);

    return 0;
}