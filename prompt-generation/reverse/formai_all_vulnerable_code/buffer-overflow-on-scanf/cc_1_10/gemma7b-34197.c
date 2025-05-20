//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char username[20];
    char password[20];
    int vote_choice;

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Validation code
    if (strcmp(username, "admin") == 0 && strcmp(password, "secret") == 0)
    {
        printf("Welcome, Administrator!\n");
    }
    else
    {
        printf("Invalid username or password.\n");
        exit(1);
    }

    // Voting options
    printf("Please select your vote choice:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");

    scanf("%d", &vote_choice);

    // Vote processing code
    switch (vote_choice)
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
            printf("Invalid vote choice.\n");
            break;
    }

    // Results display
    printf("Thank you for voting. The results are:\n");
    printf("Candidate A: %d votes\n", rand() % 100);
    printf("Candidate B: %d votes\n", rand() % 100);
    printf("Candidate C: %d votes\n", rand() % 100);

    return 0;
}