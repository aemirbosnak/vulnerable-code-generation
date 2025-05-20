//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 300

struct candidate {
    int id;
    char name[20];
    int votes;
};

struct voter {
    int id;
    char name[20];
    int voted; //0 for not voted, 1 for voted
    int vote; //candidate id
};

struct candidate candidates[MAX_CANDIDATES];
struct voter voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

void add_candidate() {
    char name[20];
    printf("\nEnter candidate name: ");
    scanf("%s", name);
    candidates[num_candidates].id = num_candidates + 1;
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void view_candidates() {
    printf("\nID\tName\tVotes\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

int login_voter(int id) {
    for(int i=0; i<num_voters; i++) {
        if(voters[i].id == id) {
            if(voters[i].voted == 0) {
                return i;
            } else {
                printf("\nYou have already voted!\n");
                return -1;
            }
        }
    }
    printf("\nInvalid voter ID!\n");
    return -1;
}

void vote() {
    int id;
    printf("\nEnter your voter ID: ");
    scanf("%d", &id);
    int index = login_voter(id);
    if(index != -1) {
        int candidate_id;
        printf("\nChoose your candidate from the following:");
        view_candidates();
        printf("\nEnter candidate ID: ");
        scanf("%d", &candidate_id);
        voters[index].voted = 1;
        voters[index].vote = candidate_id;
        candidates[candidate_id-1].votes++;
        printf("\nThank you for voting!\n");
    }
}

void add_voter() {
    char name[20];
    printf("\nEnter voter name: ");
    scanf("%s", name);
    voters[num_voters].id = num_voters + 1;
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted = 0;
    num_voters++;
}

void view_voters() {
    printf("\nID\tName\tVoted\tVote\n");
    for(int i=0; i<num_voters; i++) {
        printf("%d\t%s\t%d\t%d\n", voters[i].id, voters[i].name, voters[i].voted, voters[i].vote);
    }
}

void menu() {
    int choice;
    do {
        printf("\n\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. View candidates\n");
        printf("3. Add voter\n");
        printf("4. View voters\n");
        printf("5. Vote\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                view_candidates();
                break;
            case 3:
                add_voter();
                break;
            case 4:
                view_voters();
                break;
            case 5:
                vote();
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 6);
}

int main() {
    menu();
    return 0;
}