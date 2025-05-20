//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2 && count < MAX_WORDS) {
        count++;
    }

    fclose(file);
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to translate: ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(input, words[i].english) == 0) {
                printf("The cat translation is: %s\n", words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Sorry, I don't know that word in cat.\n");
        }
    }

    return 0;
}