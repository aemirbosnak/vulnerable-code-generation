//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void init_rand(void) {
    srand(time(NULL));
}

// Get a random number between 0 and n-1
int get_random(int n) {
    return rand() % n;
}

// Get a random fortune from the array
const char *get_fortune(void) {
    const char *fortunes[] = {
        "Your future is bright.",
        "You will find success in your endeavors.",
        "You will have a long and happy life.",
        "You will meet your soulmate soon.",
        "You will win the lottery.",
        "You will become a famous artist.",
        "You will write a bestselling book.",
        "You will travel the world.",
        "You will find your true calling.",
        "You will achieve your dreams."
    };

    return fortunes[get_random(10)];
}

// Print a fortune
void print_fortune(void) {
    printf("Your fortune is: %s\n", get_fortune());
}

// Recursively call the fortune teller
void fortune_teller(int depth) {
    // Base case: stop recursion if depth is 0
    if (depth == 0) {
        print_fortune();
        return;
    }

    // Recursive case: decrement depth and call fortune_teller again
    fortune_teller(depth - 1);
}

// Main function
int main(void) {
    // Initialize the random number generator
    init_rand();

    // Get the input from the user
    int depth;
    printf("Enter the depth of the fortune teller (0-10): ");
    scanf("%d", &depth);

    // Recursively call the fortune teller
    fortune_teller(depth);

    return 0;
}