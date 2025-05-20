//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

struct word {
    char *english;
    char *alien;
};

void load_words(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count == MAX_WORDS) {
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    struct word words[MAX_WORDS];
    load_words(words);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    output[0] = '\0';

    int i = 0;
    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            int j;
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(words[j].english, input + i) == 0) {
                    strcat(output, words[j].alien);
                    i += strlen(words[j].english) - 1;
                    break;
                }
            }
        } else {
            strcat(output, &input[i]);
        }
        i++;
    }

    printf("Translated sentence: %s\n", output);

    return 0;
}