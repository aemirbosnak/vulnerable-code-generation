//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: artistic
/*========================================================
 *
 * Title: Artistic Electronic Voting System
 * Description: This program demonstrates the implementation
 * of an electronic voting system using C programming language.
 * Author: [Your Name]
 * Date: [Date]
 *
 =========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants for maximum length of name and ID
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 15

// Define structures for Candidate, Voter, and Vote
typedef struct {
    char name[MAX_NAME_LENGTH];
    int vote_count;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int has_voted;
    int vote_index;
} Voter;

typedef struct {
    Candidate candidate;
    Voter voter;
} Vote;

// Define function prototypes
void display_menu();
void add_candidate(Candidate candidates[], int *num_candidates);
void add_voter(Voter voters[], int *num_voters);
void cast_vote(Candidate candidates[], int num_candidates, Voter voters[], int num_voters, Vote votes[], int *num_votes);
void display_results(Candidate candidates[], int num_candidates, Vote votes[], int num_votes);

int main() {
    // Declare variables
    int choice, num_candidates = 0, num_voters = 0, num_votes = 0;
    Candidate candidates[MAX_NAME_LENGTH];
    Voter voters[MAX_ID_LENGTH];
    Vote votes[MAX_NAME_LENGTH];

    // Display welcome message and menu
    printf("Welcome to the Artistic Electronic Voting System!\n");
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate(candidates, &num_candidates);
                break;
            case 2:
                add_voter(voters, &num_voters);
                break;
            case 3:
                cast_vote(candidates, num_candidates, voters, num_voters, votes, &num_votes);
                break;
            case 4:
                display_results(candidates, num_candidates, votes, num_votes);
                break;
            case 5:
                printf("Thank you for using the Artistic Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

/*
 * Function: display_menu
 * ----------------------------
 * Displays the menu of this electronic voting system.
 */
void display_menu() {
    printf("What do you want to do?\n");
    printf("1. Add a candidate\n");
    printf("2. Add a voter\n");
    printf("3. Cast a vote\n");
    printf("4. Display the results\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

/*
 * Function: add_candidate
 * ----------------------------
 * Adds a new candidate to the list of candidates.
 *
 * candidates: the array of candidates
 * num_candidates: the number of candidates in the array
 */
void add_candidate(Candidate candidates[], int *num_candidates) {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the candidate: ");
    scanf("%s", name);

    // Check if the candidate already exists
    for (int i = 0; i < *num_candidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }

    // Add a new candidate
    strcpy(candidates[*num_candidates].name, name);
    candidates[*num_candidates].vote_count = 0;
    (*num_candidates)++;
    printf("Candidate %s added successfully.\n", name);
}

/*
 * Function: add_voter
 * ----------------------------
 * Adds a new voter to the list of voters.
 *
 * voters: the array of voters
 * num_voters: the number of voters in the array
 */
void add_voter(Voter voters[], int *num_voters) {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];

    printf("Enter the name of the voter: ");
    scanf("%s", name);
    printf("Enter the ID of the voter: ");
    scanf("%s", id);

    // Check if the voter already exists
    for (int i = 0; i < *num_voters; i++) {
        if (strcmp(id, voters[i].id) == 0) {
            printf("Voter already exists.\n");
            return;
        }
    }

    // Add a new voter
    strcpy(voters[*num_voters].name, name);
    strcpy(voters[*num_voters].id, id);
    voters[*num_voters].has_voted = 0;
    voters[*num_voters].vote_index = -1;
    (*num_voters)++;
    printf("Voter %s added successfully.\n", name);
}

/*
 * Function: cast_vote
 * ----------------------------
 * Allows a voter to cast a vote for a candidate.
 *
 * candidates: the array of candidates
 * num_candidates: the number of candidates in the array
 * voters: the array of voters
 * num_voters: the number of voters in the array
 * votes: the array of votes
 * num_votes: the number of votes in the array
 */
void cast_vote(Candidate candidates[], int num_candidates, Voter voters[], int num_voters, Vote votes[], int *num_votes) {
    char voter_id[MAX_ID_LENGTH];
    char candidate_name[MAX_NAME_LENGTH];
    int candidate_index;

    printf("Enter your ID: ");
    scanf("%s", voter_id);

    // Find the index of the voter
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voter_id, voters[i].id) == 0) {
            voter_index = i;
            break;
        }
    }

    // Check if the voter exists
    if (voter_index == -1) {
        printf("Voter not found.\n");
        return;
    }

    // Check if the voter has already voted
    if (voters[voter_index].has_voted) {
        printf("You have already cast your vote.\n");
        return;
    }

    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidate_name);

    // Find the index of the candidate
    candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidate_name, candidates[i].name) == 0) {
            candidate_index = i;
            break;
        }
    }

    // Check if the candidate exists
    if (candidate_index == -1) {
        printf("Candidate not found.\n");
        return;
    }

    // Add the vote
    strcpy(votes[*num_votes].candidate.name, candidates[candidate_index].name);
    strcpy(votes[*num_votes].voter.name, voters[voter_index].name);
    strcpy(votes[*num_votes].voter.id, voters[voter_index].id);
    votes[*num_votes].voter.has_voted = 1;
    votes[*num_votes].voter.vote_index = *num_votes;
    candidates[candidate_index].vote_count++;
    (*num_votes)++;
    printf("Your vote has been cast successfully.\n");
}

/*
 * Function: display_results
 * ----------------------------
 * Displays the results of the election.
 *
 * candidates: the array of candidates
 * num_candidates: the number of candidates in the array
 * votes: the array of votes
 * num_votes: the number of votes in the array
 */
void display_results(Candidate candidates[], int num_candidates, Vote votes[], int num_votes) {
    printf("Election Results:\n");
    printf("-----------------\n");

    // Display the vote count for each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }

    // Display the list of voters who have cast their votes
    printf("\n");
    printf("List of Voters who have Voted:\n");
    printf("---------------------------------\n");

    for (int i = 0; i < num_votes; i++) {
        printf("%s (%s)\n", votes[i].voter.name, votes[i].voter.id);
    }

    // Display the list of voters who have not cast their votes
    printf("\n");
    printf("List of Voters who have Not Voted:\n");
    printf("------------------------------------\n");

    for (int i = 0; i < num_candidates; i++) {
        int found = 0;
        for (int j = 0; j < num_votes; j++) {
            if (strcmp(candidates[i].name, votes[j].candidate.name) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s\n", candidates[i].name);
        }
    }
}