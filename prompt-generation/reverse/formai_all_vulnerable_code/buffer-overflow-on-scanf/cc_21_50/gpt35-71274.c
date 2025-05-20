//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CANDIDATES 10  // maximum number of candidates that can be registered for the election
#define VOTER_ID_LENGTH 8  // length of the voter ID number
#define BALLOT_BOX_SIZE 1000   // maximum number of votes that can be cast in one election

/* Candidate struct */
typedef struct {
    int id;  // unique candidate ID
    char name[50];  // candidate name
    int number_of_votes;  // total number of votes received
} Candidate;

/* Voter struct */
typedef struct {
    char id[VOTER_ID_LENGTH];  // voter ID number
    bool has_voted;  // true if the voter has already cast a vote
    int candidate_id;  // ID of the candidate the voter voted for
} Voter;

int main()
{
    Candidate candidates[MAX_CANDIDATES]; // array of candidates
    Voter voters[BALLOT_BOX_SIZE]; // array of voters
    int num_candidates = 0;  // number of candidates registered for the election
    int num_voters = 0;  // number of voters who have cast their votes
    int winner_id = -1;  // ID of the candidate with the most votes

    /* Seed the random number generator */
    srand(time(NULL));

    /* Register candidates */
    printf("How many candidates are participating in this election? (max %d)\n", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    while (num_candidates < 1 || num_candidates > MAX_CANDIDATES)
    {
        printf("Invalid number of candidates. Please enter a number between 1 and %d: ", MAX_CANDIDATES);
        scanf("%d", &num_candidates);
    }
    for (int i = 0; i < num_candidates; i++)
    {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].number_of_votes = 0;
    }

    /* Register voters */
    printf("\nEnter voter IDs (8 characters long) one by one. Enter -1 to finish.\n");
    char voter_id[VOTER_ID_LENGTH];
    int i = 0;
    while (i < BALLOT_BOX_SIZE)
    {
        scanf("%s", voter_id);
        if (atoi(voter_id) == -1) break;
        if (strlen(voter_id) != VOTER_ID_LENGTH)
        {
            printf("Invalid voter ID. Voter ID must be %d characters long. Please try again.\n", VOTER_ID_LENGTH);
            continue;
        }
        bool voter_exists = false;
        for (int j = 0; j < num_voters; j++)
        {
            if (strcmp(voters[j].id, voter_id) == 0)
            {
                voter_exists = true;
                break;
            }
        }
        if (voter_exists)
        {
            printf("This voter has already registered.\n");
            continue;
        }
        strcpy(voters[num_voters].id, voter_id);
        voters[num_voters].has_voted = false;
        num_voters++;
    }

    /* Voting begins */
    while (true)
    {
        int choice = -1;
        printf("\nWhat would you like to do?\n1. Display candidates\n2. Vote\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nCandidates:\n");
            for (int j = 0; j < num_candidates; j++)
            {
                printf("%d. %s\n", candidates[j].id, candidates[j].name);
            }
        }
        else if (choice == 2)
        {
            if (num_voters == 0)
            {
                printf("There are no registered voters.");
                continue;
            }
            /* Get random voter */
            int voter_index = rand() % num_voters;
            while (voters[voter_index].has_voted)  // select a voter who hasn't voted yet
            {
                voter_index = rand() % num_voters;  
            }
            printf("\nVoter ID: %s\n", voters[voter_index].id);
            printf("Please enter the ID number of the candidate you want to vote for: ");
            int candidate_choice;
            scanf("%d", &candidate_choice);
            bool candidate_exists = false;
            for (int j = 0; j < num_candidates; j++)
            {
                if (candidates[j].id == candidate_choice)
                {
                    candidate_exists = true;
                    break;
                }
            }
            if (!candidate_exists)
            {
                printf("Invalid candidate ID. Please try again.");
                continue;
            }
            voters[voter_index].has_voted = true;  // make sure this voter can't vote again
            voters[voter_index].candidate_id = candidate_choice;  // record the voter's choice
            candidates[candidate_choice-1].number_of_votes++;  // add a vote to the selected candidate
            
            /* Check for a winner or tie */
            winner_id = -1;
            for (int j = 0; j < num_candidates; j++)
            {
                if (candidates[j].number_of_votes > candidates[winner_id-1].number_of_votes)
                {
                    winner_id = j+1;
                }
                else if (candidates[j].number_of_votes == candidates[winner_id-1].number_of_votes)
                {
                    winner_id = -1;  // if there's a tie, there is no winner
                }
            }
            if (winner_id != -1)
            {
                printf("The winner is %s with %d vote(s)!\n", candidates[winner_id-1].name, candidates[winner_id-1].number_of_votes);
                break;  // election is over
            }
            else if (num_voters == num_candidates)  // if all voters have cast their votes and there's still a tie
            {
                printf("The election has ended in a tie!");
                break;
            }
        }
        else if (choice == 3)
        {
            printf("Goodbye!");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1, 2 or 3.");
        }
    }

    return 0;
}