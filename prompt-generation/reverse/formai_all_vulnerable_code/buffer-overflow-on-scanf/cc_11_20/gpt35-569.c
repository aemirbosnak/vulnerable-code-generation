//FormAI DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

int main() {
    FILE *file_ptr;
    char* filename = "database.txt";
    char line[MAX_LINES];
    int character, choice, count = 0;

    // Cyberpunk-style intro
    printf("Welcome to the File Manager 3000\n"
           "What do you want to do?\n");

    do {
        // User options
        printf("\n1. Create new file\n"
               "2. Write to file\n"
               "3. Read from file\n"
               "4. Delete file\n"
               "5. Quit\n"
               "> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Create new file
                file_ptr = fopen(filename, "w");
                if (file_ptr == NULL) {
                    printf("Error: could not create file\n");
                } else {
                    printf("File created successfully\n");
                }
                fclose(file_ptr);
                break;

            case 2:
                // Write to file
                file_ptr = fopen(filename, "a");
                if (file_ptr == NULL) {
                    printf("Error: could not open file\n");
                } else {
                    printf("What do you want to add to the file?\n");
                    scanf("\n");
                    fgets(line, MAX_LINES, stdin);
                    fprintf(file_ptr, "%s", line);
                    printf("Write successful\n");
                }
                fclose(file_ptr);
                break;

            case 3:
                // Read from file
                file_ptr = fopen(filename, "r");
                if (file_ptr == NULL) {
                    printf("Error: could not open file\n");
                } else {
                    printf("File contents:\n");
                    while ((character = fgetc(file_ptr)) != EOF) {
                        putchar(character);
                        count++;
                    }
                    if (count == 0) {
                        printf("File is empty\n");
                    }
                }
                fclose(file_ptr);
                break;

            case 4:
                // Delete file
                if (remove(filename) == 0) {
                    printf("File deleted successfully\n");
                } else {
                    printf("Error: could not delete file\n");
                }
                break;
            
            case 5:
                // Quit program
                printf("Goodbye\n");
                exit(0);

            default:
                // Invalid choice
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}