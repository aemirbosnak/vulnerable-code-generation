//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <string.h>

/* Define the maximum number of candidates */
#define MAX_CANDIDATES 10

/* Define Candidate Type */
typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

/* Define the Voting System */
typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
} VotingSystem;

/* Function Declarations */
void initialize_system(VotingSystem* system);
void register_candidate(VotingSystem* system);
int vote_for_candidate(VotingSystem* system, int candidate_id);
void display_results(VotingSystem* system);

/* Main Function */
int main() {
    VotingSystem system;
    int choice, candidate_id, num_votes;

    /* Initialize the Voting System */
    initialize_system(&system);

    printf("-----------------------------------------\n");
    printf(" Welcome to the Electronic Voting System \n");
    printf("-----------------------------------------\n");

    while(1) {
        /* Display the Menu */
        printf("\n Menu: \n");
        printf("1. Register Candidate \n");
        printf("2. Vote for Candidate \n");
        printf("3. Display Results \n");
        printf("4. Exit \n");

        /* Get the User's Choice */
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        /* Process the User's Choice */
        switch(choice) {
            case 1:     // Register Candidate
                register_candidate(&system);
                break;
            case 2:     // Vote for Candidate
                printf("\n Enter Candidate ID to Vote: ");
                scanf("%d", &candidate_id);
                num_votes = vote_for_candidate(&system, candidate_id);
                if(num_votes == -1) {
                    printf("\n Invalid Candidate ID \n");
                } else {
                    printf("\n You have successfully voted for %s with %d votes \n", system.candidates[candidate_id].name, num_votes);
                }
                break;
            case 3:     // Display Results
                display_results(&system);
                break;
            case 4:     // Exit
                printf("\n Thank you for using Electronic Voting System! \n");
                return 0;
            default:
                printf("\n Invalid Choice! Try Again \n");
        }
    }
}

/* Function to Initialize the Voting System */
void initialize_system(VotingSystem* system) {
    /* Set the number of candidates to 0 */
    system->num_candidates = 0;
}

/* Function to Register a Candidate */
void register_candidate(VotingSystem* system) {
    Candidate candidate;

    /* Get the Candidate's Name */
    printf("\n Enter Candidate Name: ");
    scanf("%s", candidate.name);

    /* Set the Candidate ID */
    candidate.id = system->num_candidates;

    /* Set the Candidate's Votes to 0 */
    candidate.votes = 0;

    /* Add the Candidate to the System */
    system->candidates[system->num_candidates] = candidate;
    system->num_candidates++;
}

/* Function to Vote for a Candidate */
int vote_for_candidate(VotingSystem* system, int candidate_id) {
    /* Check if the Candidate ID is Valid */
    if(candidate_id >= 0 && candidate_id < system->num_candidates) {
        /* Increase the Candidate's Votes by 1 */
        system->candidates[candidate_id].votes++;
        return system->candidates[candidate_id].votes;
    }

    /* Invalid Candidate ID */
    return -1;
}

/* Function to Display the Voting Results */
void display_results(VotingSystem* system) {
    int i;

    printf("\n Candidate ID  Candidate Name     Votes \n");
    printf("-----------------------------------------\n");

    /* Loop through all the Candidates */
    for(i=0; i<system->num_candidates; i++) {
        printf(" %-12d %-17s %-6d \n", system->candidates[i].id, system->candidates[i].name, system->candidates[i].votes);
    }
}