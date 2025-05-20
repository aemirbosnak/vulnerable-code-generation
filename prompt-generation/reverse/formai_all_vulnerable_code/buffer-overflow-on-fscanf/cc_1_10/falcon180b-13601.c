//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char english[100];
    char cat[100];
} word_t;

void load_words(word_t words[])
{
    FILE *file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

int main()
{
    word_t words[MAX_WORDS];
    load_words(words);

    char input[100];
    while (1) {
        printf("Enter a sentence: ");
        fgets(input, sizeof(input), stdin);

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
                printf("%s ", token);
            }

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    return 0;
}