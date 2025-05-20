//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: rigorous
#include <stdio.h>

/* Define the maximum number of candidates */
#define MAX_CANDIDATES_SIZE 10

/* Define the structure for the candidate */
struct candidate {
    int id;
    char name[100];
    char party[100];
    int vote_count;
};

/* Define the function for printing the candidates list */
void print_candidate_list(struct candidate candidates[], int num_candidates) {
    printf("\nCandidate List:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d.\t%s (%s)\n", candidates[i].id, candidates[i].name, candidates[i].party);
    }
    printf("\n");
}

/* Define the function for getting the user's vote */
void get_user_vote(struct candidate candidates[], int num_candidates) {
    int vote_candidate_id;
    printf("\nEnter Candidate ID to vote: ");
    scanf("%d", &vote_candidate_id);
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == vote_candidate_id) {
            candidates[i].vote_count++;
            printf("\nYou have successfully voted for %s (%s)\n", candidates[i].name, candidates[i].party);
            return;
        }
    }
    printf("\nInvalid Candidate ID!\n");
}

/* Define the function for printing the election result */
void print_election_result(struct candidate candidates[], int num_candidates) {
    printf("\nElection Result:\n\n");
    printf("Candidate\t\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s (%s)\t\t%d\n", candidates[i].name, candidates[i].party, candidates[i].vote_count);
    }
    printf("\n");
}

/* Main function */
int main() {
    /* Initialize the candidates array */
    struct candidate candidates[MAX_CANDIDATES_SIZE] = {
        {1, "John Doe", "Independent", 0},
        {2, "Jane Smith", "Republican", 0},
        {3, "Bob Johnson", "Democrat", 0},
    };
    int num_candidates = 3;

    /* Print the candidate list */
    print_candidate_list(candidates, num_candidates);

    /* Loop until the user chooses to exit */
    int choice;
    do {
        /* Print the menu */
        printf("Menu:\n");
        printf("1. Vote\n");
        printf("2. View Election Result\n");
        printf("3. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        /* Process the user's choice */
        switch (choice) {
            case 1:
                get_user_vote(candidates, num_candidates);
                break;
            case 2:
                print_election_result(candidates, num_candidates);
                break;
            case 3:
                printf("\nThank You for using the Electronic Voting System.\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}