//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define a macro for storing maximum number of voters
#define MAX_VOTERS 100

// define a global variable for keeping track of the number of voters
int num_voters = 0;

// define a structure for storing voter information
struct Voter {
    char name[50];
    int age;
    char address[100];
    int voted;
} voters[MAX_VOTERS];

// function to add a new voter
void add_voter(char name[], int age, char address[]) {
    if(num_voters >= MAX_VOTERS) {
        printf("\nMaximum number of voters reached!");
        return;
    }
    struct Voter v;
    strcpy(v.name, name);
    v.age = age;
    strcpy(v.address, address);
    v.voted = 0;
    voters[num_voters++] = v;
    printf("\nNew voter added successfully!");
}

// function to get the index of a voter by name
int get_voter_index(char name[]) {
    int i;
    for(i=0; i<num_voters; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// function to cast a vote
void cast_vote(char name[]) {
    int index = get_voter_index(name);
    if(index == -1) {
        printf("\nInvalid voter name!");
    } else if(voters[index].voted) {
        printf("\n%s has already cast a vote!", name);
    } else {
        printf("\n%s, please cast your vote.", name);
        // code to take input from the user and record the vote goes here
        voters[index].voted = 1;
        printf("\nThank you for casting your vote, %s!", name);
    }
}

int main() {
    int choice, age;
    char name[50], address[100];
    
    while(1) {
        printf("\nEnter your choice:");
        printf("\n1. Add new voter");
        printf("\n2. Cast a vote");
        printf("\n3. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter voter name:");
                scanf("%s", name);
                printf("Enter voter age:");
                scanf("%d", &age);
                printf("Enter voter address:");
                scanf("%s", address);
                add_voter(name, age, address);
                break;
            case 2:
                printf("\nEnter voter name:");
                scanf("%s", name);
                cast_vote(name);
                break;
            case 3:
                printf("\nExiting program...");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!");
        }
    }
    
    return 0;
}