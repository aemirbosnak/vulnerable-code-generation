//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define BUFFER_SIZE 4096

typedef struct {
    char *name;
    int infected;
} File;

void scan_file(const char *filename, File *file) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int size;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    file->infected = 0;
    while ((size = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        char *p = buffer;
        while (size > 0) {
            if (*p == 0xE8) { // check for virus signature
                file->infected = 1;
                break;
            }
            p++;
            size--;
        }
    }

    fclose(fp);
}

int main() {
    File files[MAX_FILES];
    int num_files = 0;
    char path[1024];
    char *p;

    printf("Enter the path to scan: ");
    scanf("%s", path);

    p = strrchr(path, '/');
    if (p == NULL) {
        strcpy(p, ".");
    } else {
        *p = '\0';
    }

    while (1) {
        char *filename = readdir(path);
        if (filename == NULL) {
            break;
        }

        if (filename[0] == '.') {
            continue;
        }

        strcat(path, "/");
        strcat(path, filename);

        files[num_files].name = strdup(filename);
        files[num_files].infected = 0;
        num_files++;

        scan_file(path, &files[num_files - 1]);

        if (files[num_files - 1].infected) {
            printf("%s is infected with a virus!\n", files[num_files - 1].name);
        }
    }

    return 0;
}