//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// declare structure for candidate
struct candidate
{
    char name[30];
    int votes;
};

// declare function prototypes
void cast_vote(struct candidate list[], int num_candidates);
void display_results(struct candidate list[], int num_candidates);

int main()
{
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // dynamically allocate memory for candidate array
    struct candidate *list = (struct candidate*)malloc(num_candidates * sizeof(struct candidate));

    // input candidate names
    printf("Enter the names of candidates:\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("Candidate %d: ", i+1);
        scanf("%s", list[i].name);
        list[i].votes = 0; // initialize votes to zero
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    printf("\nVoting begins...\n");
    for(int i=1; i<=num_voters; i++)
    {
        printf("\nVoter %d\n", i);
        cast_vote(list, num_candidates);
    }

    printf("\nVoting has ended. Displaying Results...\n");
    display_results(list, num_candidates);

    // free dynamically allocated memory
    free(list);
    return 0;
}

void cast_vote(struct candidate list[], int num_candidates)
{
    int choice;
    printf("Choose a candidate by entering the corresponding number:\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("%d. %s\n", i+1, list[i].name);
    }
    scanf("%d", &choice);

    // check if choice is valid
    if(choice >= 1 && choice <= num_candidates)
    {
        list[choice-1].votes++;
        printf("Your vote has been cast for %s\n", list[choice-1].name);
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
        cast_vote(list, num_candidates); // recursive call until valid choice is made
    }
}

void display_results(struct candidate list[], int num_candidates)
{
    // find the winner with maximum votes
    int max_votes = 0, winner = 0;
    for(int i=0; i<num_candidates; i++)
    {
        if(list[i].votes > max_votes)
        {
            max_votes = list[i].votes;
            winner = i;
        }
    }

    printf("\nResults:\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("%s: %d votes\n", list[i].name, list[i].votes);
    }
    printf("-----------------------------------------------------\n");
    printf("Winner: %s with %d votes\n", list[winner].name, max_votes);
}