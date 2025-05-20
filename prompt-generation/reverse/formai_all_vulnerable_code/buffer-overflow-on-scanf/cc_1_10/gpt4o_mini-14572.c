//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntroduction();
int getUserInput(char *prompt);
int performArithmeticOperation(int a, int b, char op);
void printResults(int result);

int main() {
    char *characters[5] = {
        "The Great Mathematician",
        "The Enigmatic Alchemist",
        "The Curious Student",
        "The Time-Traveling Scholar",
        "The Wise Old Sage"
    };
    
    srand(time(NULL));
    int characterIndex = rand() % 5;
    
    printIntroduction(characters[characterIndex]);

    // Loop for puzzles
    for (int i = 0; i < 5; i++) {
        int a = rand() % 100 + 1; // Random number between 1 and 100
        int b = rand() % 100 + 1; // Random number between 1 and 100
        char operations[4] = {'+', '-', '*', '/'};
        char op = operations[rand() % 4];
        
        printf("\nChallenge %d: What is %d %c %d? ", i + 1, a, op, b);
        
        int userResult = getUserInput("Your answer: ");
        int correctResult = performArithmeticOperation(a, b, op);
        
        if (userResult == correctResult) {
            printf("Correct! Wisdom grows with every correct answer!\n");
        } else {
            printf("Incorrect... The shadows of ignorance linger in the air...\n");
            printf("The correct answer was: %d\n", correctResult);
        }
        
        // Small narrative twist after each challenge
        if (i == 2) {
            printf("As you solve the mysteries, a portal opens revealing secrets of the universe...\n");
        }
        
        if (i == 4) {
            printf("With your newfound knowledge, the characters gather around you, celebrating your wisdom!\n");
        }
    }

    printf("\nYour journey concludes as you step back into the normal realm...\n");
    return 0;
}

void printIntroduction(char *character) {
    printf("Welcome, traveler! You are in the realm of numbers where logic reigns supreme.\n");
    printf("A chosen one, guided by %s, shall embark on a journey of arithmetic wonders!\n", character);
}

int getUserInput(char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

int performArithmeticOperation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Division by zero is not allowed!\n");
                return 0;
            }
        default:
            printf("Unknown operation!\n");
            return 0;
    }
}

void printResults(int result) {
    printf("The result is: %d\n", result);
}