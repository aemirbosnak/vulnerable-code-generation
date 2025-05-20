#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20

int main() {
    char words[MAX_WORDS][WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    char input[1000];
    int i, j;

    printf("Enter words separated by spaces (max %d words):\n", MAX_WORDS);
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            input[i] = '\0';
        }
    }

    char *token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(words[j], token) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found && strlen(token) > 0) {
            strcpy(words[count[0]], token);
            count[count[0]]++;
        }
        token = strtok(NULL, " ");
    }

    printf("\nWord frequencies:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        if (count[i] > 0) {
            printf("%s: %d\n", words[i], count[i]);
        }
    }

    return 0;
}
