//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate_sentence(char *sentence, struct word words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORD_LENGTH; i++) {
            if (strcasecmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == MAX_WORD_LENGTH) {
            printf("unknown ");
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}