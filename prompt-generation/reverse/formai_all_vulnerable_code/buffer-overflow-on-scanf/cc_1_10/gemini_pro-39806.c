//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible fortunes
char *fortunes[] = {
    "You will have a long and happy life.",
    "You will be rich and famous.",
    "You will find true love.",
    "You will travel the world.",
    "You will make a difference in the world.",
    "You will be successful in everything you do.",
    "You will be happy and content.",
    "You will have a fulfilling life.",
    "You will live a long and prosperous life.",
    "You will be surrounded by loved ones.",
    "You will be healthy and strong.",
    "You will have a bright future.",
    "You will achieve your goals.",
    "You will be happy and successful.",
    "You will have a long and happy life.",
    "You will be surrounded by loved ones.",
    "You will be successful in everything you do.",
    "You will make a difference in the world.",
    "You will be happy and content.",
    "You will have a fulfilling life.",
    "You will live a long and prosperous life.",
    "You will be healthy and strong.",
    "You will have a bright future.",
    "You will achieve your goals.",
    "You will be happy and successful.",
    "You will have a long and happy life.",
    "You will be surrounded by loved ones.",
    "You will be successful in everything you do.",
    "You will make a difference in the world.",
    "You will be happy and content.",
    "You will have a fulfilling life.",
    "You will live a long and prosperous life.",
    "You will be healthy and strong.",
    "You will have a bright future.",
    "You will achieve your goals.",
    "You will be happy and successful.",
    "You will have a long and happy life.",
    "You will be surrounded by loved ones.",
    "You will be successful in everything you do.",
    "You will make a difference in the world.",
    "You will be happy and content.",
    "You will have a fulfilling life.",
    "You will live a long and prosperous life.",
    "You will be healthy and strong.",
    "You will have a bright future.",
    "You will achieve your goals.",
    "You will be happy and successful."
};

// Get a random fortune
char *get_fortune() {
    // Seed the random number generator
    srand(time(NULL));

    // Get a random number between 0 and the number of fortunes
    int random_number = rand() % (sizeof(fortunes) / sizeof(char *));

    // Return the fortune at the random index
    return fortunes[random_number];
}

// Print the fortune to the console
void print_fortune() {
    // Get a random fortune
    char *fortune = get_fortune();

    // Print the fortune to the console
    printf("Your fortune is: %s\n", fortune);
}

int main() {
    // Print a welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Prompt the user to enter their name
    printf("What is your name? ");
    char name[256];
    scanf("%s", name);

    // Print a personalized fortune
    printf("Your fortune, %s, is: %s\n", name, get_fortune());

    return 0;
}