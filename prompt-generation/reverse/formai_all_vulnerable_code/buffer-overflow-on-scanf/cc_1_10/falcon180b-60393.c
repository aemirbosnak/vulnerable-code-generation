//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int word_lengths[MAX_WORDS];
int num_words;

void load_words(char *filename) {
    FILE *file;
    char line[MAX_WORD_LENGTH + 1];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        words[i] = strdup(line);
        word_lengths[i] = strlen(line);
        i++;
    }

    num_words = i;
    fclose(file);
}

void generate_typing_test() {
    int i, j;
    char *word;
    int word_length;
    char sentence[MAX_WORD_LENGTH + 1];

    for (i = 0; i < num_words; i++) {
        word = words[i];
        word_length = word_lengths[i];

        for (j = 0; j < word_length; j++) {
            sentence[j] = word[j];
        }

        sentence[word_length] = '\0';

        printf("%s ", sentence);
    }
}

int main() {
    char *filename;
    int i;

    printf("Enter the name of the file containing words:\n");
    scanf("%s", filename);

    load_words(filename);

    printf("Press enter to start the typing test:\n");
    getchar();

    clock_t start_time, end_time;
    double elapsed_time;

    start_time = clock();
    generate_typing_test();
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nYou typed %d words in %.2f seconds.\n", num_words, elapsed_time);

    return 0;
}