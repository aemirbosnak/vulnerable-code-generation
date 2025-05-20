//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char* english;
    char* alien;
};

void load_words(struct word* words) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate_sentence(const char* sentence, struct word* words) {
    char* tokens[MAX_WORDS];
    int num_tokens = 0;

    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_tokens; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == num_tokens) {
            if (num_tokens >= MAX_WORDS) {
                printf("Too many words in sentence.\n");
                exit(1);
            }

            strcpy(words[num_tokens].english, token);
            strcpy(words[num_tokens].alien, "");
            num_tokens++;
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char sentence[MAX_WORD_LENGTH*MAX_WORDS+1];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);
    printf("\n");

    return 0;
}