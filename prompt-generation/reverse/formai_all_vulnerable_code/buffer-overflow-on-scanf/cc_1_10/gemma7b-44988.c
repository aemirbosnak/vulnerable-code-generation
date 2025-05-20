//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int voter_id;
    char voter_name[50];
    int vote_choice;
    struct candidate
    {
        char name[50];
        int votes;
    } candidate_list[] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Peter Pan", 0}
    };

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your voter ID:");
    scanf("%d", &voter_id);

    printf("Please enter your voter name:");
    scanf("%s", voter_name);

    printf("Please select your vote choice:\n");
    printf("1. John Doe\n");
    printf("2. Jane Doe\n");
    printf("3. Peter Pan\n");
    scanf("%d", &vote_choice);

    switch (vote_choice)
    {
        case 1:
            candidate_list[0].votes++;
            printf("Thank you for your vote, Mr./Ms. %s!\n", voter_name);
            break;
        case 2:
            candidate_list[1].votes++;
            printf("Thank you for your vote, Mr./Ms. %s!\n", voter_name);
            break;
        case 3:
            candidate_list[2].votes++;
            printf("Thank you for your vote, Mr./Ms. %s!\n", voter_name);
            break;
        default:
            printf("Invalid vote choice.\n");
    }

    printf("The results of the election:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s received %d votes.\n", candidate_list[i].name, candidate_list[i].votes);
    }

    return 0;
}