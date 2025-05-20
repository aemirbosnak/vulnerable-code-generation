//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Alan Turing
#include <stdio.h>

// Function to print the menu
void printMenu() {
    printf("1. Register to vote\n");
    printf("2. Vote\n");
    printf("3. View results\n");
    printf("4. Exit\n");
}

// Function to register a new voter
void registerVoter() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    // Save the voter's name to a file or database
    FILE *file = fopen("voters.txt", "a");
    fprintf(file, "%s\n", name);
    fclose(file);

    printf("You have been registered to vote.\n");
}

// Function to cast a vote
void vote() {
    char choice[10];
    printf("Enter your choice (1-3): ");
    scanf("%s", choice);

    // Save the vote to a file or database
    FILE *file = fopen("votes.txt", "a");
    fprintf(file, "%s\n", choice);
    fclose(file);

    printf("Your vote has been cast.\n");
}

// Function to view the results
void viewResults() {
    FILE *file = fopen("votes.txt", "r");
    char choice;
    int votes[3] = {0};

    while (fscanf(file, "%c", &choice) == 1) {
        if (choice >= '1' && choice <= '3') {
            votes[choice - '1']++;
        }
    }

    printf("The results are:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %c: %d votes\n", i+1, '1' + i, votes[i]);
    }

    fclose(file);
}

// Main function
int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                vote();
                break;
            case 3:
                viewResults();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}