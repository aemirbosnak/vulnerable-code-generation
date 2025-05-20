//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 100

typedef struct {
    int romeoVotes;
    int julietVotes;
    int totalVotes;
} VoteCount;

typedef struct {
    char *voterName;
} Voter;

Voter voters[MAX_VOTERS];
VoteCount voteCount = {0, 0, 0};

void displayVotes() {
    printf("\nCurrent Vote Count:\n");
    printf("Romeo: %d votes\n", voteCount.romeoVotes);
    printf("Juliet: %d votes\n", voteCount.julietVotes);
    printf("Total Votes: %d\n", voteCount.totalVotes);
}

void castVote() {
    char name[50];
    char choice;

    printf("Enter your name (O, dear Voter!): ");
    scanf("%s", name);

    for (int i = 0; i < voteCount.totalVotes; i++) {
        if (strcmp(voters[i].voterName, name) == 0) {
            printf("Alas! You have already cast your vote, %s.\n", name);
            return;
        }
    }

    printf("Whom dost thou favor? (r for Romeo, j for Juliet): ");
    scanf(" %c", &choice);

    if (choice == 'r') {
        voteCount.romeoVotes++;
        printf("Thy vote for Romeo has been counted, %s. Romantic, indeed!\n", name);
    } else if (choice == 'j') {
        voteCount.julietVotes++;
        printf("Thy vote for Juliet has been counted, %s. A fair choice!\n", name);
    } else {
        printf("What madness is this? Please vote either 'r' or 'j'.\n");
        return;
    }

    voters[voteCount.totalVotes].voterName = strdup(name);
    voteCount.totalVotes++;
}

void displayResults() {
    printf("\n** Final Results **\n");
    displayVotes();
    if (voteCount.romeoVotes > voteCount.julietVotes) {
        printf("Alas! The winner is Romeo! The maiden shall weep...\n");
    } else if (voteCount.julietVotes > voteCount.romeoVotes) {
        printf("Hark! The winner is Juliet! Love shall prevail!\n");
    } else {
        printf("What tragedy! Tis a tie! Both Romeo and Juliet remain beloved!\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Dare ye participate in this fateful voting? (Yes: 1 / No: 0): ");
    scanf("%d", &choice);

    if (choice != 1) {
        printf("Very well, withdraw thyself from this fate!\n");
        return 0;
    }

    do {
        printf("\n1. Cast a vote\n");
        printf("2. Display current votes\n");
        printf("3. Show final results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                displayVotes();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Farewell, noble voter! May love guide your heart!\n");
                exit(0);
            default:
                printf("What jest is this? Please choose a valid option.\n");
        }
    } while (1);

    return 0;
}