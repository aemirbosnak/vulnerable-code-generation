//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to display menu options
void display_menu() {
    printf("\n\nWelcome to the Electronic Voting System!\n");
    printf("-------------------------------\n");
    printf("1. Register to Vote\n");
    printf("2. Login to Vote\n");
    printf("3. Exit\n");
    printf("-------------------------------\n");
}

// Function to register a new voter
void register_voter() {
    char name[50];
    int age;
    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("\nRegistration successful!\n");
}

// Function to login and cast a vote
void login_and_vote() {
    char name[50];
    int age;
    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("\nWelcome, %s! You are now logged in to the Electronic Voting System.\n", name);
    printf("-------------------------------\n");
    printf("1. Cast your vote\n");
    printf("2. View results\n");
    printf("3. Logout\n");
    printf("-------------------------------\n");
}

// Function to cast a vote
void cast_vote() {
    printf("\nThank you for casting your vote!\n");
}

// Function to view results
void view_results() {
    printf("\nThe results of the election are:\n");
    printf("-------------------------------\n");
    printf("Candidate A: 50 votes\n");
    printf("Candidate B: 100 votes\n");
    printf("Candidate C: 75 votes\n");
    printf("-------------------------------\n");
}

int main() {
    int choice;
    do {
        system("clear");
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                register_voter();
                break;
            case 2:
                login_and_vote();
                break;
            case 3:
                printf("\nExiting the Electronic Voting System...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 3);
    return 0;
}