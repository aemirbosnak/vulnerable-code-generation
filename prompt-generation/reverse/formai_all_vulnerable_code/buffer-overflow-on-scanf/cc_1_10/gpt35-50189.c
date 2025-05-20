//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

int votes[MAX_VOTERS][MAX_CANDIDATES];
int candidate_count;
int voter_count;

void print_winner(int *arr);
void vote(int *arr, int voter, int candidate);
int is_valid_candidate(int candidate);
int is_valid_voter(int voter);
int is_winner(int candidate);
int get_top_candidate_index(int *arr, int n);
void count_votes(int *arr, int candidate_index, int count);

void count_votes(int *arr, int candidate_index, int count){
    for (int i = 0; i < voter_count; i++) {
        if (*(arr + i * candidate_count + candidate_index) == 1) {
            count++;
        }
    }
}

int get_top_candidate_index(int *arr, int n) {
    int candidate_index = 0;
    int count = 0;

    for (int i = 0; i < candidate_count; i++) {
        int candidate_count = 0;
        count_votes(arr, i, candidate_count);

        if (candidate_count > count) {
            candidate_index = i;
            count = candidate_count;
        }
    }

    return candidate_index;
}

int is_winner(int candidate) {
    int count = 0;

    for (int i = 0; i < voter_count; i++) {
        if (votes[i][candidate] == 1) {
            count++;
        }
    }

    if (count > voter_count / 2) {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_voter(int voter) {
    if (voter < 0 || voter >= voter_count) {
        return 0;
    }

    return 1;
}

int is_valid_candidate(int candidate) {
    if (candidate < 0 || candidate >= candidate_count) {
        return 0;
    }

    return 1;
}

void vote(int *arr, int voter, int candidate) {
    if (!is_valid_voter(voter)) {
        printf("Invalid voter id %d\n", voter);
        return;
    }

    if (!is_valid_candidate(candidate)) {
        printf("Invalid candidate id %d\n", candidate);
        return;
    }

    *(arr + voter * candidate_count + candidate) = 1;
}

void print_winner(int *arr) {
    int candidate_index = get_top_candidate_index(arr, voter_count);

    if (is_winner(candidate_index)) {
        printf("Winner is candidate %d\n", candidate_index + 1);
    } else {
        printf("No winner found, going for another round of voting\n");

        for (int i = 0; i < voter_count; i++) {
            int candidate;
            printf("Enter vote for voter %d: ", i + 1);
            scanf("%d", &candidate);

            vote(arr, i, candidate - 1);
        }

        print_winner(arr);
    }
}

int main() {
    printf("Enter number of candidates: ");
    scanf("%d", &candidate_count);

    printf("Enter number of voters: ");
    scanf("%d", &voter_count);

    for (int i = 0; i < voter_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            votes[i][j] = 0;
        }
    }

    for (int i = 0; i < voter_count; i++) {
        int candidate;

        printf("Enter vote for voter %d: ", i + 1);
        scanf("%d", &candidate);

        vote((int *) votes, i, candidate - 1);
    }

    print_winner((int *) votes);

    return 0;
}