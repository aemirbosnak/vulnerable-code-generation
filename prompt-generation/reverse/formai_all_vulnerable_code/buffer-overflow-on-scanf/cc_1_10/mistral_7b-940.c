//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define NUM_FORTUNES 7

// Struct to store fortune and corresponding condition
typedef struct {
    int condition;
    char* fortune;
} Fortune;

// Array of fortunes and their conditions
Fortune fortunes[NUM_FORTUNES] = {
    {3, "Love is a rose, its thorns will pierce your heart, but its sweet perfume will keep you coming back for more."},
    {4, "Your heart belongs to another, but fate has a way of bringing you together."},
    {5, "Patience and trust will lead you to a deep and meaningful connection."},
    {6, "Joy and happiness will fill your days, as you and your beloved grow closer than ever."},
    {7, "Your love is strong and true, and will weather any storm that comes your way."},
    {8, "A secret admirer awaits, but beware, for love can be a dangerous game."},
    {9, "Your heart is closed off, but a chance encounter may change everything."}
};

// Function to generate a random number between 1 and 9
int rollDice() {
    return rand() % 9 + 1;
}

// Function to get the fortune based on name and dice roll
void getFortune(char name[MAX_NAME_LENGTH]) {
    int roll = rollDice();
    int i;

    for (i = 0; i < NUM_FORTUNES; i++) {
        if (roll == fortunes[i].condition) {
            printf("%s\n", fortunes[i].fortune);
            printf("Your fortune for the day, %s:\n", name);
            return;
        }
    }

    // If no fortune is found, display a generic message
    printf("I'm sorry, I couldn't find a fortune for you, %s.\n", name);
}

int main() {
    char name[MAX_NAME_LENGTH];
    int i;

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("Enter your name: ");
    scanf("%s", name);

    getFortune(name);

    // Display all fortunes for fun
    for (i = 0; i < NUM_FORTUNES; i++) {
        printf("%d. %s\n", i + 1, fortunes[i].fortune);
    }

    return 0;
}