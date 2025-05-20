//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TRIES 5

void welcomeUser() {
    printf("🎉 Welcome to the Ultimate Surprise Math Challenge! 🎉\n");
}

void generateRandomQuiz(int *a, int *b) {
    *a = rand() % 20 + 1;  // Random number between 1 and 20
    *b = rand() % 20 + 1;  // Random number between 1 and 20
}

void askQuestion(int a, int b) {
    printf("What is %d + %d? ", a, b);
}

int getAnswer() {
    int answer;
    scanf("%d", &answer);
    return answer;
}

void checkAnswer(int userAns, int correctAns) {
    if (userAns == correctAns) {
        printf("🎉 Correct! You are a math genius! 🎉\n");
    } else {
        printf("😢 Oops! That's not right! The correct answer was %d.\n", correctAns);
    }
}

void surpriseChallenge(int a, int b) {
    printf("🔔 Surprise Challenge! Now, what is %d * %d? ", a, b);
    int userAns = getAnswer();
    int correctAns = a * b;
    checkAnswer(userAns, correctAns);
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    welcomeUser();

    int totalPoints = 0;
    int tries = 0;
    char playAgain = 'y';

    while (playAgain == 'y') {
        int a, b;
        generateRandomQuiz(&a, &b);
        askQuestion(a, b);
        
        // Get the user's answer
        int userAns = getAnswer();
        int correctAns = a + b;
        checkAnswer(userAns, correctAns);
        
        if (userAns == correctAns) {
            totalPoints += 1;
            surpriseChallenge(a, b);
        }
        
        tries++;
        if (tries >= MAX_TRIES) {
            printf("🤔 You've reached the maximum tries! Your total points: %d\n", totalPoints);
            break;
        }

        printf("Do you want to continue playing? (y/n) ");
        scanf(" %c", &playAgain);
    }

    printf("🎊 Thank you for playing! You scored a total of %d points! 🎊\n", totalPoints);
    return 0;
}