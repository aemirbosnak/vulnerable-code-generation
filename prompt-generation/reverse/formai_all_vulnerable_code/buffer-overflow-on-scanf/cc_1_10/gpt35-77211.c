//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char words[5][10] = {"apple", "banana", "orange", "grape", "kiwi"};
    srand(time(NULL));
    int i, j;
    char str[50], ch;
    double correct, incorrect, total_time, typing_speed;
    time_t start, end;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following words and press enter:\n");

    for(i = 0; i < 5; i++) {
        printf("%s\n", words[i]);
        scanf("%s", str);
        if(strcmp(words[i], str) == 0) {
            printf("Correct!\n");
            correct++;
        }
        else {
            printf("Incorrect!\n");
            incorrect++;
        }
    }

    total_time = 0;
    for(i = 0; i < 3; i++) {
        printf("Type the following sentence and press enter:\n");
        char sentence[100] = "The quick brown fox jumps over the lazy dog.";
        int len = strlen(sentence);

        start = time(NULL);
        scanf("%s", str);
        end = time(NULL);

        total_time += difftime(end, start);

        if(strcmp(sentence, str) == 0) {
            printf("Correct!\n");
            correct++;
        }
        else {
            printf("Incorrect!\n");
            incorrect++;
        }
    }

    typing_speed = (correct / (correct + incorrect)) / (total_time / 60);
    printf("Your typing speed is: %f words per minute\n", typing_speed);

    return 0;
}