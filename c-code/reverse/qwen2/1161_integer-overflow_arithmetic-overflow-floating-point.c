#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024 * 1024

int main() {
    char input[MAX_INPUT_SIZE];
    int wordCount = 0;
    int specialCharCount = 0;
    long totalWordLength = 0;
    long totalSpecialCharDistance = 0;
    double avgWordLength = 0.0;
    double avgSpecialCharDistance = 0.0;
    int lastSpecialCharIndex = -1;

    printf("Enter text (max %d characters):\n", MAX_INPUT_SIZE);
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            totalWordLength += 1;
        }
        if (!isalnum(input[i]) && !isspace(input[i])) {
            specialCharCount++;
            if (lastSpecialCharIndex != -1) {
                totalSpecialCharDistance += i - lastSpecialCharIndex - 1;
            }
            lastSpecialCharIndex = i;
        }
    }

    if (totalWordLength > 0) {
        avgWordLength = (double)totalWordLength / wordCount;
    }
    if (specialCharCount > 0 && lastSpecialCharIndex != -1) {
        avgSpecialCharDistance = (double)totalSpecialCharDistance / (specialCharCount - 1);
    }

    printf("Word Count: %d\n", wordCount);
    printf("Special Character Count: %d\n", specialCharCount);
    printf("Average Word Length: %.2f\n", avgWordLength);
    printf("Average Special Character Distance: %.2f\n", avgSpecialCharDistance);

    return 0;
}
