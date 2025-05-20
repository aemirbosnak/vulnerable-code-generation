//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 20
#define MAX_CHOICES 3

struct Voter {
    char name[MAX_NAME_LENGTH + 1];
    int choice[MAX_CHOICES];
    int voted;
};

struct Voter voters[MAX_VOTERS];
int num_voters = 0;

void register_voter() {
    if (num_voters >= MAX_VOTERS) {
        printf("Sorry, maximum number of voters reached.\n");
        return;
    }

    printf("Enter your name: ");
    fgets(voters[num_voters].name, MAX_NAME_LENGTH, stdin);
    voters[num_voters].name[strcspn(voters[num_voters].name, "\n")] = '\0';

    voters[num_voters].voted = 0;
    num_voters++;
}

void vote() {
    if (num_voters <= 0) {
        printf("Sorry, no voters registered yet.\n");
        return;
    }

    int index, i;
    printf("Enter your index: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_voters) {
        printf("Invalid index.\n");
        return;
    }

    if (voters[index].voted) {
        printf("You have already voted.\n");
        return;
    }

    printf("Enter your choice (1-3): ");
    for (i = 0; i < MAX_CHOICES; i++) {
        scanf("%d", &voters[index].choice[i]);
        if (voters[index].choice[i] < 1 || voters[index].choice[i] > MAX_CHOICES) {
            printf("Invalid choice. Please enter a valid choice (1-3).\n");
            i--;
            continue;
        }
    }

    voters[index].voted = 1;
}

void display_results() {
    int sum[MAX_CHOICES] = {0};

    for (int i = 0; i < num_voters; i++) {
        for (int j = 0; j < MAX_CHOICES; j++) {
            sum[voters[i].choice[j] - 1] += 1;
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%d: %d votes\n", i + 1, sum[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Register voter\n2. Cast vote\n3. Display results\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_voter();
                break;
            case 2:
                vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}