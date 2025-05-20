//FormAI DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char ques[200];
    char optA[50], optB[50], optC[50], optD[50];
    char correct_ans;
};

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Add new question\n");
    printf("2. Take exam\n");
    printf("3. View all questions\n");
    printf("4. Exit\n");
}

void add_question(struct question *q, int count) {
    fflush(stdin);
    printf("Enter the question: ");
    fgets(q[count].ques, 200, stdin);
    fflush(stdin);

    printf("Enter option A: ");
    fgets(q[count].optA, 50, stdin);
    fflush(stdin);

    printf("Enter option B: ");
    fgets(q[count].optB, 50, stdin);
    fflush(stdin);

    printf("Enter option C: ");
    fgets(q[count].optC, 50, stdin);
    fflush(stdin);

    printf("Enter option D: ");
    fgets(q[count].optD, 50, stdin);
    fflush(stdin);

    printf("Enter correct option (A/B/C/D): ");
    scanf("%c", &q[count].correct_ans);
    fflush(stdin);

    printf("Question added successfully!\n");
}

int take_exam(struct question *q, int count) {
    char ans;
    int score = 0;

    for(int i=0; i<count; i++) {
        printf("\nQ. %s", q[i].ques);
        printf("A. %sB. %sC. %sD. %s", q[i].optA, q[i].optB, q[i].optC, q[i].optD);
        printf("Enter your answer (A/B/C/D): ");
        scanf("%c", &ans);
        fflush(stdin);

        if(ans == q[i].correct_ans) {
            score++;
        }
    }

    printf("\n\nYour score is %d/%d\n", score, count);
    return score;
}

void view_questions(struct question *q, int count) {
    if(count == 0) {
        printf("No questions added yet.\n");
    } else {
        for(int i=0; i<count; i++) {
            printf("Question %d:\n", i+1);
            printf("Q. %s", q[i].ques);
            printf("A. %sB. %sC. %sD. %s", q[i].optA, q[i].optB, q[i].optC, q[i].optD);
            printf("Correct answer: %c\n\n", q[i].correct_ans);
        }
    }
}

int main() {
    int choice, count=0, total_score=0;
    struct question q[50];

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1: 
                add_question(q, count);
                count++;
                break;
            case 2:
                if(count == 0) {
                    printf("No questions added yet.\n");
                } else {
                    total_score += take_exam(q, count);
                }
                break;
            case 3:
                view_questions(q, count);
                break;
            case 4:
                printf("Thank you for using the program!\n");
                break;
            default: 
                printf("Invalid choice.\n");
                break;
        }

    } while(choice != 4);

    printf("Total score: %d/%d\n", total_score, count);

    return 0;
}