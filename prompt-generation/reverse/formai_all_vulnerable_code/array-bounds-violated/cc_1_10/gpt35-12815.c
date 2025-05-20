//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_PATH_LENGTH 256
#define MAX_BUFFER_SIZE 1024

int check_file_extension(char *filename) {
    char *extension = strrchr(filename, '.');
    if (extension == NULL) {
        return 0;
    }
    if (strcmp(extension, ".c") == 0) {
        return 1;
    }
    return 0;
}

int check_for_virus(char *buffer) {
    // Check for virus patterns in the buffer
    if (strstr(buffer, "malware") != NULL) {
        return 1;
    }
    if (strstr(buffer, "virus") != NULL) {
        return 1;
    }
    if (strstr(buffer, "trojan") != NULL) {
        return 1;
    }
    if (strstr(buffer, "rootkit") != NULL) {
        return 1;
    }
    return 0;
}

int main() {

    char file_path[MAX_FILE_PATH_LENGTH];
    char buffer[MAX_BUFFER_SIZE];

    printf("Welcome to the C Antivirus Scanner\n\n");
    printf("Please enter the file path to the C program you wish to scan: ");
    fgets(file_path, MAX_FILE_PATH_LENGTH, stdin);
    file_path[strlen(file_path) - 1] = '\0';    // Remove trailing newline character

    if (!check_file_extension(file_path)) {
        printf("\nError: File is not a .c file\n");
        exit(1);
    }

    FILE *fptr = fopen(file_path, "r");
    if (fptr == NULL) {
        printf("\nError: Unable to open file\n");
        exit(1);
    }

    int virus_found = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, fptr) != NULL) {
        if (check_for_virus(buffer)) {
            virus_found = 1;
            break;
        }
    }

    fclose(fptr);

    if (virus_found) {
        printf("\nAlert: Virus found in file\n");
    } else {
        printf("\nSuccess: No virus found in file\n");
    }

    return 0;
}