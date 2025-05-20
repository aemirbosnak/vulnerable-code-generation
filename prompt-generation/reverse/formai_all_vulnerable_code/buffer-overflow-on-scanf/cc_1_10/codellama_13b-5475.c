//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
/*
 * Example C Electronic Voting System Program
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void print_menu();
void register_voter();
void start_voting();
void end_voting();

// Global variables
int voter_count = 0;
int voter_registered = 0;
int vote_count = 0;

// Main function
int main() {
    print_menu();
    return 0;
}

// Function definitions
void print_menu() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("1. Register voter\n");
    printf("2. Start voting\n");
    printf("3. End voting\n");
    printf("Enter your choice: ");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            register_voter();
            break;
        case 2:
            start_voting();
            break;
        case 3:
            end_voting();
            break;
        default:
            printf("Invalid choice!\n");
            print_menu();
            break;
    }
}

void register_voter() {
    printf("Enter voter ID: ");
    char voter_id[100];
    scanf("%s", voter_id);
    printf("Enter voter name: ");
    char voter_name[100];
    scanf("%s", voter_name);
    printf("Voter %s registered successfully!\n", voter_name);
    voter_count++;
    voter_registered++;
}

void start_voting() {
    printf("Voting started!\n");
    while (voter_registered > 0) {
        printf("Enter voter ID: ");
        char voter_id[100];
        scanf("%s", voter_id);
        printf("Enter vote: ");
        int vote = 0;
        scanf("%d", &vote);
        printf("Vote registered successfully!\n");
        voter_registered--;
        vote_count++;
    }
    printf("Voting ended!\n");
}

void end_voting() {
    printf("Voting ended!\n");
    printf("Voter count: %d\n", voter_count);
    printf("Vote count: %d\n", vote_count);
    printf("Thank you for using the Electronic Voting System!\n");
}