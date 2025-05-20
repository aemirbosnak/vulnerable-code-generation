//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
  char name[20], choice[20];
  int health = 100, score = 0;

  printf("Welcome to Adventure Game! Please enter your name: ");
  scanf("%s", name);

  printf("\nHi, %s! You are a brave adventurer on a quest to find the legendary treasure.\n", name);

  while(health > 0) {
    printf("\n-------------------------------------------------\n");
    printf("You are now in a dark and spooky forest. What would you like to do? (Type your choice)\n");
    printf("1. Move forward\n");
    printf("2. Rest\n");
    printf("3. Look for clues\n");

    scanf("%s", choice);

    if(strcmp(choice, "1") == 0) { // Move forward
      printf("\nYou slowly move forward, careful not to make any noise.\n");
      printf("Suddenly, you hear something approaching...\n");
      printf("Oh no! It's a pack of wild wolves!\n");

      int wolves = rand() % 3 + 1;
      int wolf_health = 30;

      while(wolves > 0 && health > 0) {
        printf("\n-------------------------------------------------\n");
        printf("There are %d wolves attacking you! What will you do? (Type your choice)\n", wolves);
        printf("1. Fight\n");
        printf("2. Run\n");

        scanf("%s", choice);

        if(strcmp(choice, "1") == 0) { // Fight
          printf("\nYou draw your sword and charge at the wolves!\n");
          printf("You attack the first wolf and deal 25 damage!\n");

          wolf_health -= 25;

          if(wolf_health <= 0) {
            printf("\nYou have defeated a wolf!\n");
            score += 10;
            wolves--;
            wolf_health = 30;
          }

          if(wolves > 0) {
            printf("\nThe wolves are not impressed, they continue to attack!\n");
            printf("You take 10 damage from their combined attacks!\n");

            health -= 10;

            if(health <= 0) {
              printf("\nYou have died!\n");
              printf("Your score: %d\n", score);
              break;
            }
          }
        } else if(strcmp(choice, "2") == 0) { // Run
          printf("\nYou turn around and run as fast as you can!\n");

          int damage = rand() % 20 + 10;
          printf("But the wolves catch up to you and bite you from behind!\n");
          printf("You take %d damage!\n", damage);

          health -= damage;

          if(health <= 0) {
            printf("\nYou have died!\n");
            printf("Your score: %d\n", score);
            break;
          }
        } else {
          printf("\nInvalid choice, try again!\n");
        }
      }
    } else if(strcmp(choice, "2") == 0) { // Rest
      printf("\nYou find a clearing and decide to rest for a while.\n");
      printf("You regain 10 health points.\n");

      health += 10;

      if(health > 100) {
        health = 100; // Set health to a maximum of 100
      }
    } else if(strcmp(choice, "3") == 0) { // Look for clues
      printf("\nYou search the area for clues.\n");
      printf("You find a piece of paper with the following message:\n");
      printf("North, East, South, West.\n");
    } else {
      printf("\nInvalid choice, try again!\n");
    }
  }
  
  return 0;
}