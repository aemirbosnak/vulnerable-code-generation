//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define FILENAME "voters.txt"

typedef struct {
    int id;
    char name[50];
    int vote; // index of candidate voted for
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int voter_count = 0;

// Function declarations
void init_candidates();
void register_voter();
void cast_vote();
void display_results();
int is_voter_registered(int id);
void save_voter_data();
void load_voter_data();
void clear_screen();

int main() {
    int choice;

    load_voter_data(); // Load existing voter data

    while (1) {
        clear_screen();
        printf("=== Electronic Voting System ===\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
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
                display_results();
                break;
            case 4:
                printf("Exiting...\n");
                save_voter_data();
                exit(0);
        }
    }
    return 0;
}

void init_candidates() {
    strcpy(candidates[0].name, "Alice");
    strcpy(candidates[1].name, "Bob");
    strcpy(candidates[2].name, "Charlie");
    strcpy(candidates[3].name, "Dave");
    strcpy(candidates[4].name, "Eve");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }
}

void register_voter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Registration is full!\n");
        return;
    }

    Voter new_voter;
    printf("Enter Voter ID: ");
    scanf("%d", &new_voter.id);
    if (is_voter_registered(new_voter.id)) {
        printf("Voter ID %d is already registered!\n", new_voter.id);
        return;
    }

    printf("Enter Voter Name: ");
    scanf("%s", new_voter.name);

    new_voter.vote = -1; // Initialized as not voted
    voters[voter_count++] = new_voter;
    printf("Voter registered successfully!\n");
    sleep(2); // Pause for user to read
}

void cast_vote() {
    int voter_id, candidate_id;
    printf("Enter your Voter ID: ");
    scanf("%d", &voter_id);

    for (int i = 0; i < voter_count; i++) {
        if (voters[i].id == voter_id) {
            if (voters[i].vote != -1) {
                printf("Voter ID %d has already voted!\n", voter_id);
                return;
            }
            printf("Candidates:\n");
            for (int j = 0; j < MAX_CANDIDATES; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            printf("Choose a candidate (1-%d): ", MAX_CANDIDATES);
            scanf("%d", &candidate_id);
            if (candidate_id < 1 || candidate_id > MAX_CANDIDATES) {
                printf("Invalid candidate selection!\n");
                return;
            }

            voters[i].vote = candidate_id - 1;
            candidates[candidate_id - 1].votes++;
            printf("Vote recorded successfully!\n");
            sleep(2); // Pause for user to read
            return;
        }
    }
    printf("Voter ID %d is not registered!\n", voter_id);
}

void display_results() {
    printf("=== Voting Results ===\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    sleep(5); // Pause for user to read
}

int is_voter_registered(int id) {
    for (int i = 0; i < voter_count; i++) {
        if (voters[i].id == id) {
            return 1; // Voter is registered
        }
    }
    return 0; // Voter not found
}

void save_voter_data() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving voter data!\n");
        return;
    }
    for (int i = 0; i < voter_count; i++) {
        fprintf(file, "%d %s %d\n", voters[i].id, voters[i].name, voters[i].vote);
    }
    fclose(file);
}

void load_voter_data() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No existing voter data found.\n");
        init_candidates();
        return;
    }
    while (fscanf(file, "%d %s %d", &voters[voter_count].id, voters[voter_count].name, &voters[voter_count].vote) != EOF) {
        voter_count++;
    }
    fclose(file);
    init_candidates();
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}