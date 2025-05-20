//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

//function to display candidates
void displayCandidates() {
    printf("*** List of Candidates ***\n");
    printf("1. John\n");
    printf("2. Jane\n");
    printf("3. Michael\n");
    printf("4. Sarah\n");
    printf("5. Richard\n");
    printf("***********************\n\n");
}

//function to count votes for each candidate
void castVote(int *count) {
    displayCandidates();
    int choice;
    printf("Enter the candidate number you wish to vote for: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            *(count + 0) += 1;  //increment vote count for John
            break;
        case 2:
            *(count + 1) += 1;  //increment vote count for Jane
            break;
        case 3:
            *(count + 2) += 1;  //increment vote count for Michael
            break;
        case 4:
            *(count + 3) += 1;  //increment vote count for Sarah
            break;
        case 5:
            *(count + 4) += 1;  //increment vote count for Richard
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

//function to display total votes for each candidate
void displayResults(int *count) {
    printf("*** Total Votes for Each Candidate ***\n");
    printf("John: %d\n", *(count + 0));
    printf("Jane: %d\n", *(count + 1));
    printf("Michael: %d\n", *(count + 2));
    printf("Sarah: %d\n", *(count + 3));
    printf("Richard: %d\n", *(count + 4));
    printf("*************************************\n\n");
}

//main function
int main() {
    printf("*** Welcome to Electronic Voting System ***\n");
    int count[5] = {0, 0, 0, 0, 0};  //initialize vote count to zero for all candidates

    int option;
    do {
        printf("Select an option:\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                castVote(count);
                break;
            case 2:
                displayResults(count);
                break;
            case 3:
                printf("Thank you for using Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(option != 3);

    return 0;
}