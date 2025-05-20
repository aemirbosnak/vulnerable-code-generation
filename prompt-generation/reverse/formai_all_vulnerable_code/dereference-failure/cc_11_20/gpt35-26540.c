//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int randomNumber = 0;
    char question[100];
    char answer[10];

    // Seed the random number generator with the current time
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What would you like to ask the fortune teller?\n");
    fgets(question, 100, stdin);
    printf("\nThinking...\n");

    // Generate a random number between 1 and 10
    randomNumber = (rand() % 10) + 1;

    // Use the random number to select one of ten possible answers
    switch (randomNumber) {
        case 1:
            strcpy(answer, "Yes");
            break;
        case 2:
            strcpy(answer, "No");
            break;
        case 3:
            strcpy(answer, "Maybe");
            break;
        case 4:
            strcpy(answer, "It is certain");
            break;
        case 5:
            strcpy(answer, "Outlook good");
            break;
        case 6:
            strcpy(answer, "Signs point to yes");
            break;
        case 7:
            strcpy(answer, "Cannot predict now");
            break;
        case 8:
            strcpy(answer, "Ask again later");
            break;
        case 9:
            strcpy(answer, "Most likely");
            break;
        case 10:
            strcpy(answer, "Don't count on it");
            break;
    }

    // Print the answer
    printf("\nThe answer to your question is: %s\n", answer);

    return 0;

}