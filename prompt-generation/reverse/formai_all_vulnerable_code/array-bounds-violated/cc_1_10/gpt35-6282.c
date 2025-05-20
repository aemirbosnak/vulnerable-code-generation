//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char name[30];
    printf("Hello there, what is your name?\n");
    fgets(name, 30, stdin);

    // Removing newline character from input string
    size_t length = strlen(name);
    if (name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }

    printf("Nice to meet you, %s!\n", name);

    // Capitalizing the first letter of the input string
    if (strlen(name) > 0) {
        name[0] = toupper(name[0]);
    }

    printf("Did you know that if you rearrange the letters of your name, you can make some interesting words?\n");

    // Generating permutations of the input string
    int num_permutations = 1;
    for (int i = 2; i <= strlen(name); i++) {
        num_permutations *= i;
    }

    char** permutations = (char**) malloc(num_permutations * sizeof(char*));
    for (int i = 0; i < num_permutations; i++) {
        permutations[i] = (char*) malloc((strlen(name) + 1) * sizeof(char));
    }

    int index = 0;
    do {
        strncpy(permutations[index], name, strlen(name) + 1);
        index++;
    } while (next_permutation(name, strlen(name)));

    // Printing out permutations and checking for interesting words
    int num_interesting_words = 0;
    char* interesting_words[] = {"love", "hate", "life", "death", "joy", "fear", "hope", "passion"};

    for (int i = 0; i < num_permutations; i++) {
        printf("%s\n", permutations[i]);

        for (int j = 0; j < sizeof(interesting_words) / sizeof(char*); j++) {
            if (strstr(permutations[i], interesting_words[j]) != NULL) {
                num_interesting_words++;
                break;
            }
        }
    }

    printf("Out of %d permutations, %d contain interesting words.\n", num_permutations, num_interesting_words);

    // Freeing dynamically allocated memory
    for (int i = 0; i < num_permutations; i++) {
        free(permutations[i]);
    }
    free(permutations);

    return 0;
}

int next_permutation(char* str, int n) {
    int i, j;

    for (i = n - 2; i >= 0; i--) {
        if (str[i] < str[i + 1]) {
            break;
        }
    }

    if (i < 0) {
        return 0;
    }

    for (j = n - 1; j > i; j--) {
        if (str[j] > str[i]) {
            break;
        }
    }

    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    for (int k = i + 1; k <= (n + i) / 2; k++) {
        char temp = str[k];
        str[k] = str[n + i - k];
        str[n + i - k] = temp;
    }

    return 1;
}