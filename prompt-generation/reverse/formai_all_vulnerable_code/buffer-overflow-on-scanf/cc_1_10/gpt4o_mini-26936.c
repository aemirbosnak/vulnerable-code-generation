//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[255];
    char options[4][255]; // Four options for each question
    int answer; // The index of the correct answer
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
    {"What is 2 + 2?", {"3", "4", "5", "6"}, 1},
    {"What is the largest planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2},
    {"Which element has the chemical symbol O?", {"Osmium", "Oxygen", "Gold", "Iron"}, 1},
    {"Who wrote 'Hamlet'?", {"Charles Dickens", "Mark Twain", "William Shakespeare", "John Keats"}, 2}
};

void displayQuestion(Question q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber + 1, q.question);
    for (int i = 0; i < 4; i++) {
        printf("  %d. %s\n", i + 1, q.options[i]);
    }
}

int getAnswer() {
    int choice;
    printf("Your answer (1-4): ");
    scanf("%d", &choice);
    return choice - 1; // converting to 0-based index
}

void takeExam() {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i], i);
        int userAnswer = getAnswer();
        
        if (userAnswer == questions[i].answer) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Wrong! The correct answer was: %s\n\n", questions[i].options[questions[i].answer]);
        }
    }
    
    printf("Your total score: %d out of %d\n", score, MAX_QUESTIONS);
    float percentage = ((float)score / MAX_QUESTIONS) * 100;
    printf("Percentage: %.2f%%\n", percentage);
    
    if (percentage >= 60) {
        printf("Status: Passed\n");
    } else {
        printf("Status: Failed\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("\nWelcome to the Online Examination System\n");
        printf("1. Take Exam\n");
        printf("2. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                takeExam();
                break;
            case 2:
                printf("Thank you for using the Online Examination System. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 2);
    
    return 0;
}