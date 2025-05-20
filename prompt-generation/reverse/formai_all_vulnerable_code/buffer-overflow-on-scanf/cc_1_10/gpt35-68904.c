//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of candidates possible
#define MAX_CANDIDATES 10

// Define maximum length of candidate names
#define MAX_NAME_LENGTH 20

// Define maximum number of voters
#define MAX_VOTERS 100

// Define maximum number of parties participating in the election
#define MAX_PARTIES 5

// Define maximum length of party names
#define MAX_PARTY_LENGTH 20

// Define the vote struct
typedef struct
{
    char candidate[MAX_NAME_LENGTH];
    int vote_count;
} Vote;

// Define the candidate struct
typedef struct
{
    char name[MAX_NAME_LENGTH];
    int party_id;
} Candidate;

// Define the party struct
typedef struct
{
    char name[MAX_PARTY_LENGTH];
} Party;

// Declare global variables
Candidate candidates[MAX_CANDIDATES];
Vote votes[MAX_VOTERS];
Party parties[MAX_PARTIES];
int num_candidates = 0, num_parties = 0, num_voters = 0;

// Function to display menu
void display_menu()
{
    printf("--Electronic Voting System--\n");
    printf("1. Add a Candidate\n");
    printf("2. Add a Party\n");
    printf("3. Cast a Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Please enter a menu option (1-5): ");
}

// Function to add a candidate
void add_candidate()
{
    printf("--Add Candidate--\n");
    if(num_candidates == MAX_CANDIDATES)
    {
        printf("Maximum number of candidates reached!\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    printf("Enter party ID (1-%d): ", num_parties);
    scanf("%d", &candidates[num_candidates].party_id);
    num_candidates++;
}

// Function to add a party
void add_party()
{
    printf("--Add Party--\n");
    if(num_parties == MAX_PARTIES)
    {
        printf("Maximum number of parties reached!\n");
        return;
    }
    printf("Enter party name: ");
    scanf("%s", parties[num_parties].name);
    num_parties++;
}

// Function to cast a vote
void cast_vote()
{
    printf("--Cast Vote--\n");
    if(num_candidates == 0 || num_parties == 0)
    {
        printf("There are no candidates or parties yet!\n");
        return;
    }
    if(num_voters == MAX_VOTERS)
    {
        printf("Maximum number of voters reached!\n");
        return;
    }
    printf("Select a candidate by ID (1-%d):\n", num_candidates);
    for(int i = 0; i < num_candidates; i++)
    {
        printf("%d. %s (%s)\n", i+1, candidates[i].name, parties[candidates[i].party_id-1].name);
    }
    int candidate_id;
    scanf("%d", &candidate_id);
    votes[num_voters].vote_count = 1;
    strcpy(votes[num_voters].candidate, candidates[candidate_id-1].name);
    num_voters++;
}

// Function to display results of the election
void display_results()
{
    printf("--Results--\n");
    if(num_voters == 0)
    {
        printf("No votes have been cast yet!\n");
        return;
    }
    int party_votes[MAX_PARTIES] = {0}; // initialize array of party votes to 0
    for(int i = 0; i < num_voters; i++)
    {
        for(int j = 0; j < num_candidates; j++)
        {
            if(strcmp(votes[i].candidate, candidates[j].name) == 0)
            {
                party_votes[candidates[j].party_id-1]++;
                break;
            }
        }
    }
    for(int i = 0; i < num_parties; i++)
    {
        printf("%s: %d votes\n", parties[i].name, party_votes[i]);
    }
}

// Main function
int main()
{
    int choice;
    do
    {
        display_menu();
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                add_candidate();
                break;
            case 2:
                add_party();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}