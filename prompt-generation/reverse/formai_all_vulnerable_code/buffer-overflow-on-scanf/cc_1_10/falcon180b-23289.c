//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[100];
    char path[300];
    char ext[10];
    time_t timestamp;
} file_t;

void backup_file(char* source_path, char* dest_path) {
    FILE* source_file = fopen(source_path, "rb");
    FILE* dest_file = fopen(dest_path, "wb");

    if (source_file == NULL || dest_file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file))!= 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    printf("File backed up successfully.\n");
}

int main() {
    char source_path[300];
    char dest_path[300];
    char backup_path[300];

    printf("Enter source file path: ");
    scanf("%s", source_path);

    printf("Enter destination file path: ");
    scanf("%s", dest_path);

    strcpy(backup_path, dest_path);
    strcat(backup_path, ".bak");

    backup_file(source_path, backup_path);

    return 0;
}