//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define VOTER_ID_MAX_LENGTH 10

struct candidate {
    int id;
    char name[50];
    int votes;
};

struct voter {
    char id[VOTER_ID_MAX_LENGTH];
    bool has_voted;
    int vote;
};

struct election {
    struct candidate candidates[MAX_CANDIDATES];
    int num_of_candidates;
    struct voter voters[MAX_CANDIDATES];
    int num_of_voters;
};

void add_candidate(struct election *election, int id, char *name) {
    struct candidate new_candidate = {id, "", 0};
    strcpy(new_candidate.name, name);
    election->candidates[election->num_of_candidates++] = new_candidate;
}

void add_voter(struct election *election, char *id) {
    struct voter new_voter = {"", false, -1};
    strcpy(new_voter.id, id);
    election->voters[election->num_of_voters++] = new_voter;
}

bool is_voter_registered(struct election *election, char *voter_id) {
    for(int i = 0; i < election->num_of_voters; i++) {
        if(strcmp(election->voters[i].id, voter_id) == 0) {
            return true;
        }
    }
    return false;
}

void show_candidates(struct election *election) {
    printf("List of Candidates:\n");
    for(int i = 0; i < election->num_of_candidates; i++) {
        printf("%d. %s\n", election->candidates[i].id, election->candidates[i].name);
    }
}

bool verify_candidate(struct election *election, int candidate_id) {
    for(int i = 0; i < election->num_of_candidates; i++) {
        if(election->candidates[i].id == candidate_id) {
            return true;
        }
    }
    return false;
}

void show_votes(struct election *election) {
    printf("Current vote count:\n");
    for(int i = 0; i < election->num_of_candidates; i++) {
        printf("%s: %d\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

void cast_vote(struct election *election, char *voter_id, int candidate_id) {
    for(int i = 0; i < election->num_of_voters; i++) {
        if(strcmp(election->voters[i].id, voter_id) == 0) {
            if(!election->voters[i].has_voted) {
                if(verify_candidate(election, candidate_id)) {
                    election->voters[i].has_voted = true;
                    election->candidates[candidate_id-1].votes++;
                    printf("Vote cast successfully.\n");
                }
                else {
                    printf("Invalid candidate id.\n");
                }
            }
            else {
                printf("You have already cast a vote.\n");
            }
            return;
        }
    }
    printf("You are not registered to vote.\n");
}

int main() {
    struct election election = {{}, 0, {}, 0};
    char choice[10];
    while(true) {
        printf("\nEnter a choice:\n1. Add candidate\n2. Add voter\n3. Show candidates\n4. Cast vote\n5. Show votes\n6. Quit\n");
        scanf("%s", choice);
        if(strcmp(choice, "1") == 0) {
            char name[50];
            int id;
            printf("\nEnter candidate name: ");
            scanf("%s", name);
            printf("Enter candidate id: ");
            scanf("%d", &id);
            add_candidate(&election, id, name);
            printf("Candidate added successfully.\n");
        }
        else if(strcmp(choice, "2") == 0) {
            char id[VOTER_ID_MAX_LENGTH];
            printf("\nEnter voter id: ");
            scanf("%s", id);
            add_voter(&election, id);
            printf("Voter added successfully.\n");
        }
        else if(strcmp(choice, "3") == 0) {
            show_candidates(&election);
        }
        else if(strcmp(choice, "4") == 0) {
            char voter_id[VOTER_ID_MAX_LENGTH];
            int candidate_id;
            printf("\nEnter voter id: ");
            scanf("%s", voter_id);
            printf("Enter candidate id: ");
            scanf("%d", &candidate_id);
            cast_vote(&election, voter_id, candidate_id);
        }
        else if(strcmp(choice, "5") == 0) {
            show_votes(&election);
        }
        else if(strcmp(choice, "6") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}