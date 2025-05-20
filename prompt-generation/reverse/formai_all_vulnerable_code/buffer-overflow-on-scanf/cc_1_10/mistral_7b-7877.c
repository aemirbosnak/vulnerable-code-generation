//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_OPTIONS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int option;
} Voter;

int main() {
    srand(time(NULL));
    Voter voters[MAX_VOTERS];
    int num_voters = 0, options[MAX_OPTIONS] = {0};
    char name[MAX_NAME_LENGTH];

    printf("Welcome to the Magical Flying Carpet Electronic Voting System!\n");
    printf("Please enter your name:\n");
    scanf("%s", name);
    strcpy(voters[num_voters].name, name);
    num_voters++;

    while (num_voters < MAX_VOTERS) {
        int random_number = rand() % MAX_OPTIONS;
        options[random_number]++;

        printf("\n%s, your vote has been cast on option %d.\n", name, random_number + 1);
        printf("A magical genie has appeared to record your vote!\n");
        printf("Press ENTER to continue...\n");
        getchar();
        system("clear"); // or cls for Windows

        printf("Please enter your name:\n");
        scanf("%s", name);
        strcpy(voters[num_voters].name, name);
        num_voters++;
    }

    printf("\nVoting results:\n");

    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("Option %d: %d votes\n", i + 1, options[i]);
    }

    return 0;
}