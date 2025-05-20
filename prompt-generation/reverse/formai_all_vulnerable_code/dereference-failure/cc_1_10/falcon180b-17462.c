//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

typedef struct {
    char *filename;
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int buffer_index;
    int buffer_size;
    int modified;
} File;

void init_file(File *f, char *filename) {
    f->filename = filename;
    f->fp = fopen(filename, "r");
    if (f->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    f->buffer_index = 0;
    f->buffer_size = 0;
    f->modified = 0;
}

void read_file(File *f) {
    char c;
    int i = 0;
    while ((c = fgetc(f->fp))!= EOF) {
        if (i >= MAX_FILE_SIZE - 1) {
            printf("Error: File %s is too large\n", f->filename);
            exit(1);
        }
        f->buffer[i++] = c;
    }
    f->buffer_size = i;
}

void write_file(File *f) {
    if (f->modified) {
        fseek(f->fp, 0, SEEK_SET);
        fwrite(f->buffer, f->buffer_size, 1, f->fp);
        f->modified = 0;
    }
}

void close_file(File *f) {
    fclose(f->fp);
}

int compare_files(File *f1, File *f2) {
    int cmp;
    while ((cmp = memcmp(f1->buffer, f2->buffer, f1->buffer_size)) == 0) {
        if (f1->buffer_size == f2->buffer_size) {
            return 0;
        }
        read_file(f1);
        read_file(f2);
    }
    return cmp;
}

void synchronize_files(File *f1, File *f2) {
    int cmp;
    while ((cmp = compare_files(f1, f2))!= 0) {
        if (cmp < 0) {
            write_file(f2);
        } else {
            write_file(f1);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }
    File f1, f2;
    init_file(&f1, argv[1]);
    init_file(&f2, argv[2]);
    synchronize_files(&f1, &f2);
    close_file(&f1);
    close_file(&f2);
    return 0;
}