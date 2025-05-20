//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_menu(void);
void vote_cast(void);
void vote_history(void);

int main()
{
    int choice;

    display_menu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            vote_cast();
            break;
        case 2:
            vote_history();
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}

void display_menu(void)
{
    printf("-----------------------------------\n");
    printf("Electronic Voting System\n");
    printf("-----------------------------------\n");
    printf("1. Vote Cast\n");
    printf("2. Vote History\n");
    printf("Please select an option: ");
}

void vote_cast(void)
{
    char candidate_name[20];
    int vote_count = 0;

    printf("Enter the candidate's name: ");
    scanf("%s", candidate_name);

    // Logic to add the vote to the candidate's count
    vote_count++;

    printf("Your vote has been cast for %s.\n", candidate_name);
}

void vote_history(void)
{
    // Logic to display the vote history
    printf("Your vote history:\n");
    printf("------------------------\n");
    printf("Candidate name: | Vote count |\n");
    printf("------------------------\n");
    // Display the vote history
}