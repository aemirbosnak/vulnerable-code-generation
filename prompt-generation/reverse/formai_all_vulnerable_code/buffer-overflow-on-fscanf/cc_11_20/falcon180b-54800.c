//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH + 1];
    int count;
};

int main() {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    struct word dictionary[MAX_WORDS];
    int num_words = 0;

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Warning: dictionary is full.\n");
            break;
        }

        dictionary[num_words].word[0] = toupper(word[0]);
        strcpy(&dictionary[num_words].word[1], word);
        dictionary[num_words].count = 0;
        num_words++;
    }

    fclose(file);

    char input_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, input)!= NULL) {
        int length = strlen(line);
        int i = 0;
        char word[MAX_WORD_LENGTH + 1];

        while (i < length) {
            if (isalpha(line[i])) {
                strcpy(word, &line[i]);
                i += strlen(word);
            } else {
                strcpy(word, "");
            }

            int found = 0;
            for (int j = 0; j < num_words; j++) {
                if (strcmp(word, &dictionary[j].word[1]) == 0 && isalpha(dictionary[j].word[0])) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Misspelled word: %s\n", word);
            }
        }
    }

    fclose(input);

    return 0;
}