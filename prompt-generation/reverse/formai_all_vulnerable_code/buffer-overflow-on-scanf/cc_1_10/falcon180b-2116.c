//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

void add_candidate(char* name) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }
    strcpy(candidates[MAX_CANDIDATES - 1].name, name);
    candidates[MAX_CANDIDATES - 1].votes = 0;
}

void add_voter(char* name, int age) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            printf("Voter already exists.\n");
            return;
        }
    }
    strcpy(voters[MAX_VOTERS - 1].name, name);
    voters[MAX_VOTERS - 1].age = age;
}

void vote(char* voter_name, int candidate_index) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            candidates[candidate_index].votes++;
            printf("Vote cast for %s.\n", candidates[candidate_index].name);
            return;
        }
    }
    printf("Voter not found.\n");
}

void display_results() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char choice;
    int i;
    do {
        printf("Enter your choice:\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Vote\n");
        printf("4. Display results\n");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            printf("Enter candidate name: ");
            scanf("%s", candidates[MAX_CANDIDATES - 1].name);
            break;
        case '2':
            printf("Enter voter name: ");
            scanf("%s", voters[MAX_VOTERS - 1].name);
            printf("Enter voter age: ");
            scanf("%d", &voters[MAX_VOTERS - 1].age);
            break;
        case '3':
            printf("Enter voter name: ");
            scanf("%s", voters[MAX_VOTERS - 1].name);
            printf("Enter candidate index (1-%d): ", MAX_CANDIDATES - 1);
            scanf("%d", &i);
            vote(voters[MAX_VOTERS - 1].name, i);
            break;
        case '4':
            display_results();
            break;
        }
    } while (choice!= '5');
    return 0;
}