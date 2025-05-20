//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fortunes
char *fortunes[] = {
    "You will have a prosperous day!",
    "A new opportunity will come your way!",
    "You will find love in unexpected places!",
    "Your hard work will pay off soon!",
    "You will receive good news today!",
    "A friend will offer you help when you need it most!",
    "You will overcome a challenge with ease!",
    "Your creativity will shine through today!",
    "You will have a peaceful and relaxing day!",
    "Today is a great day to start something new!"
};

// Function to generate a random number within a range
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a fortune
void print_fortune(char *fortune) {
    printf("%s\n", fortune);
}

// Main function
int main() {
    int num_fortunes;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of fortunes they want to receive
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &num_fortunes);

    // Loop through and print the requested number of fortunes
    for (int i = 0; i < num_fortunes; i++) {
        // Generate a random index into the fortunes array
        int index = rand_int(0, sizeof(fortunes) / sizeof(fortunes[0]) - 1);

        // Print the fortune
        print_fortune(fortunes[index]);

        // Ask the user if they want to continue
        printf("Would you like to receive another fortune? (y/n) ");
        scanf(" %c", &choice);

        // If the user doesn't want to continue, break out of the loop
        if (choice!= 'y' && choice!= 'Y') {
            break;
        }
    }

    return 0;
}