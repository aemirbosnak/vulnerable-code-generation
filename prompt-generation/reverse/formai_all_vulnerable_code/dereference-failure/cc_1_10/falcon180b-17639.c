//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

struct file {
    char name[MAX_SIZE];
    int size;
    char content[MAX_SIZE];
};

void read_file(struct file *file) {
    FILE *fp = fopen(file->name, "r");
    if (fp == NULL) {
        printf("Error: File does not exist.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);
    fread(file->content, file->size, 1, fp);
    fclose(fp);
}

void write_file(struct file *file) {
    FILE *fp = fopen(file->name, "w");
    if (fp == NULL) {
        printf("Error: File cannot be written.\n");
        exit(1);
    }
    fwrite(file->content, file->size, 1, fp);
    fclose(fp);
}

void sync_files(struct file *file1, struct file *file2) {
    if (strcmp(file1->content, file2->content)!= 0) {
        if (file1->size > file2->size) {
            printf("File 1 is larger. Overwriting File 2.\n");
            write_file(file1);
        } else {
            printf("File 2 is larger. Overwriting File 1.\n");
            write_file(file2);
        }
    } else {
        printf("Files are already synchronized.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./program file1 file2\n");
        exit(1);
    }

    struct file file1, file2;

    strcpy(file1.name, argv[1]);
    strcpy(file2.name, argv[2]);

    read_file(&file1);
    read_file(&file2);

    sync_files(&file1, &file2);

    return 0;
}