//FormAI DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, userAns, correctAns, result = 0;
    srand(time(0));

    printf("Welcome to the paranoid math test!\n");
    printf("You will be given 10 math exercises to solve.\n");
    printf("You have to answer at least 9 correctly to pass the test.\n");
    printf("You will have 10 seconds to answer each question.\n");
    printf("If you fail to answer within time or give incorrect answer, you will fail.\n");
    printf("Good luck!\n\n");

    for(int i=1; i<=10; i++) {
        num1 = rand()%10 + 1;
        num2 = rand()%10 + 1;
        correctAns = num1 + num2;

        printf("\nQuestion %d:\n", i);
        printf("%d + %d = ", num1, num2);
        fflush(stdout);

        time_t start = time(NULL);
        scanf("%d", &userAns);
        time_t end = time(NULL);

        if(difftime(end, start) > 10) {
            printf("\nYou took too long to answer the question!\n");
            printf("You failed the paranoid math test!\n");
            printf("Goodbye!\n");
            exit(0);
        }

        if(userAns == correctAns) {
            printf("Correct!\n");
            result++;
        }
        else {
            printf("Incorrect!\n");
            printf("You failed the paranoid math test!\n");
            printf("Goodbye!\n");
            exit(0);
        }
    }

    if(result < 9) {
        printf("\nYou did not pass the paranoid math test!\n");
        printf("You answered %d questions correctly.\n", result);
        printf("Goodbye!\n");
        exit(0);
    }

    printf("\nCongratulations! You passed the paranoid math test!\n");
    printf("You answered %d questions correctly!\n", result);
    printf("Goodbye!\n");

    return 0;
}