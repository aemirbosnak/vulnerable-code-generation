//FormAI DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file_pointer;
    char input[100], output[100];
    int choice;

    printf("1. Write to file\n2. Read from file\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Writing to a file
            printf("\nEnter file name to write: ");
            scanf("%s", input);

            file_pointer = fopen(input, "w");

            if(ferror(file_pointer)) {
                printf("Failed to open file");
                exit(1);
            }

            printf("Enter data to write: ");
            scanf(" %[^\n]", output);

            fprintf(file_pointer, "%s", output);
            fclose(file_pointer);
            printf("\nData written successfully!");
            break;
        case 2:
            // Reading from a file
            printf("\nEnter file name to read: ");
            scanf("%s", input);

            file_pointer = fopen(input, "r");

            if(ferror(file_pointer)) {
                printf("Failed to open file");
                exit(1);
            }

            printf("\nContents of the file:\n");

            while(fgets(output, sizeof(output), file_pointer)) {
                printf("%s", output);
            }

            fclose(file_pointer);
            break;
        case 3:
            // Exiting the program
            printf("\nExiting...");
            exit(0);
        default:
            printf("\nInvalid choice!");
            break;
    }

    return 0;
}