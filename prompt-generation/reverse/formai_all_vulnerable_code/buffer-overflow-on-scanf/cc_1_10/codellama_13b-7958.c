//Code Llama-13B DATASET v1.0 Category: File handling ; Style: grateful
// Program to read and write files in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50];
    char ch;
    int i = 0;

    printf("Enter the name of the file you want to read: ");
    scanf("%s", filename);

    // Open the file in read mode
    fp = fopen(filename, "r");

    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file character by character
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
        i++;
    }

    // Close the file
    fclose(fp);

    printf("\n%d characters read from the file.\n", i);

    // Open the file in write mode
    fp = fopen(filename, "w");

    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write to the file
    fprintf(fp, "This is a sample text written to the file.\n");

    // Close the file
    fclose(fp);

    printf("Text written to the file successfully.\n");

    return 0;
}