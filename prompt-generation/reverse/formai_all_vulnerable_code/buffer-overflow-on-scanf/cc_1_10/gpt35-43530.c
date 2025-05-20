//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char name[50];
    int voted;
};

struct Election {
    struct Candidate candidates[10];
    struct Voter voters[50];
    int num_candidates;
    int num_voters;
};

void add_candidate(struct Election *election, char *name) {
    if(election->num_candidates >= 10) {
        printf("Error: Maximum Candidates limit reached.\n");
    } else {
        strcpy(election->candidates[election->num_candidates].name, name);
        election->candidates[election->num_candidates].votes = 0;
        election->num_candidates++;
        printf("Candidate %s added successfully!\n", name);
    }
}

void add_voter(struct Election *election, char *name) {
    if(election->num_voters >= 50) {
        printf("Error: Maximum Voters limit reached.\n");
    } else {
        strcpy(election->voters[election->num_voters].name, name);
        election->voters[election->num_voters].voted = 0;
        election->num_voters++;
        printf("Voter %s added successfully!\n", name);
    }
}

void cast_vote(struct Election *election, char *voter_name, char *candidate_name) {
    int i, voter_index = -1, candidate_index = -1;
    for(i=0; i<election->num_voters; i++) {
        if(strcmp(election->voters[i].name, voter_name) == 0) {
            voter_index = i;
            break;
        }
    }
    if(voter_index == -1 || election->voters[voter_index].voted) {
        printf("Error: Voter not found or already voted.\n");
        return;
    }
    for(i=0; i<election->num_candidates; i++) {
        if(strcmp(election->candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }
    if(candidate_index == -1) {
        printf("Error: Candidate not found.\n");
        return;
    }
    election->candidates[candidate_index].votes++;
    election->voters[voter_index].voted = 1;
    printf("Vote casted successfully!\n");
}

void print_result(struct Election *election) {
    int i;
    printf("\nCandidate\tVotes\n");
    for(i=0; i<election->num_candidates; i++) {
        printf("%s\t\t%d\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

int main() {
    struct Election election;
    election.num_candidates = 0;
    election.num_voters = 0;
    int ch;
    char name[50], candidate[50], voter[50];
    while(1) {
        printf("\nElection Panel\n");
        printf("1. Add Candidate\n2. Add Voter\n3. Cast Vote\n4. View Result\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(&election, name);
                break;
            case 2:
                printf("Enter voter name: ");
                scanf("%s", name);
                add_voter(&election, name);
                break;
            case 3:
                printf("Enter voter name: ");
                scanf("%s", voter);
                printf("Enter candidate name: ");
                scanf("%s", candidate);
                cast_vote(&election, voter, candidate);
                break;
            case 4:
                print_result(&election);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Error: Invalid Choice.\n");
                break;
        }
    }
    return 0;
}