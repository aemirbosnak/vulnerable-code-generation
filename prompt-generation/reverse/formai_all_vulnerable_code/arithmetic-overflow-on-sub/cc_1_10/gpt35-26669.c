//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to calculate CPM (Characters Per Minute)
int calculateCPM(int typedChar, int elapsedTime) {
    float timeInMinute = elapsedTime / 60.0;
    int cpm = (typedChar / 5) / timeInMinute;
    return cpm;
}

int main() {
    char sampleText[] = "The quick brown fox jumps over the lazy dog";
    int textLen = sizeof(sampleText) / sizeof(sampleText[0]) - 1; // Excluding the null character
    int index = 0, typedChar = 0, incorrectChar = 0, unfinished = 1;
    time_t startTime = time(NULL), elapsedTime;

    printf("Type the following text as fast as you can:\n%s\n\n", sampleText);

    while (unfinished) {
        char currentChar = getchar();
        if (currentChar == sampleText[index] && index < textLen) {
            typedChar++;
            index++;
            printf("%c", currentChar);
        }
        else if (currentChar == 8 || currentChar == 127) { // Handling Backspace or Delete key
            if (index > 0) {
                index--;
                typedChar--;
                printf("\b \b"); // Move the cursor back, erase the character and move back again
            }
        }
        else if (currentChar == 10 || currentChar == 13) { // Handling Enter Key
            unfinished = 0;
        }
        else {
            incorrectChar++;
            printf("(\033[31m%c\033[0m)", sampleText[index]);
        }
    }

    elapsedTime = time(NULL) - startTime;
    printf("\n\nTotal characters typed: %d\n", typedChar);
    printf("Total incorrect characters: %d\n", incorrectChar);
    printf("Total time elapsed: %ld seconds\n", elapsedTime);
    printf("Your typing speed is: %d CPM (Characters Per Minute)\n", calculateCPM(typedChar, elapsedTime));

    return 0;
}