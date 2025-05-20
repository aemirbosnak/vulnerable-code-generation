//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generateRandomChar() {
    int c = rand() % 26 + 65;
    return c;
}

int main() {
    srand(time(NULL));
    char quote[] = "The quick brown fox jumps over the lazy dog.";
    int len = strlen(quote);
    char userInput[100];
    printf("*** Surrealist Typing Speed Test ***\n\n");
    printf("You will be typing a quote that is not of this world.\n");
    printf("Your goal is to type the entire quote as fast as possible.\n");
    printf("Press ENTER to start.\n");
    getchar();
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("TYPE!\n");
    int i = 0, errors = 0, timeElapsed = 0;
    clock_t start = clock();
    while (i < len) {
        int c = generateRandomChar();
        printf("%c", c);
        if (getchar() != quote[i]) {
            errors++;
        }
        userInput[i] = c;
        i++;
    }
    userInput[i] = '\0';
    clock_t end = clock();
    timeElapsed = (int)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nCongratulations! You have completed the Surrealist Typing Speed Test!\n");
    printf("Here is your result:\n");
    printf("Time elapsed: %d seconds\n", timeElapsed);
    printf("Errors: %d\n", errors);
    printf("Accuracy: %.2f%%\n\n", 100 - ((float)errors / (float)len) * 100);
    printf("Your input: %s\n", userInput);
    printf("The correct quote: %s\n", quote);
    return 0;
}