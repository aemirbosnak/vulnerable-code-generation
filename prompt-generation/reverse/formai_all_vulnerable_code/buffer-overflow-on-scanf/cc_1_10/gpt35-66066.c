//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>

// Define the maximum number of voters allowed in the system
#define MAX_VOTERS 100

// Define the maximum number of candidates allowed in the system
#define MAX_CANDIDATES 10

// Define the structure for storing voter information
struct voter {
    int id;
    char name[50];
    int age;
    char address[100];
};

// Define the structure for storing candidate information
struct candidate {
    int id;
    char name[50];
    char party[50];
    int votes;
};

// Declare global variables
struct voter voters[MAX_VOTERS];
struct candidate candidates[MAX_CANDIDATES];
int num_voters = 0;
int num_candidates = 0;

// Function to add voter to the system
void add_voter() {
    struct voter new_voter;
    printf("Enter Voter ID: ");
    scanf("%d", &new_voter.id);
    printf("Enter Voter Name: ");
    scanf("%s", new_voter.name);
    printf("Enter Voter Age: ");
    scanf("%d", &new_voter.age);
    printf("Enter Voter Address: ");
    scanf("%s", new_voter.address);
    voters[num_voters] = new_voter;
    num_voters++;
}

// Function to add candidate to the system
void add_candidate() {
    struct candidate new_candidate;
    printf("Enter Candidate ID: ");
    scanf("%d", &new_candidate.id);
    printf("Enter Candidate Name: ");
    scanf("%s", new_candidate.name);
    printf("Enter Candidate Party: ");
    scanf("%s", new_candidate.party);
    new_candidate.votes = 0;
    candidates[num_candidates] = new_candidate;
    num_candidates++;
}

// Function to display all the voters in the system
void display_voters() {
    printf("List of Voters:\n");
    for (int i=0; i<num_voters; i++) {
        printf("ID: %d, Name: %s, Age: %d, Address: %s\n", voters[i].id, voters[i].name, voters[i].age, voters[i].address);
    }
}

// Function to display all the candidates in the system
void display_candidates() {
    printf("List of Candidates:\n");
    for (int i=0; i<num_candidates; i++) {
        printf("ID: %d, Name: %s, Party: %s, Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].party, candidates[i].votes);
    }
}

// Function to cast a vote
void vote() {
    int voter_id, candidate_id;
    printf("Enter Voter ID: ");
    scanf("%d", &voter_id);
    for (int i=0; i<num_voters; i++) {
        if (voter_id == voters[i].id) {
            printf("Enter Candidate ID: ");
            scanf("%d", &candidate_id);
            for (int j=0; j<num_candidates; j++) {
                if (candidate_id == candidates[j].id) {
                    candidates[j].votes++;
                    printf("Vote casted successfully!\n");
                    return;
                }
            }
            printf("Invalid Candidate ID! Please try again.\n");
            return;
        }
    }
    printf("Invalid Voter ID! Please try again.\n");
}

int main() {
    int choice;
    printf("Welcome to the Electronic Voting System!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add Voter\n");
        printf("2. Add Candidate\n");
        printf("3. Display Voters\n");
        printf("4. Display Candidates\n");
        printf("5. Cast Vote\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_voter();
                break;
            case 2:
                add_candidate();
                break;
            case 3:
                display_voters();
                break;
            case 4:
                display_candidates();
                break;
            case 5:
                vote();
                break;
            case 6:
                printf("Thank you for using the Electronic Voting System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}