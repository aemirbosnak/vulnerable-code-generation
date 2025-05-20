//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of a given length
char* generateRandomString(int length) {
    char* result = malloc(length + 1);
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        result[i] = characters[rand() % strlen(characters)];
    }
    result[length] = '\0';
    return result;
}

// Function to calculate the typing speed in WPM
double calculateTypingSpeed(int correctWords, int incorrectWords, int totalWords, double timeTaken) {
    int netWords = correctWords - incorrectWords;
    if (netWords < 0) {
        netWords = 0;
    }
    double wordsPerMinute = (double) netWords / (timeTaken / 60);
    printf("Words per minute: %.2f\n", wordsPerMinute);
    printf("Accuracy: %.2f%%\n", 100.0 * correctWords / totalWords);
    return wordsPerMinute;
}

// Function to run the typing speed test
void runTypingTest(int testDuration) {
    srand(time(NULL));
    int correctWords = 0;
    int incorrectWords = 0;
    int totalWords = 0;
    clock_t startTime = clock();
    char* word;
    while (difftime(clock(), startTime) < testDuration) {
        word = generateRandomString(rand() % 10 + 1);
        printf("%s\n", word);
        char input[100];
        fgets(input, 100, stdin);
        if (strlen(input) == strlen(word) && strcmp(input, word) == 0) {
            correctWords++;
        } else {
            incorrectWords++;
        }
        totalWords++;
    }
    double typingSpeed = calculateTypingSpeed(correctWords, incorrectWords, totalWords, testDuration);
    printf("Your typing speed is %.2f WPM\n", typingSpeed);
}

int main() {
    int testDuration;
    printf("Enter the duration of the typing test in seconds: ");
    scanf("%d", &testDuration);
    runTypingTest(testDuration);
    return 0;
}