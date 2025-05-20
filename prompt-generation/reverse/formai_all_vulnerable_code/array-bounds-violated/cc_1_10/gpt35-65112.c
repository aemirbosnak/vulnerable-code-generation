//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_instructions();
void enter_room(char *room_name);

int main()
{
   srand(time(NULL));  //seed the random number generator

   print_instructions();  //print out the starting instructions

   //define the rooms in the haunted house
   char *rooms[] = {"Foyer", "Sitting Room", "Kitchen", "Dining Room", "Library", "Bedroom", "Bathroom", "Basement"};
   int num_rooms = sizeof(rooms)/sizeof(rooms[0]);

   int current_room = rand()%num_rooms;  //choose a random starting room

   while(1)  //loop until player exits the house
   {
       enter_room(rooms[current_room]);  //enter the current room

       //ask the player which direction they want to move in
       printf("Which direction do you want to move in (N, S, E, W)?\n");
       char direction = getchar();
       getchar();  //clear the newline character from the input stream

       //check if the player wants to exit the house
       if(direction == 'Q')
       {
           printf("You have successfully escaped the haunted house!\n");
           break;
       }

       //determine the index of the room in the given direction
       int new_room;
       switch(direction)
       {
           case 'N':
               new_room = current_room + 3;
               if(new_room >= num_rooms)  //check if out of bounds
               {
                   printf("There is no room in that direction.\n");
                   continue;
               }
               break;
           case 'S':
               new_room = current_room - 3;
               if(new_room < 0)  //check if out of bounds
               {
                   printf("There is no room in that direction.\n");
                   continue;
               }
               break;
           case 'E':
               new_room = current_room + 1;
               if(new_room%3 == 0)  //check if out of bounds
               {
                   printf("There is no room in that direction.\n");
                   continue;
               }
               break;
           case 'W':
               new_room = current_room - 1;
               if((new_room + 1)%3 == 0)  //check if out of bounds
               {
                   printf("There is no room in that direction.\n");
                   continue;
               }
               break;
           default:
               printf("Invalid direction.\n");
               continue;
       }

       current_room = new_room;  //update the current room to the new room
   }

   return 0;
}

void print_instructions()
{
    printf("Welcome to the haunted house! You will start in a randomly chosen room.\n");
    printf("Your goal is to find your way out of the house.\n");
    printf("You can move in the following directions: North (N), South (S), East (E), and West (W).\n");
    printf("Type Q to quit the game.\n");
}

void enter_room(char *room_name)
{
    printf("You have entered the %s.\n", room_name);

    //determine what creature is in the room
    int creature = rand()%3;
    switch(creature)
    {
        case 0:
            printf("There is a vampire in the room!\n");
            break;
        case 1:
            printf("There is a ghost in the room!\n");
            break;
        case 2:
            printf("There is a werewolf in the room!\n");
            break;
    }

    //generate a random puzzle
    int puzzle = rand()%3;
    switch(puzzle)
    {
        case 0:
            printf("There is a riddle on the wall:\n");
            printf("What is always in front of you but can't be seen?\n");
            printf("Answer: The future.\n");
            break;
        case 1:
            printf("There is a locked chest in the room.\n");
            printf("You must find the key to unlock it.\n");
            break;
        case 2:
            printf("There is a trap door on the floor.\n");
            printf("You must find a way to open it.\n");
            break;
    }
}