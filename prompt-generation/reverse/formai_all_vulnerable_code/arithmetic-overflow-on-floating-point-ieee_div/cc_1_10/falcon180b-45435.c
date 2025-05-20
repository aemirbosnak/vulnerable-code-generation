//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 10
#define MAX_TIME 60

typedef struct {
    char word[MAX_LENGTH];
    int length;
} Word;

void loadWords(Word words[], int count) {
    FILE *file;
    char line[MAX_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, file)!= NULL && i < count) {
        strcpy(words[i].word, line);
        words[i].length = strlen(words[i].word);
        i++;
    }

    fclose(file);
}

int main() {
    Word words[MAX_WORDS];
    int count;
    int score = 0;
    int incorrect = 0;
    int time = MAX_TIME;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the number of words you want to type (between 1 and %d): ", MAX_WORDS);
    scanf("%d", &count);

    loadWords(words, count);

    printf("You will have %d seconds to type as many words as you can.\n", time);
    printf("Press ENTER to start.\n");
    getchar();

    clock_t start = clock();

    while (time > 0 && count > 0) {
        printf("%s", words[count - 1].word);
        char input[MAX_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[count - 1].word) == 0) {
            score++;
        } else {
            incorrect++;
        }

        time--;
        count--;
    }

    clock_t end = clock();

    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime's up! You typed %d words correctly and %d words incorrectly.\n", score, incorrect);
    printf("Your score is %d points and your typing speed is %d WPM.\n", score, (int)(60.0 / elapsed));

    return 0;
}