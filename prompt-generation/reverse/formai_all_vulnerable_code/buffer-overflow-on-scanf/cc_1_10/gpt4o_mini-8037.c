//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voter_id[NAME_LENGTH];
    int has_voted; // 0 for no, 1 for yes
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void add_candidate();
void view_candidates();
void cast_vote();
void tally_votes();
void initialize_voters();
int find_voter(const char *voter_id);
void print_results();



int main() {
    int choice;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. View Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Tally Votes\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                view_candidates();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                tally_votes();
                break;
            case 5:
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}

void add_candidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Cannot add more candidates.\n");
        return;
    }
    
    printf("Enter candidate name: ");
    fgets(candidates[candidate_count].name, NAME_LENGTH, stdin);
    candidates[candidate_count].name[strcspn(candidates[candidate_count].name, "\n")] = '\0'; // Remove newline
    candidates[candidate_count].votes = 0;
    candidate_count++;
    printf("Candidate added successfully!\n");
}

void view_candidates() {
    if (candidate_count == 0) {
        printf("No candidates available.\n");
        return;
    }

    printf("\nList of Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s (Votes: %d)\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void cast_vote() {
    char voter_id[NAME_LENGTH];

    printf("Enter your Voter ID: ");
    fgets(voter_id, NAME_LENGTH, stdin);
    voter_id[strcspn(voter_id, "\n")] = '\0'; // Remove newline

    int idx = find_voter(voter_id);
    if (idx == -1) {
        if (voter_count >= MAX_VOTERS) {
            printf("Voter registration is full.\n");
            return;
        }
        strcpy(voters[voter_count].voter_id, voter_id);
        voters[voter_count].has_voted = 1; // mark as voted
        voter_count++;
    } else if (voters[idx].has_voted == 1) {
        printf("You have already voted!\n");
        return;
    }

    view_candidates();
    int choice;
    printf("Select candidate by number: ");
    scanf("%d", &choice);
    getchar(); // consume newline

    if (choice < 1 || choice > candidate_count) {
        printf("Invalid selection.\n");
        return;
    }

    candidates[choice - 1].votes++;
    printf("Vote casted for %s!\n", candidates[choice - 1].name);
    voters[idx].has_voted = 1; // mark as voted
}

int find_voter(const char *voter_id) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void tally_votes() {
    printf("\nTallying results...\n");
    print_results();
}

void print_results() {
    if (candidate_count == 0) {
        printf("No candidates to display results.\n");
        return;
    }

    int total_votes = 0;
    for (int i = 0; i < candidate_count; i++) {
        total_votes += candidates[i].votes;
    }

    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes,
               total_votes > 0 ? (candidates[i].votes * 100.0 / total_votes) : 0);
    }
}