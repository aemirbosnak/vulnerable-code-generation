//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 10

struct word {
    char word[WORD_LENGTH];
    int count;
};

int main() {
    FILE *file;
    char line[100];
    char word[WORD_LENGTH];
    struct word dictionary[MAX_WORDS];
    int count = 0;
    int i;

    // Load dictionary
    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: Dictionary file not found.\n");
        return 1;
    }
    while (fscanf(file, "%s", word)!= EOF) {
        dictionary[count].word[0] = toupper(word[0]);
        strcpy(&dictionary[count].word[1], &word[1]);
        dictionary[count].count = 0;
        count++;
    }
    fclose(file);

    // Load document
    file = fopen("document.txt", "r");
    if (file == NULL) {
        printf("Error: Document file not found.\n");
        return 1;
    }

    // Spell check
    while (fgets(line, 100, file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int word_length = strlen(token);
            if (word_length > 0 && word_length <= WORD_LENGTH) {
                strcpy(word, token);
                for (i = 0; i < word_length; i++) {
                    if (!isalpha(word[i])) {
                        word[i] = '\0';
                        word_length = i;
                        break;
                    }
                }
                word[word_length] = '\0';
                int index = 0;
                while (index < count && strcmp(dictionary[index].word, word)!= 0) {
                    index++;
                }
                if (index == count) {
                    printf("Misspelled word: %s\n", token);
                } else {
                    dictionary[index].count++;
                }
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    // Print results
    printf("\nSpell check completed.\n");
    printf("Total words checked: %d\n", count);
    for (i = 0; i < count; i++) {
        if (dictionary[i].count > 0) {
            printf("Word: %s\n", dictionary[i].word);
            printf("Occurrences: %d\n", dictionary[i].count);
        }
    }

    return 0;
}