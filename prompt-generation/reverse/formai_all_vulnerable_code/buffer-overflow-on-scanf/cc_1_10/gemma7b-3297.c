//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char username[20];
    char password[20];
    int voter_id;
    int choice;

    system("clear");

    printf("Welcome to the Immersive Electronic Voting System!\n");
    printf("Please enter your username:");
    scanf("%s", username);

    printf("Please enter your password:");
    scanf("%s", password);

    printf("Please enter your voter ID:");
    scanf("%d", &voter_id);

    system("clear");

    printf("Hello, %s! You are logged in as voter ID %d.\n", username, voter_id);

    printf("Please select your choice:\n");
    printf("1. Vote for Candidate A\n");
    printf("2. Vote for Candidate B\n");
    printf("3. Vote for Candidate C\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You have voted for Candidate A.\n");
            break;
        case 2:
            printf("You have voted for Candidate B.\n");
            break;
        case 3:
            printf("You have voted for Candidate C.\n");
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    system("clear");

    printf("Thank you for voting, %s! Your vote has been recorded.\n", username);

    return 0;
}