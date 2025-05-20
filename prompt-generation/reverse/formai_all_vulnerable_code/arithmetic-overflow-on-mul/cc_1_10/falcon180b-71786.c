//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char text[100];
    int length, words, correct_words, wrong_words, speed, accuracy;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Enter the text you want to type: ");
    scanf("%s", text);
    length = strlen(text);

    srand(time(NULL));
    int index = rand() % length;
    char* word = strtok(text, " ");
    while (word!= NULL) {
        if (strlen(word) > 0) {
            words++;
        }
        word = strtok(NULL, " ");
    }

    printf("You will type %d words.\n", words);
    printf("Press enter to start...\n");
    getchar();

    start_time = time(NULL);
    for (int i = 0; i < words; i++) {
        index = rand() % length;
        word = strtok(text, " ");
        while (word!= NULL) {
            if (strlen(word) > 0) {
                printf("%s ", word);
                if (i % 2 == 0) {
                    correct_words++;
                } else {
                    wrong_words++;
                }
            }
            word = strtok(NULL, " ");
        }
        printf("\n");
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    speed = (int) round(words / elapsed_time);
    accuracy = (int) round((correct_words / words) * 100);

    printf("\nYou finished the test in %d seconds.\n", elapsed_time);
    printf("Your typing speed is %d words per minute.\n", speed);
    printf("Your accuracy is %d%%.\n", accuracy);

    return 0;
}