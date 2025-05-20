//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

void write_header(FILE *fp, char *name, int size);
void read_header(FILE *fp, char *name, int *size);

int main() {
    FILE *fp;
    char name[100], buff[BUFF_SIZE];
    int size;

    printf("Enter the file name to be backed up: ");
    scanf("%s", name);

    fp = fopen(name, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    read_header(fp, name, &size);
    fclose(fp);

    fp = fopen("backup.bin", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    write_header(fp, name, size);

    while ((size = fread(buff, 1, BUFF_SIZE, fp)) > 0) {
        fwrite(buff, 1, size, fp);
    }

    fclose(fp);

    return 0;
}

void write_header(FILE *fp, char *name, int size) {
    fwrite(&name, strlen(name) + 1, 1, fp);
    fwrite(&size, sizeof(size), 1, fp);
}

void read_header(FILE *fp, char *name, int *size) {
    fread(name, strlen(name) + 1, 1, fp);
    fread(size, sizeof(size), 1, fp);
}