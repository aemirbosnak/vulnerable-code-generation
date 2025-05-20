//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1000

int main() {

    char text[MAX_LEN], newText[MAX_LEN], c;
    int len, alphaCount = 0, digitCount = 0, spaceCount = 0;

    printf("Enter a string of text: ");
    fgets(text, MAX_LEN, stdin);

    // Removing new lines from input
    len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
        len--;
    }

    // Counting the number of alphabetical characters, digits and spaces
    for (int i = 0; i < len; i++) {
        c = text[i];

        if (isalpha(c)) {
            alphaCount++;
        } else if (isdigit(c)) {
            digitCount++;
        } else if (isspace(c)) {
            spaceCount++;
        }
    }

    // Replacing every second space with a hyphen
    int newLen = 0, spaceCounter = 0;
    for (int i = 0; i < len; i++) {
        c = text[i];

        if (isspace(c)) {
            spaceCounter++;

            if (spaceCounter % 2 == 0) {
                newText[newLen++] = '-';
                continue;
            }
        }

        newText[newLen++] = c;
    }

    // Randomly shuffling the alphabetical characters
    int alphaLen = 0;
    char alphaArr[alphaCount];
    for (int i = 0; i < len; i++) {
        c = text[i];

        if (isalpha(c)) {
            alphaArr[alphaLen++] = c;
        }
    }

    srand(time(0));
    for (int i = alphaLen - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = alphaArr[j];
        alphaArr[j] = alphaArr[i];
        alphaArr[i] = temp;
    }

    int alphaCounter = 0;
    for (int i = 0; i < len; i++) {
        c = text[i];

        if (isalpha(c)) {
            newText[i] = alphaArr[alphaCounter++];
        }
    }

    printf("\nOriginal Text: %s\n", text);
    printf("Number of Alphabetical Characters: %d\n", alphaCount);
    printf("Number of Digits: %d\n", digitCount);
    printf("Number of Spaces: %d\n", spaceCount);

    printf("\nNew Text: %s\n", newText);

    return 0;
}