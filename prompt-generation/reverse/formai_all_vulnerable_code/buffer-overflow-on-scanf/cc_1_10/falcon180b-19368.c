//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Question {
    char question[100];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    char correct_option[3];
};

void generate_question(struct Question *q) {
    int rand_index;
    char ch;

    srand(time(0));

    strcpy(q->question, "What is the capital of France? ");

    rand_index = rand() % 4;

    switch (rand_index) {
        case 0:
            strcpy(q->option1, "Paris");
            strcpy(q->correct_option, "A");
            break;

        case 1:
            strcpy(q->option1, "Berlin");
            strcpy(q->correct_option, "B");
            break;

        case 2:
            strcpy(q->option1, "Madrid");
            strcpy(q->correct_option, "C");
            break;

        case 3:
            strcpy(q->option1, "Rome");
            strcpy(q->correct_option, "D");
            break;
    }

    for (int i = 1; i <= 4; i++) {
        if (i == rand_index)
            continue;

        rand_index = rand() % 4;

        switch (rand_index) {
            case 0:
                strcpy(q->option2, "Paris");
                break;

            case 1:
                strcpy(q->option2, "Berlin");
                break;

            case 2:
                strcpy(q->option2, "Madrid");
                break;

            case 3:
                strcpy(q->option2, "Rome");
                break;
        }
    }
}

int main() {
    int num_questions, correct_answers = 0;
    char choice;
    struct Question questions[10];

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions you want to answer: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        generate_question(&questions[i]);
        printf("\n%d. %s", i + 1, questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("\n%c. %s", 'A' + j, questions[i].option1);
        }

        printf("\nEnter your solution: ");
        scanf(" %c", &choice);

        if (choice == questions[i].correct_option[0]) {
            correct_answers++;
        }
    }

    printf("\nYou have answered %d out of %d questions correctly.", correct_answers, num_questions);

    return 0;
}