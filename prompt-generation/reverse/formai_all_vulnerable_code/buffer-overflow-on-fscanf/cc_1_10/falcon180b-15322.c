//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} word_t;

int load_words(word_t words[]) {
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

int translate_sentence(char sentence[], word_t words[]) {
    int length = strlen(sentence);
    char *tokens[length];
    int num_tokens = 0;

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < num_tokens; i++) {
        char *english_word = tokens[i];
        int english_length = strlen(english_word);

        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcasecmp(english_word, words[j].english) == 0 && english_length == strlen(words[j].english)) {
                printf("%s ", words[j].cat);
                break;
            }
        }
    }

    printf("\n");
    return 0;
}

int main() {
    word_t words[MAX_WORDS];

    if (load_words(words)!= 0) {
        return 1;
    }

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}