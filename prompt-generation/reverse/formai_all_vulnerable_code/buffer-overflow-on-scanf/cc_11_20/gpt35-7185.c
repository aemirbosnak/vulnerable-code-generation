//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int num;
    char name[20];
    srand(time(NULL));

    // Get user's name
    printf("Hello, what is your name?\n");
    scanf("%s", name);

    // Greet the user and ask for their question
    printf("Hello %s, I am the automated fortune teller. Ask me a yes or no question.\n", name);

    // Get user's question
    char question[100];
    scanf(" %[^\n]s", question);

    // Generate a random number and use it to determine the fortune
    num = rand() % 10;
    printf("Hmm, let me think...\n");
    switch(num) {
        case 0:
            printf("I'm sorry, %s, I cannot predict that.\n", name);
            break;
        case 1:
            printf("Yes, definitely.\n");
            break;
        case 2:
            printf("It is decidedly so.\n");
            break;
        case 3:
            printf("Without a doubt.\n");
            break;
        case 4:
            printf("Reply hazy, try again.\n");
            break;
        case 5:
            printf("Ask again later.\n");
            break;
        case 6:
            printf("Better not tell you now.\n");
            break;
        case 7:
            printf("My sources say no.\n");
            break;
        case 8:
            printf("Outlook not so good.\n");
            break;
        case 9:
            printf("Very doubtful.\n");
            break;
    }

    // Thank the user for using the fortune teller and end the program
    printf("Thank you for using the automated fortune teller, %s!\n", name);
    return 0;
}