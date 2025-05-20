#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main() {
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int counts[100] = {0};
    int count_index = 0;

    while (fscanf(file, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i <= count_index; i++) {
            if (strcmp(word, word) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }
        if (!found && count_index < 99) {
            strcpy(word, word);
            counts[count_index++]++;
        }
    }

    fclose(file);

    for (int i = 0; i < count_index; i++) {
        printf("%s: %d\n", word, counts[i]);
    }

    return 0;
}
