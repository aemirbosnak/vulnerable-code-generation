//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char word[MAX_WORD_LENGTH];
    int i;
    int word_length;
    char dictionary[MAX_WORD_LENGTH][MAX_WORD_LENGTH];

    // Build the dictionary
    dictionary[0][0] = 'a';
    dictionary[0][1] = 'b';
    dictionary[0][2] = 'c';
    dictionary[0][3] = 'd';
    dictionary[0][4] = 'e';
    dictionary[0][5] = 'f';
    dictionary[0][6] = 'g';
    dictionary[0][7] = 'h';
    dictionary[0][8] = 'i';
    dictionary[0][9] = 'j';
    dictionary[0][10] = 'k';
    dictionary[0][11] = 'l';
    dictionary[0][12] = 'm';
    dictionary[0][13] = 'n';
    dictionary[0][14] = 'o';
    dictionary[0][15] = 'p';
    dictionary[0][16] = 'q';
    dictionary[0][17] = 'r';
    dictionary[0][18] = 's';
    dictionary[0][19] = 't';
    dictionary[1][0] = 'u';
    dictionary[1][1] = 'v';
    dictionary[1][2] = 'w';
    dictionary[1][3] = 'x';
    dictionary[1][4] = 'y';
    dictionary[1][5] = 'z';

    // Get the word to check
    printf("Enter a word: ");
    scanf("%s", word);

    // Calculate the word length
    word_length = strlen(word);

    // Check if the word is in the dictionary
    for (i = 0; i < word_length; i++)
    {
        char letter = word[i];

        // Convert the letter to lowercase
        letter = tolower(letter);

        // Check if the letter is in the dictionary
        if (dictionary[0][letter - 'a'] == letter)
        {
            // The letter is in the dictionary
            printf("The word %s is in the dictionary.\n", word);
            break;
        }
    }

    // The word is not in the dictionary
    printf("The word %s is not in the dictionary.\n", word);

    return 0;
}