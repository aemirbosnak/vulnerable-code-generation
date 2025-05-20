//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }
    num_words = 0;
    while (fscanf(file, "%s", words[num_words])!= EOF) {
        num_words++;
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    load_words();
    printf("Welcome to the typing speed test!\n");
    printf("You will be typing %d words.\n", num_words);
    printf("Press enter to begin...\n");
    getchar();
    int correct = 0;
    int incorrect = 0;
    int total_time = 0;
    for (int i = 0; i < num_words; i++) {
        int word_length = strlen(words[i]);
        printf("%s\n", words[i]);
        int start_time = clock();
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        int end_time = clock();
        int elapsed_time = end_time - start_time;
        total_time += elapsed_time;
        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        printf("You typed '%s' in %d milliseconds.\n", input, elapsed_time);
    }
    double wpm = (double)num_words / (total_time / 1000.0);
    printf("You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("Your typing speed is %.2f words per minute.\n", wpm);
    return 0;
}