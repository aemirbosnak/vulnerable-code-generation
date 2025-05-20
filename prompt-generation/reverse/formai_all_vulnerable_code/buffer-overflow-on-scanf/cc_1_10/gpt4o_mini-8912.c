//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void displayInstruct();
int generateRandomNumber(int min, int max);
void analyzeBirthYear(int year, int *fortune);
void analyzeName(char *name, int *fortune);
void generateFortune(int fortune);

int main() {
    int year, fortune = 0;
    char name[50];

    // Seed the random number generator
    srand(time(0));

    // Display instructions to the user
    displayInstruct();

    // Get user input for birth year
    printf("Enter your birth year (YYYY): ");
    scanf("%d", &year);
    analyzeBirthYear(year, &fortune);

    // Get user input for name
    printf("Enter your name: ");
    scanf("%s", name);
    analyzeName(name, &fortune);

    // Generate and display the user's fortune
    generateFortune(fortune);

    return 0;
}

// Function to display instructions
void displayInstruct() {
    printf("Welcome to the Mathematical Fortune Teller!\n");
    printf("This program predicts your fortune based on your birth year and name.\n\n");
}

// Function to generate a random number within a specified range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to analyze birth year
void analyzeBirthYear(int year, int *fortune) {
    int digitSum = 0;

    while (year > 0) {
        digitSum += year % 10;
        year /= 10;
    }

    // Using the sum of digits to influence fortune
    *fortune += digitSum % 5;
}

// Function to analyze name
void analyzeName(char *name, int *fortune) {
    int nameValue = 0;

    // Simple algorithm to calculate a numeric value from the name
    for (int i = 0; name[i] != '\0'; i++) {
        nameValue += name[i] - 'a' + 1; // Assuming lowercase letters
    }

    *fortune += nameValue % 5;
}

// Function to generate and display the user's fortune
void generateFortune(int fortune) {
    switch (fortune % 5) {
        case 0:
            printf("Your fortune: Today is a great day for new beginnings!\n");
            break;
        case 1:
            printf("Your fortune: Be cautious of unexpected changes.\n");
            break;
        case 2:
            printf("Your fortune: A surprise gift is on its way to you.\n");
            break;
        case 3:
            printf("Your fortune: Trust your instincts; they will guide you well.\n");
            break;
        case 4:
            printf("Your fortune: Collaborate with others; teamwork brings the best results.\n");
            break;
        default:
            printf("An error occurred; please try again.\n");
            break;
    }
}