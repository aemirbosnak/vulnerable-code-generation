//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 50
#define MAX_NAME_LENGTH 20

typedef struct candidate {
    int id;
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

int search_by_id(int id) {
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].id == id)
            return i;
    }
    return -1;
}

void add_candidate() {
    if(num_candidates >= MAX_CANDIDATES) {
        printf("Sorry, maximum limit for candidates has been reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    Candidate c = {
        .id = num_candidates + 1,
        .votes = 0
    };
    strcpy(c.name, name);

    candidates[num_candidates++] = c;

    printf("Candidate added successfully!\n");
}

void list_candidates() {
    printf("ID\tName\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d\t%s\n", candidates[i].id, candidates[i].name);
    }
}

void cast_vote() {
    printf("Enter candidate ID to vote for: ");
    int id;
    scanf("%d", &id);

    int index = search_by_id(id);
    if(index < 0) {
        printf("Invalid candidate ID!\n");
        return;
    }

    candidates[index].votes++;

    printf("Vote casted successfully!\n");
}

void show_stats() {
    printf("Vote Statistics\n");
    printf("ID\tName\tVotes\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    int choice;

    do {
        printf("Menu\n----\n");
        printf("1. Add Candidate\n");
        printf("2. List Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Show Statistics\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                list_candidates();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                show_stats();
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}