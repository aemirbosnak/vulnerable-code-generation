//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char name[20];
  char answer;
  int choice;

  // introduction
  printf("Welcome to the Artistic Adventure Game!\n");
  printf("What is your name?\n");
  gets(name);
  printf("Hello, %s! Are you ready to start the game? (Y/N)\n", name);
  scanf("%c", &answer);
  
  //start game
  if (answer == 'Y' || answer == 'y')
  {
    printf("\nGreat! You find yourself in a dark room. There is no door but a small window.\n");
    printf("You look out the window and see a beautiful garden. What do you do?\n");
    printf("\n1) Open the window and jump out to get a closer look.\n");
    printf("2) Sit and stare at the garden from afar.\n");
    printf("3) Look around the room for clues.\n");
    scanf("%d", &choice);

    //choice 1
    if (choice == 1)
    {
      printf("\nYou open the window and jump out. You land in a bush and get scratched by the thorns.\n");
      printf("As you stand up, you see a rabbit hopping by. It seems to be in a hurry. What do you do?\n");
      printf("\n1) Follow the rabbit and see where it goes.\n");
      printf("2) Ignore the rabbit and keep exploring the garden.\n");
      scanf("%d", &choice);
      
      //choice 1.1
      if (choice == 1)
      {
        printf("\nYou follow the rabbit through a maze of bushes and flowers. \n");
        printf("You come across a pond, where the rabbit jumps in and disappears.\n");
        printf("Do you want to jump in after it? (Y/N)\n");
        scanf(" %c", &answer);
        
        //choice 1.1.1
        if (answer == 'Y' || answer == 'y')
        {
          printf("\nYou jump in after the rabbit. You swim to the middle of the pond and find a door at the bottom.\n");
          printf("Do you want to open the door? (Y/N)\n");
          scanf(" %c", &answer);
          
          //choice 1.1.1.1
          if (answer == 'Y' || answer == 'y')
          {
            printf("\nYou open the door and find yourself in a beautiful room filled with art and sculptures.\n");
            printf("There is a note on the wall that reads 'Congratulations, you have found the treasure of the garden'\n");
            printf("You feel a sense of accomplishment and exit the garden.\n");
          }
          //choice 1.1.1.2
          else
          {
            printf("\nYou decide to leave the door alone and swim back to the shore.\n");
            printf("You explore the garden some more but can't find anything else of interest.\n");
            printf("You leave the garden feeling empty and unfulfilled.\n");
          }
        }
        
        //choice 1.1.2
        else
        {
          printf("\nYou decide not to jump in after the rabbit and explore the garden some more.\n");
          printf("You come across a gazebo where you see a man sitting. He seems to be in deep thought.\n");
          printf("Do you want to talk to him? (Y/N)\n");
          scanf(" %c", &answer);
          
          //choice 1.1.2.1
          if (answer == 'Y' || answer == 'y')
          {
            printf("\nYou approach the man and strike up a conversation.\n");
            printf("He tells you stories of his travels and adventures, inspiring you to seek new experiences.\n");
            printf("You leave the garden feeling fulfilled and motivated.\n");
          }
          //choice 1.1.2.2
          else
          {
            printf("\nYou decide not to talk to the man and continue exploring the garden.\n");
            printf("You don't find anything else of interest and leave the garden feeling unsatisfied.\n");
          }
        }
      }
      
      //choice 1.2
      else
      {
        printf("\nYou decide to ignore the rabbit and explore the garden some more.\n");
        printf("You come across a statue that catches your eye. It seems to be glowing.\n");
        printf("Do you want to investigate? (Y/N)\n");
        scanf(" %c", &answer);
        
        //choice 1.2.1
        if (answer == 'Y' || answer == 'y')
        {
          printf("\nYou approach the statue and notice a small keyhole at its base.\n");
          printf("Do you have a key? (Y/N)\n");
          scanf(" %c", &answer);
          
          //choice 1.2.1.1
          if (answer == 'Y' || answer == 'y')
          {
            printf("\nYou pull out the key and unlock the statue. It opens up to reveal a hidden passage.\n");
            printf("You follow the passage and find yourself in a room filled with gold and jewels.\n");
            printf("You have found the treasure of the garden!\n");
          }
          //choice 1.2.1.2
          else
          {
            printf("\nYou don't have a key and can't seem to find one anywhere.\n");
            printf("You leave the garden feeling frustrated and disappointed.\n");
          }
        }
        //choice 1.2.2
        else
        {
          printf("\nYou decide not to investigate the statue and continue exploring the garden.\n");
          printf("You don't find anything else of interest and leave the garden feeling unfulfilled.\n");
        }
      }
    }
    
    // choice 2
    else if (choice == 2)
    {
      printf("\nYou sit and stare at the garden from afar.\n");
      printf("As you sit there, you feel a sense of peace and tranquility.\n");
      printf("However, you also feel like you're missing out on something.\n");
      printf("Do you want to explore the garden further? (Y/N)\n");
      scanf(" %c", &answer);
      if (answer == 'Y' || answer == 'y')
      {
        printf("\nYou get up and explore the garden further.\n");
        printf("You come across a pond where you see a fish swimming. It seems to be staring at you.\n");
        printf("Do you want to catch the fish? (Y/N)\n");
        scanf(" %c", &answer);
        if (answer == 'Y' || answer == 'y')
        {
          printf("\nYou try to catch the fish but it's too fast for you.\n");
          printf("You leave the garden feeling a little disappointed but still at peace.\n");
        }
        else
        {
          printf("\nYou decide not to catch the fish and continue exploring the garden.\n");
          printf("You don't find anything else of interest and leave the garden feeling a little empty.\n");
        }
      }
      else
      {
        printf("\nYou decide not to explore the garden any further and leave feeling peaceful but unfulfilled.\n");
      }
    }
    
    //choice 3
    else
    {
      printf("\nYou decide to look around the room for clues.\n");
      printf("You notice a painting on the wall that seems to be out of place.\n");
      printf("Do you want to investigate the painting? (Y/N)\n");
      scanf(" %c", &answer);
      if (answer == 'Y' || answer == 'y')
      {
        printf("\nYou move the painting and find a small keyhole.\n");
        printf("Do you have a key? (Y/N)\n");
        scanf(" %c", &answer);
        if (answer == 'Y' || answer == 'y')
        {
          printf("\nYou pull out the key and unlock the keyhole. A hidden door opens up.\n");
          printf("You follow the passage and find yourself in a room filled with gold and jewels.\n");
          printf("You have found the treasure of the garden!\n");
        }
        else
        {
          printf("\nYou don't have a key and can't seem to find one anywhere.\n");
          printf("You leave the room feeling frustrated and unfulfilled.\n");
        }
      }
      else
      {
        printf("\nYou decide not to investigate the painting and continue exploring the room.\n");
        printf("You don't find anything else of interest and leave feeling unfulfilled.\n");
      }
    }
  }
  
  //end game
  else
  {
    printf("\nToo bad! Maybe next time.\n");
  }

  return 0;
}