//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50], question[100], reply;
    int fortune_num;

    printf("Welcome to the C Automated Fortune Teller!\n");
    printf("What is your name?\n");
    fgets(name, 50, stdin);

    printf("Hello %s, what is your question?\n", name);

    fgets(question, 100, stdin);
    printf("\n\nThinking...\n\n");

    // Generate a random number between 1 and 6
    srand(time(0));
    fortune_num = rand() % 6 + 1;

    switch (fortune_num) {
        case 1:
            printf("The stars are not aligned for that to happen.\n");
            break;

        case 2:
            printf("It is certain.\n");
            break;

        case 3:
            printf("My sources say no.\n");
            break;

        case 4:
            printf("Outlook good.\n");
            break;

        case 5:
            printf("Reply hazy, try again.\n");
            break;

        case 6:
            printf("Cannot predict now.\n");
            break;

        default:
            printf("Oops! Something went wrong.\n");
    }

    // Ask if user wants another question
    printf("\n\n%s, would you like to ask another question? (Y/N)\n", name);
    scanf(" %c", &reply);

    if (reply == 'Y' || reply == 'y') {
        main(); // Call the main function again to repeat the process
    } else {
        printf("Thank you for trying the C Automated Fortune Teller!\n");
    }

    return 0;
}