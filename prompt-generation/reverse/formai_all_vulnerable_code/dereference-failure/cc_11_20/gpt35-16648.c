//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the energetic C Text processing program!\n");
    printf("Enter the text you want to process:\n");

    char *input_string = (char *) malloc(1000 * sizeof(char));
    fgets(input_string, 1000, stdin);

    // Counting the number of characters in the text
    int char_count = strlen(input_string) - 1; // Excluding '\n' character
    printf("Number of characters in the text: %d\n", char_count);

    // Converting the text to uppercase
    printf("Uppercase version of the text: ");
    for (int i = 0; i < char_count; i++)
    {
        printf("%c", toupper(input_string[i]));
    }
    printf("\n");

    // Reversing the text
    printf("Reversed version of the text: ");
    for (int i = char_count - 1; i >= 0; i--)
    {
        printf("%c", input_string[i]);
    }
    printf("\n");

    // Counting the number of words in the text
    char *word = strtok(input_string, " \n"); // Tokenizing the first word
    int word_count = 0;
    while (word != NULL)
    {
        word_count++;
        word = strtok(NULL, " \n"); // Tokenizing the next word
    }
    printf("Number of words in the text: %d\n", word_count);

    // Counting the number of vowels in the text
    int vowel_count = 0;
    for (int i = 0; i < char_count; i++)
    {
        char c = input_string[i];
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' || c == 'u' || c == 'U')
        {
            vowel_count++;
        }
    }
    printf("Number of vowels in the text: %d\n", vowel_count);

    // Freeing allocated memory
    free(input_string);

    printf("Thanks for using the energetic C Text processing program!\n");

    return 0;
}