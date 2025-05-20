//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT 300
#define WORD_LENGTH 5

int main() {
    FILE *fp;
    char filename[50];
    char word[WORD_LENGTH+1];
    int i, j, count, correct = 0, incorrect = 0;
    float speed, accuracy;
    time_t start, end;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < WORD_COUNT; i++) {
        j = rand() % (WORD_LENGTH - 2) + 3;
        word[j] = '\0';
        for (int k = 0; k < j; k++) {
            word[k] = 'a' + rand() % 26;
        }
        fprintf(fp, "%s\n", word);
    }
    fclose(fp);

    printf("Press ENTER to start the test.\n");
    scanf("%s", "");

    start = clock();
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        printf("%s\n", word);
        fflush(stdout);
        scanf("%s", "");
        if (strcmp(word, "")) {
            if (strcmp(word, "")) {
                count++;
                if (strcmp(word, "")) {
                    correct++;
                } else {
                    incorrect++;
                }
            }
        }
    }
    fclose(fp);
    end = clock();

    speed = (float)count / (end - start);
    accuracy = (float)correct / count * 100;

    printf("\nTest results:\n");
    printf("Number of words typed: %d\n", count);
    printf("Number of correct words: %d\n", correct);
    printf("Number of incorrect words: %d\n", incorrect);
    printf("Typing speed: %.2f words per second\n", speed);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}