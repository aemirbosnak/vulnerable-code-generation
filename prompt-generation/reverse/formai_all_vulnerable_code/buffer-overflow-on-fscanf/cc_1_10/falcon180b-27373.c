//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define WORD_LENGTH_MIN 4
#define WORD_LENGTH_MAX 10

char *words[MAX_WORDS];
int num_words;

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }
    char word[100];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) >= WORD_LENGTH_MIN && strlen(word) <= WORD_LENGTH_MAX) {
            words[num_words++] = strdup(word);
        }
    }
    fclose(fp);
}

int main() {
    load_words();
    srand(time(NULL));
    int index = rand() % num_words;
    char *word = words[index];
    printf("Type the following word: %s\n", word);
    fflush(stdout);
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    char c;
    while ((c = getchar())!= '\n') {
        if (isalpha(c)) {
            if (tolower(c) == tolower(word[total])) {
                correct++;
            } else {
                incorrect++;
            }
        }
        total++;
    }
    if (correct == strlen(word)) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }
    printf("You typed %d correct letters and %d incorrect letters.\n", correct, incorrect);
    return 0;
}