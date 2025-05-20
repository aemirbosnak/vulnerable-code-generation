//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define BLOCK_SIZE 512

struct block {
    int index;
    char data[BLOCK_SIZE];
};

struct file {
    char name[20];
    int size;
    struct block blocks[MAX_FILE_SIZE];
};

void read_file(struct file* f) {
    FILE* fp = fopen(f->name, "rb");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    f->size = ftell(fp);
    rewind(fp);

    int i = 0;
    while (f->size > 0) {
        fread(f->blocks[i].data, BLOCK_SIZE, 1, fp);
        f->blocks[i++].index = i;
        f->size -= BLOCK_SIZE;
    }

    fclose(fp);
}

void write_file(struct file* f) {
    FILE* fp = fopen(f->name, "wb");
    if (fp == NULL) {
        printf("Error: could not create file.\n");
        return;
    }

    int i = 0;
    while (i < f->size) {
        fwrite(f->blocks[i].data, BLOCK_SIZE, 1, fp);
        i += BLOCK_SIZE;
    }

    fclose(fp);
}

int main() {
    struct file file;
    printf("Enter file name: ");
    scanf("%s", file.name);

    read_file(&file);

    printf("File successfully read.\n");
    printf("Do you want to write the file? (y/n): ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y') {
        write_file(&file);
        printf("File successfully written.\n");
    }

    return 0;
}