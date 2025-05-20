#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int freq[26] = {0};
    int maxFreq = 0;
    char maxChar;

    printf("Enter text: ");
    gets(text);

    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            freq[text[i] - 'a']++;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            freq[text[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i + 'a';
        }
    }

    printf("Most frequent letter: %c\n", maxChar);
    printf("Count: %d\n", maxFreq);

    return 0;
}
