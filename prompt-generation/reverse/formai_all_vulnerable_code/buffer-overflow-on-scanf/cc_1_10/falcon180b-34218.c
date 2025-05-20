//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int candidate;
} Voter;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int num_voters = 0;
int num_candidates = 0;

void add_voter() {
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    printf("Enter voter password: ");
    scanf("%s", voters[num_voters].password);
    printf("Enter candidate number: ");
    scanf("%d", &voters[num_voters].candidate);
    num_voters++;
}

int authenticate_voter(char* name, char* password) {
    int i;
    for(i=0; i<num_voters; i++) {
        if(!strcmp(voters[i].name, name) &&!strcmp(voters[i].password, password)) {
            return 1;
        }
    }
    return 0;
}

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    num_candidates++;
}

void vote() {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int candidate;
    int i;

    printf("Enter voter name: ");
    scanf("%s", name);
    printf("Enter voter password: ");
    scanf("%s", password);

    i = authenticate_voter(name, password);

    if(i == 1) {
        printf("Enter candidate number: ");
        scanf("%d", &candidate);
        candidates[candidate-1].votes++;
    } else {
        printf("Invalid credentials\n");
    }
}

void show_results() {
    int i;
    printf("\nResults:\n");
    for(i=0; i<num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add voter\n");
        printf("2. Add candidate\n");
        printf("3. Vote\n");
        printf("4. Show results\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_voter();
                break;
            case 2:
                add_candidate();
                break;
            case 3:
                vote();
                break;
            case 4:
                show_results();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}