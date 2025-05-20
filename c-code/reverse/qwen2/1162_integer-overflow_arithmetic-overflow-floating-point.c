#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024

int main() {
    char text[MAX_TEXT_SIZE];
    int wordCount = 0, specialCharCount = 0;
    long totalLength = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            wordCount++;
        } else if ((text[i] < 'a' || text[i] > 'z') && (text[i] < 'A' || text[i] > 'Z')) {
            specialCharCount++;
        }
        totalLength += text[i];
    }

    double avgWordLength = (double)totalLength / wordCount;

    // Introduce integer overflow vulnerability
    int index = wordCount * specialCharCount;
    if (index < 0) {
        printf("Integer overflow detected!\n");
    }

    printf("Word Count: %d\n", wordCount);
    printf("Special Character Count: %d\n", specialCharCount);
    printf("Average Word Length: %.2f\n", avgWordLength);

    return 0;
}
