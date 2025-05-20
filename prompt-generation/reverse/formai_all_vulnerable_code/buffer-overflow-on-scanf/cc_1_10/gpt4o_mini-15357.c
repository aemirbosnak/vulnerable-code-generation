//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_QUESTIONS 5

// Structure for a quiz question
typedef struct {
    char question[256];
    char options[4][100];
    int correctAnswer; // Index of the correct option (0-3)
} QuizQuestion;

// Function prototypes
void displayQuestion(QuizQuestion q);
int getUserAnswer();
void displayResult(int score);

int main() {
    // Array of quiz questions
    QuizQuestion quiz[NUM_QUESTIONS] = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Lisbon"},
            2
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Saturn"},
            1
        },
        {
            "What is the largest mammal in the world?",
            {"Elephant", "Blue Whale", "Great White Shark", "Giraffe"},
            1
        },
        {
            "Which famous scientist developed the theory of relativity?",
            {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"},
            1
        },
        {
            "What element does 'O' represent on the periodic table?",
            {"Gold", "Oxygen", "Osmium", "Opal"},
            1
        }
    };

    int score = 0;

    // Welcome message
    printf("🎉 Welcome to the Happy Quiz Game! 🎉\n\n");

    // Loop through each question
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        displayQuestion(quiz[i]);
        int userAnswer = getUserAnswer();

        // Check if the answer is correct
        if (userAnswer == quiz[i].correctAnswer) {
            printf("🎉 Correct! 🎉\n\n");
            score++;
        } else {
            printf("😢 Sorry, that's incorrect. The correct answer was: %s\n\n", quiz[i].options[quiz[i].correctAnswer]);
        }
    }

    // Display final result
    displayResult(score);
    return 0;
}

// Function to display a quiz question
void displayQuestion(QuizQuestion q) {
    printf("Question: %s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

// Function to get user answer
int getUserAnswer() {
    int answer;
    printf("Enter your answer (1-4): ");
    
    while (1) {
        // Check if input is a valid integer
        if (scanf("%d", &answer) == 1 && answer >= 1 && answer <= 4) {
            break;
        } else {
            printf("🚫 Please enter a valid option (1-4): ");
            while(getchar() != '\n'); // Clear invalid input
        }
    }
    
    return answer - 1; // Convert to zero-based index
}

// Function to display the final result
void displayResult(int score) {
    printf("🌟 Quiz Completed! 🌟\n");
    printf("Your score: %d out of %d\n", score, NUM_QUESTIONS);
    float percentage = ((float)score / NUM_QUESTIONS) * 100;
    printf("You scored: %.2f%%\n", percentage);
    
    if (percentage == 100.0) {
        printf("🎊 Perfect score! You're a genius! 🎊\n");
    } else if (percentage >= 80.0) {
        printf("🥳 Great job! You're really smart! 🥳\n");
    } else if (percentage >= 50.0) {
        printf("😊 Not bad! Keep up the good work! 😊\n");
    } else {
        printf("😅 Don’t worry! Practice makes perfect! 😅\n");
    }
}