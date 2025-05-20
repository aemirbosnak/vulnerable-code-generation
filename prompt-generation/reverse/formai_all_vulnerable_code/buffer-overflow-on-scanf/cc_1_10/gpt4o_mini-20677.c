//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showGreeting() {
    printf("🎉 Welcome to the Cheerful Quiz Game! 🎉\n");
    printf("Let's test your knowledge and have some fun!\n\n");
}

void showQuestion(int questionNumber) {
    switch (questionNumber) {
        case 1:
            printf("Question 1: What is the capital of France?\n");
            printf("a) London\nb) Paris\nc) Rome\nd) Berlin\n");
            break;
        case 2:
            printf("Question 2: Which planet is known as the Red Planet?\n");
            printf("a) Earth\nb) Mars\nc) Jupiter\nd) Venus\n");
            break;
        case 3:
            printf("Question 3: Who wrote 'Hamlet'?\n");
            printf("a) Charles Dickens\nb) William Shakespeare\nc) Mark Twain\nd) J.K. Rowling\n");
            break;
        case 4:
            printf("Question 4: What is the smallest prime number?\n");
            printf("a) 1\nb) 2\nc) 3\nd) 4\n");
            break;
        case 5:
            printf("Question 5: How many continents are there on Earth?\n");
            printf("a) 5\nb) 6\nc) 7\nd) 8\n");
            break;
        default:
            printf("🤔 Hmm, it seems to be an extra question!\n");
            break;
    }
}

char getUserAnswer() {
    char answer;
    printf("Your answer (a/b/c/d): ");
    scanf(" %c", &answer);
    return answer;
}

void showResult(int score) {
    printf("\n🎊 Thank you for playing the Cheerful Quiz Game! 🎊\n");
    printf("Your total score is: %d out of 5\n", score);
    if (score == 5) {
        printf("🌟 Wow, you're a genius! 🌟\n");
    } else if (score >= 3) {
        printf("😊 Great job! You know your stuff! 😊\n");
    } else {
        printf("🤗 Keep trying! You'll get better every time! 🤗\n");
    }
}

int main() {
    showGreeting();
    
    int score = 0;
    char correctAnswers[5] = {'b', 'b', 'b', 'b', 'c'}; // Correct answers for the questions
    char userAnswer;

    for (int i = 0; i < 5; i++) {
        showQuestion(i + 1);
        userAnswer = getUserAnswer();

        if (userAnswer == correctAnswers[i]) {
            printf("🎉 Correct! Well done! 🎉\n");
            score++;
        } else {
            printf("😢 Oops! The correct answer was: %c\n\n", correctAnswers[i]);
        }
        
        printf("\n\n"); // Add space between questions for readability
    }

    showResult(score);
    printf("Goodbye! Have a cheerful day ahead! 🌈\n");
    return 0;
}