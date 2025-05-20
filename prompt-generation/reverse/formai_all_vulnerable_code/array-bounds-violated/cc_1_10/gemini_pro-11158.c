//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: energetic
// **Rock the Vote: A C Electronic Voting Adventure**

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// **Candidate Crypts:**
typedef struct candidate {
    char *name;
    int votes;
} Candidate;

// **The Electric Booth:**
Candidate candidates[] = {
    { "Dr. Volt", 0 },
    { "Captain Capacitor", 0 },
    { "Madame Megabyte", 0 }
};
int total_voters;
int total_votes;

// **Cast Your Vote!**
void vote(int candidate_index) {
    candidates[candidate_index].votes++;
    total_votes++;
}

// **Results Revolution:**
void print_results() {
    printf("**Voltage Victory! Here are the results:**\n");
    for (int i = 0; i < sizeof(candidates) / sizeof(Candidate); i++) {
        printf(" - %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("**Total Votes Cast:** %d\n", total_votes);
}

// **Main Mayhem:**
int main() {
    // **Voter Rush:**
    printf("**Welcome to the Electronic Voting Extravaganza!**\n");
    printf("Enter the total number of voters: ");
    scanf("%d", &total_voters);

    // **Candidate Countdown:**
    for (int i = 0; i < total_voters; i++) {
        printf("\nVoter %d, cast your vote (1 for Dr. Volt, 2 for Captain Capacitor, 3 for Madame Megabyte): ", i + 1);
        int vote_choice;
        scanf("%d", &vote_choice);
        vote(vote_choice - 1);
    }

    // **Election Electrification:**
    print_results();

    // **Power Down:**
    printf("\n**Thanks for voting! Democracy just got electrified!**\n");
    return 0;
}