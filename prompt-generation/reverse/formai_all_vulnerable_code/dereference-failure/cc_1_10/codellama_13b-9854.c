//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: excited
/*
 * File Backup System
 * By John Doe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

#define BUFSIZE 1024

typedef struct {
    char *path;
    char *file;
    char *backup;
} file_t;

void print_usage(char *progname) {
    printf("Usage: %s <path> <file> <backup>\n", progname);
    printf("    <path>  - path to the file to backup\n");
    printf("    <file>  - name of the file to backup\n");
    printf("    <backup> - name of the backup file\n");
}

void backup_file(file_t *file) {
    FILE *fp = fopen(file->path, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    FILE *fp2 = fopen(file->backup, "w");
    if (fp2 == NULL) {
        perror("Error creating backup file");
        exit(1);
    }

    char buf[BUFSIZE];
    while (fgets(buf, BUFSIZE, fp) != NULL) {
        fputs(buf, fp2);
    }

    fclose(fp);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        exit(1);
    }

    file_t file;
    file.path = argv[1];
    file.file = argv[2];
    file.backup = argv[3];

    backup_file(&file);

    return 0;
}