//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    int range = max - min + 1;
    int result = rand() % range;
    return result + min;
}

// Array of fortunes
const char *fortunes[MAX_FORTUNES] = {
    "The universe is a friendly place. Believe in it.",
    "You will find a treasure today.",
    "Your hard work will pay off.",
    "You are on the right path.",
    "Good things are coming your way.",
    "Trust your instincts.",
    "A surprise awaits you.",
    "You will meet an interesting person.",
    "Your creativity will be rewarded.",
    "Your luck is changing for the better."
};

int main() {
    srand(time(NULL)); // Seed the random number generator

    int user_input;
    printf("Enter a number between 1 and %d: ", MAX_FORTUNES);
    scanf("%d", &user_input);

    // Check if user input is within the valid range
    if (user_input < 1 || user_input > MAX_FORTUNES) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Generate a random number and provide the corresponding fortune
    int random_number = rand_range(1, MAX_FORTUNES);
    if (user_input == random_number) {
        printf("Congratulations! Your fortune is: %s\n", fortunes[user_input-1]);
    } else {
        printf("Sorry, the fortune for %d is: %s\n", random_number, fortunes[random_number-1]);
        printf("But based on your input, here's your fortune: %s\n", fortunes[user_input-1]);
    }

    return 0;
}