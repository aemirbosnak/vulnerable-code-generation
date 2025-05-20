//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWERS 5
#define MAX_PATH_LENGTH 50

typedef struct {
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswerIndex;
} Question;

void clearScreen() {
    printf("\033[H\033[J");
}

void printInstructions() {
    printf("Welcome to 'Journey of the Mind'!\n");
    printf("Answer the following questions to navigate your mind.\n");
    printf("Try to find the correct path to discover yourself!\n\n");
}

void askQuestion(Question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i + 1, q->answers[i]);
    }
}

int getPlayerAnswer() {
    int choice;
    printf("Your choice (1-%d): ", MAX_ANSWERS);
    scanf("%d", &choice);
    return choice - 1; // Convert to 0-based index
}

void navigatePath(int pathNumber) {
    switch (pathNumber) {
        case 0:
            printf("You have chosen the path of Reflection! You feel calm and grounded.\n");
            break;
        case 1:
            printf("You have chosen the path of Anxiety! You feel a surge of unease...\n");
            break;
        case 2:
            printf("You have chosen the path of Joy! You feel an excitement bubbling within you...\n");
            break;
        case 3:
            printf("You have chosen the path of Sadness. You feel a heaviness in your heart.\n");
            break;
        case 4:
            printf("You have chosen the path of Inspiration! You are filled with creativity and hope.\n");
            break;
        default:
            printf("An unknown path. You wander aimlessly...\n");
            break;
    }
}

int main() {
    clearScreen();
    printInstructions();

    Question questions[3] = {
        {
            "How do you feel today?",
            {"Calm", "Uneasy", "Excited", "Sad", "Inspired"},
            0
        },
        {
            "What do you seek?",
            {"Clarity", "Comfort", "Adventure", "Connection", "Creativity"},
            1
        },
        {
            "What is your greatest concern?",
            {"The future", "Loneliness", "Failure", "Acceptance", "Growth"},
            2
        }
    };

    int score = 0;

    for (int i = 0; i < 3; i++) {
        askQuestion(&questions[i]);
        int answerIndex = getPlayerAnswer();
        
        if (answerIndex == questions[i].correctAnswerIndex) {
            score++;
            printf("Correct choice! You resonate with this path.\n\n");
        } else {
            printf("Not quite. But every choice is a learning experience.\n\n");
        }
    }

    printf("Your total score: %d out of 3\n", score);
    printf("Based on your answers, you will now navigate your chosen path...\n");

    int finalPath = score; // Using score to determine final path
    navigatePath(finalPath);

    printf("\nThank you for embarking on this journey of self-discovery. Goodbye!\n");

    return 0;
}