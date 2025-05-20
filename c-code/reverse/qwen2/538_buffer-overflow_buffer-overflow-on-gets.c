#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char sentence[MAX_LEN];
    int freq[26] = {0};

    printf("Enter a sentence: ");
    gets(sentence);

    for (int i = 0; sentence[i]; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            freq[sentence[i] - 'a']++;
        }
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", 'a' + i, freq[i]);
        }
    }

    return 0;
}
