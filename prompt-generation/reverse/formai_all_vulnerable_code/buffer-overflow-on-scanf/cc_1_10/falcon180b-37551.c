//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random number
int randNum(int min,int max)
{
    return rand()%(max-min+1)+min;
}

//Function to display fortune
void fortune(int num)
{
    switch(num)
    {
        case 1:
            printf("You will have a great day today!\n");
            break;
        case 2:
            printf("Something good is about to happen to you!\n");
            break;
        case 3:
            printf("You will meet someone special today!\n");
            break;
        case 4:
            printf("You will receive good news soon!\n");
            break;
        case 5:
            printf("Your hard work will pay off soon!\n");
            break;
        case 6:
            printf("You will experience a positive change in your life!\n");
            break;
        case 7:
            printf("Your future looks bright!\n");
            break;
        case 8:
            printf("You will overcome any obstacles in your way!\n");
            break;
        case 9:
            printf("You will be successful in your endeavors!\n");
            break;
        case 10:
            printf("You will have good luck today!\n");
            break;
        default:
            printf("Sorry, no fortune for you.\n");
            break;
    }
}

//Main function
int main()
{
    int choice;
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press 1 for a fortune, 0 to exit.\n");
    while(1)
    {
        scanf("%d",&choice);
        if(choice==1)
        {
            int num=randNum(1,10);
            fortune(num);
        }
        else if(choice==0)
        {
            printf("Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}