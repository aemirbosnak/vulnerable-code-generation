//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOTERS 5
#define CANDIDATES 3

typedef struct {
    char name[30];
    int candidate;
} Voter;

void init_voters(Voter voters[VOTERS]) {
    for (int i = 0; i < VOTERS; i++) {
        voters[i].candidate = -1;
    }
}

void display_menu(Voter voters[VOTERS]) {
    printf("Electronic Voting System\n");
    printf("=======================\n");
    printf("1. Register to vote\n");
    printf("2. View candidates\n");
    printf("3. Cast your vote\n");
    printf("4. Exit\n");
}

int main() {
    srand(time(NULL));
    Voter voters[VOTERS];
    init_voters(voters);
    int choice;

    while (1) {
        display_menu(voters);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", voters[0].name);
                printf("You are now registered to vote!\n");
                break;
            case 2:
                printf("The candidates are:\n");
                for (int i = 0; i < CANDIDATES; i++) {
                    printf("%d. %s\n", i + 1, "Candidate " + i);
                }
                break;
            case 3:
                if (voters[0].candidate == -1) {
                    printf("You have not selected a candidate yet.\n");
                } else {
                    printf("You have selected candidate %d.\n", voters[0].candidate + 1);
                }
                break;
            case 4:
                printf("Thank you for using our Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}