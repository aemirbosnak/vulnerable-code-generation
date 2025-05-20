//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    char input[MAX_WORD_LENGTH];
    char corrected_input[MAX_WORD_LENGTH];
    char* word;
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    int i, j;

    // Load dictionary
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error loading dictionary.\n");
        return 1;
    }

    while (fscanf(dictionary_file, "%s", input)!= EOF) {
        dictionary[num_words].word[0] = tolower(input[0]);
        strcpy(dictionary[num_words].word + 1, input + 1);
        dictionary[num_words].count = 1;
        num_words++;
    }

    fclose(dictionary_file);

    // Spell check user input
    printf("Enter text to spell check:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    i = 0;
    while (i < strlen(input)) {
        if (isspace(input[i])) {
            word = strtok(input, " ");

            if (word!= NULL) {
                if (strlen(word) > MAX_WORD_LENGTH) {
                    printf("Error: Word \"%s\" is too long.\n", word);
                } else {
                    for (j = 0; j < num_words; j++) {
                        if (strcmp(word, dictionary[j].word) == 0) {
                            dictionary[j].count++;
                            break;
                        }
                    }

                    if (j == num_words) {
                        strcpy(dictionary[num_words].word, word);
                        dictionary[num_words].count = 1;
                        num_words++;
                    }
                }
            }

            i = strlen(input);
            corrected_input[i] = '\0';
        } else {
            corrected_input[i] = input[i];
            i++;
        }
    }

    // Output spell check results
    printf("Spell check complete.\n");
    printf("Number of words checked: %d\n", num_words);

    for (i = 0; i < num_words; i++) {
        if (dictionary[i].count > 1) {
            printf("Word \"%s\" appears %d times.\n", dictionary[i].word, dictionary[i].count);
        }
    }

    return 0;
}