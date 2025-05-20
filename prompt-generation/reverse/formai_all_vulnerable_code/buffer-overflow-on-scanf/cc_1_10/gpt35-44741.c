//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

struct Candidate {
    int id;
    char name[50];
    int vote_count;
};

int main() {
    struct Candidate candidates[5]; //array of candidates
    int choice = 0, i, vote_count = 0;
    int id;

    //initialize candidates
    candidates[0].id = 1;
    strcpy(candidates[0].name, "John");
    candidates[0].vote_count = 0;

    candidates[1].id = 2;
    strcpy(candidates[1].name, "Jane");
    candidates[1].vote_count = 0;

    candidates[2].id = 3;
    strcpy(candidates[2].name, "Bob");
    candidates[2].vote_count = 0;

    candidates[3].id = 4;
    strcpy(candidates[3].name, "Samantha");
    candidates[3].vote_count = 0;
    
    candidates[4].id = 5;
    strcpy(candidates[4].name, "David");
    candidates[4].vote_count = 0;

    while (choice != -1) {
        //display menu
        printf("\nPlease select a candidate by entering his/her ID number followed by the Enter key:\n");
        for (i = 0; i < 5; i++)
            printf("%d. %s\n", candidates[i].id, candidates[i].name);
        printf("\nEnter -1 to quit.\n");

        //read user input
        scanf("%d", &id);

        //check if user wants to quit
        if (id == -1) {
            printf("Goodbye!");
            break;
        }

        //validate user input
        for (i = 0; i < 5; i++)
            if (id == candidates[i].id) {
                candidates[i].vote_count++; //increment vote count of the candidate
                vote_count++; //increment total vote count
                break;
            }

        if (i == 5)
            printf("Invalid candidate ID.\n");
    }

    //print voting results
    printf("\nVoting has ended. Here are the results:\n");
    for (i = 0; i < 5; i++)
        printf("%s - %d votes\n", candidates[i].name, candidates[i].vote_count);
    printf("Total votes: %d\n", vote_count);

    //determine winner
    int max_votes = 0, winner_index = 0;
    for (i = 0; i < 5; i++) {
        if (candidates[i].vote_count > max_votes) {
            max_votes = candidates[i].vote_count;
            winner_index = i;
        }
    }
    printf("\nWinner: %s with %d votes!\n", candidates[winner_index].name, max_votes);

    return 0;
}