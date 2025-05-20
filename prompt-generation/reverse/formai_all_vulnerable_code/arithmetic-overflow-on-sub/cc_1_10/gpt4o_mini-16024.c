//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

// Struct to hold information about a quiz question
typedef struct {
    char question[100];
    char options[4][50];
    int answer; // index of the correct answer (0, 1, 2, or 3)
} QuizQuestion;

// Function to print the welcome message
void printWelcome() {
    printf("🎉 Welcome to the Cheerful Quiz Game! 🎉\n");
    printf("Answer the questions and rack up those points! Let's get started! 🌟\n\n");
}

// Function to display a question and capture the user's answer
int askQuestion(QuizQuestion q) {
    printf("Question: %s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d: %s\n", i + 1, q.options[i]);
    }
    printf("Your answer (1-4): ");
    int answer;
    scanf("%d", &answer);
    return answer - 1; // Convert 1-4 to 0-3 for indexing
}

// Function to calculate score
void displayScore(int score) {
    printf("\n🎯 Your final score is: %d out of %d! 🎯\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("🏆 Perfect score! You're a quiz master! 🏆\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("👏 Well done! You have good general knowledge! 👏\n");
    } else {
        printf("😢 Don't worry, practice makes perfect! Try again! 😢\n");
    }
}

int main() {
    // Initializing the quiz questions
    QuizQuestion quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Lisbon"}, 
            2},
        {"Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Saturn"}, 
            1},
        {"What is 2 + 2?",
            {"3", "4", "1", "5"}, 
            1},
        {"Who wrote 'Romeo and Juliet'?",
            {"Charles Dickens", "Harper Lee", "William Shakespeare", "Mark Twain"}, 
            2},
        {"What is the largest ocean on Earth?",
            {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"}, 
            3}
    };

    int score = 0; // To keep track of the user's score
    int userAnswer;

    // Start the game
    printWelcome();

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        userAnswer = askQuestion(quiz[i]);

        // Check if the user's answer is correct
        if (userAnswer == quiz[i].answer) {
            printf("🎉 Correct! 🎉\n");
            score++;
        } else {
            printf("😢 Sorry, the right answer was: %s\n\n", quiz[i].options[quiz[i].answer]);
        }
        printf("\n");
    }

    // Display the final score
    displayScore(score);

    // Cheerful exit message
    printf("\nThank you for playing the Cheerful Quiz Game! 🌈\n");
    printf("Have a great day! 😊\n");

    return 0; // Indicate that the program finished successfully
}