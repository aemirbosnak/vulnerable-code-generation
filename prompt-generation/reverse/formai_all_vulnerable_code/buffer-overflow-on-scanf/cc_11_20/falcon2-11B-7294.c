//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice = rand() % 10 + 1;
    int question = rand() % 10 + 1;
    int answer = rand() % 10 + 1;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Your choices are:\n");
    printf("1. Love\n2. Money\n3. Health\n4. Career\n5. Family\n");

    printf("Which area would you like to ask a question about?\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Your question about love is...\n");
            break;
        case 2:
            printf("Your question about money is...\n");
            break;
        case 3:
            printf("Your question about health is...\n");
            break;
        case 4:
            printf("Your question about career is...\n");
            break;
        case 5:
            printf("Your question about family is...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("What is your question?\n");
    scanf("%d", &question);

    switch (question) {
        case 1:
            printf("Your answer is...\n");
            break;
        case 2:
            printf("Your answer is...\n");
            break;
        case 3:
            printf("Your answer is...\n");
            break;
        case 4:
            printf("Your answer is...\n");
            break;
        case 5:
            printf("Your answer is...\n");
            break;
        default:
            printf("Invalid question.\n");
            break;
    }

    printf("Your fortune is...\n");
    switch (answer) {
        case 1:
            printf("Good luck with your love life!\n");
            break;
        case 2:
            printf("Your financial future looks bright!\n");
            break;
        case 3:
            printf("Take care of your health.\n");
            break;
        case 4:
            printf("You're on the right track in your career!\n");
            break;
        case 5:
            printf("Your family is your greatest support.\n");
            break;
        default:
            printf("Sorry, I can't give you a fortune.\n");
            break;
    }

    return 0;
}