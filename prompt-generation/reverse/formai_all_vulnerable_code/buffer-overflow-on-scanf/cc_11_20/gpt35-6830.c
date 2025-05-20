//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    char name[256];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nWelcome %s to the Automated Fortune Teller!\n\n", name);

    char question[256];
    printf("Please ask me a yes or no question: ");
    scanf("%s", question);

    srand(time(NULL));
    int random_number = rand() % 10;

    char *outcome;

    switch(random_number) {
        case 0:
            outcome = "It is certain.";
            break;
        case 1:
            outcome = "It is decidedly so.";
            break;
        case 2:
            outcome = "Without a doubt.";
            break;
        case 3:
            outcome = "Yes – definitely.";
            break;
        case 4:
            outcome = "You may rely on it.";
            break;
        case 5:
            outcome = "As I see it, yes.";
            break;
        case 6:
            outcome = "Most likely.";
            break;
        case 7:
            outcome = "Outlook good.";
            break;
        case 8:
            outcome = "Yes.";
            break;
        case 9:
            outcome = "Signs point to yes.";
            break;
        default:
            outcome = "I'm sorry, I didn't quite understand the question. Please try again.";
            break;
    }

    printf("You asked: %s\n", question);
    printf("The answer to your question is: %s\n", outcome);

    return 0;
}