//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store Candidate Information
struct candidate {
    int id;
    char name[50];
    int votes;
};

// Structure to store Voter Information
struct voter {
    int id;
    char name[50];
    int voted;
};

// Function to add a new candidate
void add_candidate(struct candidate* ptr, int* count) {
    printf("Enter candidate name: ");
    scanf("%s", ptr[*count].name);
    ptr[*count].id = *count+1;
    ptr[*count].votes = 0;
    *count += 1;
    printf("Candidate added successfully.\n");
}

// Function to add a new voter
void add_voter(struct voter* ptr, int* count) {
    printf("Enter voter name: ");
    scanf("%s", ptr[*count].name);
    ptr[*count].id = *count+1;
    ptr[*count].voted = 0;
    *count += 1;
    printf("Voter added successfully.\n");
}

// Function to display candidate list
void display_candidates(struct candidate* ptr, int count) {
    printf("List of Candidates:\n");
    for(int i=0; i<count; i++) {
        printf("%d. %s (%d votes)\n", ptr[i].id, ptr[i].name, ptr[i].votes);
    }
    printf("\n");
}

// Function to display voter list
void display_voters(struct voter* ptr, int count) {
    printf("List of Voters:\n");
    for(int i=0; i<count; i++) {
        printf("%d. %s", ptr[i].id, ptr[i].name);
        if(ptr[i].voted)
            printf(" (Voted)\n");
        else
            printf("\n");
    }
    printf("\n");
}

int main() {
    int candidate_count = 0, voter_count = 0, voting_done = 0;
    struct candidate candidates[50];
    struct voter voters[50];

    // Adding Candidates
    add_candidate(candidates, &candidate_count);
    add_candidate(candidates, &candidate_count);
    add_candidate(candidates, &candidate_count);
    add_candidate(candidates, &candidate_count);
    add_candidate(candidates, &candidate_count);

    // Adding Voters
    add_voter(voters, &voter_count);
    add_voter(voters, &voter_count);
    add_voter(voters, &voter_count);
    add_voter(voters, &voter_count);
    add_voter(voters, &voter_count);
    add_voter(voters, &voter_count);

    // Displaying Candidate and Voter List
    display_candidates(candidates, candidate_count);
    display_voters(voters, voter_count);

    // Voting Process
    while(!voting_done) {
        int voter_id, candidate_id;

        printf("Enter Voter ID (0 to QUIT): ");
        scanf("%d", &voter_id);

        if(voter_id == 0)
            break;

        // Checking if Voter has already Voted
        if(voters[voter_id-1].voted) {
            printf("You have already Voted.\n\n");
            continue;
        }

        printf("Enter Candidate ID to Vote: ");
        scanf("%d", &candidate_id);

        // Checking if Candidate ID is Valid
        if(candidate_id < 1 || candidate_id > candidate_count) {
            printf("Invalid Candidate ID.\n\n");
            continue;
        }

        // Voting Done Successfully
        voters[voter_id-1].voted = 1;
        candidates[candidate_id-1].votes += 1;
        printf("Voted successfully.\n\n");
    }

    // Displaying Final Result
    display_candidates(candidates, candidate_count);
    printf("Voting System Closed.\n");

    return 0;
}