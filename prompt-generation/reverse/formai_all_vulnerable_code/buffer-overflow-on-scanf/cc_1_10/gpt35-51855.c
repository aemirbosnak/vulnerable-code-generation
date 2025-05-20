//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printHeader()
{
    printf("\n\n             C WORD FREQUENCY COUNTER\n");
    printf("             --- ------- --------\n");
    printf("Welcome to the most trippy word frequency counter you'll ever see!\n");
}

void printFooter()
{
    printf("Thanks for using the C Word Frequency Counter.\nHappy coding!\n\n");
}

int countWord(char* word, char* text)
{
    int count = 0;
    char *ptr = text;
    while ((ptr = strstr(ptr, word)) != NULL)
    {
        // Check if the word is complete or just a substring of a bigger word
        if ((ptr == text || !isalpha(*(ptr - 1))) && !isalpha(*(ptr + strlen(word))))
        {
            count++;
            ptr += strlen(word);
        }
        else
        {
            ptr++;
        }
    }
    return count;
}

void printFrequency(char* word, char* text)
{
    int frequency = countWord(word, text);
    printf("\n%s occurs %d times in the text.\n", word, frequency);
}

void printAllFrequencies(char* text)
{
    const char *const delimiters = " \t\n,.?!-";

    // Create a copy of the input text that can be modified
    char* copy = malloc(strlen(text) + 1);
    strcpy(copy, text);

    // Convert all characters to uppercase for case-insensitivity
    for (int i = 0; i < strlen(copy); i++)
    {
        copy[i] = toupper(copy[i]);
    }

    // Tokenize the text into individual words
    char* word = strtok(copy, delimiters);
    while (word != NULL)
    {
        // Calculate and print the frequency of the current word
        printFrequency(word, text);

        // Advance to the next word
        word = strtok(NULL, delimiters);
    }

    free(copy);
}

void printMenu()
{
    printf("\nWhat do you want to do?\n");
    printf("1. Enter some text\n");
    printf("2. Exit\n");
    printf("\nEnter your choice: ");
}

void getText(char* buffer, int size)
{
    printf("\nEnter some text:\n");
    fflush(stdin); // clear input buffer
    fgets(buffer, size, stdin);

    // Remove trailing newline character
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }
}

int main()
{
    char choice;
    char text[1000];

    printHeader();

    do
    {
        printMenu();
        scanf("%c", &choice);

        switch (choice)
        {
            case '1':
                getText(text, sizeof(text));
                printAllFrequencies(text);
                break;
            case '2':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != '2');

    printFooter();

    return 0;
}