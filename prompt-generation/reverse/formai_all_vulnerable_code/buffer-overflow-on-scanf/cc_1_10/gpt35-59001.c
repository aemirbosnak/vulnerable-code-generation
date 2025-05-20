//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;
    char filename[20], str[100], ch;
    int choice, count = 0;

    while(1) {
        printf("\n1. Create a new file\n2. Read an existing file\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter the name of the new file: ");
                scanf("%s", filename);

                // Open the file for writing
                file_ptr = fopen(filename, "w");

                if(file_ptr == NULL) {
                    printf("Error creating file!");
                    exit(1);
                }

                printf("\nEnter text for the file (enter # to stop):\n");
                scanf(" %c", &ch);
                while(ch != '#') {
                    fputc(ch, file_ptr);
                    scanf("%c", &ch);
                }

                fclose(file_ptr);
                printf("\nFile created!");
                break;

            case 2: 
                printf("\nEnter the name of the existing file: ");
                scanf("%s", filename);

                // Open the file for reading
                file_ptr = fopen(filename, "r");

                if(file_ptr == NULL) {
                    printf("Error opening file!");
                    exit(1);
                }

                printf("\nThe contents of the file are:\n");

                while((ch = fgetc(file_ptr)) != EOF) {
                    putchar(ch);
                    if(ch == '\n') count++;
                }

                printf("\n\nNumber of lines in the file: %d", count);
                fclose(file_ptr);
                break;

            case 3: 
                printf("\nExiting program...");
                exit(0);
                break;

            default: 
                printf("\nInvalid choice! Please enter a valid choice.");
        }
    }
    return 0;
}