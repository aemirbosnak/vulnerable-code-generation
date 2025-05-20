//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int voter_id;
    int voted;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

void add_candidate(char* name) {
    int i;
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            printf("%s is already a candidate.\n", name);
            return;
        }
    }
    strcpy(candidates[i].name, name);
    candidates[i].votes = 0;
}

void add_voter(char* name, int voter_id) {
    int i;
    for(i=0; i<MAX_VOTERS; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            printf("%s is already a voter.\n", name);
            return;
        }
    }
    strcpy(voters[i].name, name);
    voters[i].voter_id = voter_id;
    voters[i].voted = 0;
}

void vote(int voter_id, int candidate_id) {
    int i;
    for(i=0; i<MAX_VOTERS; i++) {
        if(voters[i].voter_id == voter_id &&!voters[i].voted) {
            voters[i].voted = 1;
            candidates[candidate_id-1].votes++;
            break;
        }
    }
}

void display_results() {
    int i, max_votes = 0;
    for(i=0; i<MAX_CANDIDATES; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    printf("Election results:\n");
    for(i=0; i<MAX_CANDIDATES; i++) {
        printf("%-20s %d votes (%d%%)\n", candidates[i].name, candidates[i].votes, (int)((float)candidates[i].votes/max_votes*100));
    }
}

int main() {
    int choice, voter_id, candidate_id;
    char name[50];

    system("clear");

    while(1) {
        printf("\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Vote\n");
        printf("4. Display results\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                printf("Enter voter name: ");
                scanf("%s", name);
                printf("Enter voter ID: ");
                scanf("%d", &voter_id);
                add_voter(name, voter_id);
                break;
            case 3:
                printf("Enter voter ID: ");
                scanf("%d", &voter_id);
                printf("Enter candidate ID: ");
                scanf("%d", &candidate_id);
                vote(voter_id, candidate_id);
                break;
            case 4:
                display_results();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}