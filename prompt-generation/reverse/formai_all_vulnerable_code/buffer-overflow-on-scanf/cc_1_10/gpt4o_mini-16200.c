//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10

void puzzle() {
    printf("Welcome to the Puzzle of the Numbers!\n");
    printf("You will be asked to enter %d numbers.\n", MAX_NUMBERS);
    printf("Let the adventure begin!\n");
}

int read_numbers(int *numbers, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Oh no! That's not a valid number! Try again.\n");
            while(getchar() != '\n'); // Clear the input buffer
            i--; // Decrement i to repeat this iteration
        }
    }
    return 0;
}

void process_numbers(int *numbers, int count) {
    printf("\nLet's process the numbers!\n");
    int sum = 0, highest = numbers[0], lowest = numbers[0];
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        if (numbers[i] > highest) highest = numbers[i];
        if (numbers[i] < lowest) lowest = numbers[i];
    }
    printf("Sum: %d\n", sum);
    printf("Highest: %d\n", highest);
    printf("Lowest: %d\n", lowest);
}

void error_handling_example() {
    int *numbers = malloc(MAX_NUMBERS * sizeof(int));
    if (!numbers) {
        printf("Memory allocation failed! The realm of numbers has vanished.\n");
        exit(EXIT_FAILURE);
    }

    int result = read_numbers(numbers, MAX_NUMBERS);
    if (result != 0) {
        printf("There was an error reading numbers! A riddle unsolved!\n");
    } else {
        process_numbers(numbers, MAX_NUMBERS);
    }

    free(numbers);
    printf("The puzzle is complete! Thank you for playing.\n");
}

void mystical_quest() {
    printf("\nA mystical quest awaits! Are you ready to dive deeper?\n");
    printf("1. Traverse deeper into the next challenge\n");
    printf("2. Retreat back to the safety of oblivion\n");
    printf("Choose wisely (1 or 2): ");
    
    int choice;
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Ah! A twist in the path! Choose either 1 or 2: ");
        while(getchar() != '\n'); // Clear input buffer
    }

    if (choice == 1) {
        printf("You have chosen to press onward!\n");
        error_handling_example();
    } else {
        printf("You have retreated! The number realm is safe... for now.\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    puzzle();
    mystical_quest();
    return 0;
}