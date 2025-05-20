//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[1000];
    printf("Enter the string to be compressed: ");
    fgets(input, sizeof(input), stdin);

    int i, j, n = strlen(input);
    int count[26] = {0};

    for (i = 0; i < n; i++) {
        count[input[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (count[i] > 1) {
            j = i;
            while (j < 26) {
                if (count[j] > 0) {
                    count[j] = 0;
                    j++;
                } else {
                    break;
                }
            }

            for (j = i + 1; j < 26; j++) {
                count[j] += count[j - 1];
            }

            for (j = i; j < 26; j++) {
                count[j]--;
            }
        }
    }

    for (i = 0; i < n; i++) {
        int k = input[i] - 'a';
        if (count[k] > 1) {
            int c = input[i] - 'a';
            printf("%c", c);
            for (j = 1; j < count[k]; j++) {
                printf("%c", c);
            }
        } else {
            printf("%c", input[i]);
        }
    }
    printf("\n");

    return 0;
}