//Falcon-180B DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to create a new file
void create_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot create file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "This is a new file.\n");
    fclose(fp);
}

// Function to append to an existing file
void append_to_file(char *filename) {
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    fprintf(fp, "This is an appended line.\n");
    fclose(fp);
}

// Function to read from a file
void read_from_file(char *filename) {
    FILE *fp;
    char ch;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

// Function to delete a file
void delete_file(char *filename) {
    remove(filename);
    printf("%s deleted.\n", filename);
}

// Main function
int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Create a new file
    create_file(filename);

    // Append to the same file
    append_to_file(filename);

    // Read from the file
    read_from_file(filename);

    // Delete the file
    delete_file(filename);

    return 0;
}