//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define VIRUS_SIGNATURE "VIRUS"

// Function to read file content into buffer
void read_file(FILE *fp, char *buffer) {
    char ch;
    int count = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (count >= MAX_FILE_SIZE) {
            printf("File size exceeds limit.\n");
            exit(1);
        }
        buffer[count++] = ch;
    }
    buffer[count] = '\0';
}

// Function to scan for virus signature
int scan_virus(char *buffer) {
    char *signature = VIRUS_SIGNATURE;
    char *ptr = strstr(buffer, signature);

    if (ptr!= NULL) {
        printf("Virus found!\n");
        return 1;
    } else {
        printf("No virus found.\n");
        return 0;
    }
}

int main() {
    char filename[50];
    FILE *fp;
    char buffer[MAX_FILE_SIZE];

    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Read file content into buffer
    read_file(fp, buffer);

    // Scan for virus signature
    scan_virus(buffer);

    fclose(fp);
    return 0;
}