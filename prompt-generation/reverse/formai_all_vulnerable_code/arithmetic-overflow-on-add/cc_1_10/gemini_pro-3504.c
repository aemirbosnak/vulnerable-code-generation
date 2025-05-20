//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

// Function to get the file size
long get_file_size(char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Function to read a file into a buffer
char *read_file(char *filename) {
    long file_size = get_file_size(filename);
    if (file_size == -1) {
        return NULL;
    }

    char *buf = malloc(file_size + 1);
    if (buf == NULL) {
        return NULL;
    }

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        free(buf);
        return NULL;
    }

    fread(buf, file_size, 1, fp);
    buf[file_size] = '\0';

    fclose(fp);

    return buf;
}

// Function to write a buffer to a file
int write_file(char *filename, char *buf, long size) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }

    fwrite(buf, size, 1, fp);

    fclose(fp);

    return 0;
}

// Function to create a backup of a file
int backup_file(char *filename) {
    char *buf = read_file(filename);
    if (buf == NULL) {
        return -1;
    }

    long file_size = get_file_size(filename);
    if (file_size == -1) {
        free(buf);
        return -1;
    }

    char backup_filename[256];
    snprintf(backup_filename, 256, "%s.%ld.bak", filename, time(NULL));

    int ret = write_file(backup_filename, buf, file_size);

    free(buf);

    return ret;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int ret = backup_file(argv[1]);
    if (ret == -1) {
        printf("Error backing up file: %s\n", argv[1]);
        return 1;
    }

    printf("Backup file created: %s\n", argv[1]);

    return 0;
}