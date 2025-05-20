//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
    // Define the Alien Language Dictionary
    char alienLanguage[5][10] = {"faw", "rek", "zew", "pax", "lup"};

    // Define the Human Language Dictionary
    char humanLanguage[5][10] = {"hello", "goodbye", "thank you", "please", "sorry"};

    // Get the input from user
    char input[20];
    printf("Enter a sentence in Alien Language (max 20 characters): ");
    scanf("%s", input);

    // Split the input into separate words
    char *words[10];
    int i = 0;
    words[i] = strtok(input, " ");
    while (words[i] != NULL) {
        i++;
        words[i] = strtok(NULL, " ");
    }

    // Translate each word in the input into Human Language
    char output[100] = "";
    for (int j = 0; j < i; j++) {
        // Search for the word in the Alien Language Dictionary
        int k;
        for (k = 0; k < 5; k++) {
            if (strcmp(words[j], alienLanguage[k]) == 0) {
                break;
            }
        }
        // If the word is found, add the translated word into the output string
        if (k < 5) {
            strcat(output, humanLanguage[k]);
            strcat(output, " ");
        }
        // If the word is not found, add the original word into the output string
        else {
            strcat(output, words[j]);
            strcat(output, " ");
        }
    }

    // Print the output
    printf("Translation into Human Language: %s", output);

    return 0;
}