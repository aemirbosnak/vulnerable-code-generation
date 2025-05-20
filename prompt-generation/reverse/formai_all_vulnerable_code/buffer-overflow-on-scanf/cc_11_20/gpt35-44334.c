//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char yesNo;
    int randomNum;
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n\n");

    do {
        printf("What is your question? (Type 'q' to quit)\n");
        char question[100];
        scanf("%s", question);

        if (question[0] == 'q' && question[1] == '\0') {
            printf("\nThank you for visiting the Automated Fortune Teller!\n");
            break;
        }

        printf("\nThinking...\n\n");
        usleep(500000);
        randomNum = rand() % 10;

        switch (randomNum) {
            case 0:
                printf("Yes.\n\n");
                break;
            case 1:
                printf("No.\n\n");
                break;
            case 2:
                printf("Maybe.\n\n");
                break;
            case 3:
                printf("It is highly probable.\n\n");
                break;
            case 4:
                printf("Unlikely.\n\n");
                break;
            case 5:
                printf("Ask again later.\n\n");
                break;
            case 6:
                printf("As I see it, yes.\n\n");
                break;
            case 7:
                printf("Outlook not so good.\n\n");
                break;
            case 8:
                printf("Cannot predict now.\n\n");
                break;
            case 9:
                printf("Most likely.\n\n");
                break;
        }

        printf("Would you like to ask another question? (y/n)\n");
        scanf(" %c", &yesNo);

        while (getchar() != '\n'); //flush the input

    } while (yesNo == 'y' || yesNo == 'Y');

    return 0;
}