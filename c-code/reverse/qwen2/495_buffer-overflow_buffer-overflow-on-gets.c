#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];
    int frequency[26] = {0};
    int max_count = 0;
    char max_letter = '\0';

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            char lower = tolower(input[i]);
            frequency[lower - 'a']++;
            if (frequency[lower - 'a'] > max_count) {
                max_count = frequency[lower - 'a'];
                max_letter = lower;
            }
        }
    }

    if (max_letter != '\0') {
        printf("Most frequent letter: %c\n", max_letter);
        printf("Count: %d\n", max_count);
    } else {
        printf("No letters found.\n");
    }

    return 0;
}
