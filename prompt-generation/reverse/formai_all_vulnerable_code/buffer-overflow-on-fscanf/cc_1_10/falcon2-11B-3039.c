//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the voter's details
typedef struct {
    char name[50];
    int age;
    int gender;
    char choice[50];
} Voter;

// Function to read the voter's details
Voter read_voter_details(char *file_name) {
    Voter voter;
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return voter;
    }

    // Read the voter's details from the file
    fscanf(fp, "%s %d %d %s", voter.name, &voter.age, &voter.gender, voter.choice);

    // Close the file
    fclose(fp);

    return voter;
}

// Function to display the voter's details
void display_voter_details(Voter voter) {
    printf("Name: %s\n", voter.name);
    printf("Age: %d\n", voter.age);
    printf("Gender: %d\n", voter.gender);
    printf("Choice: %s\n", voter.choice);
}

// Function to count the votes for a candidate
int count_votes(Voter *voters, int num_voters, char *candidate) {
    int count = 0;
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].choice, candidate) == 0) {
            count++;
        }
    }

    return count;
}

// Function to print the vote count for each candidate
void print_vote_count(Voter *voters, int num_voters, char *candidates[]) {
    for (int i = 0; candidates[i]!= NULL; i++) {
        int count = count_votes(voters, num_voters, candidates[i]);
        printf("%s: %d\n", candidates[i], count);
    }
}

// Function to sort the voter details in descending order of age
void sort_voters(Voter *voters, int num_voters) {
    for (int i = 0; i < num_voters - 1; i++) {
        for (int j = 0; j < num_voters - i - 1; j++) {
            if (voters[j].age < voters[j+1].age) {
                Voter temp = voters[j];
                voters[j] = voters[j+1];
                voters[j+1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Read the voter details from a file
    Voter *voters = (Voter*) malloc(sizeof(Voter) * 5);
    char candidates[5][50] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D", "Candidate E"};
    char file_name[50];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    for (int i = 0; i < 5; i++) {
        voters[i] = read_voter_details(file_name);
    }

    // Display the voter details
    for (int i = 0; i < 5; i++) {
        display_voter_details(voters[i]);
    }

    // Sort the voter details in descending order of age
    sort_voters(voters, 5);

    // Count the votes for each candidate
    print_vote_count(voters, 5, candidates);

    return 0;
}