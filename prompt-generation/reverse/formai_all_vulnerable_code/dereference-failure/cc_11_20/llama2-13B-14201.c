//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_WORD "magic"

void spell_checker(char* word) {
    int i, j, k, l;
    char c, previous_c;
    int num_mistakes = 0;

    // Step 1: Check for capitalization mistakes
    for (i = 0; word[i] != '\0'; i++) {
        c = word[i];
        if (c >= 'A' && c <= 'Z') {
            if (word[i - 1] >= 'a' && word[i - 1] <= 'z') {
                num_mistakes++;
            }
        } else if (c >= 'a' && c <= 'z') {
            if (word[i - 1] >= 'A' && word[i - 1] <= 'Z') {
                num_mistakes++;
            }
        }
    }

    // Step 2: Check for repeated letters
    for (i = 0; word[i] != '\0'; i++) {
        c = word[i];
        previous_c = word[i - 1];
        if (c == previous_c) {
            num_mistakes++;
        }
    }

    // Step 3: Check for letter permutations
    for (i = 0; word[i] != '\0'; i++) {
        c = word[i];
        for (j = i + 1; j < strlen(word); j++) {
            if (word[j] == c) {
                num_mistakes++;
                break;
            }
        }
    }

    // Step 4: Check for vowel placement
    for (i = 0; word[i] != '\0'; i++) {
        c = word[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            if (word[i - 1] == 'y' && word[i + 1] == 'a') {
                num_mistakes++;
            }
        }
    }

    // Step 5: Check for special cases
    if (word[0] == 'i' && word[1] == 'n' && word[2] == 't') {
        num_mistakes++;
    }

    // Step 6: Print the results
    if (num_mistakes > 0) {
        printf("Spell check results:\n");
        printf("  * Found %d mistakes.\n", num_mistakes);
        printf("  * Mistakes include: ");
        for (i = 0; i < num_mistakes; i++) {
            printf(" %c", word[i]);
        }
        printf("\n");
    } else {
        printf("Congratulations! Your word is spelled correctly.\n");
    }
}

int main() {
    char word[100];
    int num_tries;

    // Get the word from the user
    printf("Enter a word to spell check: ");
    fgets(word, 100, stdin);

    // Limit the number of tries to 5
    num_tries = 5;

    // Loop until the word is spelled correctly or all tries are used up
    while (num_tries > 0) {
        spell_checker(word);
        num_tries--;
    }

    return 0;
}