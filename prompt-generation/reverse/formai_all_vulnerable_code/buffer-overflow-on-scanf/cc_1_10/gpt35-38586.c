//FormAI DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // initialize variables
    char name[20];
    int score = 0;
    int answer;

    // welcome message
    printf("Welcome to the Retro C Examination System!\n");
    printf("Please enter your name: ");

    // read in user's name
    fgets(name, 20, stdin);

    // main quiz loop
    for (int i = 1; i <= 5; i++) {
        // clear console
        system("cls");

        // present question
        printf("Question %d:\n", i);
        switch(i) {
            case 1:
                printf("What year was C invented?\n");
                printf("1. 1970\n2. 1980\n3. 1990\n4. 2000\n");
                answer = 1;
                break;
            case 2:
                printf("In C, what is the keyword for declaring an int variable?\n");
                printf("1. char\n2. int\n3. float\n4. double\n");
                answer = 2;
                break;
            case 3:
                printf("Which of the following is an example of a pointer dereference?\n");
                printf("1. int *x = &y;\n2. int *x;\nx = &y;\n3. *x = &y;\n4. *x = y;\n");
                answer = 4;
                break;
            case 4:
                printf("What is the maximum value of an unsigned int on a typical machine?\n");
                printf("1. 2^16\n2. 2^32\n3. 2^64\n4. 2^128\n");
                answer = 2;
                break;
            case 5:
                printf("Which of the following is NOT a bitwise operator?\n");
                printf("1. &\n2. |\n3. ^\n4. !\n");
                answer = 4;
                break;
        }

        // get user's answer
        printf("\nYour answer: ");
        scanf("%d", &score);

        // validate answer
        if(score < 1 || score > 4) {
            printf("\nInvalid answer\n");
            i--;
            continue;
        }

        // check answer
        if(score == answer) {
            printf("\nCorrect!\n");
            score++;
        } else {
            printf("\nIncorrect!\n");
        }

        // pause before continuing to next question
        printf("\nPress enter to continue...");
        getchar();
        getchar();
    }

    // present final score
    printf("Congratulations, %s! Your final score is %d/5\n", name, score);

    return 0;
}