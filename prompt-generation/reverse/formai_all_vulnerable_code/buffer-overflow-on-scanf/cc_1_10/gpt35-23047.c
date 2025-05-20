//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("Welcome to the C Antivirus scanner!\n");
    
    char filename[100];
    
    printf("Please enter the name of the file you want to scan: ");
    scanf("%s", filename);

    // Open the file in read-only mode
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open the file. Please try again.\n");
        return 1;
    }

    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    fclose(fp);

    // Check if the file size is greater than 5MB
    if (size > 5000000) {
        printf("Warning: This file is too large and may contain malicious code. Do you want to scan it anyway? (y/n)\n");

        char answer[2];
        scanf("%s", answer);

        if (strcmp(answer, "n") == 0) {
            printf("Exiting the program...\n");
            return 0;
        }
    }

    printf("Scanning the file for viruses...\n");

    // Simulating the scanning process by printing dots
    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout);
        usleep(50000);
    }

    printf("\n");

    printf("No viruses were detected! This file is safe to use.\n");

    return 0;
}