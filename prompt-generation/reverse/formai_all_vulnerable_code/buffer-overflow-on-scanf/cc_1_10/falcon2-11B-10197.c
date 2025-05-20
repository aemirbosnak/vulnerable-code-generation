//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
} Candidate;

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create a list of candidates
    Candidate candidates[5] = {
        {"John Doe", 35},
        {"Jane Smith", 40},
        {"Bob Johnson", 50},
        {"Alice Davis", 45},
        {"Charlie Brown", 55}
    };

    // Print the list of candidates
    printf("Candidates:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d\n", candidates[i].name, candidates[i].age);
    }

    // Vote for a candidate
    printf("Vote for a candidate:\n");
    printf("1. John Doe\n");
    printf("2. Jane Smith\n");
    printf("3. Bob Johnson\n");
    printf("4. Alice Davis\n");
    printf("5. Charlie Brown\n");

    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        printf("You voted for %s, %d\n", candidates[choice - 1].name, candidates[choice - 1].age);
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    // Print the results
    printf("Results:\n");
    printf("1. %s, %d - %.2f%%\n", candidates[0].name, candidates[0].age, (float)candidates[0].age / 5 * 100);
    printf("2. %s, %d - %.2f%%\n", candidates[1].name, candidates[1].age, (float)candidates[1].age / 5 * 100);
    printf("3. %s, %d - %.2f%%\n", candidates[2].name, candidates[2].age, (float)candidates[2].age / 5 * 100);
    printf("4. %s, %d - %.2f%%\n", candidates[3].name, candidates[3].age, (float)candidates[3].age / 5 * 100);
    printf("5. %s, %d - %.2f%%\n", candidates[4].name, candidates[4].age, (float)candidates[4].age / 5 * 100);

    return 0;
}