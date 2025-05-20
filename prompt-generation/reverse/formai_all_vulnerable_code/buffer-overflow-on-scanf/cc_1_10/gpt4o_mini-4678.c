//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_PARTIES 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Party;

typedef struct {
    char voter_id[MAX_NAME_LENGTH];
    int has_voted;
} Voter;

Party parties[MAX_PARTIES];
Voter voters[MAX_VOTERS];
int total_parties = 0;
int total_voters = 0;

void init_parties() {
    printf("Enter the number of parties (max %d): ", MAX_PARTIES);
    scanf("%d", &total_parties);
    getchar();  // Consume newline character

    for (int i = 0; i < total_parties; i++) {
        printf("Enter name of party %d: ", i + 1);
        fgets(parties[i].name, MAX_NAME_LENGTH, stdin);
        parties[i].name[strcspn(parties[i].name, "\n")] = 0;  // Remove newline
        parties[i].votes = 0;
    }
}

void register_voter() {
    if (total_voters >= MAX_VOTERS) {
        printf("Voter registration limit reached!\n");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%s", voters[total_voters].voter_id);
    voters[total_voters].has_voted = 0;
    total_voters++;
}

int find_voter(const char* voter_id) {
    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1;
}

void cast_vote() {
    char voter_id[MAX_NAME_LENGTH];
    printf("Enter voter ID: ");
    scanf("%s", voter_id);

    int voter_index = find_voter(voter_id);
    if (voter_index == -1) {
        printf("Voter not found! Please register first.\n");
        return;
    }

    if (voters[voter_index].has_voted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Vote for one of the following parties:\n");
    for (int i = 0; i < total_parties; i++) {
        printf("%d. %s\n", i + 1, parties[i].name);
    }

    int choice;
    printf("Enter party number to vote (1 - %d): ", total_parties);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > total_parties) {
        printf("Invalid choice! Please try again.\n");
        return;
    }

    parties[choice - 1].votes++;
    voters[voter_index].has_voted = 1;
    printf("Thank you for voting!\n");
}

void show_results() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < total_parties; i++) {
        printf("%s: %d votes\n", parties[i].name, parties[i].votes);
    }
}

void reset_votes() {
    for (int i = 0; i < total_parties; i++) {
        parties[i].votes = 0;
    }
    printf("Voting has been reset!\n");
}

int main() {
    int choice;
    init_parties();
    
    while (1) {
        printf("\nElectronic Voting System Menu:\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Show Results\n");
        printf("4. Reset Votes\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_voter();
                break;
            case 2:
                cast_vote();
                break;
            case 3:
                show_results();
                break;
            case 4:
                reset_votes();
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}