//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_OPTIONS 3

struct Voter {
    int voter_id;
    char name[MAX_NAME_LENGTH];
    int option;
};

int main() {
    int num_voters = 0;
    struct Voter voters[MAX_VOTERS];
    int candidate_count[MAX_OPTIONS] = {0};
    char election_name[50];
    int current_option = 0;

    printf("Enter election name: ");
    scanf("%s", election_name);

    while (true) {
        printf("\n1. Register\n2. Vote\n3. View Results\n4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_voters >= MAX_VOTERS) {
                    printf("Maximum number of voters reached.\n");
                    break;
                }
                printf("Enter your name: ");
                scanf("%s", voters[num_voters].name);
                voters[num_voters].voter_id = num_voters + 1;
                num_voters++;
                break;

            case 2:
                if (num_voters == 0) {
                    printf("No registered voters.\n");
                    break;
                }
                printf("Enter your voter ID: ");
                int voter_id;
                scanf("%d", &voter_id);
                int voter_index = voter_id - 1;

                if (voter_index >= num_voters || strcmp(voters[voter_index].name, "")) {
                    printf("Invalid voter ID.\n");
                    break;
                }

                printf("Choose your option (1-%d): ", MAX_OPTIONS);
                scanf("%d", &current_option);
                if (current_option < 1 || current_option > MAX_OPTIONS) {
                    printf("Invalid option.\n");
                    break;
                }

                voters[voter_index].option = current_option;
                candidate_count[current_option - 1]++;
                printf("Your vote has been recorded.\n");
                break;

            case 3:
                printf("\nCurrent Election Results:\n");
                for (int i = 0; i < MAX_OPTIONS; i++) {
                    printf("Option %d: %d votes\n", i + 1, candidate_count[i]);
                }
                break;

            case 4:
                printf("Exiting the system.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}