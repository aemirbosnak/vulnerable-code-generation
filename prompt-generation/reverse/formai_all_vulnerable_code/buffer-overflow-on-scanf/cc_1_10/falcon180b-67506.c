//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    char input[100];
    int choice, score = 0;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Choose a mode:\n1. Easy\n2. Medium\n3. Hard\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter the name of an element:\n");
            scanf("%s",input);
            if(strcmp(input,"Hydrogen") == 0)
            {
                printf("Correct! Score = 1\n");
                score++;
            }
            else
            {
                printf("Incorrect! Score = 0\n");
            }
            break;
        case 2:
            printf("Enter the symbol of an element:\n");
            scanf("%s",input);
            if(strcmp(input,"H") == 0)
            {
                printf("Correct! Score = 1\n");
                score++;
            }
            else
            {
                printf("Incorrect! Score = 0\n");
            }
            break;
        case 3:
            printf("Enter the atomic number of an element:\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                printf("Correct! Score = 1\n");
                score++;
            }
            else
            {
                printf("Incorrect! Score = 0\n");
            }
            break;
        default:
            printf("Invalid choice! Score = 0\n");
            break;
    }
    if(score == 0)
    {
        printf("You need to study more! \n");
    }
    else if(score == 1)
    {
        printf("Good job! \n");
    }
    else
    {
        printf("Excellent! \n");
    }
    return 0;
}