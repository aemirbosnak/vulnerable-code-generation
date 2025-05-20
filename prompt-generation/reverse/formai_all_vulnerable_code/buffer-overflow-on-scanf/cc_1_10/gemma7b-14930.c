//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_ballot_box(int x, int y)
{
    printf("#####################################################\n");
    printf("#                                 #\n");
    printf("#   %c %c %c   #\n", x, y, x + 1);
    printf("#                                 #\n");
    printf("#####################################################\n");
}

void draw_candidate_names(char *name1, char *name2)
{
    printf("______________________________________________\n");
    printf("%s\n", name1);
    printf("%s\n", name2);
    printf("______________________________________________\n");
}

void vote(int choice)
{
    switch (choice)
    {
        case 1:
            printf("You have voted for %s\n", "Candidate 1");
            break;
        case 2:
            printf("You have voted for %s\n", "Candidate 2");
            break;
        default:
            printf("Invalid vote\n");
    }
}

int main()
{
    char name1[] = "John Doe";
    char name2[] = "Jane Doe";

    draw_ballot_box(10, 5);
    draw_candidate_names(name1, name2);

    int choice;

    printf("Please select a candidate: ");
    scanf("%d", &choice);

    vote(choice);

    return 0;
}