//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTER 1000
#define MAX_NAME_SIZE 50
#define MAX_CHOICE_SIZE 50

typedef struct
{
    char name[MAX_NAME_SIZE];
    int choice;
} Voter;

int main()
{
    Voter voters[MAX_VOTER];
    int num_voters = 0;
    int vote_count = 0;
    int choices_count = 0;
    int num_choices = 0;
    char choices[MAX_CHOICE_SIZE];
    int choice_votes[MAX_CHOICE_SIZE];
    int i, j, k;

    // Get number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Get voter names and choices
    for (i = 0; i < num_voters; i++)
    {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter the vote choice of voter %d: ", i + 1);
        scanf("%d", &voters[i].choice);
        if (voters[i].choice > num_choices)
        {
            num_choices = voters[i].choice;
        }
    }

    // Get choice options
    printf("Enter the different choices available (comma separated): ");
    scanf("%s", choices);

    // Convert choice options to array
    char *choice_token;
    choice_token = strtok(choices, ",");
    while (choice_token != NULL)
    {
        choice_votes[choices_count] = 0;
        choices_count++;
        choice_token = strtok(NULL, ",");
    }

    // Count votes for each choice
    for (i = 0; i < num_voters; i++)
    {
        choice_votes[voters[i].choice - 1]++;
        vote_count++;
    }

    // Display results
    printf("\nResults\n");
    for (i = 0; i < choices_count; i++)
    {
        printf("%s: %d votes\n", choices[i], choice_votes[i]);
    }
    printf("Total votes: %d\n", vote_count);

    return 0;
}