//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

struct word {
    char *english;
    char *cat;
};

int load_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        return 1;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

int translate_sentence(struct word *words, char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < strlen(token); i++) {
            if (isalpha(token[i])) {
                token[i] = tolower(token[i]);
            }
        }

        struct word *word = words;
        while (word->english!= NULL) {
            if (strcmp(token, word->english) == 0) {
                printf("%s ", word->cat);
                break;
            }
            word++;
        }

        if (word->english == NULL) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}

int main() {
    struct word words[MAX_WORDS];
    if (load_words(words)!= 0) {
        return 1;
    }

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(words, sentence);

    return 0;
}