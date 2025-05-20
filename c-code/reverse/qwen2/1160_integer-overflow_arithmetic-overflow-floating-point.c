#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char text[1024];
    int wordCount = 0;
    int specialCharCount = 0;
    long totalChars = 0;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            wordCount++;
        } else if ((text[i] >= '!') && (text[i] <= '/') || 
                   (text[i] >= ':') && (text[i] <= '@') || 
                   (text[i] >= '[') && (text[i] <= '`') || 
                   (text[i] >= '{')) {
            specialCharCount++;
        }
        totalChars += text[i];
    }

    // Intentionally introduce an integer overflow vulnerability
    int avgWordLength = (totalChars + wordCount - 1) / wordCount;

    printf("Word Count: %d\n", wordCount);
    printf("Special Character Count: %d\n", specialCharCount);
    printf("Average Word Length: %d\n", avgWordLength);

    return 0;
}
