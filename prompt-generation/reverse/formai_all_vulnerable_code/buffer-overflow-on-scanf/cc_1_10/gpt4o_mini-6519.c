//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_ISSUES 10
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    int has_voted;
} Voter;

typedef struct {
    char title[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int votes_for;
    int votes_against;
} Issue;

Voter voters[MAX_VOTERS];
Issue issues[MAX_ISSUES];
int voter_count = 0;
int issue_count = 0;

void register_voter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Voter registration full!\n");
        return;
    }
    
    printf("Enter your name (Max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", voters[voter_count].name);
    printf("Enter your age: ");
    scanf("%d", &voters[voter_count].age);
    voters[voter_count].has_voted = 0;
    
    voter_count++;
    printf("Voter registered: %s, Age: %d\n", voters[voter_count - 1].name, voters[voter_count - 1].age);
}

void create_issue() {
    if (issue_count >= MAX_ISSUES) {
        printf("Issue limit reached!\n");
        return;
    }
    
    printf("Enter issue title: ");
    scanf(" %[^\n]%*c", issues[issue_count].title); // allow spaces
    printf("Enter issue description: ");
    scanf(" %[^\n]%*c", issues[issue_count].description);
    
    issues[issue_count].votes_for = 0;
    issues[issue_count].votes_against = 0;
    issue_count++;
    
    printf("Issue created: %s\n", issues[issue_count - 1].title);
}

void vote() {
    char voter_name[MAX_NAME_LEN];
    
    printf("Enter your name to vote: ");
    scanf("%s", voter_name);
    
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            if (voters[i].has_voted) {
                printf("You have already voted!\n");
                return;
            }
            
            printf("Available issues to vote on:\n");
            for (int j = 0; j < issue_count; j++) {
                printf("%d: %s\n", j + 1, issues[j].title);
            }
            
            int choice;
            printf("Select an issue to vote on (number): ");
            scanf("%d", &choice);
            choice--; // Adjust for zero-based index

            if (choice < 0 || choice >= issue_count) {
                printf("Invalid choice!\n");
                return;
            }

            printf("Vote for (1) For or (2) Against: ");
            int decision;
            scanf("%d", &decision);
            if (decision == 1) {
                issues[choice].votes_for++;
            } else if (decision == 2) {
                issues[choice].votes_against++;
            } else {
                printf("Invalid decision!\n");
                return;
            }

            voters[i].has_voted = 1;
            printf("Your vote has been registered!\n");
            return;
        }
    }
    
    printf("Voter not found!\n");
}

void display_results() {
    for (int i = 0; i < issue_count; i++) {
        printf("Results for %s:\n", issues[i].title);
        printf("Votes For: %d, Votes Against: %d\n", issues[i].votes_for, issues[i].votes_against);
    }
}

int main() {
    int option;

    while (1) {
        printf("Cyberpunk Electronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Create Issue\n");
        printf("3. Vote\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            register_voter();
            break;
        case 2:
            create_issue();
            break;
        case 3:
            vote();
            break;
        case 4:
            display_results();
            break;
        case 5:
            printf("Exiting... Stay safe in the grid!\n");
            exit(0);
        default:
            printf("Invalid option! Please choose again.\n");
            break;
        }
    }

    return 0;
}