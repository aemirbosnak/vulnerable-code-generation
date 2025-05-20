//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define QUESTIONS_LENGTH 100
#define ANSWERS_LENGTH 200

typedef struct {
    char question[QUESTIONS_LENGTH];
    char answer[ANSWERS_LENGTH];
} QuestionAnswerPair;

QuestionAnswerPair questions[MAX_QUESTIONS] = {
    {"What is your favorite color?", "Blue is the color of the universe."},
    {"What is your favorite food?", "May your taste buds rejoice with every bite!"},
    {"What is your greatest fear?", "Fear is a natural response, but remember, every fear faced is a victory won."},
    {"What is your lucky number?", "The universe has a plan for you, trust in the numbers."},
    {"What is your spirit animal?", "Your spirit animal is a reflection of your inner self, discover it and embrace it."},
    {"What is your greatest strength?", "Your greatest strength is your ability to adapt and overcome."},
    {"What is your greatest weakness?", "Your greatest weakness is your fear of failure, but remember, failure is just a stepping stone to success."},
    {"What is your biggest regret?", "Your biggest regret is a lesson learned, cherish the memories and move forward."},
    {"What is your greatest accomplishment?", "Your greatest accomplishment is yet to come, but believe in yourself and you will achieve great things."},
    {"What is your future holding?", "The future is full of possibilities, embrace them with an open heart and mind."}
};

int main() {
    int i, randomNumber;
    char userAnswer[50];
    clock_t startTime, endTime;

    startTime = clock();

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will ask you a question and then give you a fortune based on your answer.\n");
    printf("Are you ready? Press Enter to begin.\n");
    getchar();

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s", questions[i].question);
        scanf("%s", userAnswer);
        strcpy(questions[i].answer, userAnswer);
    }

    randomNumber = rand() % MAX_QUESTIONS;

    printf("\nHere is your fortune based on your answer to question %d:\n", randomNumber + 1);
    printf("%s", questions[randomNumber].answer);

    endTime = clock();
    printf("\nYour session with the Automated Fortune Teller took %f seconds.\n", (float)(endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}