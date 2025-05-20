//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int questionCount = 0;
    int correctCount = 0;
    int incorrectCount = 0;
    int randomElement;
    char answer;
    srand(time(NULL));

    printf("Welcome to the Medieval Periodic Table Quiz!\n");
    printf("You will be asked to identify elements based on their symbols.\n");
    printf("Are you ready to begin? (y/n)\n");

    scanf("%c", &answer);
    if (answer == 'y') {
        printf("Great! Let's get started.\n\n");

        while (questionCount < 10) {
            randomElement = rand() % 118 + 1;

            switch(randomElement){
                case 1:
                    printf("What element has the symbol 'H'? ");
                    scanf(" %c", &answer);
                    if (answer == 'H') {
                        printf("Correct!\n");
                        correctCount++;
                    } else {
                        printf("Incorrect. The correct answer is Hydrogen.\n");
                        incorrectCount++;
                    }
                    break;
                case 2:
                    printf("What element has the symbol 'He'? ");
                    scanf(" %c", &answer);
                    if (answer == 'He') {
                        printf("Correct!\n");
                        correctCount++;
                    } else {
                        printf("Incorrect. The correct answer is Helium.\n");
                        incorrectCount++;
                    }
                    break;
                case 3:
                    printf("What element has the symbol 'Li'? ");
                    scanf(" %c", &answer);
                    if (answer == 'Li') {
                        printf("Correct!\n");
                        correctCount++;
                    } else {
                        printf("Incorrect. The correct answer is Lithium.\n");
                        incorrectCount++;
                    }
                    break;
                case 4:
                    printf("What element has the symbol 'Be'? ");
                    scanf(" %c", &answer);
                    if (answer == 'Be') {
                        printf("Correct!\n");
                        correctCount++;
                    } else {
                        printf("Incorrect. The correct answer is Beryllium.\n");
                        incorrectCount++;
                    }
                    break;
                // and so on for all 118 elements...
                default:
                    printf("Unexpected Error.\n");
                    return 1;
            }
            questionCount++;
        }

        printf("\nCongratulations! You have completed the quiz.\n");
        printf("You got %d correct answer(s) and %d incorrect answer(s).\n", correctCount, incorrectCount);
        printf("Thank you for playing!\n");

    } else {
        printf("You are not ready for the challenge of the Medieval Periodic Table Quiz.\n");
    }

    return 0;
}