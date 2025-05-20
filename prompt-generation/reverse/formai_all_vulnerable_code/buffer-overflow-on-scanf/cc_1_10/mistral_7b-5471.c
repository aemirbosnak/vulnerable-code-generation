//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 100
#define MIN_SIDE 1
#define MAX_SIDE 6

void check_memory_allocation(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Fatal error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void check_valid_input(int rolls, int sides) {
    if (rolls <= 0 || sides <= MIN_SIDE || sides > MAX_SIDE) {
        fprintf(stderr, "Invalid input. Rolls must be greater than zero. Sides must be between %d and %d.\n", MIN_SIDE, MAX_SIDE);
        exit(EXIT_FAILURE);
    }
}

int* roll_dice(int rolls, int sides) {
    int* result = (int*) malloc(rolls * sizeof(int));
    check_memory_allocation(result);

    srand(time(NULL));

    for (int i = 0; i < rolls; i++) {
        result[i] = rand() % sides + 1;
    }

    return result;
}

void print_results(int* results, int rolls) {
    printf("Results of %d dice rolls with %d sides:\n", rolls, MAX_SIDE);

    for (int i = 0; i < rolls; i++) {
        printf("Roll %d: %d\n", i + 1, results[i]);
    }

    free(results);
}

int main() {
    int rolls, sides;

    printf("Enter the number of dice rolls: ");
    scanf("%d", &rolls);

    check_valid_input(rolls, MAX_SIDE);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);

    check_valid_input(rolls, sides);

    int* results = roll_dice(rolls, sides);

    print_results(results, rolls);

    return EXIT_SUCCESS;
}