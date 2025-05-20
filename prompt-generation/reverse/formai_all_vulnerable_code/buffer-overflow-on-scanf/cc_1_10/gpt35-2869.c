//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int compressed_size(int n) {
    int count = 0;

    while (n) {
        n /= 10;
        ++count;
    }

    return count;
}

char *compress(char *str) {
    int len = strlen(str);
    char *new_str = (char *) malloc(sizeof(char) * MAX_LENGTH);
    int i = 0, j = 0;
    int count = 0;

    while (i < len) {
        count = 1;

        while (str[i] == str[i + 1] && i < len - 1) {
            ++count;
            ++i;
        }

        if (count == 1) {
            new_str[j++] = str[i++];
        } else {
            int compressed_len = compressed_size(count);
            char *temp = (char *) malloc(sizeof(char) * compressed_len + 1);
            sprintf(temp, "%d", count);
            strcat(new_str, temp);
            free(temp);

            new_str[j++] = str[i++];
        }
    }

    return new_str;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    char *new_str = compress(str);
    printf("Compressed string: %s\n", new_str);
    free(new_str);
    return 0;
}