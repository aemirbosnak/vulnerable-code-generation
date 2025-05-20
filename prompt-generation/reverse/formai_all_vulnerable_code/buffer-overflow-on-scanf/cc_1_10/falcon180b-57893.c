//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000

// Function to check if a given string is a palindrome
int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to read the contents of a file into a string
char* read_file(FILE* fp) {
    char* buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    char ch;
    int len = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (len >= MAX_FILE_SIZE - 1) {
            printf("Error: file is too large.\n");
            exit(1);
        }
        buffer[len++] = ch;
    }
    buffer[len] = '\0';
    return buffer;
}

// Function to scan a file for viruses
int scan_file(char* file_name) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", file_name);
        exit(1);
    }
    char* contents = read_file(fp);
    fclose(fp);
    int len = strlen(contents);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (is_palindrome(contents + i + 1)) {
                printf("Virus found: '%s' is a palindrome.\n", contents + i + 1);
                return 1;
            }
        }
    }
    printf("No viruses found.\n");
    return 0;
}

int main() {
    char file_name[100];
    printf("Enter the name of the file to scan: ");
    scanf("%s", file_name);
    scan_file(file_name);
    return 0;
}