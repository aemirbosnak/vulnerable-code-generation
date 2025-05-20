//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000
#define MAX_BACKUP_FILES 10

typedef struct {
    char filename[100];
    char backup_filename[100];
    time_t timestamp;
    int size;
} file_t;

int main() {
    file_t files[MAX_BACKUP_FILES];
    int num_files = 0;
    char input[100];

    printf("Enter the name of the file to backup: ");
    scanf("%s", input);

    FILE *file = fopen(input, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);

    strcpy(files[num_files].filename, input);
    strcpy(files[num_files].backup_filename, "backup_");
    strcat(files[num_files].backup_filename, input);
    strcat(files[num_files].backup_filename, "_");
    time_t now = time(NULL);
    strftime(files[num_files].backup_filename + strlen(files[num_files].backup_filename), 100, "%Y%m%d_%H%M%S", localtime(&now));
    files[num_files].timestamp = now;
    files[num_files].size = file_size;
    num_files++;

    for (int i = 0; i < num_files; i++) {
        printf("File %s was backed up to %s at %s and is %d bytes.\n", files[i].filename, files[i].backup_filename, ctime(&files[i].timestamp), files[i].size);
    }

    return 0;
}