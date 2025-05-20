//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct FileRecord {
    char filename[MAX_FILE_SIZE];
    int size;
    struct FileRecord* next;
} FileRecord;

void backup_files(FILE* file) {
    FileRecord* head = NULL;
    char filename[MAX_FILE_SIZE];
    int size;

    printf("Enter file name:");
    scanf("%s", filename);

    printf("Enter file size:");
    scanf("%d", &size);

    FileRecord* new_record = malloc(sizeof(FileRecord));
    strcpy(new_record->filename, filename);
    new_record->size = size;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }

    file = fopen("backup.txt", "w");
    fprintf(file, "Filename: %s\n", head->filename);
    fprintf(file, "Size: %d\n", head->size);

    while (head->next) {
        head = head->next;
        fprintf(file, "Filename: %s\n", head->filename);
        fprintf(file, "Size: %d\n", head->size);
    }

    fclose(file);
}

int main() {
    FILE* file = fopen("backup.txt", "w");
    backup_files(file);
    fclose(file);

    return 0;
}