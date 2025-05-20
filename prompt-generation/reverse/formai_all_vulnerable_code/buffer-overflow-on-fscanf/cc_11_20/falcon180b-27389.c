//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
    int max_words = 10, max_time = 60, score = 0, correct_words = 0, incorrect_words = 0, i, j, k, len, time_left;
    char words[max_words][20], input[50], *p;
    FILE *fp;
    clock_t start, end;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(0);
    }

    for (i = 0; i < max_words; i++) {
        fscanf(fp, "%s", words[i]);
    }
    fclose(fp);

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", max_time);
    printf("Press 'Enter' to begin.\n");

    scanf("%c", &input[0]);

    start = clock();
    time_left = max_time;

    while (time_left > 0) {
        printf("Type the following word: %s\n", words[score]);
        fflush(stdout);
        scanf("%s", input);

        len = strlen(input);
        for (j = 0; j < len; j++) {
            if (!isalpha(input[j])) {
                input[j] = '\0';
            }
        }

        p = words[score];
        for (k = 0; k < strlen(p); k++) {
            if (tolower(p[k])!= tolower(input[k])) {
                incorrect_words++;
            }
        }

        if (strlen(input) == strlen(words[score]) &&!strcmp(input, words[score])) {
            correct_words++;
        }

        score++;
        if (score == max_words) {
            score = 0;
        }

        time_left--;
    }

    end = clock();

    printf("\nTest completed!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your typing speed is %d WPM.\n", (int)(((double)correct_words / (double)max_words) * 60.0 / (double)(end - start)));

    return 0;
}