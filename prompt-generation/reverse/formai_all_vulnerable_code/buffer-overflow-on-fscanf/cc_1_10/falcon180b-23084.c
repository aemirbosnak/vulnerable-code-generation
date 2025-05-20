//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *alien;
} word_t;

int load_words(word_t words[]) {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        return -1;
    }

    int count = 0;
    while (fscanf(fp, "%s %s", words[count].english, words[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            fclose(fp);
            return -1;
        }
    }

    fclose(fp);
    return count;
}

int translate_sentence(char *sentence, word_t words[], int num_words) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}

int main() {
    word_t words[MAX_WORDS];
    int num_words = load_words(words);

    if (num_words <= 0) {
        return -1;
    }

    char sentence[1024];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words, num_words);

    return 0;
}