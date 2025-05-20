//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MIN_NUMBER 1
#define MAX_NUMBER 10

typedef struct {
    int question_number;
    int number1;
    int number2;
    int answer;
} Question;

Question questions[MAX_QUESTIONS];

void generate_question(Question *question) {
    question->number1 = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    question->number2 = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    question->answer = question->number1 + question->number2;
    question->question_number = rand() % (MAX_QUESTIONS);
}

void print_question(Question question) {
    printf("\nQuestion %d:\n", question.question_number + 1);
    printf("%d + %d = ", question.number1, question.number2);
}

int main() {
    int i, score = 0;

    srand(time(NULL));

    for (i = 0; i < MAX_QUESTIONS; i++) {
        generate_question(&questions[i]);
    }

    for (i = 0; i < MAX_QUESTIONS; i++) {
        print_question(questions[i]);
        int user_answer;
        scanf("%d", &user_answer);

        if (user_answer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("WRONG ANSWER! The correct answer is %d.\n", questions[i].answer);
        }

        printf("\n");
    }

    printf("Your final score is %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}