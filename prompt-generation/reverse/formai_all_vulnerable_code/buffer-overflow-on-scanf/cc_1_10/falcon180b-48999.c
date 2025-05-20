//Falcon-180B DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a 2D array
void print_array(int arr[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    // Sherlock Holmes and Dr. Watson are trying to solve a mystery involving a safe with a 4-digit combination lock.
    // The safe contains valuable evidence that could solve their current case.
    // They know that the combination is made up of prime numbers between 1 and 9.
    // Help them crack the code by generating random combinations and checking if they are correct.

    int safe_combination[4];
    for (int i = 0; i < 4; i++) {
        safe_combination[i] = rand_num(1, 9);
    }

    int attempts = 0;
    while (attempts < 10) {
        int user_combination[4];
        printf("Attempt #%d:\n", attempts + 1);
        for (int i = 0; i < 4; i++) {
            printf("Enter digit #%d: ", i + 1);
            scanf("%d", &user_combination[i]);
        }

        int correct_digits = 0;
        for (int i = 0; i < 4; i++) {
            if (user_combination[i] == safe_combination[i]) {
                correct_digits++;
            }
        }

        if (correct_digits == 4) {
            printf("Congratulations! You've cracked the code in %d attempts.\n", attempts + 1);
            break;
        } else if (correct_digits > 0) {
            printf("You got %d digit(s) correct.\n", correct_digits);
        } else {
            printf("Sorry, all digits are incorrect.\n");
        }

        attempts++;
    }

    return 0;
}