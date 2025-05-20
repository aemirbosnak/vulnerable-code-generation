#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHAR 256

int main() {
    char text[MAX_CHAR];
    char most_frequent;
    int freq[MAX_CHAR] = {0};
    int i, len;

    printf("Enter text: ");
    gets(text);

    for (i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            freq[(unsigned char)tolower(text[i])]++;
        }
    }

    len = sizeof(freq) / sizeof(freq[0]);
    most_frequent = text[0];
    for (i = 1; i < len; ++i) {
        if (freq[i] > freq[most_frequent - 'a']) {
            most_frequent = (char)(i + 'a');
        }
    }

    printf("Most frequent letter: %c\n", most_frequent);

    return 0;
}
