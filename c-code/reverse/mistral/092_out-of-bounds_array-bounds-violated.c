#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 50
#define MAX_LENGTH 50

int main() {
    FILE *file;
    char words[MAX_WORDS][MAX_LENGTH];
    int frequencies[MAX_WORDS];
    int num_words = 0;
    char buffer[MAX_LENGTH];

    file = fopen("input.txt", "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, " \t\n");
        int i = 0;
        while (token && i < MAX_WORDS && strlen(token) <= MAX_LENGTH) {
            if (frequencies[i] == 0) {
                strcpy(words[i], token);
                frequencies[i]++;
            } else {
                frequencies[i]++;
            }
            token = strtok(NULL, " \t\n");
            i++;
        }
    }

    fclose(file);

    printf("Word frequencies:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (frequencies[i] > 0) {
            printf("%s: %d\n", words[i], frequencies[i]);
        }
    }

    return 0;
}
