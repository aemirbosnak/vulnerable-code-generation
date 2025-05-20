//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

int main() {
    FILE *dictionary;
    Word words[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    printf("Enter the name of the dictionary file: ");
    scanf("%s", filename);
    dictionary = fopen(filename, "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }
    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in dictionary.\n");
            return 1;
        }
        line[strcspn(line, "\n")] = '\0';
        words[num_words].word[0] = toupper(line[0]);
        strncpy(words[num_words].word + 1, line + 1, MAX_WORD_LENGTH - 1);
        words[num_words].is_correct = true;
        num_words++;
    }
    fclose(dictionary);
    printf("Enter the text to spell check: ");
    char text[MAX_WORD_LENGTH];
    fgets(text, MAX_WORD_LENGTH, stdin);
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < num_words; j++) {
                if (text[i] == toupper(words[j].word[0])) {
                    int k;
                    for (k = 1; k < strlen(words[j].word); k++) {
                        if (text[i + k]!= words[j].word[k]) {
                            break;
                        }
                    }
                    if (k == strlen(words[j].word)) {
                        printf("%s is correct.\n", words[j].word);
                    } else {
                        printf("%s is incorrect.\n", words[j].word);
                    }
                }
            }
        }
    }
    return 0;
}