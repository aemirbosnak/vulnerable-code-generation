//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

void greet_user() {
    printf("🎉 Welcome to the Magical Arithmetic Adventure! 🎉\n");
    printf("🌟 Let's explore numbers and make some cheerful calculations! 🌟\n");
}

int get_random_number() {
    return rand() % MAX_NUM + 1; // Random number between 1 and MAX_NUM
}

void display_arithmetic_operations(int num1, int num2) {
    printf("\n✨ Performing arithmetic operations with %d and %d... ✨\n", num1, num2);
    printf("🤩 Addition: %d + %d = %d\n", num1, num2, num1 + num2);
    printf("🤓 Subtraction: %d - %d = %d\n", num1, num2, num1 - num2);
    printf("🙃 Multiplication: %d * %d = %d\n", num1, num2, num1 * num2);
    if (num2 != 0) {
        printf("😇 Division: %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
    } else {
        printf("😱 Division: We can't divide by zero! Let's skip this one!\n");
    }
}

void show_welcome_statistics(int totalOperations, int successCount) {
    printf("\n🤩✨ You've performed %d operations with %d successful results! Great job! ✨🤩\n",
           totalOperations, successCount);
}

void play_game() {
    int totalOperations = 0;
    int successCount = 0;
    char continueGame = 'y';

    while (continueGame == 'y') {
        int num1 = get_random_number();
        int num2 = get_random_number();

        display_arithmetic_operations(num1, num2);
        totalOperations++;

        // Simulating success or failure in some operations
        if (num1 + num2 > MAX_NUM / 2) {
            successCount++;
        }

        printf("\n🎈 Would you like to try another set of numbers? (y/n): ");
        scanf(" %c", &continueGame);
    }

    show_welcome_statistics(totalOperations, successCount);
    printf("🎊 Thanks for playing! Keep smiling and calculating! 🎊\n");
}

int main() {
    srand(time(NULL)); // Seeding the random number generator
    greet_user();
    play_game();
    return 0;
}