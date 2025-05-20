//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    int is_valid;
} Word;

Word dictionary[MAX_WORDS];

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    int i = 0;

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file!\n");
        exit(1);
    }

    while (fscanf(file, "%s", dictionary[i].str) != EOF) {
        i++;
    }

    fclose(file);

    for (int j = 0; j < i; j++) {
        strcpy(dictionary[j].str, tolower(dictionary[j].str));
        dictionary[j].is_valid = 1;
    }
}

int main() {
    char input[1024];
    int num_words, num_misspelled;

    load_dictionary("dictionary.txt");

    printf("Welcome to FutureSpell!\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("Enter a word: ");
        fgets(input, sizeof(input), stdin);
        num_words = sscanf(input, "%s", input);

        if (strchr(input, '\n') != NULL) {
            input[strcspn(input, "\n")] = '\0';
        }

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int index = 0;
        int found = 0;

        for (int i = 0; i < MAX_WORDS; i++) {
            if (dictionary[i].is_valid == 0) {
                continue;
            }

            int len = strlen(dictionary[i].str);
            int lev = 0;

            if (len > WORD_LENGTH - 1) {
                continue;
            }

            for (int j = 0; j < len && j < strlen(input); j++) {
                if (tolower(dictionary[i].str[j]) != tolower(input[j])) {
                    lev++;
                    if (lev > 2) {
                        index = i;
                        found = 1;
                        break;
                    }
                }
            }

            if (found) {
                break;
            }

            if (len == strlen(input) && strcmp(dictionary[i].str, input) == 0) {
                printf("Correct: %s\n", dictionary[i].str);
                continue;
            }
        }

        if (!found) {
            num_misspelled++;
            printf("Misspelled: %s\n", input);
        }

        printf("Press Enter to continue...\n");
        getchar();
        system("clear"); // or cls on Windows
    }

    printf("Total words checked: %d\n", num_words);
    printf("Total misspelled words: %d\n", num_misspelled);

    return 0;
}