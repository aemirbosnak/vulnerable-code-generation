//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    int id;
    char name[50];
    int vote_count;
} candidate;

typedef struct {
    int id;
    char name[50];
    int voted_for;
    int has_voted;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].id = num_candidates + 1;
    candidates[num_candidates].vote_count = 0;
    num_candidates++;
}

void list_candidates() {
    printf("ID\tName\t\tVotes\n");
    printf("----------------------------------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d\t%-15s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].vote_count);
    }
    printf("\n");
}

void add_voter() {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted_for = 0;
    voters[num_voters].has_voted = 0;
    num_voters++;
}

void list_voters() {
    printf("ID\tName\t\tVoted For\tHas Voted\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d\t%-15s\t%d\t\t", voters[i].id, voters[i].name, voters[i].voted_for);
        if (voters[i].has_voted) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    printf("\n");
}

void cast_vote() {
    int voter_id, candidate_id;
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            if (voters[i].has_voted) {
                printf("You have already voted.\n");
                return;
            }
            printf("Enter candidate ID to vote for: ");
            scanf("%d", &candidate_id);
            for (int j = 0; j < num_candidates; j++) {
                if (candidates[j].id == candidate_id) {
                    candidates[j].vote_count++;
                    voters[i].voted_for = candidate_id;
                    voters[i].has_voted = 1;
                    printf("Vote cast successfully.\n");
                    return;
                }
            }
            printf("Invalid candidate ID.\n");
            return;
        }
    }
    printf("Invalid voter ID.\n");
}

void list_results() {
    printf("Candidate\tVotes\n");
    printf("------------------------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].vote_count);
    }
    printf("\n");
}

int main() {
    int choice = 0;
    while (choice != 6) {
        printf("Electronic Voting System\n");
        printf("------------------------\n");
        printf("1. Add Candidate\n");
        printf("2. List Candidates\n");
        printf("3. Add Voter\n");
        printf("4. Cast Vote\n");
        printf("5. List Results\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
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
                list_results();
                break;
            case 6:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}