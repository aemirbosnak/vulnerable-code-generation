//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_ANSWERS 5
#define MIN_RAND_NUM 0
#define MAX_RAND_NUM 4

void fortune(int question);
void answer(int answer);

int main() {
    int questionsAnswered = 0;
    int randNum;
    int userAnswer;

    srand(time(NULL));

    printf("*******************************************************\n");
    printf("* Welcome to the Automated Fortune Teller!           *\n");
    printf("* Prepare to be amazed by the power of the stars!   *\n");
    printf("*******************************************************\n");

    while(questionsAnswered < NUM_QUESTIONS) {
        printf("\nQuestion %d of %d:\n", questionsAnswered + 1, NUM_QUESTIONS);
        printf("What number am I thinking of between 0 and 4?\n");
        fortune(questionsAnswered);

        scanf("%d", &userAnswer);

        randNum = rand() % (NUM_ANSWERS);
        answer(randNum);

        questionsAnswered++;
    }

    printf("\nYour final answer was correct %d times out of %d.\n", questionsAnswered - 1, NUM_QUESTIONS);

    return 0;
}

void fortune(int question) {
    printf("\nYour fortune for question %d:\n", question + 1);
    printf("You will find the number I'm thinking of easily!\n");
    printf("May the stars be in your favor!\n");
}

void answer(int answer) {
    int userAnswer;

    switch(answer) {
        case 0:
            printf("Sorry, that was not the number I was thinking of.\n");
            printf("Keep trying! The number I have in mind is between 0 and 4.\n");
            break;
        case 1:
            printf("Congratulations! You have answered correctly.\n");
            printf("Your prize for this question is: A secret power that will make you invincible.\n");
            break;
        case 2:
            printf("Good job! You are getting closer.\n");
            printf("Keep trying! The number I have in mind is between 0 and 4.\n");
            break;
        case 3:
            printf("Amazing! You are so close to figuring it out.\n");
            printf("Keep going! The number I have in mind is between 0 and 4.\n");
            break;
        case 4:
            printf("Bravo! You have answered correctly.\n");
            printf("Your prize for this question is: A magic lamp that grants three wishes.\n");
            break;
        default:
            printf("Error: Invalid answer.\n");
    }
}