//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_VOTERS 100
#define MAX_OPTIONS 5

typedef struct {
    char name[100];
    int age;
    int votes[MAX_OPTIONS];
} Voter;

Voter voters[MAX_VOTERS];
int num_voters;

int main() {
    char choice;
    int i, option;

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the voters' names: ");
    for (i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }

    printf("Enter the age of each voter: ");
    for (i = 0; i < num_voters; i++) {
        scanf("%d", &voters[i].age);
    }

    printf("Select an option from 1 to %d: ", MAX_OPTIONS);
    scanf("%d", &option);

    printf("Enter the name of each voter: ");
    for (i = 0; i < num_voters; i++) {
        scanf("%s", voters[i].name);
    }

    printf("Enter the age of each voter: ");
    for (i = 0; i < num_voters; i++) {
        scanf("%d", &voters[i].age);
    }

    for (i = 0; i < num_voters; i++) {
        voters[i].votes[option]++;
    }

    for (i = 0; i < num_voters; i++) {
        printf("%s %d %d\n", voters[i].name, voters[i].votes[option], voters[i].age);
    }

    return 0;
}