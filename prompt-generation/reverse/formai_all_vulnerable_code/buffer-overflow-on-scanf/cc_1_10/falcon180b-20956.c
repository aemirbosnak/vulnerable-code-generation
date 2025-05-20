//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} FileInfo;

int main() {
    int num_files;
    scanf("%d", &num_files);

    FileInfo files[num_files];

    // Read in file names and backup file names
    for (int i = 0; i < num_files; i++) {
        scanf("%s", files[i].file_name);
        scanf("%s", files[i].backup_file_name);
    }

    // Backup each file
    for (int i = 0; i < num_files; i++) {
        FILE *file = fopen(files[i].file_name, "r");
        if (file == NULL) {
            printf("Error: Could not open file %s\n", files[i].file_name);
            exit(1);
        }

        FILE *backup_file = fopen(files[i].backup_file_name, "w");
        if (backup_file == NULL) {
            printf("Error: Could not create backup file %s\n", files[i].backup_file_name);
            exit(1);
        }

        char buffer[10000];
        while (fgets(buffer, sizeof(buffer), file)!= NULL) {
            fputs(buffer, backup_file);
        }

        fclose(file);
        fclose(backup_file);
    }

    printf("Backup complete!\n");

    return 0;
}