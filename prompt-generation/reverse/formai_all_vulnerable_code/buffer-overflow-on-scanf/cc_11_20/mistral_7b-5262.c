//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUES 5
#define NUM_ANSW 6

typedef struct {
    char question[100];
    int answer;
} Question;

Question quesBank[NUM_QUES] = {
    {"What is your favorite color?", 1},
    {"What is your favorite food?", 2},
    {"What is your lucky number?", 3},
    {"What is your favorite hobby?", 4},
    {"What is your zodiac sign?", 5}
};

int main(void) {
    srand(time(NULL));
    int userAnswer, quesNum, randAnswer;

    for (quesNum = 0; quesNum < NUM_QUES; quesNum++) {
        printf("\n%s", quesBank[quesNum].question);
        scanf("%d", &userAnswer);

        randAnswer = rand() % NUM_ANSW;

        switch (quesBank[quesNum].answer) {
            case 1:
                if (userAnswer == 1)
                    printf("\nCorrect answer! You have great taste!\n");
                else
                    printf("\nSorry, that's not correct. The correct answer is Red.\n");
                break;
            case 2:
                if (userAnswer == 2)
                    printf("\nCorrect answer! I knew you had a good palate!\n");
                else
                    printf("\nSorry, that's not correct. The correct answer is Pizza.\n");
                break;
            case 3:
                if (userAnswer == randAnswer)
                    printf("\nCorrect answer! That's a lucky guess!\n");
                else
                    printf("\nSorry, that's not correct. The correct answer is %d.\n", quesBank[quesNum].answer);
                break;
            case 4:
                if (userAnswer == randAnswer)
                    printf("\nCorrect answer! That's impressive!\n");
                else
                    printf("\nSorry, that's not correct. The correct answer is Painting.\n");
                break;
            case 5:
                if (userAnswer == randAnswer)
                    printf("\nCorrect answer! That's amazing!\n");
                else {
                    char userSign[20];
                    printf("\nSorry, that's not correct. Your zodiac sign is ");
                    scanf("%s", userSign);

                    if (strcmp(userSign, "Aquarius") == 0) {
                        randAnswer = 0;
                        printf("\nI see. So you're an Aquarius, and your answer was incorrect.\n");
                    } else {
                        printf("\nI'm sorry, that's not correct. The correct answer is %s.\n", (quesBank[quesNum].answer == 1) ? "Aquarius" : "Pisces");
                    }
                }
                break;
            default:
                printf("\nSomething went wrong! Exiting...\n");
                exit(EXIT_FAILURE);
        }
    }

    printf("\nThank you for playing the Automated Fortune Teller game!");
    return 0;
}