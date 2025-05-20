//Falcon-180B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function to count the number of lines in a file
int countLines(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

int main() {
    FILE* file;
    char filename[100];
    int choice, lines;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Display menu
    printf("\nMenu:\n");
    printf("1. Count lines in file\n");
    printf("2. Display file contents\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Count lines in file
    if (choice == 1) {
        lines = countLines(file);
        printf("Number of lines in file: %d\n", lines);
    }
    // Display file contents
    else if (choice == 2) {
        char c;
        while ((c = fgetc(file))!= EOF) {
            printf("%c", c);
        }
        printf("\n");
    }
    // Exit program
    else if (choice == 3) {
        exit(0);
    }
    else {
        printf("Invalid choice.\n");
    }

    // Close file
    fclose(file);

    return 0;
}