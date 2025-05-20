//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question structure
typedef struct Question {
    char question[100];
    char options[4][100];
    int correct_option;
} Question;

// Exam structure
typedef struct Exam {
    char name[100];
    int num_questions;
    Question questions[100];
} Exam;

// Function to create a new question
Question create_question() {
    Question question;
    printf("Enter the question: ");
    scanf(" %[^\n]", question.question);
    printf("Enter the four options: ");
    for (int i = 0; i < 4; i++) {
        scanf(" %[^\n]", question.options[i]);
    }
    printf("Enter the correct option (1-4): ");
    scanf(" %d", &question.correct_option);
    return question;
}

// Function to create a new exam
Exam create_exam() {
    Exam exam;
    printf("Enter the exam name: ");
    scanf(" %[^\n]", exam.name);
    printf("Enter the number of questions: ");
    scanf(" %d", &exam.num_questions);
    for (int i = 0; i < exam.num_questions; i++) {
        exam.questions[i] = create_question();
    }
    return exam;
}

// Function to take the exam
void take_exam(Exam exam) {
    int score = 0;
    for (int i = 0; i < exam.num_questions; i++) {
        printf("%s\n", exam.questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, exam.questions[i].options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf(" %d", &answer);
        if (answer == exam.questions[i].correct_option) {
            score++;
        }
    }
    printf("Your score is %d out of %d\n", score, exam.num_questions);
}

// Function to save the exam to a file
void save_exam(Exam exam) {
    FILE *fp = fopen("exam.txt", "w");
    fprintf(fp, "%s\n", exam.name);
    fprintf(fp, "%d\n", exam.num_questions);
    for (int i = 0; i < exam.num_questions; i++) {
        fprintf(fp, "%s\n", exam.questions[i].question);
        for (int j = 0; j < 4; j++) {
            fprintf(fp, "%s\n", exam.questions[i].options[j]);
        }
        fprintf(fp, "%d\n", exam.questions[i].correct_option);
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("1. Create new exam\n");
        printf("2. Take exam\n");
        printf("3. Save exam\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                create_exam();
                break;
            case 2:
                take_exam(create_exam());
                break;
            case 3:
                save_exam(create_exam());
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}