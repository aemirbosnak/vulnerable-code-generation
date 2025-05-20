#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void treasure_hunt(char *input) {
    int i, secret = 42;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '*') {
            printf("Congratulations! You found the secret number: %d\n", ++secret);
            return;
        }
    }

    printf("Try again. The secret number is hidden among the '*'s.\n");
}

int main() {
    char input[100];

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Enter your guess (up to 100 characters): ");
    scanf("%s", input);

    treasure_hunt(input);

    return 0;
}
