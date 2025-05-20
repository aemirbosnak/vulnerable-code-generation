//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message() {
    printf("🎉 Welcome to the Happy Math Exercise Game! 🎉\n");
    printf("Get ready to have some fun while practicing your math skills!\n");
    printf("You'll be given math questions, and let's see how many you can get right! 😊\n");
    printf("Let's begin! 🚀\n\n");
}

void print_score(int score, int total) {
    printf("Your current score is: %d out of %d\n", score, total);
    printf("🌈 Keep up the good work! 🌈\n");
}

int addition_question() {
    int a = rand() % 100;
    int b = rand() % 100;
    printf("What is %d + %d? ", a, b);
    return a + b;
}

int multiplication_question() {
    int a = rand() % 12;
    int b = rand() % 12;
    printf("What is %d * %d? ", a, b);
    return a * b;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int score = 0;
    int total_questions = 5; // Number of questions to ask
    int answer, correct_answer;

    print_welcome_message();

    for (int i = 1; i <= total_questions; i++) {
        printf("\nQuestion %d:\n", i);
        
        // Select a question type randomly
        if (rand() % 2 == 0) {
            correct_answer = addition_question();
        } else {
            correct_answer = multiplication_question();
        }

        printf("Your answer: ");
        scanf("%d", &answer);

        if (answer == correct_answer) {
            printf("🎉 Correct! 🎉 You're doing great!\n");
            score++;
        } else {
            printf("😢 Oops! The correct answer was %d.\n", correct_answer);
        }

        print_score(score, i);
    }

    printf("\n🌟 Game Over! 🌟\n");
    printf("You scored %d out of %d.\n", score, total_questions);
    
    // Display a message based on the user's performance
    if (score == total_questions) {
        printf("Amazing! You're a math wizard! 🧙‍♂️✨\n");
    } else if (score >= total_questions / 2) {
        printf("Great job! Keep practicing and you'll become even better! 👍\n");
    } else {
        printf("Don't give up! Practice makes perfect! You can do it! 💪\n");
    }

    printf("\nThank you for playing the Happy Math Exercise Game! Come back soon! 🎈\n");
    return 0;
}