//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int num_words = 0;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        words[num_words++] = strdup(word);
    }
    fclose(file);
}

int main() {
    load_words();
    printf("Enter a sentence: ");
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    int i, j;
    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            char word[MAX_WORD_LENGTH];
            int word_length = 0;
            while (isalpha(sentence[i]) && word_length < MAX_WORD_LENGTH) {
                word[word_length++] = tolower(sentence[i]);
                i++;
            }
            word[word_length] = '\0';
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, words[j]) == 0) {
                    printf("Alien: %s\n", word);
                    break;
                }
            }
        } else {
            printf("%c", sentence[i]);
        }
    }
    return 0;
}