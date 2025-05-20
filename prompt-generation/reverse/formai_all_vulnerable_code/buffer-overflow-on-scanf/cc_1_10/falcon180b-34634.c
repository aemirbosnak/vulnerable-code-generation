//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to generate a random fortune
void generate_fortune(char *fortune) {
    const char *fortunes[] = {
        "You will have a great day!",
        "Good things are coming your way!",
        "Your hard work will pay off soon!",
        "You will find love in unexpected places!",
        "A new opportunity is waiting for you!",
        "Your future is bright and full of possibilities!",
        "You are a shining star, keep shining bright!",
        "Believe in yourself and all that you are!",
        "Success is just around the corner, keep going!",
        "You are loved and appreciated, never forget that!"
    };

    int rand_index = rand() % 10;
    strcpy(fortune, fortunes[rand_index]);
}

// Function to display a fortune
void display_fortune(const char *fortune) {
    printf("\nYour fortune:\n%s\n", fortune);
}

// Function to get user input for their name
void get_name(char *name) {
    printf("What is your name? ");
    scanf("%s", name);
}

int main() {
    char name[MAX_LENGTH];
    char fortune[MAX_LENGTH];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the user's name
    get_name(name);

    // Generate a random fortune
    generate_fortune(fortune);

    // Display the fortune with a personalized message
    printf("Hello %s!\n", name);
    printf("I am your personal fortune teller.\n");
    printf("Today's fortune for you:\n");
    display_fortune(fortune);

    return 0;
}