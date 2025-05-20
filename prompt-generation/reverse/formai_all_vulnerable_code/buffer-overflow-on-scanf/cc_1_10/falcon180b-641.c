//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    char name[50];
    int voted;
    int choice;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

void add_candidate() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == '\0') {
            printf("Enter the name of the candidate: ");
            scanf("%s", candidates[i].name);
            candidates[i].votes = 0;
            break;
        }
    }
}

void add_voter() {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].name[0] == '\0') {
            printf("Enter the name of the voter: ");
            scanf("%s", voters[i].name);
            voters[i].voted = 0;
            voters[i].choice = -1;
            break;
        }
    }
}

void vote() {
    int i, j, choice;
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    for (i = 0; i < MAX_VOTERS; i++) {
        if (strcmp(voters[i].name, name) == 0 &&!voters[i].voted) {
            for (j = 0; j < MAX_CANDIDATES; j++) {
                if (candidates[j].name[0]!= '\0') {
                    printf("%d. %s\n", j + 1, candidates[j].name);
                }
            }

            printf("Enter the number of the candidate you want to vote for: ");
            scanf("%d", &choice);

            if (choice >= 1 && choice <= MAX_CANDIDATES) {
                candidates[choice - 1].votes++;
                voters[i].voted = 1;
                voters[i].choice = choice;
            } else {
                printf("Invalid choice.\n");
            }

            break;
        }
    }
}

void display_results() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0]!= '\0') {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    int choice;

    system("clear");

    add_candidate();
    add_candidate();
    add_candidate();

    add_voter();
    add_voter();

    while (1) {
        system("clear");
        printf("1. Add candidate\n2. Add voter\n3. Vote\n4. Display results\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_candidate();
            break;
        case 2:
            add_voter();
            break;
        case 3:
            vote();
            break;
        case 4:
            display_results();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}