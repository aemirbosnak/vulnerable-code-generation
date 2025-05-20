//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int x,y,z;
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark forest. You can go North, South, East or West.\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            x=rand()%2;
            if(x==0)
            {
                printf("You went North and found a treasure!\n");
            }
            else
            {
                printf("You went North and found nothing.\n");
            }
            break;

        case 2:
            x=rand()%2;
            if(x==0)
            {
                printf("You went South and found a treasure!\n");
            }
            else
            {
                printf("You went South and found nothing.\n");
            }
            break;

        case 3:
            x=rand()%2;
            if(x==0)
            {
                printf("You went East and found a treasure!\n");
            }
            else
            {
                printf("You went East and found nothing.\n");
            }
            break;

        case 4:
            x=rand()%2;
            if(x==0)
            {
                printf("You went West and found a treasure!\n");
            }
            else
            {
                printf("You went West and found nothing.\n");
            }
            break;

        default:
            printf("Invalid choice. Try again.\n");
    }

    return 0;
}