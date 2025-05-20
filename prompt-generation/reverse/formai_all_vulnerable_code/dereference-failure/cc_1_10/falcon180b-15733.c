//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1000000

struct File {
    char name[50];
    char path[100];
    char extension[10];
    int size;
};

void create_file(struct File *file, char *filename) {
    strcpy(file->name, filename);
    strcpy(file->path, "C:\\");
    strcpy(file->extension, ".txt");
    file->size = 0;
}

void open_file(struct File *file) {
    FILE *fp;
    fp = fopen(file->path, "a");
    if (fp == NULL) {
        printf("Error: File cannot be opened\n");
        exit(1);
    }
    fclose(fp);
}

void write_file(struct File *file, char *data) {
    FILE *fp;
    fp = fopen(file->path, "a");
    if (fp == NULL) {
        printf("Error: File cannot be opened\n");
        exit(1);
    }
    fprintf(fp, "%s", data);
    fclose(fp);
    file->size += strlen(data);
}

void backup_file(struct File *file) {
    char backup_path[100];
    strcpy(backup_path, "C:\\Backup\\");
    strcat(backup_path, file->name);
    strcat(backup_path, ".bak");

    FILE *fp;
    fp = fopen(backup_path, "w");
    if (fp == NULL) {
        printf("Error: Backup file cannot be created\n");
        exit(1);
    }

    FILE *fp1;
    fp1 = fopen(file->path, "r");
    if (fp1 == NULL) {
        printf("Error: File cannot be opened\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp1))!= EOF) {
        fprintf(fp, "%c", ch);
    }

    fclose(fp1);
    fclose(fp);
}

int main() {
    struct File file;
    create_file(&file, "test.txt");
    open_file(&file);

    char data[] = "This is a test file";
    write_file(&file, data);

    backup_file(&file);

    return 0;
}