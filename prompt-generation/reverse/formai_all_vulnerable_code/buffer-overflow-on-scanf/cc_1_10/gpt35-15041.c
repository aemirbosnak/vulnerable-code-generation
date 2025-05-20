//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of candidates
#define MAX_CANDIDATES 5

// define the maximum number of voters
#define MAX_VOTERS 1000

// define a candidate struct
typedef struct Candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

// define a voter struct
typedef struct Voter {
    int id;
    char name[50];
    int voted_for;
} Voter;

// define global variables
Candidate candidates[MAX_CANDIDATES]; // an array to store the candidates
Voter voters[MAX_VOTERS]; // an array to store the voters
int num_candidates = 0; // the number of candidates
int num_voters = 0; // the number of voters

// function prototypes
void add_candidate();
void list_candidates();
void add_voter();
void cast_vote();
void display_results();
int get_candidate_index_by_id(int id);

int main() {
    int choice;
    do {
        // display the menu
        printf("\n\nWelcome to the Electronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. List Candidates\n");
        printf("3. Add Voter\n");
        printf("4. Cast Vote\n");
        printf("5. Display Results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // do the corresponding action based on user input
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                list_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                cast_vote();
                break;
            case 5:
                display_results();
                break;
            case 6:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// function to add a candidate
void add_candidate() {
    // check if maximum number of candidates has been reached
    if (num_candidates == MAX_CANDIDATES) {
        printf("Sorry, you cannot add any more candidates.\n");
        return;
    }

    // ask for candidate details
    Candidate candidate;
    printf("Enter candidate ID: ");
    scanf("%d", &candidate.id);
    printf("Enter candidate name: ");
    scanf("%s", candidate.name);

    // add the candidate to the candidates array
    candidates[num_candidates] = candidate;
    num_candidates++;

    printf("Candidate added successfully!\n");
}

// function to list the candidates
void list_candidates() {
    // check if there are no candidates
    if (num_candidates == 0) {
        printf("No candidates found.\n");
        return;
    }

    printf("ID\tName\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// function to add a voter
void add_voter() {
    // check if maximum number of voters has been reached
    if (num_voters == MAX_VOTERS) {
        printf("Sorry, you cannot add any more voters.\n");
        return;
    }

    // ask for voter details
    Voter voter;
    printf("Enter voter ID: ");
    scanf("%d", &voter.id);
    printf("Enter voter name: ");
    scanf("%s", voter.name);

    // add the voter to the voters array
    voters[num_voters] = voter;
    num_voters++;

    printf("Voter added successfully!\n");
}

// function to cast a vote
void cast_vote() {
    // check if there are no candidates or voters
    if (num_candidates == 0 || num_voters == 0) {
        printf("Please add at least one candidate and one voter before casting a vote.\n");
        return;
    }

    // ask for voter details
    int voter_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    // search for the voter
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            voter_index = i;
            break;
        }
    }

    // check if the voter was found
    if (voter_index == -1) {
        printf("Voter not found.\n");
        return;
    }

    // check if the voter has already voted
    if (voters[voter_index].voted_for != 0) {
        printf("Voter has already cast a vote.\n");
        return;
    }

    // list the candidates
    list_candidates();

    // ask for candidate details
    int candidate_id;
    printf("Enter candidate ID to vote for: ");
    scanf("%d", &candidate_id);

    // get the candidate index
    int candidate_index = get_candidate_index_by_id(candidate_id);

    // check if the candidate was found
    if (candidate_index == -1) {
        printf("Candidate not found.\n");
        return;
    }

    // add the vote to the candidate and mark the voter as voted
    candidates[candidate_index].votes++;
    voters[voter_index].voted_for = candidate_id;

    printf("Vote cast successfully!\n");
}

// function to display the results
void display_results() {
    // check if there are no candidates or voters
    if (num_candidates == 0 || num_voters == 0) {
        printf("Please add at least one candidate and one voter before displaying the results.\n");
        return;
    }

    // list the candidates with their votes
    list_candidates();

    printf("Total number of voters: %d\n", num_voters);

    // calculate and display the winner
    int max_votes = 0;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    if (winner_index != -1) {
        printf("Winner: %s with %d votes.\n", candidates[winner_index].name, candidates[winner_index].votes);
    } else {
        printf("No winner found.\n");
    }
}

// function to get the index of a candidate by ID
int get_candidate_index_by_id(int id) {
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == id) {
            return i;
        }
    }
    return -1;
}