//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
int getRandomNumber(int min, int max);
void clearScreen();

// Main function
int main() {
    int choice;
    do {
        clearScreen();
        displayMenu();
        printf("Enter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("=====================================\n");
    printf("       Retro Math Challenge         \n");
    printf("=====================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("0. Exit\n");
}

// Function to perform addition
void performAddition() {
    int num1 = getRandomNumber(1, 100);
    int num2 = getRandomNumber(1, 100);
    int answer;

    printf("\nWhat is %d + %d? ", num1, num2);
    printf("\nYour answer: ");
    scanf("%d", &answer);

    if (answer == (num1 + num2)) {
        printf("Correct! %d + %d = %d\n", num1, num2, num1 + num2);
    } else {
        printf("Incorrect! The correct answer is %d\n", num1 + num2);
    }
    printf("Press Enter to continue...");
    getchar(); getchar(); // Wait for user input
}

// Function to perform subtraction
void performSubtraction() {
    int num1 = getRandomNumber(1, 100);
    int num2 = getRandomNumber(1, num1); // Ensure num2 <= num1
    int answer;

    printf("\nWhat is %d - %d? ", num1, num2);
    printf("\nYour answer: ");
    scanf("%d", &answer);

    if (answer == (num1 - num2)) {
        printf("Correct! %d - %d = %d\n", num1, num2, num1 - num2);
    } else {
        printf("Incorrect! The correct answer is %d\n", num1 - num2);
    }
    printf("Press Enter to continue...");
    getchar(); getchar();
}

// Function to perform multiplication
void performMultiplication() {
    int num1 = getRandomNumber(1, 10);
    int num2 = getRandomNumber(1, 10);
    int answer;

    printf("\nWhat is %d * %d? ", num1, num2);
    printf("\nYour answer: ");
    scanf("%d", &answer);

    if (answer == (num1 * num2)) {
        printf("Correct! %d * %d = %d\n", num1, num2, num1 * num2);
    } else {
        printf("Incorrect! The correct answer is %d\n", num1 * num2);
    }
    printf("Press Enter to continue...");
    getchar(); getchar();
}

// Function to perform division
void performDivision() {
    int num1 = getRandomNumber(1, 100);
    int num2 = getRandomNumber(1, 10); // Avoid division by zero
    int answer;

    printf("\nWhat is %d / %d? (Provide answer as an integer): ", num1, num2);
    printf("\nYour answer: ");
    scanf("%d", &answer);

    if (answer == (num1 / num2)) {
        printf("Correct! %d / %d = %d\n", num1, num2, num1 / num2);
    } else {
        printf("Incorrect! The correct answer is %d\n", num1 / num2);
    }
    printf("Press Enter to continue...");
    getchar(); getchar();
}

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }
    return rand() % (max - min + 1) + min;
}

// Function to clear the terminal screen
void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the terminal
}