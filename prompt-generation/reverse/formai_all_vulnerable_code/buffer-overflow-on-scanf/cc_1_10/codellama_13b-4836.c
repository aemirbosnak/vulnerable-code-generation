//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the voter information
struct Voter {
    int id;
    char name[50];
    int age;
    char gender;
    char city[50];
};

// Structure to store the election information
struct Election {
    char name[50];
    int num_candidates;
    int num_voters;
    struct Voter* voters;
    char* candidates[10];
};

// Function to read and store the voter information
void read_voters(struct Election* election) {
    int i;
    for (i = 0; i < election->num_voters; i++) {
        struct Voter* voter = &election->voters[i];
        printf("Enter the voter's ID: ");
        scanf("%d", &voter->id);
        printf("Enter the voter's name: ");
        scanf("%s", voter->name);
        printf("Enter the voter's age: ");
        scanf("%d", &voter->age);
        printf("Enter the voter's gender: ");
        scanf(" %c", &voter->gender);
        printf("Enter the voter's city: ");
        scanf("%s", voter->city);
    }
}

// Function to read and store the election information
void read_election(struct Election* election) {
    printf("Enter the election name: ");
    scanf("%s", election->name);
    printf("Enter the number of candidates: ");
    scanf("%d", &election->num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &election->num_voters);
    election->voters = (struct Voter*)malloc(election->num_voters * sizeof(struct Voter));
    read_voters(election);
}

// Function to display the election results
void display_results(struct Election* election) {
    int i;
    for (i = 0; i < election->num_candidates; i++) {
        printf("%s: ", election->candidates[i]);
        int num_votes = 0;
        int j;
        for (j = 0; j < election->num_voters; j++) {
            struct Voter* voter = &election->voters[j];
            if (strcmp(voter->name, election->candidates[i]) == 0) {
                num_votes++;
            }
        }
        printf("%d\n", num_votes);
    }
}

int main() {
    struct Election election;
    read_election(&election);
    display_results(&election);
    return 0;
}