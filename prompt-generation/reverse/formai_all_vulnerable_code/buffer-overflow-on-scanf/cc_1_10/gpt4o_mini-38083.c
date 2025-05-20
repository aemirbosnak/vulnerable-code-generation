//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[50];
    int vote_count;
} Candidate;

typedef struct {
    int id;
    char name[50];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void initialize_candidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &candidate_count);
    getchar(); // to consume newline

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].id = i + 1; // Assign candidate ID
        printf("Enter name for candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // Remove newline
        candidates[i].vote_count = 0; // Initialize vote count
    }
}

void initialize_voters() {
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &voter_count);
    getchar(); // to consume newline

    for (int i = 0; i < voter_count; i++) {
        voters[i].id = i + 1; // Assign voter ID
        printf("Enter name for voter %d: ", i + 1);
        fgets(voters[i].name, sizeof(voters[i].name), stdin);
        voters[i].name[strcspn(voters[i].name, "\n")] = 0; // Remove newline
        voters[i].has_voted = 0; // Initialize has_voted flag
    }
}

void cast_vote() {
    for (int i = 0; i < voter_count; i++) {
        if (voters[i].has_voted == 0) { // Check if the voter hasn't voted
            printf("Voter %s, please cast your vote (1-%d): ", voters[i].name, candidate_count);
            int vote;
            scanf("%d", &vote);
            if (vote < 1 || vote > candidate_count) {
                printf("Invalid vote! You can't vote for this candidate.\n");
                i--; // Repeat this voter
                continue;
            }
            candidates[vote - 1].vote_count++;
            voters[i].has_voted = 1; // Mark this voter as voted
            printf("Thank you, %s! Your vote for %s has been recorded.\n", voters[i].name, candidates[vote - 1].name);
        } else {
            printf("Voter %s has already voted.\n", voters[i].name);
        }
    }
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    
    int max_votes = -1;
    char winner[50];
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].vote_count > max_votes) {
            max_votes = candidates[i].vote_count;
            strcpy(winner, candidates[i].name);
        }
    }
    printf("The winner is: %s with %d votes!\n", winner, max_votes);
}

int main() {
    printf("Welcome to the Electronic Voting System\n");
    
    initialize_candidates();
    initialize_voters();
    cast_vote();
    display_results();
    
    return 0;
}