#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int main() {
    FILE *file;
    char word[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    int frequencies[26] = {0};

    if ((file = fopen("input.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        int i = 0;
        for (; i < strlen(buffer); ++i) {
            word[i] = toupper(buffer[i]);
            if (i >= BUFFER_SIZE - 1) break;
        }
        word[i] = '\0';

        int j = 0;
        for (; j < 26; ++j) {
            if (word[0] == 'A' + j) {
                frequencies[j]++;
                break;
            }
        }
        if (j == 26) {
            printf("Invalid character: %s\n", word);
        }
        count++;
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < 26; ++i) {
        if (frequencies[i] > 0) {
            printf("%c: %d\n", 'A' + i, frequencies[i]);
        }
    }
    printf("Total words: %d\n", count);

    fclose(file);
    return 0;
}
