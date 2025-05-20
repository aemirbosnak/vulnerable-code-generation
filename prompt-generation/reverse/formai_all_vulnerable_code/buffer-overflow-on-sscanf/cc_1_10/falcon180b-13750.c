//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_LEN 1024
#define MAX_LINE_LEN 1024
#define MAX_VIRUS_LEN 1024

// Function to check if a string contains only alphanumeric characters
int is_valid_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to read a file and store its contents in a buffer
int read_file(char* file_path, char* buffer) {
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_path);
        return 0;
    }
    char ch;
    int len = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (len >= MAX_FILE_LEN) {
            printf("Error: File %s is too large\n", file_path);
            fclose(fp);
            return 0;
        }
        buffer[len++] = ch;
    }
    fclose(fp);
    buffer[len] = '\0';
    return 1;
}

// Function to scan a file for viruses
int scan_file(char* virus_db, char* file_path) {
    FILE* fp = fopen(virus_db, "r");
    if (fp == NULL) {
        printf("Error: Could not open virus database\n");
        return 0;
    }
    char line[MAX_LINE_LEN];
    char virus_name[MAX_VIRUS_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (sscanf(line, "%s", virus_name)!= 1) {
            printf("Error: Invalid virus name in database\n");
            fclose(fp);
            return 0;
        }
        if (strlen(virus_name) >= MAX_VIRUS_LEN) {
            printf("Error: Virus name %s is too long\n", virus_name);
            fclose(fp);
            return 0;
        }
        char buffer[MAX_FILE_LEN];
        if (!read_file(file_path, buffer)) {
            fclose(fp);
            return 0;
        }
        char* pos = strstr(buffer, virus_name);
        if (pos!= NULL) {
            printf("Virus detected: %s\n", virus_name);
        }
    }
    fclose(fp);
    return 1;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s virus_database file_to_scan\n", argv[0]);
        return 0;
    }
    if (!is_valid_string(argv[1])) {
        printf("Error: Invalid virus database path\n");
        return 0;
    }
    if (!is_valid_string(argv[2])) {
        printf("Error: Invalid file path\n");
        return 0;
    }
    scan_file(argv[1], argv[2]);
    return 0;
}