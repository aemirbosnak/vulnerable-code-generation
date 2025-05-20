//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>

int main() {
  char player_name[20];
  int player_health = 100;
  int player_score = 0;
  int choice;
  
  printf("Welcome adventurer! What is your name?\n");
  scanf("%s", player_name);
  
  printf("Greetings, %s! Your journey will be tough and dangerous, but also rewarding. You start your adventure with %d health and %d score.\n", player_name, player_health, player_score);
  
  printf("You find yourself at a crossroad. Which way will you go? (1) Left, (2) Right, (3) Straight\n");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("You chose to go left. You encounter a group of bandits. They attack you!\n");
      player_health -= 30;
      printf("You lost 30 health. You have %d health left.\n", player_health);
      break;
    case 2:
      printf("You chose to go right. You discover a hidden treasure chest. It contains 50 gold coins!\n");
      player_score += 50;
      printf("You gained 50 score. Your score is now %d.\n", player_score);
      break;
    case 3:
      printf("You chose to go straight. You see a dark cave. It looks scary, but also promising. Do you want to enter it? (1) Yes, (2) No\n");
      scanf("%d", &choice);
      
      if(choice == 1) {
        printf("You enter the cave. It's dark and damp. You hear strange sounds. Suddenly, you see a glowing object in the distance. You walk towards it. It's a magical artifact! You touch it and... you feel an immense power flowing through your body. You gained 100 score!\n");
        player_score += 100;
        printf("Your score is now %d.\n", player_score);
      } else {
        printf("You choose not to enter the cave. You continue your journey.\n");
      }
      break;
    default:
      printf("Invalid choice. You stand still, not sure which way to go.\n");
  }
  
  printf("You continue your journey. You encounter a troll. It's blocking your path. You have to defeat it to proceed. (1) Attack, (2) Run\n");
  scanf("%d", &choice);
  
  if(choice == 1) {
    printf("You attack the troll. You deal 40 damage. The troll retaliates and deals 20 damage. You have %d health left.\n", player_health -= 20);
    
    if(player_health <= 0) {
      printf("You have been defeated. Your journey ends here.\n");
      return 0;
    }
    
    printf("You deal another 40 damage. The troll falls to the ground, defeated. You gained 80 score!\n");
    player_score += 80;
  } else {
    printf("You run away, but the troll catches up to you. It deals 50 damage. You have %d health left.\n", player_health -= 50);
    
    if(player_health <= 0) {
      printf("You have been defeated. Your journey ends here.\n");
      return 0;
    }
    
    printf("You manage to escape, but you lose 20 score.\n");
    player_score -= 20;
  }
  
  printf("You reach your destination. You accomplished your mission! Your final score is %d.\n", player_score);
  
  return 0;
}