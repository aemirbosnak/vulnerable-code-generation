//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_LENGTH 50
#define ALPHABET_SIZE 26

int main() {
    int i, j, k;
    int word_count = 0;
    int word_length[MAX_WORDS];
    char words[MAX_WORDS][MAX_LENGTH];
    int dict_size = 0;
    char dict[MAX_WORDS][MAX_LENGTH];

    // Read dictionary from file
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(dict_file, "%s", dict[dict_size]) != EOF) {
        word_length[dict_size] = strlen(dict[dict_size]);
        dict_size++;
    }

    fclose(dict_file);

    // Get input from user
    char input[100];
    printf("Enter a word to check: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    // Check input against dictionary
    int found = 0;
    for (i = 0; i < dict_size; i++) {
        int match = 1;
        int diff = 0;

        for (j = 0; j < word_length[i] && j < strlen(input); j++) {
            if (tolower(input[j]) != tolower(dict[i][j])) {
                diff++;
                if (diff > 1) {
                    match = 0;
                    break;
                }
            }
        }

        if (match && strlen(input) == word_length[i]) {
            printf("The word '%s' is spelled correctly.\n", input);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("The word '%s' is not in the dictionary.\n", input);
    }

    return 0;
}