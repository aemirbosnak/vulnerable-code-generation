//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

//Struct to hold the line number and character count
typedef struct {
    int line_number;
    int char_count;
} LineCount;

//Struct to hold the file name and line count
typedef struct {
    char filename[MAX_LINE_LENGTH];
    int num_lines;
    LineCount lines[MAX_NUM_LINES];
} FileInfo;

void read_file(char *filename, FileInfo *file_info) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int char_count = 0;

    //Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    //Read the file line by line and count the number of characters in each line
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char_count = strlen(line);
        file_info->lines[line_number].line_number = line_number + 1;
        file_info->lines[line_number].char_count = char_count;
        line_number++;
    }

    file_info->num_lines = line_number;

    //Close the file
    fclose(fp);
}

void print_file_info(FileInfo *file_info) {
    int i;

    printf("File: %s\n", file_info->filename);
    printf("Number of lines: %d\n", file_info->num_lines);

    for (i = 0; i < file_info->num_lines; i++) {
        printf("Line %d: %d characters\n", file_info->lines[i].line_number, file_info->lines[i].char_count);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    FileInfo file_info;

    //Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    //Read the file and count the number of lines and characters in each line
    read_file(filename, &file_info);

    //Print the file information
    print_file_info(&file_info);

    return 0;
}