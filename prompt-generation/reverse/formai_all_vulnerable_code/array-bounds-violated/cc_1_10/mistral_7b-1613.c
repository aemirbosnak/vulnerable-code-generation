//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define ARRAY_SIZE 10
#define MIN_LENGTH 5

typedef struct {
    char str[MIN_LENGTH + 1];
    long int time;
} StringWithTime;

void printArray(StringWithTime arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s : %ldms\n", arr[i].str, arr[i].time);
    }
}

void calculateTypingSpeed(char input[], StringWithTime arr[], int *index, int size) {
    char currentString[MIN_LENGTH + 1];
    int currentIndex = *index;
    double elapsedTime = 0.0;
    clock_t start, end;

    start = clock();

    strncpy(currentString, arr[currentIndex].str, MIN_LENGTH);
    currentString[MIN_LENGTH] = '\0';

    int i = 0;
    while (input[i] && strcmp(currentString, &input[i]) != 0) {
        i++;
    }

    if (input[i] == '\0') {
        arr[currentIndex].time = clock() - start;
        *index = (*index + 1) % size;
    }

    end = clock();
    elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    arr[currentIndex].time += elapsedTime;
}

int main() {
    StringWithTime words[ARRAY_SIZE] = {{"apple", 0}, {"banana", 0}, {"cherry", 0}, {"date", 0}, {"elderberry", 0}, {"fig", 0}, {"grape", 0}, {"honeydew", 0}, {"kiwi", 0}, {"mango", 0}};
    int index = 0;
    char input[101];

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following words and press Enter after each word:\n");

    while (1) {
        printf("\n%s: ", words[index].str);
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (strlen(input) < MIN_LENGTH) {
            printf("Word length should be minimum %d characters.\n", MIN_LENGTH);
            continue;
        }

        calculateTypingSpeed(input, words, &index, ARRAY_SIZE);
    }

    printf("\nYour typing speed:\n");
    printArray(words, ARRAY_SIZE);

    double average = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        average += (double)words[i].time / (double)(strlen(words[i].str) * 5);
    }

    average /= ARRAY_SIZE;

    printf("\nYour average typing speed: %.2f wpm\n", average);

    return 0;
}