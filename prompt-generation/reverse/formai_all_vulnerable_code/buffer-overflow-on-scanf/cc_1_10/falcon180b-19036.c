//Falcon-180B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new file
void create_file(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to create file %s\n", filename);
        exit(1);
    }
    fclose(fp);
}

// Function to append to a file
void append_file(char *filename, char *text) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "%s", text);
    fclose(fp);
}

// Function to read from a file
void read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

// Function to delete a file
void delete_file(char *filename) {
    remove(filename);
}

// Main function
int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Create a new file
    create_file(filename);

    // Append some text to the file
    char text[100] = "Hello, world!";
    append_file(filename, text);

    // Read from the file
    read_file(filename);

    // Delete the file
    delete_file(filename);

    return 0;
}