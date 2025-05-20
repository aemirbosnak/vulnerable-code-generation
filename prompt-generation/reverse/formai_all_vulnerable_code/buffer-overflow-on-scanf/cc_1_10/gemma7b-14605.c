//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

Candidate candidates[] = {
    {"Mr. A", 0},
    {"Ms. B", 0},
    {"Mr. C", 0},
    {"Ms. D", 0},
    {"Mr. E", 0}
};

void vote(char candidate)
{
    for (int i = 0; i < 5; i++)
    {
        if (candidates[i].name[0] == candidate)
        {
            candidates[i].votes++;
            break;
        }
    }
}

int main()
{
    char vote_choice;
    time_t t = time(NULL);

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select a candidate: ");

    scanf(" %c", &vote_choice);

    vote(vote_choice);

    printf("Thank you for voting, %s!\n", candidates[0].name);
    printf("The results of the election:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    printf("The time of your vote: %s", ctime(&t));

    return 0;
}