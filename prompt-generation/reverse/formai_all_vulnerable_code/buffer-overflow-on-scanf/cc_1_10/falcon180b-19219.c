//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    char text[10000];
    int length;
    FILE *file;
    Word words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the filename: ");
    scanf("%s", text);

    file = fopen(text, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while ((length = fread(text, sizeof(char), 10000, file)) > 0) {
        for (int i = 0; i < length; i++) {
            char c = tolower(text[i]);
            if (isalpha(c)) {
                int found = 0;
                for (int j = 0; j < num_words; j++) {
                    if (strcmp(words[j].word, &text[i]) == 0) {
                        words[j].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strncpy(words[num_words].word, &text[i], MAX_WORD_LENGTH);
                    words[num_words].word[MAX_WORD_LENGTH - 1] = '\0';
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    fclose(file);

    printf("Total words: %d\n", num_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}