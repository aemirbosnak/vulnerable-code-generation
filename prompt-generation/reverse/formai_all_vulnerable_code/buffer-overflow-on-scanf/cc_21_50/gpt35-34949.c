//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Welcome message
  printf("Welcome to the Haunted House Simulator!\n\n");

  // Seed RNG
  srand(time(NULL));

  // Set up game variables
  int hasKey = 0; // Player does not have key initially
  int hasLamp = 0; // Player does not have lamp initially
  int hasMadeNoise = 0; // Player has not made noise initially
  int isCursed = 0; // Player is not cursed initially
  int isDead = 0; // Player is not dead initially
  int roomNum = 0; // Player starts in room 0
  int ghostRoom = rand() % 10 + 1; // Ghost is in a random room between 1-10
  int lampBatteryLife = 3; // Lamp starts with 3 batteries
  char input; // Player input variable

  // Main game loop
  while (!isDead && roomNum != ghostRoom)
  {
    // Print room description based on player's current location
    switch (roomNum)
    {
      case 0:
        printf("You are in the entrance room.\n");
        break;
      case 1:
        printf("You are in the living room.\n");
        break;
      case 2:
        printf("You are in the kitchen.\n");
        break;
      case 3:
        printf("You are in the dining room.\n");
        break;
      case 4:
        printf("You are in the bathroom.\n");
        break;
      case 5:
        printf("You are in the bedroom.\n");
        break;
      case 6:
        printf("You are in the attic.\n");
        break;
      case 7:
        printf("You are in the basement.\n");
        break;
      case 8:
        printf("You are in the storage room.\n");
        break;
      case 9:
        printf("You are in the library.\n");
        break;
      case 10:
        // Player has reached the ghost room
        break;
      default:
        printf("Error: Invalid room number.\n");
        break;
    }

    // If player has lamp, check battery life
    if (hasLamp)
    {
      printf("The lamp has %d batteries remaining.\n", lampBatteryLife);
      if (lampBatteryLife <= 0)
      {
        // Lamp has run out of battery, give player a scare and remove lamp
        printf("The lamp ran out of batteries and you are plunged into darkness!\n");
        hasLamp = 0;
        isCursed = 1;
      }
    }

    // Check if player is cursed (i.e. in total darkness)
    if (isCursed)
    {
      printf("You hear ghostly whispers and shivers run down your spine.\n");
    }

    // Check if player has made noise
    if (hasMadeNoise)
    {
      // Ghost has been alerted, move it to a new room
      ghostRoom = rand() % 10 + 1;
      printf("You hear the sound of footsteps getting closer.\n");
      hasMadeNoise = 0;
    }

    // Player options menu
    printf("What would you like to do?\n");
    printf("1. Move to another room.\n");
    if (!hasLamp)
    {
      printf("2. Search for a lamp.\n");
    }
    else
    {
      printf("2. Turn on/off the lamp.\n");
    }
    if (!hasKey)
    {
      printf("3. Look for a key.\n");
    }
    else
    {
      printf("3. Unlock a door.\n");
    }
    printf("4. Make a loud noise.\n");
    printf("5. Quit.\n");
    scanf(" %c", &input);

    // Switch statement for player options
    switch (input)
    {
      case '1':
        printf("Which room would you like to move to? (1-10)\n");
        scanf("%d", &roomNum);
        break;
      case '2':
        if (!hasLamp)
        {
          // Player finds a lamp in the current room
          printf("You found a lamp!\n");
          hasLamp = 1;
        }
        else
        {
          // Player turns the lamp on/off
          if (lampBatteryLife > 0)
          {
            printf("You turn the lamp %s.\n", hasLamp ? "off" : "on");
            hasLamp = !hasLamp;
          }
          else
          {
            printf("The lamp is out of batteries!\n");
          }
        }
        break;
      case '3':
        if (!hasKey)
        {
          // Player finds key in current room
          printf("You found a key!\n");
          hasKey = 1;
        }
        else
        {
          // Player tries to unlock a door
          printf("Which door would you like to unlock? (1-10)\n");
          int doorNum;
          scanf("%d", &doorNum);
          if (doorNum == ghostRoom)
          {
            printf("The ghost is in this room, you can't unlock the door!\n");
          }
          else if (doorNum != roomNum + 1 && doorNum != roomNum - 1)
          {
            printf("You can only unlock doors to adjacent rooms!\n");
          }
          else
          {
            printf("You unlocked the door!\n");
          }
        }
        break;
      case '4':
        // Player makes a loud noise, alerting the ghost
        printf("You make a loud noise!\n");
        hasMadeNoise = 1;
        break;
      case '5':
        // Player quits the game
        printf("Thanks for playing!\n");
        isDead = 1;
        break;
      default:
        printf("Invalid input, please try again.\n");
        break;
    }

    // Decrement lamp battery life if lamp is on
    if (hasLamp && input == '2')
    {
      lampBatteryLife--;
    }
  }

  if (isDead)
  {
    // Player quit early, do nothing
  }
  else
  {
    // Player reached the ghost room, game over
    printf("You enter the room and feel a cold breath on your neck. You turn around and see the ghost of the haunted house staring at you with hollow eyes. You scream in terror as the ghost engulfs you, tormenting you for all eternity.\n");
  }

  return 0;
}