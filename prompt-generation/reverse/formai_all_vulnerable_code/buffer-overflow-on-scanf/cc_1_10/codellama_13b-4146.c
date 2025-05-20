//Code Llama-13B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
/*
 * Automated Fortune Teller Program
 *
 * This program generates a random fortune cookie message for the user.
 * The user can input their name and their birthday to receive a personalized fortune.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Fortune cookie messages
char *fortunes[] = {
    "You will soon have a new experience.",
    "You will be happy in your work.",
    "You will soon have a new adventure.",
    "You will be successful in your career.",
    "You will have a new opportunity.",
    "You will soon have a new friend.",
    "You will soon have a new hobby.",
    "You will be happy in your relationships.",
    "You will soon have a new challenge.",
    "You will be successful in your personal life.",
};

// Function to generate a random fortune cookie message
char *generate_fortune(void) {
    srand(time(NULL));
    int fortune_index = rand() % (sizeof(fortunes) / sizeof(char *));
    return fortunes[fortune_index];
}

int main(void) {
    // Get the user's name and birthday
    char name[100];
    char birthday[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your birthday (DD-MM-YYYY): ");
    scanf("%s", birthday);

    // Generate a random fortune cookie message
    char *fortune = generate_fortune();

    // Print the fortune cookie message with the user's name and birthday
    printf("Here is your fortune, %s:\n", name);
    printf("\"%s\"\n", fortune);
    printf("Happy %s!\n", birthday);

    return 0;
}