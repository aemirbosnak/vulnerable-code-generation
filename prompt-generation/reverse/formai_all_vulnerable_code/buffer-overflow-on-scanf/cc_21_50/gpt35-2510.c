//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int score=0, i;
    char answer[2];
    printf("Welcome to the Periodic Table Quiz Game!\n\n");
    printf("Instructions:\n");
    printf("1. Enter the correct symbol for the given element\n");
    printf("2. Each correct answer earns you 10 points\n");
    printf("3. Enter your answer in capital letters\n");
    printf("4. Press q to quit\n\n");
    printf("Are you ready to begin? (y/n): ");
    scanf("%s", answer);
    if(answer[0]=='n' || answer[0]=='N')
       exit(0);
    printf("\n");
    while(1)
    {
       printf("1. What is the symbol for Nitrogen?: ");
       scanf("%s", answer);
       if(answer[0]=='n' && answer[1]=='i' || answer[0]=='N' && answer[1]=='I')
         {
            score+=10;
            printf("Correct!\n");
         }
        else if(answer[0]=='q' || answer[0]=='Q')
        {
            printf("Thank you for playing. Your final score is: %d\n", score);
            exit(0);
        }
        else
            printf("Incorrect! The correct answer is NI.\n");
        printf("\n");
        printf("2. What is the symbol for Oxygen?: ");
        scanf("%s", answer);
        if(answer[0]=='o' && answer[1]=='x' || answer[0]=='O' && answer[1]=='X')
         {
            score+=10;
            printf("Correct!\n");
         }
        else if(answer[0]=='q' || answer[0]=='Q')
        {
            printf("Thank you for playing. Your final score is: %d\n", score);
            exit(0);
        }
        else 
            printf("Incorrect! The correct answer is OX.\n");
        printf("\n");
        printf("3. What is the symbol for Gold?: ");
        scanf("%s", answer);
        if(answer[0]=='a' && answer[1]=='u' || answer[0]=='A' && answer[1]=='U')
         {
            score+=10;
            printf("Correct!\n");
         }
        else if(answer[0]=='q' || answer[0]=='Q')
        {
            printf("Thank you for playing. Your final score is: %d\n", score);
            exit(0);
        }
        else
            printf("Incorrect! The correct answer is AU.\n");
        printf("\n");
        printf("4. What is the symbol for Carbon?: ");
        scanf("%s", answer);
        if(answer[0]=='c' && answer[1]=='o' || answer[0]=='C' && answer[1]=='O')
         {
            score+=10;
            printf("Correct!\n");
         }
        else if(answer[0]=='q' || answer[0]=='Q')
        {
            printf("Thank you for playing. Your final score is: %d\n", score);
            exit(0);
        }
        else
            printf("Incorrect! The correct answer is CO.\n");
        printf("\n");
        printf("5. What is the symbol for Iron?: ");
        scanf("%s", answer);
        if(answer[0]=='f' && answer[1]=='e' || answer[0]=='F' && answer[1]=='E')
         {
            score+=10;
            printf("Correct!\n");
         }
        else if(answer[0]=='q' || answer[0]=='Q')
        {
            printf("Thank you for playing. Your final score is: %d\n", score);
            exit(0);
        }
        else
            printf("Incorrect! The correct answer is FE.\n");
        printf("\n");
        printf("Congratulations! You finished the game. Your final score is: %d\n", score);
    }
    return 0;
}