//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* name;
    int age;
    char* email;
} Candidate;

int main() {
    // Create an array of candidates
    Candidate candidates[10] = {
        {"John Doe", 35, "johndoe@example.com"},
        {"Jane Smith", 28, "janesmith@example.com"},
        {"Bob Johnson", 42, "bobjohnson@example.com"},
        {"Alice Brown", 25, "alicebrown@example.com"},
        {"Tom White", 45, "tomwhite@example.com"},
        {"Mary Green", 31, "marygreen@example.com"},
        {"David Black", 40, "davidblack@example.com"},
        {"Emily Davis", 29, "emilydavis@example.com"},
        {"Michael Lee", 36, "michaellee@example.com"},
        {"Sophia Taylor", 30, "sophiataylor@example.com"}
    };

    // Prompt user to enter their name
    printf("Please enter your name: ");
    char name[50];
    fgets(name, sizeof(name), stdin);

    // Prompt user to select a candidate
    printf("Please select a candidate: ");
    int candidateIndex = -1;
    while (candidateIndex < 0 || candidateIndex >= 10) {
        printf("%s\n", candidates[candidateIndex].name);
        candidateIndex = scanf("%d", &candidateIndex);
    }

    // Prompt user to enter their vote
    printf("Please enter your vote: ");
    char vote[50];
    fgets(vote, sizeof(vote), stdin);

    // Check if the vote is valid
    if (strcmp(vote, "1")!= 0 && strcmp(vote, "2")!= 0 && strcmp(vote, "3")!= 0 && strcmp(vote, "4")!= 0 && strcmp(vote, "5")!= 0 && strcmp(vote, "6")!= 0 && strcmp(vote, "7")!= 0 && strcmp(vote, "8")!= 0 && strcmp(vote, "9")!= 0 && strcmp(vote, "10")!= 0) {
        printf("Invalid vote! Please try again.\n");
        return 1;
    }

    // Update the vote count for the selected candidate
    candidates[candidateIndex].age++;

    // Print the updated vote count for the selected candidate
    printf("%s: %d\n", candidates[candidateIndex].name, candidates[candidateIndex].age);

    return 0;
}