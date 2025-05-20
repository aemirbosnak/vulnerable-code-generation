//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH]; // array to store words
int num_words; // number of words in array

void load_words(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }

        int len = strlen(line);
        if (len > MAX_WORD_LENGTH) {
            printf("Error: word \"%s\" is too long\n", line);
            exit(1);
        }

        strcpy(words[num_words], line);
        num_words++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    load_words(filename);

    int score = 0;
    int time = 60;

    printf("Press enter to start\n");
    getchar();

    while (time > 0) {
        char word[MAX_WORD_LENGTH];
        int len = rand() % num_words;
        strcpy(word, words[len]);

        printf("%s\n", word);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(word, input) == 0) {
            score++;
        }

        time--;
    }

    printf("Your score is %d\n", score);

    return 0;
}