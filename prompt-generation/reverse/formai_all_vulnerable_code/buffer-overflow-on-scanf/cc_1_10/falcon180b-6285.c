//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 10

typedef struct {
    char name[100];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[100];
    int age;
    int gender;
    int votes[MAX_CANDIDATES];
} Voter;

void read_candidates(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
    }
}

void read_voters(Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        printf("Enter voter age: ");
        scanf("%d", &voters[i].age);
        printf("Enter voter gender (1 for male, 2 for female): ");
        scanf("%d", &voters[i].gender);
    }
}

int compare_candidates(const void *a, const void *b) {
    Candidate *candidate_a = (Candidate *)a;
    Candidate *candidate_b = (Candidate *)b;
    return strcmp(candidate_a->name, candidate_b->name);
}

int compare_votes(const void *a, const void *b) {
    Voter *voter_a = (Voter *)a;
    Voter *voter_b = (Voter *)b;
    return voter_a->votes[0] - voter_b->votes[0];
}

void count_votes(Candidate candidates[], Voter voters[], int num_candidates, int num_voters) {
    qsort(candidates, num_candidates, sizeof(Candidate), compare_candidates);
    for (int i = 0; i < num_voters; i++) {
        int max_votes = 0;
        int max_index = 0;
        for (int j = 0; j < num_candidates; j++) {
            if (voters[i].votes[j] > max_votes) {
                max_votes = voters[i].votes[j];
                max_index = j;
            }
        }
        candidates[max_index].votes[0]++;
    }
}

void print_results(Candidate candidates[], int num_candidates) {
    printf("Election results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes[0]);
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    Candidate candidates[num_candidates];
    read_candidates(candidates, num_candidates);

    Voter voters[num_voters];
    read_voters(voters, num_voters);

    count_votes(candidates, voters, num_candidates, num_voters);

    print_results(candidates, num_candidates);

    return 0;
}