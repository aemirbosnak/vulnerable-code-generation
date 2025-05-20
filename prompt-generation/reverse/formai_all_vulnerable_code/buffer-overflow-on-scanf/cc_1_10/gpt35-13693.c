//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

/* Define a function to store entered text in a file */
void store_text(char *filename)
{
    char text[MAX_CHARS];

    printf("Enter some text to store in the file: ");
    fgets(text, MAX_CHARS, stdin);

    FILE *fp = fopen(filename, "w");

    /* Write the input string to the file */
    fputs(text, fp);

    fclose(fp);

    printf("Text stored successfully!\n");
}

/* Define a function to retrieve text from a file and display it on the screen */
void display_text(char *filename)
{
    char text[MAX_CHARS];

    FILE *fp = fopen(filename, "r");

    /* Read the text from the file */
    fgets(text, MAX_CHARS, fp);

    fclose(fp);

    printf("\nText from file:\n%s", text);
}

int main(void)
{
    int choice;
    char filename[50];

    printf("Welcome to Text Processing Program!\n");

    printf("Enter a file name to create or access: ");
    fgets(filename, 50, stdin);

    /* Remove the newline character from the end of the filename */
    filename[strcspn(filename, "\n")] = '\0';

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Store text in file\n");
        printf("2. Display text from file\n");
        printf("3. Exit program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); /* Consume the newline character left by scanf() */

        switch (choice)
        {
            case 1:
                store_text(filename);
                break;
            
            case 2:
                display_text(filename);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}