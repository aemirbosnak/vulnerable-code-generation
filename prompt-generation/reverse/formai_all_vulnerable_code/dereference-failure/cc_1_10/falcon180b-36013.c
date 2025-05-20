//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *source_path;
    char *destination_path;
} SyncPair;

void sync_files(SyncPair *pair) {
    DIR *source_dir = opendir(pair->source_path);
    DIR *dest_dir = opendir(pair->destination_path);

    struct dirent *source_ent;
    struct dirent *dest_ent;

    while ((source_ent = readdir(source_dir))!= NULL && (dest_ent = readdir(dest_dir))!= NULL) {
        if (strcmp(source_ent->d_name, ".")!= 0 && strcmp(source_ent->d_name, "..")!= 0) {
            if (strcmp(dest_ent->d_name, ".")!= 0 && strcmp(dest_ent->d_name, "..")!= 0) {
                if (strcmp(source_ent->d_name, dest_ent->d_name)!= 0) {
                    char *source_file_path = malloc(strlen(pair->source_path) + strlen(source_ent->d_name) + 2);
                    char *dest_file_path = malloc(strlen(pair->destination_path) + strlen(dest_ent->d_name) + 2);

                    strcpy(source_file_path, pair->source_path);
                    strcat(source_file_path, "/");
                    strcat(source_file_path, source_ent->d_name);

                    strcpy(dest_file_path, pair->destination_path);
                    strcat(dest_file_path, "/");
                    strcat(dest_file_path, dest_ent->d_name);

                    if (S_ISDIR(source_ent->d_type)) {
                        mkdir(dest_file_path, 0755);
                    } else {
                        FILE *source_file = fopen(source_file_path, "rb");
                        FILE *dest_file = fopen(dest_file_path, "wb");

                        char buffer[BUFFER_SIZE];
                        while (fgets(buffer, BUFFER_SIZE, source_file)!= NULL) {
                            fputs(buffer, dest_file);
                        }

                        fclose(source_file);
                        fclose(dest_file);
                    }

                    free(source_file_path);
                    free(dest_file_path);
                }
            }
        }
    }

    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <source_path> <destination_path>\n", argv[0]);
        return 1;
    }

    SyncPair pair = {argv[1], argv[2]};
    sync_files(&pair);

    return 0;
}