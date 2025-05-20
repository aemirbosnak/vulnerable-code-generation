//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word_t {
    char *english;
    char *alien;
};

int main() {
    FILE *dict_file;
    char line[MAX_WORD_LEN];
    char *word;
    struct word_t *dict = calloc(MAX_WORDS, sizeof(struct word_t));

    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(dict_file, "%s", line)!= EOF) {
        word = strdup(line);
        dict[num_words].english = word;
        dict[num_words].alien = "";
        num_words++;
    }

    fclose(dict_file);

    char input[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LEN, stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(dict[i].english, token) == 0) {
                printf("%s ", dict[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}