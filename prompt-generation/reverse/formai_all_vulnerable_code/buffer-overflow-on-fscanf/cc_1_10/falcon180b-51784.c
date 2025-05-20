//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char *name;
    char *contents;
    size_t size;
} File;

int is_file_name_valid(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!isalnum(name[i]) && name[i]!= '.' && name[i]!= '-') {
            return 0;
        }
    }
    return 1;
}

int is_file_content_valid(char *contents) {
    int i;
    for (i = 0; i < strlen(contents); i++) {
        if (!isprint(contents[i])) {
            return 0;
        }
    }
    return 1;
}

void print_file_contents(File *file) {
    printf("File Name: %s\n", file->name);
    printf("File Contents:\n");
    printf("%s\n", file->contents);
}

int main() {
    FILE *fp1, *fp2;
    char ch1, ch2;
    char name1[MAX_FILE_NAME_LENGTH], name2[MAX_FILE_NAME_LENGTH];
    char contents1[MAX_LINE_LENGTH], contents2[MAX_LINE_LENGTH];
    char *token1, *token2;
    int count1 = 0, count2 = 0;
    int valid1 = 0, valid2 = 0;
    int i;

    // Open files
    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file names
    fscanf(fp1, "%s", name1);
    fscanf(fp2, "%s", name2);

    if (!is_file_name_valid(name1) ||!is_file_name_valid(name2)) {
        printf("Invalid file name.\n");
        exit(1);
    }

    // Read file contents
    while ((ch1 = fgetc(fp1))!= EOF) {
        contents1[count1++] = ch1;
    }

    while ((ch2 = fgetc(fp2))!= EOF) {
        contents2[count2++] = ch2;
    }

    contents1[count1] = '\0';
    contents2[count2] = '\0';

    // Check if file contents are valid
    valid1 = is_file_content_valid(contents1);
    valid2 = is_file_content_valid(contents2);

    if (!valid1 ||!valid2) {
        printf("Invalid file content.\n");
        exit(1);
    }

    // Compare file contents
    if (strcmp(contents1, contents2) == 0) {
        printf("Files are synchronized.\n");
    } else {
        printf("Files are not synchronized.\n");
        printf("File 1:\n");
        print_file_contents(&(File){.name = name1,.contents = contents1,.size = strlen(contents1)});
        printf("File 2:\n");
        print_file_contents(&(File){.name = name2,.contents = contents2,.size = strlen(contents2)});
    }

    // Close files
    fclose(fp1);
    fclose(fp2);

    return 0;
}