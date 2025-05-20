//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

void displayMenu() {
    printf("Welcome to the Paranormal Arithmetic Challenge!\n");
    printf("You will be faced with a series of cryptic arithmetic problems.\n");
    printf("Solve them correctly to prove your intelligence...\n");
    printf("But beware! Mistakes may come with dire consequences!\n");
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int generateQuestion() {
    int num1 = getRandomNumber(1, 100);
    int num2 = getRandomNumber(1, 100);
    char operators[] = {'+', '-', '*', '/'};
    char selectedOperator = operators[getRandomNumber(0, 3)];
    
    switch (selectedOperator) {
        case '+':
            printf("What is %d + %d?\n", num1, num2);
            return num1 + num2;
        case '-':
            printf("What is %d - %d?\n", num1, num2);
            return num1 - num2;
        case '*':
            printf("What is %d * %d?\n", num1, num2);
            return num1 * num2;
        case '/':
            if (num2 == 0) num2++; // Avoid division by zero
            printf("What is %d / %d (give integer result)?\n", num1, num2);
            return num1 / num2;
    }
    return 0; // Just a failsafe
}

void paranoiaMode() {
    printf("Is someone watching you? Stay focused...\n");
    printf("Oh, the pressure...\n");
}

void playGame() {
    int score = 0;
    int answer, correctAnswer;
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        correctAnswer = generateQuestion();
        printf("Your answer: ");
        
        if (scanf("%d", &answer) != 1) {
            printf("Interesting! But that's not a valid answer...\n");
            attempts++;
            continue;
        }

        if (answer == correctAnswer) {
            score++;
            printf("Correct! But stay alert, it might just be a trap!\n");
        } else {
            printf("Wrong answer! Are you trying to deceive me?\n");
            attempts++;
        }

        if (attempts < MAX_ATTEMPTS) {
            paranoiaMode();
        } else {
            printf("You've exhausted your chances... or have you?\n");
        }
    }

    printf("Your final score: %d\n", score);
    if (score < 3) {
        printf("Perhaps you need to rethink your strategy...\n");
    } else {
        printf("Well done! But always stay cautious...\n");
    }
}

int main() {
    srand(time(NULL));
    displayMenu();
    playGame();
    
    printf("Thank you for participating in the Paranormal Arithmetic Challenge!\n");
    printf("Remember, knowledge is power. Always question everything...\n");

    return 0;
}