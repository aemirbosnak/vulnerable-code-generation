//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_COUNT 10
#define LINES_COUNT 5
#define BUFFER_SIZE 80

void print_words(char **words) {
    for (int i = 0; i < WORDS_COUNT; i++) {
        printf("%s ", words[i]);
        fflush(stdout);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char *words[WORDS_COUNT];
    FILE *words_file = fopen("words.txt", "r");

    for (int i = 0; i < WORDS_COUNT; i++) {
        char word[BUFFER_SIZE];
        fscanf(words_file, "%s", word);
        words[i] = malloc(strlen(word) + 1);
        strcpy(words[i], word);
    }
    fclose(words_file);

    int lines[LINES_COUNT];
    for (int i = 0; i < LINES_COUNT; i++) {
        lines[i] = rand() % (WORDS_COUNT / 2) + 1;
    }

    clock_t start = clock();
    for (int line = 0; line < LINES_COUNT; line++) {
        print_words(words);
        for (int i = 0; i < lines[line]; i++) {
            int index = rand() % WORDS_COUNT;
            char c = getchar();
            if (getchar() != words[index][0]) {
                printf("Error: Incorrect character at line %d, word %s\n", line + 1, words[index]);
                break;
            }
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %fs\n", time_spent);

    for (int i = 0; i < WORDS_COUNT; i++) {
        free(words[i]);
    }

    return 0;
}