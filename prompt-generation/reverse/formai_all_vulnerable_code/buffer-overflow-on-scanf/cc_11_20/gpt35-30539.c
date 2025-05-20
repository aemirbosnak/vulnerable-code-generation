//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to the Paranoid Ebook Reader!\n");
    printf("Reading an ebook can be dangerous, but we've got you covered.\n");
    printf("Please provide the name and path of the ebook you would like to read: ");

    // Getting the filepath input from user
    char filepath[100];
    scanf("%s", filepath);

    // Checking for potential file tampering
    if (strstr(filepath, "../") != NULL) {
        printf("\nPossible file tampering detected. Terminating program.\n");
        return 0;
    }

    // Opening the file
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("\nError: File not found or unable to open. Terminating program.\n");
        return 0;
    }

    // Verifying that the file is an ebook
    char file_extension[5];
    int i = 0;
    while (filepath[i] != '\0') {
        if (filepath[i] == '.') {
            int j = i;
            while (filepath[j] != '\0') {
                file_extension[j-i] = filepath[j];
                j++;
            }
            file_extension[j-i] = '\0';
        }
        i++;
    }
    if (strcmp(file_extension, ".epub") != 0
        && strcmp(file_extension, ".mobi") != 0
        && strcmp(file_extension, ".pdf") != 0) {
            printf("\nError: File format not supported. Terminating program.\n");
            return 0;
    }

    // Reading and displaying the contents of the ebook
    printf("\nReading contents of ebook:\n");
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        if (ch != '\n') {
            printf("%c", ch);
            if (rand()%50 == 0) {
                printf("[WARNING: Possible malicious code detected.]\n");
                printf("Do you want to continue reading? (Y/N):");
                char choice;
                scanf("%c", &choice);
                if (choice != 'Y' && choice != 'y' && choice != '\n') {
                    printf("Terminating program.\n");
                    return 0;
                }
            }
        }
    }

    // Closing the file
    fclose(fp);

    // Exit message
    printf("\n\nEnd of ebook. Thank you for using the Paranoid Ebook Reader!\n");

    return 0;
}