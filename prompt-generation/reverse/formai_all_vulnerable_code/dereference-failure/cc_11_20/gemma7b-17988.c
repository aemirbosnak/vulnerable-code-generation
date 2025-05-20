//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100] = "The future is bright, and the book is the key to unlocking it.";
    int i = 0;

    // Futuristic ebook reader interface
    printf("Welcome to the Galactic Book Nook, where the future of reading unfolds.\n");
    printf("Please select a reading mode:\n");
    printf("1. Linear Text\n");
    printf("2. Text Highlights\n");
    printf("3. Voice Reading\n");

    // Get the user's choice
    int choice = atoi(stdin);

    switch (choice)
    {
        case 1:
            // Display the text line by line
            for (i = 0; str[i] != '\0'; i++)
            {
                printf("%c", str[i]);
                if (str[i] == ' ')
                {
                    printf("\n");
                }
            }
            break;

        case 2:
            // Highlight the text with different colors
            for (i = 0; str[i] != '\0'; i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    printf("\033[1;31m%c\033[0m", str[i]);
                }
                else if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    printf("\033[1;33m%c\033[0m", str[i]);
                }
                else
                {
                    printf("%c", str[i]);
                }
            }
            break;

        case 3:
            // Read the text aloud
            printf("Please wait while I read the book to you...\n");
            system("espeak -v female -r 1.5 \"The future is bright, and the book is the key to unlocking it.\"");
            break;
    }

    return 0;
}