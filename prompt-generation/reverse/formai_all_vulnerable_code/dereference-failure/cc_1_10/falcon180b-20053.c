//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_count;
} File;

void open_file(File *file, char *filename) {
    strcpy(file->name, filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
}

int read_line(File *file) {
    char c;
    int i = 0;
    while ((c = fgetc(file->fp))!= EOF) {
        if (i >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long in file %s\n", file->name);
            exit(1);
        }
        file->line[i++] = c;
    }
    file->line[i] = '\0';
    return 1;
}

int is_virus(char *line) {
    char *viruses[] = {"virus", "trojan", "worm", "malware", "spyware", "adware", "keylogger", "rootkit", "ransomware", "botnet"};
    int i;
    for (i = 0; i < sizeof(viruses)/sizeof(viruses[0]); i++) {
        if (strstr(line, viruses[i])!= NULL) {
            return 1;
        }
    }
    return 0;
}

void close_file(File *file) {
    fclose(file->fp);
}

void print_line(File *file) {
    printf("%s:%d: %s", file->name, file->line_count, file->line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char filename[MAX_FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);
    File file;
    open_file(&file, filename);
    while (read_line(&file)) {
        if (is_virus(file.line)) {
            print_line(&file);
        }
    }
    close_file(&file);
    return 0;
}