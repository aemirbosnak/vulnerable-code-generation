//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to print the menu
void print_menu() {
    printf("1. Cast Vote\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
}

// Function to get user choice
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to cast vote
void cast_vote(char* name) {
    printf("Enter 1 to vote for Alice\n");
    printf("Enter 2 to vote for Bob\n");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You voted for Alice\n");
    } else if (choice == 2) {
        printf("You voted for Bob\n");
    } else {
        printf("Invalid choice\n");
    }
}

// Function to view results
void view_results() {
    int alice_votes = 0;
    int bob_votes = 0;

    FILE* fp = fopen("votes.txt", "r");
    if (fp == NULL) {
        printf("No votes yet\n");
    } else {
        char line[100];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strstr(line, "Alice")!= NULL) {
                alice_votes++;
            } else if (strstr(line, "Bob")!= NULL) {
                bob_votes++;
            }
        }
        fclose(fp);

        printf("Total Votes: %d\n", alice_votes + bob_votes);
        printf("Alice got %d votes\n", alice_votes);
        printf("Bob got %d votes\n", bob_votes);
    }
}

// Function to save vote in file
void save_vote(char* name) {
    FILE* fp = fopen("votes.txt", "a");
    if (fp == NULL) {
        printf("Error saving vote\n");
    } else {
        fprintf(fp, "%s voted\n", name);
        fclose(fp);
    }
}

int main() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    while (1) {
        print_menu();
        int choice = get_choice();

        switch (choice) {
            case 1:
                cast_vote(name);
                save_vote(name);
                break;
            case 2:
                view_results();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}