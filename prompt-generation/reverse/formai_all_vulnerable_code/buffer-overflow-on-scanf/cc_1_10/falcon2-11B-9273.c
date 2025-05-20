//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    char str[MAX_WORD_LENGTH];
    int freq[26] = {0};
    int total_freq = 0;
    int i, j;

    printf("Enter a string:\n");
    scanf("%s", str);

    // Convert string to lowercase
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }

    // Count frequency of each letter in the string
    for (i = 0; i < strlen(str); i++) {
        freq[str[i] - 'a']++;
        total_freq++;
    }

    // Sort the frequency array
    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < strlen(str) - i - 1; j++) {
            if (freq[j] > freq[j + 1]) {
                char temp = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = temp;
            }
        }
    }

    // Print the frequency array
    printf("Frequency Array: ");
    for (i = 0; i < strlen(str); i++) {
        if (freq[i] > 0) {
            printf("%c ", freq[i] % 26 + 'a');
            total_freq--;
        }
    }
    printf("\n");

    printf("Total frequency of all letters: %d\n", total_freq);

    return 0;
}