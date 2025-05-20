//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int choice;
    printf("Welcome to the Adventure Game.\n");
    printf("Press any key to continue.\n");
    getchar();
    printf("You wake up in a dark room with no memory of how you got here.\n");
    printf("What do you do?\n");
    printf("1. Look around\n");
    printf("2. Try to open the door\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("You look around and find a flashlight. Do you:\n");
            printf("1. Turn it on\n");
            printf("2. Leave it\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("You turn on the flashlight and see a key on the floor. Do you:\n");
                    printf("1. Pick it up\n");
                    printf("2. Leave it\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:
                            printf("You pick up the key and try it on the door. It opens! You step outside and see a forest. Do you:\n");
                            printf("1. Explore the forest\n");
                            printf("2. Go back inside\n");
                            scanf("%d",&choice);
                            switch(choice)
                            {
                                case 1:
                                    printf("You explore the forest and find a treasure chest. Do you:\n");
                                    printf("1. Open it\n");
                                    printf("2. Leave it\n");
                                    scanf("%d",&choice);
                                    switch(choice)
                                    {
                                        case 1:
                                            printf("You open the chest and find a map leading to a hidden city. The adventure continues...\n");
                                            break;
                                        case 2:
                                            printf("You leave the chest and continue exploring the forest.\n");
                                            break;
                                    }
                                    break;
                                case 2:
                                    printf("You go back inside the room.\n");
                                    break;
                            }
                            break;
                        case 2:
                            printf("You leave the key and continue exploring the room.\n");
                            break;
                    }
                    break;
                case 2:
                    printf("You leave the flashlight and continue exploring the room.\n");
                    break;
            }
            break;
        case 2:
            printf("You try to open the door but it's locked. You need to find a key.\n");
            break;
    }
    return 0;
}