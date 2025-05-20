//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
// Post-Apocalyptic Voting System

#include <stdio.h>

struct Voter {
    char name[20];
    int age;
    char candidate[20];
};

struct Voter voters[100];
int num_voters = 0;
int num_candidates;
char candidates[100][20];

void add_voter(char name[], int age, char candidate[]) {
    struct Voter voter;
    strcpy(voter.name, name);
    voter.age = age;
    strcpy(voter.candidate, candidate);
    voters[num_voters] = voter;
    num_voters++;
}

void print_voters() {
    int i;
    printf("Voter List:\n");
    for (i = 0; i < num_voters; i++) {
        printf("%s, %d, %s\n", voters[i].name, voters[i].age, voters[i].candidate);
    }
}

int count_votes(char candidate[]) {
    int i, count = 0;
    for (i = 0; i < num_voters; i++) {
        if (strcmp(candidates[i], candidate) == 0) {
            count++;
        }
    }
    return count;
}

char* winner() {
    int i, max = 0, winner_index;
    char* winner = (char*)malloc(100);
    for (i = 0; i < num_candidates; i++) {
        if (count_votes(candidates[i]) > max) {
            max = count_votes(candidates[i]);
            winner_index = i;
        }
    }
    strcpy(winner, candidates[winner_index]);
    return winner;
}

int main() {
    int i;
    printf("Number of Candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the name of each candidate: ");
    for (i = 0; i < num_candidates; i++) {
        fgets(candidates[i], 100, stdin);
    }
    printf("Number of Voters: ");
    scanf("%d", &num_voters);
    printf("Enter the name, age, and candidate for each voter: ");
    for (i = 0; i < num_voters; i++) {
        fgets(candidates[i], 100, stdin);
    }
    add_voter(candidates[0], 0, "A");
    add_voter(candidates[1], 0, "B");
    add_voter(candidates[2], 0, "C");
    print_voters();
    printf("Winner: %s\n", winner());
    return 0;
}