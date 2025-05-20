//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define QUESTION_LENGTH 100
#define ANSWERS 5

struct Question {
    char question[QUESTION_LENGTH];
    int answer;
};

void print_menu() {
    printf("\n*********************************\n");
    printf("* Welcome to the Peaceful Fortune *\n");
    printf("* Tell me your question and I'll *\n");
    printf("* give you a peaceful answer.    *\n");
    printf("*********************************\n");
}

void read_question(struct Question questions[]) {
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nEnter question %d: ", i + 1);
        scanf("%s", questions[i].question);
        questions[i].answer = -1;
    }
}

int find_answer(struct Question questions[]) {
    srand(time(NULL));
    int index = rand() % ANSWERS;
    return index;
}

void give_answer(struct Question questions[], int answer_index) {
    char *answers[ANSWERS] = {"Peace is the answer.",
                               "The universe is on your side.",
                               "Everything will be alright.",
                               "You have the strength to overcome.",
                               "Trust in the journey of life."};
    printf("\nYour peaceful answer for question %d is:\n", questions[answer_index].answer + 1);
    printf("%s\n", answers[answer_index]);
}

int main() {
    struct Question questions[MAX_QUESTIONS];
    int i, answer_index;

    print_menu();
    read_question(questions);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        answer_index = find_answer(questions);
        give_answer(questions, answer_index);
    }

    return 0;
}