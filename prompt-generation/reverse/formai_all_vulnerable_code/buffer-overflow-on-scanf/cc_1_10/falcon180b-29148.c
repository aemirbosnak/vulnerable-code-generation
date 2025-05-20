//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

// Function to count words in a string
int countWords(char *str)
{
    int count = 0;
    char *word = strtok(str, " \t\r\n\f\v,.?!;:");

    // Loop until all words are counted
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\r\n\f\v,.?!;:");
    }

    return count;
}

// Function to count characters in a string
int countChars(char *str)
{
    int count = 0;

    // Loop until the end of the string is reached
    while (*str!= '\0') {
        count++;
        str++;
    }

    return count;
}

// Function to count lines in a string
int countLines(char *str)
{
    int count = 0;
    char *line = strtok(str, "\n");

    // Loop until all lines are counted
    while (line!= NULL) {
        count++;
        line = strtok(NULL, "\n");
    }

    return count;
}

// Function to count sentences in a string
int countSentences(char *str)
{
    int count = 0;
    char *sentence = strtok(str, ".!? ");

    // Loop until all sentences are counted
    while (sentence!= NULL) {
        count++;
        sentence = strtok(NULL, ".!? ");
    }

    return count;
}

int main()
{
    char input[1000];
    int choice;

    printf("Welcome to the Word Count Tool!\n");
    printf("Please enter your text:\n");
    fgets(input, 1000, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    printf("What would you like to count?\n");
    printf("1. Words\n");
    printf("2. Characters\n");
    printf("3. Lines\n");
    printf("4. Sentences\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("The number of words is: %d\n", countWords(input));
            break;
        case 2:
            printf("The number of characters is: %d\n", countChars(input));
            break;
        case 3:
            printf("The number of lines is: %d\n", countLines(input));
            break;
        case 4:
            printf("The number of sentences is: %d\n", countSentences(input));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}