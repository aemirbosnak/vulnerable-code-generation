//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int q_id;
    char question[1000];
    char option_a[100];
    char option_b[100];
    char option_c[100];
    char option_d[100];
    char answer[100];
} question_t;

void print_question(question_t question){
    printf("%d. %s\n", question.q_id, question.question);
    printf("A. %s\n", question.option_a);
    printf("B. %s\n", question.option_b);
    printf("C. %s\n", question.option_c);
    printf("D. %s\n", question.option_d);
}

void add_question(question_t *questions, int *num_questions){
    question_t new_question;
    printf("Enter question: ");
    fgets(new_question.question, 1000, stdin);
    printf("Enter option A: ");
    fgets(new_question.option_a, 100, stdin);
    printf("Enter option B: ");
    fgets(new_question.option_b, 100, stdin);
    printf("Enter option C: ");
    fgets(new_question.option_c, 100, stdin);
    printf("Enter option D: ");
    fgets(new_question.option_d, 100, stdin);
    printf("Enter answer (A, B, C, or D): ");
    fgets(new_question.answer, 100, stdin);
    new_question.q_id = *num_questions;
    questions[*num_questions] = new_question;
    *num_questions += 1;
    printf("Question added successfully!\n");
}

void take_quiz(question_t *questions, int num_questions){
    int score = 0;
    for(int i = 0; i < num_questions; i++){
        printf("Question %d:\n", i+1);
        print_question(questions[i]);
        char user_answer[100];
        printf("Enter answer: ");
        fgets(user_answer, 100, stdin);
        if(strcmp(user_answer, questions[i].answer) == 0){
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong!\n");
        }
    }
    printf("Your score: %d / %d\n", score, num_questions);
}

int main(){
    question_t questions[1000];
    int num_questions = 0;
    int choice = 0;
    do {
        printf("1. Add question\n2. Take quiz\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        char c;
        scanf("%c", &c);
        switch(choice){
            case 1:
                add_question(questions, &num_questions);
                break;
            case 2:
                if(num_questions == 0){
                    printf("No questions added yet!\n");
                } else {
                    take_quiz(questions, num_questions);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 3);
    return 0;
}