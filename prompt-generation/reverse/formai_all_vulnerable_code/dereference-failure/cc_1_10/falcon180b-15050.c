//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

int main() {
    char input_text[100000];
    char *token;
    char *word_buffer = malloc(MAX_WORD_LENGTH * sizeof(char));
    struct word *word_list = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;
    int i;

    // Initialize the English to Alien dictionary
    word_list[0].english = "hello";
    word_list[0].alien = "kltpzyxm";
    num_words = 1;

    // Read input text from user
    printf("Enter the text to translate:\n");
    fgets(input_text, sizeof(input_text), stdin);

    // Tokenize the input text
    token = strtok(input_text, " \t\n\r\f\v");
    while (token!= NULL) {
        // Look up the English word in the dictionary and print the Alien translation
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_list[i].english) == 0) {
                printf("%s ", word_list[i].alien);
                break;
            }
        }

        // If the word is not found in the dictionary, add it to the end
        if (i == num_words) {
            num_words++;
            word_list = realloc(word_list, num_words * sizeof(struct word));
            word_list[num_words - 1].english = strdup(token);
            strcpy(word_buffer, token);
            while (1) {
                int j;
                for (j = 0; j < strlen(word_buffer); j++) {
                    if (!isalpha(word_buffer[j])) {
                        word_buffer[j] = '\0';
                        break;
                    }
                }
                if (j == 0) {
                    break;
                }
                word_buffer[j] = '\0';
                word_list[num_words - 1].alien = strdup(word_buffer);
                strcpy(word_buffer, &word_buffer[j + 1]);
            }
        }

        token = strtok(NULL, " \t\n\r\f\v");
    }

    printf("\n");

    return 0;
}