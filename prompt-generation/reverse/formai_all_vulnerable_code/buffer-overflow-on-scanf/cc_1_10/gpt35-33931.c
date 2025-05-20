//FormAI DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char question[512];
    char optionA[256];
    char optionB[256];
    char optionC[256];
    char optionD[256];
    char correct_answer;
} MCQ;

void print_instructions() {
    printf("Welcome to the Medieval Online Examination System!\n");
    printf("You will be presented with a series of multiple-choice questions.\n");
    printf("Choose the correct answer by entering A, B, C, or D.\n");
    printf("Good luck!\n\n");
}

void take_exam(MCQ *questions, int num_questions) {
    int score = 0;
    char answer;
    for(int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        printf("A. %s\tB. %s\n", questions[i].optionA, questions[i].optionB);
        printf("C. %s\tD. %s\n", questions[i].optionC, questions[i].optionD);

        printf("Your answer: ");
        scanf(" %c", &answer);
        answer = toupper(answer);
        if(answer == questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c.\n", questions[i].correct_answer);
        }
    }
    printf("Exam over. You scored %d out of %d.\n", score, num_questions);
}

int main() {
    MCQ questions[] = {
        {"What was the capital of the Byzantine Empire?", "Constantinople", "Rome", "Athens", "Paris", 'A'},
        {"Who wrote The Canterbury Tales?", "William Shakespeare", "Christopher Marlowe", "Geoffrey Chaucer", "John Milton", 'C'},
        {"In what year was the Magna Carta signed?", "1215", "1066", "1348", "1485", 'A'},
        {"What was the name of King Arthur's sword?", "Excalibur", "Caliburn", "Durandal", "Joyeuse", 'A'},
        {"Which city did Joan of Arc help liberate?", "Orleans", "Tours", "Lyon", "Bordeaux", 'A'},
    };
    int num_questions = sizeof(questions) / sizeof(MCQ);

    print_instructions();
    take_exam(questions, num_questions);

    return 0;
}