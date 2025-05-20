//Falcon-180B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_random_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = generate_random_number(1, 100);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int arr[SIZE];
    generate_random_array(arr, SIZE);
    print_array(arr, SIZE);

    int target = generate_random_number(1, 100);
    int guesses[SIZE];

    int num_guesses = 0;
    int correct_guesses = 0;

    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guesses[num_guesses]);

    while (num_guesses < SIZE && guesses[num_guesses]!= target) {
        if (guesses[num_guesses] < target) {
            printf("Too low. Guess again: ");
        } else {
            printf("Too high. Guess again: ");
        }
        scanf("%d", &guesses[++num_guesses]);
    }

    if (num_guesses == SIZE) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
        correct_guesses = num_guesses;
    }

    return 0;
}