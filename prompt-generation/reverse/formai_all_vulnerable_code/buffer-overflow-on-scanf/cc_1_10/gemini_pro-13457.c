//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fortunes
char *fortunes[] = {
    "You will have a long and happy life.",
    "You will be rich and famous.",
    "You will find your true love.",
    "You will have a successful career.",
    "You will travel the world.",
    "You will make a difference in the world.",
    "You will be happy and content.",
    "You will achieve your dreams.",
    "You will have a great year.",
    "You will be lucky in love.",
    "You will be successful in your career.",
    "You will have a healthy and happy life.",
    "You will be surrounded by love and happiness.",
    "You will find your purpose in life.",
    "You will make a positive impact on the world.",
    "You will be a great success in life.",
    "You will have a beautiful and fulfilling life.",
    "You will be loved and cherished by all.",
    "You will achieve great things in life."
};

// Get a random fortune
int get_random_fortune() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and the number of fortunes
    int random_number = rand() % (sizeof(fortunes) / sizeof(char *));

    // Return the random fortune
    return random_number;
}

// Print the fortune
void print_fortune(int fortune_number) {
    // Print the fortune
    printf("Your fortune is: %s\n", fortunes[fortune_number]);
}

// Get the user's name
char *get_user_name() {
    // Create a buffer for the user's name
    char *user_name = malloc(256);

    // Get the user's name from the console
    printf("What is your name? ");
    scanf("%s", user_name);

    // Return the user's name
    return user_name;
}

// Main function
int main() {
    // Get the user's name
    char *user_name = get_user_name();

    // Print a welcome message
    printf("Welcome to the Fortune Teller, %s!\n", user_name);

    // Get a random fortune
    int fortune_number = get_random_fortune();

    // Print the fortune
    print_fortune(fortune_number);

    // Free the user's name
    free(user_name);

    // Return 0 to indicate success
    return 0;
}