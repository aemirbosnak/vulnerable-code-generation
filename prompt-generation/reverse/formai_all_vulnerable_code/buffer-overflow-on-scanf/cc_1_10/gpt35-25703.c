//FormAI DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
};

// function to display menu options
void display_menu() {
    printf("*********** ONLINE EXAMINATION SYSTEM ***********\n");
    printf("1. Take Exam\n");
    printf("2. Add Question\n");
    printf("3. Exit\n");
}

// function to take exam
void take_exam(struct Question *questions, int num_questions) {
    int score = 0;
    printf("\n*********** WELCOME TO THE EXAM ***********\n\n");
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);
        int choice;
        printf("Enter your answer (1-4): ");
        scanf("%d", &choice);
        if (choice == questions[i].answer) {
            score++;
        }
    }
    printf("\n*********** YOUR SCORE: %d out of %d ***********\n\n", score, num_questions);
}

// function to add a question
void add_question(struct Question *questions, int num_questions) {
    printf("\n*********** ADD QUESTION ***********\n\n");
    struct Question new_question;
    printf("Enter the question: ");
    getchar();
    fgets(new_question.question, 100, stdin);
    printf("Enter option 1: ");
    fgets(new_question.option1, 50, stdin);
    printf("Enter option 2: ");
    fgets(new_question.option2, 50, stdin);
    printf("Enter option 3: ");
    fgets(new_question.option3, 50, stdin);
    printf("Enter option 4: ");
    fgets(new_question.option4, 50, stdin);
    printf("Enter the correct answer (1-4): ");
    scanf("%d", &new_question.answer);
    questions[num_questions] = new_question;
    printf("\n*********** QUESTION ADDED ***********\n\n");
}

int main() {
    struct Question questions[100];
    int num_questions = 0;
    int choice;
    do {
        display_menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (num_questions == 0) {
                    printf("\n*********** ERROR: NO QUESTIONS FOUND ***********\n\n");
                    break;
                }
                take_exam(questions, num_questions);
                break;
            case 2:
                add_question(questions, num_questions);
                num_questions++;
                break;
            case 3:
                printf("\n*********** THANK YOU FOR USING THE SYSTEM ***********\n\n");
                break;
            default:
                printf("\n*********** ERROR: INVALID CHOICE ***********\n\n");
                break;
        }
    } while (choice != 3);
    return 0;
}