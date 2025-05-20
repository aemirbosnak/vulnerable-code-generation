//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10
#define MAX_NAME_LENGTH 50

// List of fortunes
const char* fortunes[MAX_FORTUNES] = {
    "You will find happiness in unexpected places.",
    "A stranger will become a lifelong friend.",
    "Success is on the horizon; keep pushing forward.",
    "Your talents will shine brightly; showcase them.",
    "Love is around the corner, and it's closer than you think.",
    "You will face a challenge that will teach you valuable lessons.",
    "A great opportunity will come your way soon.",
    "New beginnings are on the way; embrace them.",
    "Adventure awaits; don't be afraid to take the leap.",
    "Your efforts will soon bear fruit; keep up the hard work."
};

// Function to print a greeting
void greetUser() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter your name to receive your fortune: ");
}

// Function to get user's name
void getUserName(char *name) {
    fgets(name, MAX_NAME_LENGTH, stdin);
    // Remove newline character from the name
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }
}

// Function to generate a random index for fortunes
int generateRandomIndex() {
    return rand() % MAX_FORTUNES;
}

// Function to provide a fortune
void provideFortune(const char *name) {
    int index = generateRandomIndex();
    printf("\n%s, your fortune is: \" %s \"\n", name, fortunes[index]);
}

// Function to repeat the fortune telling process
void repeatFortuneTelling() {
    char choice;
    printf("Do you want to receive another fortune? (y/n): ");
    scanf(" %c", &choice); // Note: the space before %c to consume any trailing newline
    while (getchar() != '\n'); // Clear the input buffer

    if (choice == 'y' || choice == 'Y') {
        printf("\nGreat! Let's get you another fortune...\n");
    } else {
        printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
        exit(0);
    }
}

// Main function
int main() {
    srand(time(0)); // Seed random number generator

    char name[MAX_NAME_LENGTH];

    greetUser();
    getUserName(name);
    
    // Loop for fortune telling until the user decides to stop
    while (1) {
        provideFortune(name);
        repeatFortuneTelling();
    }

    return 0;
}