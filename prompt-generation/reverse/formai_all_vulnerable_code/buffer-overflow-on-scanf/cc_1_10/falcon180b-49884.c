//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, n, m, c, d, e, sum = 0;
    char ch;
    FILE *fp;
    struct {
        char name[30];
        int votes;
    } candidate[10];

    printf("Enter the total number of candidates (less than 10): ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidate[i].name);
        candidate[i].votes = 0;
    }

    printf("\n");
    printf("The candidates are:\n");
    for(i=0; i<n; i++)
        printf("%d. %s\n", i+1, candidate[i].name);

    printf("\nEnter your choice of candidate number: ");
    scanf("%d", &c);

    if(c < 1 || c > n)
    {
        printf("\nInvalid choice! Please enter a number between 1 and %d.", n);
        exit(0);
    }

    printf("\nYour vote has been cast for %s.\n", candidate[c-1].name);
    candidate[c-1].votes++;

    printf("\nDo you want to see the current results? (y/n): ");
    scanf(" %c", &ch);

    if(ch == 'y' || ch == 'Y')
    {
        printf("\nCurrent results:\n");
        for(i=0; i<n; i++)
        {
            printf("%s: %d\n", candidate[i].name, candidate[i].votes);
        }
    }

    exit(0);
}