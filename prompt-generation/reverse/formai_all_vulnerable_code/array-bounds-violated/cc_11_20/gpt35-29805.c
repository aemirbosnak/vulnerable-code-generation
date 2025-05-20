//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char word[20];

    printf("Welcome to the happiest spell checker in town!\n");
    printf("Please enter a word to check its spelling: \n");

    while (scanf("%s", word) == 1) {
        int len = strlen(word);

        // check for punctuation at end of word
        if (word[len-1] == ',' || word[len-1] == '.' || word[len-1] == '?' || word[len-1] == '!') {
            word[len-1] = '\0';
            len--;
        }

        // check for numbers in word
        int has_number = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] >= '0' && word[i] <= '9') {
                has_number = 1;
                break;
            }
        }

        // spell checking algorithm
        int has_error = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] < 'a' || word[i] > 'z') {
                printf("%s is not a valid word!\n\n", word);
                has_error = 1;
                break;
            }
        }

        if (!has_error) {
            if (has_number) {
                printf("There cannot be numbers in a word!\n\n");
            } else if (strcmp(word, "hello") == 0 || strcmp(word, "world") == 0) {
                printf("%s is spelled correctly! This is a cheerful word!\n\n", word);
            } else {
                printf("%s is not spelled correctly. Cheer up, though!\n\n", word);
            }
        }

        // prompt user for another word or quit
        printf("Enter another word or type 'quit' to exit: \n");
        if (strcmp(word, "quit") == 0) {
            break;
        }
    }

    printf("Thanks for using the happiest spell checker in town!\n");

    return 0;
}