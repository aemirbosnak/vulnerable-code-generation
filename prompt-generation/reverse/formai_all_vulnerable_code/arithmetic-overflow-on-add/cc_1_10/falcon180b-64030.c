//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <dirent.h>

#define MAX_FILE_NAME 1024
#define MAX_VIRUS_NAME 1024
#define MAX_VIRUS_SIZE 1024
#define MAX_VIRUS_COUNT 1024

typedef struct {
    char name[MAX_FILE_NAME];
    char path[MAX_FILE_NAME];
    char virus[MAX_VIRUS_NAME];
    int size;
    int count;
} FileInfo;

void scan_folder(const char* folder_path) {
    DIR* dir = opendir(folder_path);
    if (dir == NULL) {
        printf("Error: Failed to open directory '%s'\n", folder_path);
        return;
    }

    FileInfo files[MAX_VIRUS_COUNT];
    int file_count = 0;

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type!= DT_REG) {
            continue;
        }

        char path[MAX_FILE_NAME];
        sprintf(path, "%s/%s", folder_path, entry->d_name);

        FILE* file = fopen(path, "rb");
        if (file == NULL) {
            continue;
        }

        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        fseek(file, 0, SEEK_SET);

        char buffer[size];
        fread(buffer, 1, size, file);
        fclose(file);

        for (int i = 0; i < MAX_VIRUS_COUNT; i++) {
            if (files[i].size == size &&!memcmp(buffer, files[i].virus, size)) {
                files[i].count++;
                break;
            }
        }

        if (file_count >= MAX_VIRUS_COUNT) {
            break;
        }

        strcpy(files[file_count].name, entry->d_name);
        strcpy(files[file_count].path, path);
        strcpy(files[file_count].virus, "Virus");
        files[file_count].size = size;
        files[file_count].count = 1;
        file_count++;
    }

    closedir(dir);

    if (file_count == 0) {
        printf("No infected files found.\n");
        return;
    }

    printf("Infected files:\n");
    for (int i = 0; i < file_count; i++) {
        printf("File name: %s\nPath: %s\nVirus: %s\nSize: %d bytes\nCount: %d\n",
            files[i].name, files[i].path, files[i].virus, files[i].size, files[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <folder_path>\n", argv[0]);
        return 1;
    }

    scan_folder(argv[1]);

    return 0;
}