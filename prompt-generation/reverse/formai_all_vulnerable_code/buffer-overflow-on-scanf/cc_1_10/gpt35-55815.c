//FormAI DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 20
#define MAX_FILE_SIZE 1024

typedef struct {
    char filename[MAX_FILENAME_LEN];
    char content[MAX_FILE_SIZE];
    time_t timestamp;
} File;

void backup(File *file, int *count);

int main() {
    File file;
    int count = 0;
    while (1) {
        printf("Enter filename (max %d characters): ", MAX_FILENAME_LEN);
        fgets(file.filename, MAX_FILENAME_LEN, stdin);
        file.filename[strcspn(file.filename, "\n")] = '\0'; // remove newline character

        printf("Enter file content (max %d characters): ", MAX_FILE_SIZE);
        fgets(file.content, MAX_FILE_SIZE, stdin);
        file.content[strcspn(file.content, "\n")] = '\0'; // remove newline character

        file.timestamp = time(NULL);

        backup(&file, &count);

        printf("File backed up!\n");

        printf("Do you want to backup another file? (Y/N): ");
        char response;
        scanf("%c", &response);
        getchar(); // remove newline character from buffer
        if (response == 'N') {
            break;
        }
    }

    printf("Total files backed up: %d\n", count);
    return 0;
}

void backup(File *file, int *count) {
    FILE *fptr;
    char filename[MAX_FILENAME_LEN + 10];
    sprintf(filename, "%s_%ld.txt", file->filename, file->timestamp);
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error creating backup file!\n");
        return;
    }
    fprintf(fptr, "File name: %s\n", file->filename);
    fprintf(fptr, "File content: %s\n", file->content);
    fprintf(fptr, "Timestamp: %s\n", asctime(localtime(&file->timestamp)));
    fclose(fptr);
    (*count)++;
}