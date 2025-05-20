//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct question {
    char text[100];
    char options[4][50];
    int correct_option;
};

int main() {
    int score = 0;
    int num_questions;
    printf("Welcome to the Online Examination System\n");
    printf("Please enter the number of questions in the exam: ");
    scanf("%d", &num_questions);

    struct question exam_questions[num_questions];

    // Input questions and options
    for (int i=0; i<num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("Enter the question text: ");
        scanf(" %[^\n]%*c", exam_questions[i].text);
        printf("Enter the options (separated by comma): ");
        scanf("%[^'\n']s", exam_questions[i].options);
        printf("Enter the correct option number (1-%d): ", sizeof(exam_questions[i].options)/sizeof(exam_questions[i].options[0]));
        scanf("%d", &exam_questions[i].correct_option);
    }

    // Shuffle the questions
    srand(time(NULL));
    for (int i=num_questions-1; i>0; i--) {
        int j = rand() % (i+1);
        struct question temp = exam_questions[i];
        exam_questions[i] = exam_questions[j];
        exam_questions[j] = temp;
    }

    // Take the exam
    printf("\n\n--- Start Exam ---\n\n");

    for (int i=0; i<num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, exam_questions[i].text);
        printf("Options: ");
        for (int j=0; j<sizeof(exam_questions[i].options)/sizeof(exam_questions[i].options[0]); j++) {
            printf("%d) %s   ", j+1, exam_questions[i].options[j]);
        }
        int choice;
        printf("\nEnter the option number: ");
        scanf("%d", &choice);

        if (choice == exam_questions[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is option %d.\n", exam_questions[i].correct_option);
        }
    }

    printf("\n\n--- Exam Completed ---\n");
    printf("Your score out of %d is %d\n", num_questions, score);
    return 0;
}