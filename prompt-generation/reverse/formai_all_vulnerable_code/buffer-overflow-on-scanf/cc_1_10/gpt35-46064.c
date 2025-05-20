//FormAI DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define BOARD_SIZE 10
#define MAX_NUM 50

// Define function prototypes
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int generate_num();
int is_prime(int num);
float calculate_hypo(int a, int b);
void guess_number();

int main() {
    // Set seed for random number generation
    srand(time(NULL));

    printf("Welcome to the C Math Exercise Program!\n\n");

    // Print board
    int board[BOARD_SIZE][BOARD_SIZE];
    printf("Here is your board:\n");
    print_board(board);

    // Generate and check prime numbers
    int num = generate_num();
    int is_prime_num = is_prime(num);
    printf("\nRandom number generated: %d\n", num);
    printf("Is the number prime? %d\n", is_prime_num);

    // Calculate hypotenuse of right triangle
    int a = 3, b = 4;
    float hypo = calculate_hypo(a, b);
    printf("\nFor a right triangle with sides a=%d and b=%d, the hypotenuse is %.2f.\n", a, b, hypo);

    // Play number guessing game
    guess_number();

    return 0;
}

// Function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % MAX_NUM;
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random number
int generate_num() {
    int num = rand() % MAX_NUM;
    return num;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the hypotenuse of a right triangle
float calculate_hypo(int a, int b) {
    float hypo = sqrt(pow(a, 2) + pow(b, 2));
    return hypo;
}

// Function to play a number guessing game
void guess_number() {
    printf("\nLet's play a number guessing game!\n");
    int num = rand() % MAX_NUM;
    int guess = -1;
    int num_guesses = 0;
    do {
        printf("Guess a number between 0 and %d: ", MAX_NUM - 1);
        scanf("%d", &guess);
        num_guesses++;
        if (guess < num) {
            printf("Too low, try again!\n");
        } else if (guess > num) {
            printf("Too high, try again!\n");
        } else {
            printf("Congratulations! You guessed the correct number %d in %d guesses.\n", num, num_guesses);
        }
    } while (guess != num);
}