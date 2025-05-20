//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, count = 0;
    char answer;
    printf("----------Welcome to the Haunted House Simulator----------\n");
    printf("You are about to enter a haunted house, do you wish to continue? (Y/N)");
    scanf("%c",&answer);
    if(answer == 'Y' || answer == 'y')
    {
        printf("Great choice!\n");
        printf("You enter the haunted house and find yourself in a room...\n");
        printf("You see two doors, one on the left and one on the right.\n");
        printf("Which door do you want to choose?\n");
        printf("1. Left door\n2. Right door\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("You have chosen the left door!\n");
            printf("As you open the door, you find yourself in a dark room.\n");
            printf("You look around and see that there is a key on the table in front of you.\n");
            printf("What do you want to do?\n");
            printf("1. Pick up the key\n2. Leave the key on the table and look for another way out\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                printf("You picked up the key.\n");
                printf("You hear a strange noise coming from the other side of the room.\n");
                printf("What do you want to do?\n");
                printf("1. Investigate the noise\n2. Leave the room through the door that you entered\n");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("You approached the source of the noise and found a hidden passage.\n");
                    printf("You use the key to open the passage and enter it.\n");
                    printf("As you move forward, you see a bright light at the end of the passage.\n");
                    printf("You reach the end of the passage and see a way out.\n");
                    printf("Congratulations! You have escaped from the haunted house.\n");
                    printf("You managed to escape the haunted house in %d moves.\n",count+3);
                    printf("We hope you enjoyed the game! Play again soon.\n");
                }
                else if(choice == 2)
                {
                    printf("You left the room through the door you entered.\n");
                    printf("You find yourself in another room.\n");
                    printf("There is a painting on the wall with a secret code.\n");
                    printf("What do you want to do?\n");
                    printf("1. Try to guess the code\n2. Look around the room for clues\n");
                    scanf("%d",&choice);
                    if(choice == 1)
                    {
                        printf("You guessed the code and a secret door opened.\n");
                        printf("You entered the door and found yourself in a dark room.\n");
                        printf("You heard strange noises coming from all around you.\n");
                        printf("Suddenly, a ghost appears right in front of you and you faint. Game over!\n");
                    }
                    else if(choice == 2)
                    {
                        printf("You look around the room and find a diary which has a clue to the secret code.\n");
                        printf("You use the code to open the secret door and enter it.\n");
                        printf("You find yourself in a room with a chest.\n");
                        printf("You open the chest and find a map showing the way to the exit.\n");
                        printf("You follow the map and manage to escape from the haunted house.\n");
                        printf("Congratulations! You have escaped from the haunted house.\n");
                        printf("You managed to escape the haunted house in %d moves.\n",count+4);
                        printf("We hope you enjoyed the game! Play again soon.\n");
                    }
                }
            }
            else if(choice == 2)
            {
                printf("You left the key on the table and look for another way out.\n");
                printf("You leave the room through the door you entered.\n");
                printf("You find yourself in another room.\n");
                printf("There is a painting on the wall with a secret code.\n");
                printf("What do you want to do?\n");
                printf("1. Try to guess the code\n2. Look around the room for clues\n");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("You guessed the code and a secret door opened.\n");
                    printf("You entered the door and found yourself in a dark room.\n");
                    printf("You heard strange noises coming from all around you.\n");
                    printf("Suddenly, a ghost appears right in front of you and you faint. Game over!\n");
                }
                else if(choice == 2)
                {
                    printf("You look around the room and find a diary which has a clue to the secret code.\n");
                    printf("You use the code to open the secret door and enter it.\n");
                    printf("You find yourself in a room with a chest.\n");
                    printf("You open the chest and find a map showing the way to the exit.\n");
                    printf("You follow the map and manage to escape from the haunted house.\n");
                    printf("Congratulations! You have escaped from the haunted house.\n");
                    printf("You managed to escape the haunted house in %d moves.\n",count+4);
                    printf("We hope you enjoyed the game! Play again soon.\n");
                }
            }
        }
        else if(choice == 2)
        {
            printf("You have chosen the right door!\n");
            printf("As you open the door, you find yourself in a small room.\n");
            printf("The room is filled with cobwebs and dust, it seems like nobody has been here for years.\n");
            printf("You see a ladder leading up to the ceiling and a door leading to another room.\n");
            printf("What do you want to do?\n");
            printf("1. Climb the ladder and look around\n2. Go through the door to the other room\n");
            scanf("%d",&choice);
            if(choice == 1)
            {
                printf("You climb the ladder and reach the top.\n");
                printf("You find yourself in an attic filled with old items and furniture.\n");
                printf("You see a box in the corner of the room.\n");
                printf("What do you want to do?\n");
                printf("1. Open the box\n2. Leave the box alone and look around the attic\n");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("You opened the box and found a key inside.\n");
                    printf("As you pick up the key, you hear strange noises coming from below.\n");
                    printf("What do you want to do?\n");
                    printf("1. Investigate the source of the noise\n2. Leave the attic and go through the door to the other room\n");
                    scanf("%d",&choice);
                    if(choice == 1)
                    {
                        printf("You investigate the noise and find a hidden passage.\n");
                        printf("You use the key to unlock the passage and enter it.\n");
                        printf("As you move forward, you see a bright light at the end of the passage.\n");
                        printf("You reach the end of the passage and see a way out.\n");
                        printf("Congratulations! You have escaped from the haunted house.\n");
                        printf("You managed to escape the haunted house in %d moves.\n",count+4);
                        printf("We hope you enjoyed the game! Play again soon.\n");
                    }
                    else if(choice == 2)
                    {
                        printf("You leave the attic and go through the door to the other room.\n");
                        printf("You find yourself in a room filled with chairs and tables.\n");
                        printf("The room looks like a dining hall.\n");
                        printf("You see a box on the table with a message beside it.\n");
                        printf("The message reads, 'Open only if you dare'\n");
                        printf("What do you want to do?\n");
                        printf("1. Open the box\n2. Leave the box alone and look for another way out\n");
                        scanf("%d",&choice);
                        if(choice == 1)
                        {
                            printf("You opened the box and found a strange crystal inside.\n");
                            printf("Suddenly, the crystal starts glowing and you hear strange noises coming from all around you.\n");
                            printf("You realized that you opened something you shouldn't have, and you faint. Game over!\n");
                        }
                        else if(choice == 2)
                        {
                            printf("You leave the box alone and look for another way out.\n");
                            printf("You find a secret passage behind one of the chairs.\n");
                            printf("You use the passage and manage to escape from the haunted house.\n");
                            printf("Congratulations! You have escaped from the haunted house.\n");
                            printf("You managed to escape the haunted house in %d moves.\n",count+5);
                            printf("We hope you enjoyed the game! Play again soon.\n");
                        }
                    }
                }
                else if(choice == 2)
                {
                    printf("You leave the box alone and look around the attic.\n");
                    printf("You find old pictures of the family who used to live in the house.\n");
                    printf("Suddenly, you hear strange noises coming from below.\n");
                    printf("What do you want to do?\n");
                    printf("1. Investigate the source of the noise\n2. Leave the attic and go through the door to the other room\n");
                    scanf("%d",&choice);
                    if(choice == 1)
                    {
                        printf("You investigate the noise and find a hidden passage.\n");
                        printf("You use the key to unlock the passage and enter it.\n");
                        printf("As you move forward, you see a bright light at the end of the passage.\n");
                        printf("You reach the end of the passage and see a way out.\n");
                        printf("Congratulations! You have escaped from the haunted house.\n");
                        printf("You managed to escape the haunted house in %d moves.\n",count+4);
                        printf("We hope you enjoyed the game! Play again soon.\n");
                    }
                    else if(choice == 2)
                    {
                        printf("You leave the attic and go through the door to the other room.\n");
                        printf("You find yourself in a room filled with chairs and tables.\n");
                        printf("The room looks like a dining hall.\n");
                        printf("You see a box on the table with a message beside it.\n");
                        printf("The message reads, 'Open only if you dare'\n");
                        printf("What do you want to do?\n");
                        printf("1. Open the box\n2. Leave the box alone and look for another way out\n");
                        scanf("%d",&choice);
                        if(choice == 1)
                        {
                            printf("You opened the box and found a strange crystal inside.\n");
                            printf("Suddenly, the crystal starts glowing and you hear strange noises coming from all around you.\n");
                            printf("You realized that you opened something you shouldn't have, and you faint. Game over!\n");
                        }
                        else if(choice == 2)
                        {
                            printf("You leave the box alone and look for another way out.\n");
                            printf("You find a secret passage behind one of the chairs.\n");
                            printf("You use the passage and manage to escape from the haunted house.\n");
                            printf("Congratulations! You have escaped from the haunted house.\n");
                            printf("You managed to escape the haunted house in %d moves.\n",count+5);
                            printf("We hope you enjoyed the game! Play again soon.\n");
                        }
                    }
                }
            }
            else if(choice == 2)
            {
                printf("You go through the door to the other room.\n");
                printf("You find yourself in a room filled with chairs and tables.\n");
                printf("The room looks like a dining hall.\n");
                printf("You see a box on the table with a message beside it.\n");
                printf("The message reads, 'Open only if you dare'\n");
                printf("What do you want to do?\n");
                printf("1. Open the box\n2. Leave the box alone and look for another way out\n");
                scanf("%d",&choice);
                if(choice == 1)
                {
                    printf("You opened the box and found a strange crystal inside.\n");
                    printf("Suddenly, the crystal starts glowing and you hear strange noises coming from all around you.\n");
                    printf("You realized that you opened something you shouldn't have, and you faint. Game over!\n");
                }
                else if(choice == 2)
                {
                    printf("You leave the box alone and look for another way out.\n");
                    printf("You find a secret passage behind one of the chairs.\n");
                    printf("You use the passage and manage to escape from the haunted house.\n");
                    printf("Congratulations! You have escaped from the haunted house.\n");
                    printf("You managed to escape the haunted house in %d moves.\n",count+5);
                    printf("We hope you enjoyed the game! Play again soon.\n");
                }
            }
        }
    }
    else if(answer == 'N' || answer == 'n')
    {
        printf("Maybe next time!\n");
    }
    else
    {
        printf("Invalid choice!\n");
    }
    return 0;
}