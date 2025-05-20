//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int i;
    for(i = 0; i < strlen(str1) && i < strlen(str2); i++) {
        if(tolower(str1[i])!= tolower(str2[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to read a file into a string
char* read_file(FILE* fp) {
    char* buffer = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    char* result = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    int i = 0;
    while(fscanf(fp, "%c", &buffer[i])!= EOF) {
        i++;
        if(i == MAX_STRING_LENGTH - 1) {
            result = (char*) realloc(result, MAX_STRING_LENGTH * 2 * sizeof(char));
        }
        strcat(result, buffer);
    }
    return result;
}

// Function to write a string to a file
void write_file(char* str, FILE* fp) {
    fprintf(fp, "%s", str);
}

// Function to synchronize two files
void synchronize_files(char* file1, char* file2) {
    FILE* fp1, *fp2;
    char* content1, *content2;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    content1 = read_file(fp1);
    content2 = read_file(fp2);

    if(compare_strings(content1, content2)) {
        printf("Files are synchronized.\n");
    } else {
        printf("Files are not synchronized.\n");
        write_file(content1, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

int main() {
    char* file1, *file2;
    printf("Enter the name of the first file: ");
    scanf("%s", file1);
    printf("Enter the name of the second file: ");
    scanf("%s", file2);

    synchronize_files(file1, file2);

    return 0;
}