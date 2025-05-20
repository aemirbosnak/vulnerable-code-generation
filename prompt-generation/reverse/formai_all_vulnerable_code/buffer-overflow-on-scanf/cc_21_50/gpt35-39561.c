//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <string.h>

int main()
{
   char direction[20], item[20];
   int health = 100, attack = 10, defense = 5;
   int goblin_health = 50, goblin_attack = 8, goblin_defense = 2;
   int boss_health = 100, boss_attack = 15, boss_defense = 10;
   int key = 0, gold = 0, level = 1, exp = 0;
   
   printf("Welcome to Adventure Game!\n");
   printf("Choose Your Name: ");
   
   char name[20];
   scanf("%s", name);
   
   printf("Welcome %s! Your journey begins here.\n", name);
   printf("You are in a forest, surrounded by trees. There is a path to your north.\n");
   printf("What direction would you like to go? ");
   
   while(scanf("%s", direction) == 1)
   {
      if(strcmp(direction, "north") == 0)
      {
         printf("You see a goblin!\n");
         printf("[1] Fight\n[2] Run\n");
         
         int choice;
         scanf("%d", &choice);
         
         while(choice != 1 && choice != 2)
         {
            printf("Invalid Choice! Please choose again: ");
            scanf("%d", &choice);
         }
         
         if(choice == 1)
         {
            printf("You engage the goblin in battle!\n");
            int round = 0;
            while(health > 0 && goblin_health > 0)
            {
               round++;
               printf("Round %d\n", round);
               printf("Your health: %d, Goblin health: %d\n", health, goblin_health);
               
               // player attack
               int damage = attack - goblin_defense;
               if(damage < 0)
                  damage = 0;
               goblin_health -= damage;
               printf("%s deals %d damage to goblin!\n", name, damage);
               
               // goblin attack
               damage = goblin_attack - defense;
               if(damage < 0)
                  damage = 0;
               health -= damage;
               printf("Goblin deals %d damage to %s!\n", damage, name);
            }
            
            if(health > 0)
            {
               printf("You defeated the goblin!\n");
               printf("You gained 20 gold and 10 exp.\n");
               gold += 20;
               exp += 10;
               if(exp >= level*50)
               {
                  level++;
                  printf("Congratulations! You leveled up to level %d!\n", level);
                  printf("Your attack increases to %d and defense increases to %d.\n", attack+5, defense+2);
                  attack += 5;
                  defense += 2;
               }
            }
            else
            {
               printf("You were killed by the goblin!\n");
               return 0;
            }
         }
         else
         {
            printf("You run away from the goblin!\n");
         }
         
         printf("What direction would you like to go? ");
      }
      else if(strcmp(direction, "east") == 0)
      {
         printf("You found a locked chest! Do you have a key?\n");
         if(key == 1)
         {
            printf("You used the key to open the chest and found 50 gold!\n");
            gold += 50;
            key = 0;
         }
         else
         {
            printf("You do not have a key to open the chest. Keep going.\n");
         }
         
         printf("What direction would you like to go? ");
      }
      else if(strcmp(direction, "west") == 0)
      {
         printf("You found a hidden cave! Would you like to enter?\n");
         printf("[1] Yes\n[2] No\n");
         
         int choice;
         scanf("%d", &choice);
         
         while(choice != 1 && choice != 2)
         {
            printf("Invalid Choice! Please choose again: ");
            scanf("%d", &choice);
         }
         
         if(choice == 1)
         {
            printf("You enter the cave and found a boss!\n");
            printf("[1] Fight\n[2] Run\n");
            
            scanf("%d", &choice);
            
            while(choice != 1 && choice != 2)
            {
               printf("Invalid Choice! Please choose again: ");
               scanf("%d", &choice);
            }
            
            if(choice == 1)
            {
               printf("You engage the boss in battle!\n");
               int round = 0;
               while(health > 0 && boss_health > 0)
               {
                  round++;
                  printf("Round %d\n", round);
                  printf("Your health: %d, Boss health: %d\n", health, boss_health);
                  
                  // player attack
                  int damage = attack - boss_defense;
                  if(damage < 0)
                     damage = 0;
                  boss_health -= damage;
                  printf("%s deals %d damage to boss!\n", name, damage);
                  
                  // boss attack
                  damage = boss_attack - defense;
                  if(damage < 0)
                     damage = 0;
                  health -= damage;
                  printf("Boss deals %d damage to %s!\n", damage, name);
               }
               
               if(health > 0)
               {
                  printf("You defeated the boss!\n");
                  printf("You win the game!\n");
                  return 0;
               }
               else
               {
                  printf("You were killed by the boss!\n");
                  return 0;
               }
            }
            else
            {
               printf("You run away from the boss!\n");
            }
         }
         else
         {
            printf("You decided not to enter the cave.\n");
         }
         
         printf("What direction would you like to go? ");
      }
      else if(strcmp(direction, "south") == 0)
      {
         printf("You found a merchant! Do you want to buy anything?\n");
         printf("[1] Key (25 gold)\n[2] Health potion (+20 health, 30 gold)\n[3] Leave\n");
         
         int choice;
         scanf("%d", &choice);
         
         while(choice != 1 && choice != 2 && choice != 3)
         {
            printf("Invalid Choice! Please choose again: ");
            scanf("%d", &choice);
         }
         
         switch(choice)
         {
            case 1:
               if(gold >= 25)
               {
                  printf("You bought a key!\n");
                  gold -= 25;
                  key = 1;
               }
               else
               {
                  printf("You don't have enough gold to buy a key!\n");
               }
               break;
            case 2:
               if(gold >= 30)
               {
                  printf("You bought a health potion!\n");
                  gold -= 30;
                  health += 20;
                  if(health > 100)
                     health = 100;
               }
               else
               {
                  printf("You don't have enough gold to buy a health potion!\n");
               }
               break;
            case 3:
               printf("You left the merchant.\n");
               break;
         }
         
         printf("What direction would you like to go? ");
      }
      else
      {
         printf("Invalid direction! Please choose again: ");
      }
   }
   
   return 0;
}