//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>

// function to validate voter ID
int validate_voter_id(int voter_id) {
    if(voter_id >= 100000 && voter_id <= 999999) {
        return 1;
    } else {
        return 0;
    }
}

// function to validate vote choice
int validate_vote_choice(int choice) {
    if(choice >= 1 && choice <= 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int voter_id, vote_choice;
    int candidate1_votes = 0, candidate2_votes = 0, candidate3_votes = 0, candidate4_votes = 0, candidate5_votes = 0;
    
    printf("Welcome to the Futuristic Electronic Voting System!\n");
    printf("Please enter your voter ID (6-digit number): ");
    scanf("%d", &voter_id);
    
    int is_valid_voter_id = validate_voter_id(voter_id);
    if(is_valid_voter_id) {
        printf("You are a valid voter. Please select your preferred candidate from the list below:\n");
        printf("1. Candidate 1\n");
        printf("2. Candidate 2\n");
        printf("3. Candidate 3\n");
        printf("4. Candidate 4\n");
        printf("5. Candidate 5\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &vote_choice);
        
        int is_valid_vote_choice = validate_vote_choice(vote_choice);
        if(is_valid_vote_choice) {
            switch(vote_choice) {
                case 1:
                    candidate1_votes++;
                    break;
                case 2:
                    candidate2_votes++;
                    break;
                case 3:
                    candidate3_votes++;
                    break;
                case 4:
                    candidate4_votes++;
                    break;
                case 5:
                    candidate5_votes++;
                    break;
                default:
                    printf("Invalid vote choice.\n");
            }
            
            printf("Thank you for your vote!\n");
        } else {
            printf("Invalid vote choice.\n");
        }
    } else {
        printf("Invalid voter ID. Please try again.\n");
    }
    
    printf("Vote count so far:\n");
    printf("Candidate 1: %d\n", candidate1_votes);
    printf("Candidate 2: %d\n", candidate2_votes);
    printf("Candidate 3: %d\n", candidate3_votes);
    printf("Candidate 4: %d\n", candidate4_votes);
    printf("Candidate 5: %d\n", candidate5_votes);
    
    return 0;
}