//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct word {
    char *word;
    int frequency;
};

int compare_frequency(const void *a, const void *b) {
    return (*(struct word *)b).frequency - (*(struct word *)a).frequency;
}

int main() {
    FILE *file;
    char text[1000000];
    char *word;
    struct word *words = NULL;
    int num_words = 0;
    int i;

    printf("Enter the name of the file to check: ");
    scanf("%s", text);

    file = fopen(text, "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while ((word = fgets(text, sizeof(text), file))!= NULL) {
        int length = strlen(word);
        int j;
        for (j = 0; j < length; j++) {
            if (isalpha(word[j])) {
                word[j] = tolower(word[j]);
            }
        }
        if (length > 2 && word[0] == 'a' && word[1] == 'n' && word[2] == 'd') {
            continue;
        }
        num_words++;
        words = realloc(words, sizeof(struct word) * num_words);
        words[num_words - 1].word = strdup(word);
        words[num_words - 1].frequency = 1;
    }

    for (i = 0; i < num_words; i++) {
        words[i].frequency++;
    }

    qsort(words, num_words, sizeof(struct word), compare_frequency);

    printf("The most frequently used words are:\n");
    for (i = 0; i < num_words; i++) {
        printf("%d. %s\n", words[i].frequency, words[i].word);
    }

    free(words);
    fclose(file);

    return 0;
}