//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vote {
    char candidate_name[50];
    int num_votes;
} Vote;

void add_candidate(Vote *candidate_list, int *num_candidates) {
    printf("Enter the name of the candidate:\n");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < *num_candidates; i++) {
        if (strcmp(name, candidate_list[i].candidate_name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }
    strcpy(candidate_list[*num_candidates].candidate_name, name);
    candidate_list[*num_candidates].num_votes = 0;
    printf("Candidate added successfully!\n");
    (*num_candidates)++;
}

void cast_vote(Vote *candidate_list, int num_candidates) {
    printf("Enter the name of the candidate:\n");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_candidates; i++) {
        if (strcmp(name, candidate_list[i].candidate_name) == 0) {
            candidate_list[i].num_votes++;
            printf("Vote casted successfully!\n");
            return;
        }
    }
    printf("Candidate does not exist.\n");
}

void print_results(Vote *candidate_list, int num_candidates) {
    printf("Candidate\tVotes Received\n");
    int i;
    for (i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidate_list[i].candidate_name, candidate_list[i].num_votes);
    }
}

int main() {
    int num_candidates = 0;
    Vote candidate_list[20];
    int choice;
    do {
        printf("Electronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Print Results\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_candidate(candidate_list, &num_candidates);
                break;
            case 2:
                cast_vote(candidate_list, num_candidates);
                break;
            case 3:
                print_results(candidate_list, num_candidates);
                break;
            case 4:
                printf("Thanks for using the Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}