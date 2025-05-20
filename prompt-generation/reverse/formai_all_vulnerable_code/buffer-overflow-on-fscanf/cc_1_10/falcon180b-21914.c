//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *cat;
} Word;

void load_words(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char input[1000];
    while (fgets(input, 1000, stdin)!= NULL) {
        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].cat);
                    break;
                }
            }

            if (i == MAX_WORDS) {
                printf("meow ");
            }

            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}