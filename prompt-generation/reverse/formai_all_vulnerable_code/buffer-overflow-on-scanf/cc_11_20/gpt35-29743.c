//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    char input[50];

    // Seed the random number generator
    srand(time(NULL));

    // Introduction and instructions
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question and type it in.\n");
    printf("The fortune teller will randomly choose an answer for you.\n\n");

    // Prompt for user input
    printf("What is your question?\n");
    scanf("%[^\n]", input);

    // Clear the input buffer
    getchar();

    // Display the user's question
    printf("\nYou asked: %s\n", input);

    // Generate a random number between 1 and 10
    choice = rand() % 10 + 1;

    // Use the random number to choose a fortune
    switch(choice) {
        case 1:
            printf("It is certain.\n");
            break;
        case 2:
            printf("It is decidedly so.\n");
            break;
        case 3:
            printf("Without a doubt.\n");
            break;
        case 4:
            printf("Yes - definitely.\n");
            break;
        case 5:
            printf("You may rely on it.\n");
            break;
        case 6:
            printf("As I see it, yes.\n");
            break;
        case 7:
            printf("Most likely.\n");
            break;
        case 8:
            printf("Outlook good.\n");
            break;
        case 9:
            printf("Yes.\n");
            break;
        case 10:
            printf("Signs point to yes.\n");
            break;
        default:
            printf("Error: Invalid choice.\n");
    }

    return 0;
}