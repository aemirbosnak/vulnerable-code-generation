//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;
    int length = 0;
    char command = '\0';

    printf("Welcome to the C Digital Diary!\n");

    while (command != 'q')
    {
        printf("Enter a command (add, edit, read, quit): ");
        scanf("%c", &command);

        switch (command)
        {
            case 'a':
                printf("Enter the text you want to add: ");
                fgets(buffer, MAX_BUFFER_SIZE, stdin);
                length = strlen(buffer);
                buffer[length - 1] = '\0';
                printf("Text added: %s\n", buffer);
                break;

            case 'e':
                printf("Enter the text you want to edit: ");
                fgets(buffer, MAX_BUFFER_SIZE, stdin);
                length = strlen(buffer);
                buffer[length - 1] = '\0';
                printf("Text edited: %s\n", buffer);
                break;

            case 'r':
                printf("Enter the text you want to read: ");
                fgets(buffer, MAX_BUFFER_SIZE, stdin);
                length = strlen(buffer);
                buffer[length - 1] = '\0';
                printf("Text read: %s\n", buffer);
                break;

            case 'q':
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}