//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

void printRoom(int roomNum);
void roomOne(char* player);
void roomTwo(char* player);
void roomThree(char* player);
void roomFour(char* player);
void roomFive(char* player);
void finalRoom(char* player);

int main() {
  srand(time(NULL));
  int roomNum = 1;
  char* player = (char*)malloc(20*sizeof(char));
  
  printf("Welcome to the Haunted House Simulator!\n");
  printf("What is your name, adventurer?\n");
  scanf("%s", player);
  
  while(roomNum != 6) {
    printRoom(roomNum);
    
    if(roomNum == 1) {
      roomOne(player);
    } else if(roomNum == 2) {
      roomTwo(player);
    } else if(roomNum == 3) {
      roomThree(player);
    } else if(roomNum == 4) {
      roomFour(player);
    } else if(roomNum == 5) {
      roomFive(player);
    }
    
    roomNum++;
  }
  
  finalRoom(player);
  
  free(player);
  return 0;
}

void printRoom(int roomNum) {
  printf("========== Room %d ==========\n", roomNum);
}

void roomOne(char* player) {
  printf("As soon as you enter the house, you hear creaking floorboards and the faint sound of whispering.\n");
  printf("You cautiously make your way through the living room and into the kitchen.\n");
  printf("You see a shiny object on the floor. Do you A) Pick it up or B) Leave it alone?\n");
  
  char choice;
  scanf(" %c", &choice);
  choice = tolower(choice);
  
  if(choice == 'a') {
    printf("You pick up the object and realize it's a key. You put it in your pocket and continue exploring the house.\n");
  } else {
    printf("You decide to leave the object alone and continue exploring the house.\n");
  }
}

void roomTwo(char* player) {
  printf("You enter a dark, dusty room that appears to be a library.\n");
  printf("The books are old and worn, but some titles catch your eye: 'Curses and Hexes', 'The Necronomicon', and 'How to Summon Demons'.\n");
  printf("Do you A) Read one of the books or B) Leave the room?\n");
  
  char choice;
  scanf(" %c", &choice);
  choice = tolower(choice);
  
  if(choice == 'a') {
    printf("You pick up 'The Necronomicon' and start to read. The words make no sense, but you feel like you've disturbed something.\n");
    printf("You quickly put the book back and leave the room.\n");
  } else {
    printf("You decide to leave the room, feeling like you shouldn't mess with things you don't understand.\n");
  }
}

void roomThree(char* player) {
  printf("You enter what appears to be a child's bedroom.\n");
  printf("The walls are covered in colorful stickers and the bed is made up with a cute quilt.\n");
  printf("You start to feel a little more at ease...until you see the strange, shadowy figure standing in the corner.\n");
  printf("Do you A) Investigate the figure or B) Run out of the room?\n");
  
  char choice;
  scanf(" %c", &choice);
  choice = tolower(choice);
  
  if(choice == 'a') {
    int chance = rand() % 10;
    if(chance > 3) {
      printf("You investigate the figure and realize it's just a coat hanging on a hook. You feel silly and leave the room.\n");
    } else {
      printf("You investigate the figure and realize it's a ghostly apparition. It attacks you and you lose a life.\n");
      // lose life
    }
  } else {
    printf("You run out of the room, feeling like you can't handle any more strange occurrences.\n");
  }
}

void roomFour(char* player) {
  printf("You enter a dimly lit room that looks like it hasn't been touched in years.\n");
  printf("As you step forward, the floorboards creak and you hear a low growl.\n");
  printf("You realize there's a large, snarling dog in the corner of the room.\n");
  printf("Do you A) Try to befriend the dog or B) Back away slowly?\n");
  
  char choice;
  scanf(" %c", &choice);
  choice = tolower(choice);
  
  if(choice == 'a') {
    printf("You slowly approach the dog and offer it a piece of your food. It sniffs it suspiciously before gobbling it up.\n");
    printf("The dog seems to have calmed down, and you decide to leave the room before it changes its mind.\n");
  } else {
    printf("You back away slowly, trying not to make any sudden movements. The dog barks at you, but doesn't seem to be interested in attacking.\n");
    printf("You leave the room quietly, glad to have avoided a confrontation.\n");
  }
}

void roomFive(char* player) {
  printf("You finally reach the final room in the house.\n");
  printf("It's a large, open space with a single object in the center: a locked chest.\n");
  printf("You pull out the key you found earlier and try it in the lock. To your surprise, it fits perfectly.\n");
  printf("As you open the chest, you hear a faint whisper in your ear.\n");
  printf("Do you A) Investigate the whisper or B) Ignore it and continue exploring the chest?\n");
  
  char choice;
  scanf(" %c", &choice);
  choice = tolower(choice);
  
  if(choice == 'a') {
    printf("You turn around to investigate the whisper, but there's no one there.\n");
    printf("You start to feel uneasy, and quickly grab what you can from the chest before leaving the room.\n");
  } else {
    printf("You ignore the whisper and focus on the chest. Inside, you find a valuable relic worth a lot of money.\n");
    printf("You leave the room feeling happy with your find, but also slightly unnerved by the whisper.\n");
  }
}

void finalRoom(char* player) {
  printf("You exit the haunted house, relieved that you made it out alive.\n");
  printf("You turn around to admire the house one last time, only to see that it's completely disappeared.\n");
  printf("You can't shake the feeling that something isn't right, but you push those thoughts to the back of your mind.\n");
  printf("You survived the haunted house, and that's all that matters.\n");
}