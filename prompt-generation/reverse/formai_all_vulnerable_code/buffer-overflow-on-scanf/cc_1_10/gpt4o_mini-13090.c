//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_ATTEMPTS 5

void generate_random_numbers(int *numbers, int n) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100; // Generate random numbers from 0 to 99
    }
}

void print_numbers(int *numbers, int n) {
    printf("Generated Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void find_max_min(int *numbers, int n, int *max, int *min) {
    *max = numbers[0];
    *min = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > *max) {
            *max = numbers[i];
        }
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
    }
}

float calculate_average(int *numbers, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return (float)sum / n;
}

void sort_numbers(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void display_sorted_numbers(int *numbers, int n) {
    printf("Sorted Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void guess_the_number_game(int target) {
    int guess;
    int attempts = 0;

    printf("Welcome to 'Guess the Number' Game!\n");
    printf("Guess a number between 0 and 99. You have %d attempts.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &guess);
        
        if (guess < 0 || guess > 99) {
            printf("Please guess a number between 0 and 99.\n");
            continue;
        }

        if (guess > target) {
            printf("Too high!\n");
        } else if (guess < target) {
            printf("Too low!\n");
        } else {
            printf("Congratulations! You guessed the number %d.\n", target);
            return;
        }

        attempts++;
    }
    printf("Sorry! You've used all your attempts. The number was %d.\n", target);
}

int main() {
    int numbers[MAX_NUMBERS];
    int n;

    printf("Enter the number of random numbers to generate (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_NUMBERS) {
        printf("Invalid number. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return 1;
    }

    generate_random_numbers(numbers, n);
    print_numbers(numbers, n);

    int max, min;
    find_max_min(numbers, n, &max, &min);
    printf("Maximum Number: %d\n", max);
    printf("Minimum Number: %d\n", min);

    float average = calculate_average(numbers, n);
    printf("Average: %.2f\n", average);

    sort_numbers(numbers, n);
    display_sorted_numbers(numbers, n);

    int target = rand() % 100; // Generate a target number for guessing game
    guess_the_number_game(target);
    
    return 0;
}