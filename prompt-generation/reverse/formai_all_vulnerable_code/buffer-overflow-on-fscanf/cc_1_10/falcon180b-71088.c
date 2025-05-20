//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void generate_conspiracy_theory(char *theory, int length) {
    srand(time(NULL));
    char *words[MAX_WORDS];
    int num_words = 0;
    int i;

    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            break;
        }
        words[num_words++] = strdup(word);
    }
    fclose(file);

    for (i = 0; i < length; i++) {
        int word_index = rand() % num_words;
        strcat(theory, words[word_index]);
        if (i < length - 1) {
            strcat(theory, " ");
        }
    }
    theory[length - 1] = '\0';
}

int main() {
    int length;
    printf("Enter the length of the conspiracy theory: ");
    scanf("%d", &length);

    char theory[MAX_CONSPIRACY_LENGTH];
    generate_conspiracy_theory(theory, length);

    printf("Your conspiracy theory is: %s\n", theory);

    return 0;
}