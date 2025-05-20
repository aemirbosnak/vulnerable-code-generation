//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100

int main()
{
    char input_word[MAX_WORD_LENGTH], output_word[MAX_WORD_LENGTH];
    int cipher[MAX_ALPHABET_SIZE];
    int i;

    // Set up the cipher for the Alien language
    cipher[0] = 4;
    cipher[1] = 5;
    cipher[2] = 3;
    cipher[3] = 6;
    cipher[4] = 2;
    cipher[5] = 7;
    cipher[6] = 1;
    cipher[7] = 8;
    cipher[8] = 0;
    cipher[9] = 9;
    cipher[10] = 12;
    cipher[11] = 13;
    cipher[12] = 10;
    cipher[13] = 11;
    cipher[14] = 16;
    cipher[15] = 17;
    cipher[16] = 14;
    cipher[17] = 15;
    cipher[18] = 20;
    cipher[19] = 21;
    cipher[20] = 18;
    cipher[21] = 19;
    cipher[22] = 24;
    cipher[23] = 25;
    cipher[24] = 22;
    cipher[25] = 23;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a word to translate: ");
    scanf("%s", input_word);

    // Apply the cipher to each letter of the input word
    for (i = 0; i < strlen(input_word); i++) {
        if (input_word[i] >= 'a' && input_word[i] <= 'z') {
            // Convert lowercase letter to corresponding Alien language letter
            output_word[i] = cipher[input_word[i] - 'a'] + 'a';
        } else if (input_word[i] >= 'A' && input_word[i] <= 'Z') {
            // Convert uppercase letter to corresponding Alien language letter
            output_word[i] = cipher[input_word[i] - 'A'] + 'A';
        } else {
            // Keep non-letter characters the same
            output_word[i] = input_word[i];
        }
    }
    output_word[i] = '\0';

    printf("Translation: %s\n", output_word);

    return 0;
}