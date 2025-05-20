//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void additionChallenge();
void subtractionChallenge();
void multiplicationChallenge();
void divisionChallenge();
void displayScore(int score, int challenges);
void displayMenu();

int main() {
    int choice;
    int totalChallenges = 0;
    int correctAnswers = 0;

    srand(time(0)); // Seed random number generation

    printf("Welcome to the Math Challenge Program!\n");
    do {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                additionChallenge();
                correctAnswers++; totalChallenges++;
                break;
            case 2:
                subtractionChallenge();
                correctAnswers++; totalChallenges++;
                break;
            case 3:
                multiplicationChallenge();
                correctAnswers++; totalChallenges++;
                break;
            case 4:
                divisionChallenge();
                correctAnswers++; totalChallenges++;
                break;
            case 5:
                displayScore(correctAnswers, totalChallenges);
                break;
            case 0:
                printf("Exiting the Math Challenge. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n*** Math Challenges ***\n");
    printf("1. Addition Challenge\n");
    printf("2. Subtraction Challenge\n");
    printf("3. Multiplication Challenge\n");
    printf("4. Division Challenge\n");
    printf("5. Show Score\n");
    printf("0. Exit\n");
}

void additionChallenge() {
    int a = rand() % 100;
    int b = rand() % 100;
    int answer;

    printf("What is %d + %d? ", a, b);
    scanf("%d", &answer);

    if (answer == a + b) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %d.\n", a + b);
    }
}

void subtractionChallenge() {
    int a = rand() % 100;
    int b = rand() % 100;
    int answer;

    // Ensure a >= b for positive results
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("What is %d - %d? ", a, b);
    scanf("%d", &answer);

    if (answer == a - b) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %d.\n", a - b);
    }
}

void multiplicationChallenge() {
    int a = rand() % 12; // Keep numbers small for multiplication
    int b = rand() % 12;
    int answer;

    printf("What is %d * %d? ", a, b);
    scanf("%d", &answer);

    if (answer == a * b) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %d.\n", a * b);
    }
}

void divisionChallenge() {
    int a = rand() % 100 + 1; // Avoid zero for division
    int b = rand() % 10 + 1;  // Avoid zero for division
    int answer;

    printf("What is %d / %d? (Give your answer up to two decimals) ", a, b);
    float correctAnswer = (float)a / b;
    scanf("%d", &answer);

    if ((float)answer == correctAnswer) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer is %.2f.\n", correctAnswer);
    }
}

void displayScore(int score, int challenges) {
    printf("\nYou answered %d out of %d challenges correctly!\n", score, challenges);
    float percentage = (float)score / challenges * 100;
    printf("Your score percentage is %.2f%%.\n", percentage);
}