//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct word {
    char *english;
    char *cat;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;

    // Load dictionary
    FILE *dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error loading dictionary\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), dict)!= NULL) {
        char *token = strtok(line, ",");
        if (num_words >= MAX_WORDS) {
            printf("Dictionary too large\n");
            return 2;
        }
        words[num_words].english = strdup(token);
        token = strtok(NULL, ",");
        words[num_words].cat = strdup(token);
        num_words++;
    }
    fclose(dict);

    // Translate sentences
    char sentence[1024];
    while (fgets(sentence, sizeof(sentence), stdin)!= NULL) {
        char *token = strtok(sentence, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].english) == 0) {
                    printf("%s ", words[i].cat);
                    break;
                }
            }
            if (i == num_words) {
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}