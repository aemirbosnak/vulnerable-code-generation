//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORD_LENGTH 32

typedef struct {
    char *filename;
    FILE *fp;
    int num_lines;
    int num_words;
} File;

void init_file(File *file, char *filename) {
    file->filename = filename;
    file->fp = NULL;
    file->num_lines = 0;
    file->num_words = 0;
}

int is_valid_filename(char *filename) {
    if (filename == NULL || strlen(filename) == 0) {
        return 0;
    }
    for (int i = 0; i < strlen(filename); i++) {
        if (!isalpha(filename[i]) &&!isdigit(filename[i]) && filename[i]!= '_' && filename[i]!= '.') {
            return 0;
        }
    }
    return 1;
}

int open_file(File *file) {
    if (file->fp!= NULL) {
        return 1;
    }
    file->fp = fopen(file->filename, "r");
    if (file->fp == NULL) {
        return 0;
    }
    return 1;
}

void close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        file->fp = NULL;
    }
}

int read_line(File *file, char *line) {
    if (file->fp == NULL) {
        return 0;
    }
    char ch;
    int i = 0;
    while ((ch = fgetc(file->fp))!= EOF && ch!= '\n') {
        line[i++] = tolower(ch);
        if (i >= MAX_LINE_LENGTH) {
            break;
        }
    }
    line[i] = '\0';
    if (ch == EOF) {
        return 0;
    }
    return 1;
}

int count_words(char *line) {
    int num_words = 0;
    int i = 0;
    while (line[i]!= '\0') {
        if (isspace(line[i])) {
            num_words++;
        }
        i++;
    }
    return num_words;
}

void display_file_stats(File *file) {
    printf("Filename: %s\n", file->filename);
    printf("Number of lines: %d\n", file->num_lines);
    printf("Number of words: %d\n", file->num_words);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    if (!is_valid_filename(filename)) {
        printf("Invalid filename\n");
        return 1;
    }
    File file;
    init_file(&file, filename);
    if (!open_file(&file)) {
        printf("Could not open file\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    int num_words = 0;
    while (read_line(&file, line)) {
        num_lines++;
        num_words += count_words(line);
    }
    close_file(&file);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    return 0;
}