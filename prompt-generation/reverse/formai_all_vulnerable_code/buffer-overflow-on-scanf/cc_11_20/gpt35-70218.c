//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int candidate1=0, candidate2=0, candidate3=0;
    int choice, count;
    
    printf("Welcome to the Electronic Voting System\n");
    printf("Candidates are: \n");
    printf("1. John Doe\n");
    printf("2. Jane Smith\n");
    printf("3. Mark Johnson\n");

    for(count=1; count<=100; count++)
    {
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                candidate1++;
                break;
            case 2:
                candidate2++;
                break;
            case 3:
                candidate3++;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                count--;
                break;
        }
    }

    printf("Total votes:\n");
    printf("John Doe: %d\n", candidate1);
    printf("Jane Smith: %d\n", candidate2);
    printf("Mark Johnson: %d\n", candidate3);

    if((candidate1 > candidate2) && (candidate1 > candidate3))
        printf("John Doe is the winner.\n");
    else if((candidate2 > candidate1) && (candidate2 > candidate3))
        printf("Jane Smith is the winner.\n");
    else if((candidate3 > candidate1) && (candidate3 > candidate2))
        printf("Mark Johnson is the winner.\n");
    else
        printf("There is a tie.\n");

    return 0;
}