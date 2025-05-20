//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void hauntedHouse();

int main()
{
    srand(time(0));
    int choice;
    while(1)
    {
        printf("Welcome to the Haunted House!\n");
        printf("Press 1 to enter the house\n");
        printf("Press 2 to exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            hauntedHouse();
        }
        else if(choice==2)
        {
            exit(0);
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void hauntedHouse()
{
    int room,ghost,scream;
    printf("You are now inside the haunted house.\n");
    printf("You find yourself in room 1.\n");
    while(1)
    {
        room=rand()%10+1;
        ghost=rand()%3+1;
        switch(ghost)
        {
            case 1:
                printf("You hear a faint whisper coming from room %d.\n",room);
                break;
            case 2:
                printf("You see a ghostly figure disappear into room %d.\n",room);
                break;
            case 3:
                printf("A ghost suddenly appears in front of you and screams!\n");
                scream=rand()%2+1;
                if(scream==1)
                {
                    printf("You scream and run into room %d.\n",room);
                }
                else
                {
                    printf("You bravely face the ghost and it disappears.\n");
                }
                break;
        }
        printf("You are now in room %d.\n",room);
        if(room==10)
        {
            printf("You have successfully escaped the haunted house!\n");
            break;
        }
    }
}