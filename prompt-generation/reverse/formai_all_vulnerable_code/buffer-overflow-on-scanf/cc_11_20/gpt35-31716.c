//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100], buffer[100];
    int i, choice, num_bytes;

    printf("Welcome to the file handling program!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new file\n");
        printf("2. Write to an existing file\n");
        printf("3. Read from a file\n");
        printf("4. Append to an existing file\n");
        printf("5. Delete a file\n");
        printf("6. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the name of the file to create: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");
                if (fp != NULL) {
                    printf("File '%s' created successfully!\n", filename);
                    fclose(fp);
                } else {
                    printf("Error creating file '%s'!\n", filename);
                }
                break;

            case 2:
                printf("\nEnter the name of the file to write to: ");
                scanf("%s", filename);

                fp = fopen(filename, "w");
                if (fp != NULL) {
                    printf("Enter the text to write to the file (press Ctrl+D to finish):\n");
                    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                        fputs(buffer, fp);
                    }
                    printf("Text written to file '%s' successfully!\n", filename);
                    fclose(fp);
                } else {
                    printf("Error writing to file '%s'!\n", filename);
                }
                break;

            case 3:
                printf("\nEnter the name of the file to read from: ");
                scanf("%s", filename);

                fp = fopen(filename, "r");
                if (fp != NULL) {
                    printf("Contents of file '%s':\n", filename);
                    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                        printf("%s", buffer);
                    }
                    printf("\n");
                    fclose(fp);
                } else {
                    printf("Error reading file '%s'!\n", filename);
                }
                break;

            case 4:
                printf("\nEnter the name of the file to append to: ");
                scanf("%s", filename);

                fp = fopen(filename, "a");
                if (fp != NULL) {
                    printf("Enter the text to append to the file (press Ctrl+D to finish):\n");
                    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                        fputs(buffer, fp);
                    }
                    printf("Text appended to file '%s' successfully!\n", filename);
                    fclose(fp);
                } else {
                    printf("Error appending to file '%s'!\n", filename);
                }
                break;

            case 5:
                printf("\nEnter the name of the file to delete: ");
                scanf("%s", filename);

                if (remove(filename) == 0) {
                    printf("File '%s' deleted successfully!\n", filename);
                } else {
                    printf("Error deleting file '%s'!\n", filename);
                }
                break;

            case 6:
                printf("\nThank you for using the file handling program!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}