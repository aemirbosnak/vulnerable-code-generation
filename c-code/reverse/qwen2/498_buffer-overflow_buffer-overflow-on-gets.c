#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1024];
    int freq[26] = {0};
    int maxFreq = 0;
    char mostFrequent;

    printf("Enter text: ");
    gets(text);

    for (int i = 0; text[i]; i++) {
        char ch = tolower(text[i]);
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] > maxFreq) {
                maxFreq = freq[ch - 'a'];
                mostFrequent = ch;
            }
        }
    }

    printf("Most frequent letter: %c\n", mostFrequent);
    return 0;
}
