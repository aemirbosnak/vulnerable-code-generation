//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

void lengthConverter();
void weightConverter();
void temperatureConverter();
void displayMenu();
int playerTurn(int playerNum);
void endGame();

int main() {
    int choice;
    int playerCount;

    printf("Welcome to the Multiplayer Unit Converter!\n");
    printf("Please enter number of players: ");
    scanf("%d", &playerCount);

    while (1) {
        displayMenu();
        printf("Players, select a conversion category: ");
        scanf("%d", &choice);
        
        if (choice == 4) {
            endGame();
            break;
        }

        for (int i = 1; i <= playerCount; i++) {
            int player = playerTurn(i);
            if (player == 4) {
                endGame();
                return 0;
            }
            switch (choice) {
                case 1:
                    lengthConverter();
                    break;
                case 2:
                    weightConverter();
                    break;
                case 3:
                    temperatureConverter();
                    break;
                default:
                    printf("Invalid choice. Please try again!\n");
            }
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nUnit Converter Menu:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
}

int playerTurn(int playerNum) {
    int choice;
    printf("Player %d's turn:\n", playerNum);
    printf("Commit your choice (1 for Convert, 2 for Skip, 3 for Show Menu, 4 to Exit): ");
    scanf("%d", &choice);
    return choice;
}

void lengthConverter() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("%.2lf meters is equal to %.2lf feet\n", meters, feet);
}

void weightConverter() {
    double kg, lbs;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    lbs = kg * 2.20462;
    printf("%.2lf kilograms is equal to %.2lf pounds\n", kg, lbs);
}

void temperatureConverter() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", celsius, fahrenheit);
}

void endGame() {
    printf("Thank you for playing the Multiplayer Unit Converter!\n");
    printf("Goodbye!\n");
}