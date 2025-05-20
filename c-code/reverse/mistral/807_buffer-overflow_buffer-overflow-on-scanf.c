#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void print_clues(char *clues[]) {
    int i;
    for (i = 0; clues[i]; i++) {
        printf("%s\n", clues[i]);
    }
}

int main() {
    char secret_word[BUFFER_SIZE];
    char input[BUFFER_SIZE];
    char *clues[] = {
        "I am the only one",
        "I have no eyes",
        "I am always hungry",
        "What is it?",
        "The answer"
    };

    strcpy(secret_word, "water");

    print_clues(clues);

    printf("Guess the secret word: ");
    fgets(input, BUFFER_SIZE, stdin);

    if (strcmp(input, secret_word) == 0) {
        printf("Congratulations! You found the treasure!\n");
    } else {
        printf("Sorry, you didn't find the treasure.\n");
    }

    return 0;
}
