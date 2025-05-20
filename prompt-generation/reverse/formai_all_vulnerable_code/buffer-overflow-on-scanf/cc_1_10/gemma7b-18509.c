//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main() {
    int n, i, j, k, l, count = 0, flag = 0;
    char str[MAX_SIZE], comp[MAX_SIZE], prev[MAX_SIZE];

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter the characters: ");
    scanf("%s", str);

    // Preprocessing
    for (i = 0; str[i] != '\0'; i++) {
        prev[i] = str[i];
    }

    // Compression
    for (i = 0; str[i] != '\0'; i++) {
        count = 1;
        for (j = i + 1; str[j] != '\0' && str[j] == str[i]; j++) {
            count++;
        }

        if (count > 1) {
            flag = 1;
            comp[k++] = str[i];
            comp[k++] = count - 1;
        } else {
            comp[k++] = str[i];
        }
    }

    // Output
    if (flag) {
        printf("Compressed data: ");
        for (i = 0; comp[i] != '\0'; i++) {
            printf("%c", comp[i]);
        }

        printf("\n");
    } else {
        printf("No compression necessary.\n");
    }

    return 0;
}