//Falcon-180B DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

// Function to open and read a file
void read_file(FILE *fp, char *filename) {
    char line[MAX_LINE_LEN];
    printf("Reading file %s:\n", filename);
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        printf("%s", line);
    }
}

// Function to write to a file
void write_file(FILE *fp, char *filename) {
    char line[MAX_LINE_LEN];
    printf("Writing to file %s:\n", filename);
    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        fputs(line, fp);
    }
}

// Function to append to a file
void append_file(FILE *fp, char *filename) {
    char line[MAX_LINE_LEN];
    printf("Appending to file %s:\n", filename);
    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        fputs(line, fp);
    }
}

int main() {
    char filename[MAX_LINE_LEN];
    char choice;
    FILE *fp;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file for reading, writing, and appending
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    do {
        printf("\nWhat would you like to do with the file?\n");
        printf("1. Read\n2. Write\n3. Append\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                read_file(fp, filename);
                break;
            case '2':
                write_file(fp, filename);
                break;
            case '3':
                append_file(fp, filename);
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\nWould you like to perform another action? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    fclose(fp);
    return 0;
}