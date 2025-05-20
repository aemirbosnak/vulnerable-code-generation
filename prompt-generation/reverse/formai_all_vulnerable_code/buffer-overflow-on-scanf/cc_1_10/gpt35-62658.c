//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to simulate the haunted house experience
void haunted_house_simulator() {
  int choice, room, num_attempts = 0;
  srand(time(NULL));
  
  //printing the intro text
  printf("Welcome to the Haunted House Simulator!\n\n");
  printf("You are standing in front of a mysterious old mansion. Do you dare to enter?\n");
  printf("1. Yes, I am brave enough!\n");
  printf("2. No, I better turn back now.\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);
  
  //checking if the user has decided to continue or not
  if(choice == 2) {
    printf("\nYou have chickened out. Goodbye!\n");
    return;
  }
  
  printf("\nAs you enter the mansion, you find yourself in a dark hallway.\n");
  printf("You hear a creaking sound from one of the rooms.\n\n");
  
  //loop to choose a random room for the user to enter
  while(num_attempts < 3) {
    room = rand() % 4 + 1;
    
    //switch statement to enter the chosen room
    switch(room) {
      case 1:
        printf("You enter a dusty old library. The books are torn and covered in spiderwebs.\n");
        printf("Suddenly, you hear a loud thud behind you!\n");
        printf("1. Look behind to see what it was.\n");
        printf("2. Ignore the sound and continue exploring the library.\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        //checking the user's choice
        if(choice == 1){
          printf("\nYou turn around and see a ghostly figure staring back at you!\n");
          printf("You run out of the library in terror!\n");
          return;
        }
        else {
          printf("\nYou hear the sound again, but you ignore it and continue exploring the library.\n");
        }
        break;
        
      case 2:
        printf("You enter a creepy dining room. The table is set for a meal, but the plates are covered in dust.\n");
        printf("You suddenly feel a chilly breeze on your neck.\n");
        printf("1. Ignore the feeling and continue exploring the dining room.\n");
        printf("2. Turn around to check if someone is there.\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        //checking the user's choice
        if(choice == 2){
          printf("\nAs you turn around, you see a ghostly figure staring back at you!\n");
          printf("You run out of the dining room in terror!\n");
          return;
        }
        else {
          printf("\nThe feeling disappears, and you continue exploring the dining room.\n");
        }
        break;
        
      case 3:
        printf("You enter a spooky bedroom. The bed is unmade, and the curtains are torn.\n");
        printf("You hear a faint whispering sound coming from one of the corners.\n");
        printf("1. Investigate the sound.\n");
        printf("2. Leave the bedroom immediately.\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        //checking the user's choice
        if(choice == 1){
          printf("\nAs you move closer to investigate the sound, you feel a cold hand on your shoulder!\n");
          printf("You scream and run out of the bedroom in terror!\n");
          return;
        }
        else {
          printf("\nYou quickly leave the bedroom, not wanting to investigate further.\n");
        }
        break;
        
      case 4:
        printf("You enter a dimly lit study. The desk is covered in dusty papers and books.\n");
        printf("You smell a faint odor coming from one of the corners.\n");
        printf("1. Investigate the smell.\n");
        printf("2. Leave the study immediately.\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        //checking the user's choice
        if(choice == 1){
          printf("\nAs you move closer to investigate the smell, you feel a sudden gust of wind and a loud noise!\n");
          printf("You turn around to see a window has been smashed open!\n");
          printf("You quickly leave the study, feeling like someone or something is watching you.\n");
          return;
        }
        else {
          printf("\nYou quickly leave the study, not wanting to investigate further.\n");
        }
        break;
    }
    num_attempts++;
  }
  
  //if the user has tried all 3 rooms without encountering a ghost, print the success message
  printf("\nAfter exploring the mansion, you find that it's actually not haunted, but just very old and creaky.\n");
  printf("You leave the mansion feeling relieved and alive.\n");
}

int main() {
  haunted_house_simulator();
  return 0;
}