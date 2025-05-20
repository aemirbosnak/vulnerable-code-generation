//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print a string recursively
void print_string(char *str) {
    if (str == NULL)
        return;
    printf("%s", str);
}

// Function to read a file recursively
void read_file(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
    }
}

// Function to write to a file recursively
void write_file(FILE *fp) {
    char ch;
    printf("Enter the string to write: ");
    scanf("%s", ch);
    fprintf(fp, "%s", ch);
}

// Function to append to a file recursively
void append_file(FILE *fp) {
    char ch[100];
    printf("Enter the string to append: ");
    scanf("%s", ch);
    fprintf(fp, "%s", ch);
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Print the contents of the file recursively
    print_string("File contents:\n");
    read_file(fp);
    printf("\n");

    // Close the file
    fclose(fp);

    // Open the file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Write to the file recursively
    print_string("Write to file:\n");
    write_file(fp);
    printf("\n");

    // Close the file
    fclose(fp);

    // Open the file for appending
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Append to the file recursively
    print_string("Append to file:\n");
    append_file(fp);
    printf("\n");

    // Close the file
    fclose(fp);

    return 0;
}