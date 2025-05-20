//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BIT_COUNT 10

void generate_random_binary(char *binary, int bit_count) {
    int i;
    for (i = 0; i < bit_count; i++) {
        binary[i] = (rand() % 2) + '0';
    }
    binary[bit_count] = '\0';
}

int main() {
    int attempts = 0;
    char user_binary[BIT_COUNT + 1];
    char computer_binary[BIT_COUNT + 1];
    char random_binary[BIT_COUNT + 1];

    srand(time(NULL));

    printf("Welcome to the Binary Guessing Game!\n");
    printf("I will generate a random binary number of length %d.\n", BIT_COUNT);
    printf("Your task is to guess it as quickly as possible.\n");

    generate_random_binary(computer_binary, BIT_COUNT);
    printf("Computer's binary number: %s\n", computer_binary);

    while (1) {
        attempts++;
        printf("Your turn! Guess the computer's binary number: ");
        scanf("%s", user_binary);

        if (strlen(user_binary) != BIT_COUNT) {
            printf("Invalid input! Please enter a binary number of length %d.\n", BIT_COUNT);
            continue;
        }

        int bit_difference = 0;
        for (int i = 0; i < BIT_COUNT; i++) {
            if (user_binary[i] != computer_binary[i]) {
                bit_difference++;
            }
        }

        printf("Attempts: %d, Differences: %d\n", attempts, bit_difference);

        if (bit_difference == 0) {
            printf("Congratulations! You guessed it right in %d attempts.\n", attempts);
            break;
        }
    }

    return 0;
}