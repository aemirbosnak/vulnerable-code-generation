//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number within a specified range
int randRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Initialize random seed

    // Array of fortune messages
    char fortuneMessages[][200] = {
        "You will soon embark on a great adventure.",
        "The decisions you make today will have a big impact on your future.",
        "Your hard work will pay off in the end.",
        "Be patient, good things come to those who wait.",
        "You will meet someone special soon.",
        "You will achieve great success in your career.",
        "Your creativity will lead you to great things.",
        "A new opportunity will arise that will change your life for the better.",
        "Your kindness will be rewarded in unexpected ways.",
        "Be open to new experiences, they will bring you happiness."
    };

    int numMessages = sizeof(fortuneMessages) / sizeof(fortuneMessages[0]);

    // Prompt user for their name
    char name[50];
    printf("Welcome to the Automated Fortune Teller! What is your name? ");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0'; // Remove newline character

    printf("\nHello, %s! I am here to tell you your fortune.\n", name);

    // Loop until user decides to quit
    while (1) {
        printf("\nEnter 'q' to quit or any other key to get your fortune: ");
        char input[2];
        fgets(input, 2, stdin);

        if (input[0] == 'q') {
            printf("\nThank you for using the Automated Fortune Teller. Goodbye, %s!\n", name);
            break;
        }

        // Generate a random number to pick a fortune message from the array
        int index = randRange(0, numMessages - 1);
        printf("\n%s\n", fortuneMessages[index]);
    }

    return 0;
}