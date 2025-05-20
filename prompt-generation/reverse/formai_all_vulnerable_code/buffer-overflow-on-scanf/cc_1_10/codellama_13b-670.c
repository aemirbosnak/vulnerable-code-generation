//Code Llama-13B DATASET v1.0 Category: File handling ; Style: irregular
/*
 * Program: File Handling
 * Description: Demonstrates how to create, write, and read a file in C
 * Author: Jatin Goel
 * Date: 01/01/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    FILE *fp;
    char filename[20];
    char buffer[100];
    int i;

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Create file
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    // Write data to file
    for (i = 0; i < 10; i++) {
        fprintf(fp, "Line %d\n", i + 1);
    }

    // Close file
    fclose(fp);

    // Read data from file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read data from file
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close file
    fclose(fp);

    return 0;
}