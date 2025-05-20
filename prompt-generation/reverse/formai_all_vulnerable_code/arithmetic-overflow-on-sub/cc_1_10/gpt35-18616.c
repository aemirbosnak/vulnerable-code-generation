//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void vote(int candidate, int *votes)
{
    votes[candidate-1]++;
    printf("You have voted for candidate %d\n", candidate);
}

void print_results(int *votes, int num_candidates)
{
    printf("\n\nELECTION RESULTS:\n\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("Candidate %d: %d votes\n", i+1, votes[i]);
    }
}

int main()
{
    int num_candidates;
    printf("Welcome to the Surrealist Electronic Voting System\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    int *votes = (int*) malloc(num_candidates * sizeof(int));

    for(int i=0; i<num_candidates; i++)
    {
        votes[i] = 0;
    }

    srand(time(0));

    while(1)
    {
        int choice = rand() % 10;
        if(choice == 0)
        {
            printf("\n\nThank you for participating in the Surrealist Electronic Voting System\n");
            print_results(votes, num_candidates);
            break;
        }

        int candidate = rand() % num_candidates + 1;
        vote(candidate, votes);
    }

    free(votes);
    return 0;
}