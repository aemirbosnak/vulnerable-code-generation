//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>

int main() {
  int strength = 10;
  int agility = 13;
  int intelligence = 15;
  int health = 100;
  int mana = 50;
  
  printf("Medieval RPG Stats\n");
  printf("-------------------\n");
  printf("Strength: %d\n", strength);
  printf("Agility: %d\n", agility);
  printf("Intelligence: %d\n", intelligence);
  printf("Health: %d/%d\n", health, health);
  printf("Mana: %d/%d\n", mana, mana);
  printf("-------------------\n");
  
  printf("You find yourself in a medieval village. As you wander around, you come across a blacksmith's shop.\n");
  printf("The blacksmith greets you warmly and offers to let you try out his hammer on the anvil.\n");
  printf("Do you want to:\n");
  printf("A) Try out the hammer\n");
  printf("B) Decline the offer\n");
  
  char choice;
  scanf("%c", &choice);
  
  if (choice == 'A' || choice == 'a') {
    printf("You grip the hammer tightly and swing it at the anvil. The sound echoes through the village.\n");
    strength += 2;
    printf("Your strength has increased to %d.\n", strength);
  }
  else if (choice == 'B' || choice == 'b') {
    printf("You decline the offer and continue on your way.\n");
  }
  else {
    printf("You didn't make a valid choice. Please try again.\n");
  }
  
  printf("You come across a wizard who is experimenting with some magical potions.\n");
  printf("He offers you a potion that he says will increase your intelligence.\n");
  printf("Do you want to:\n");
  printf("A) Drink the potion\n");
  printf("B) Refuse the potion\n");
  
  scanf(" %c", &choice);
  
  if (choice == 'A' || choice == 'a') {
    printf("You drink the potion and feel your mind expanding.\n");
    intelligence += 3;
    mana += 10;
    printf("Your intelligence has increased to %d and your mana has increased to %d.\n", intelligence, mana);
  }
  else if (choice == 'B' || choice == 'b') {
    printf("You refuse the potion and continue on your way.\n");
  }
  else {
    printf("You didn't make a valid choice. Please try again.\n");
  }
  
  printf("You come across a thief who challenges you to a game of agility.\n");
  printf("He says that he will give you a valuable item if you beat him.\n");
  printf("Do you want to:\n");
  printf("A) Accept the challenge\n");
  printf("B) Decline the challenge\n");
  
  scanf(" %c", &choice);
  
  if (choice == 'A' || choice == 'a') {
    printf("You accept the challenge and the thief sets up an obstacle course.\n");
    printf("You navigate the course flawlessly and win the valuable item.\n");
    agility += 5;
    printf("Your agility has increased to %d.\n", agility);
  }
  else if (choice == 'B' || choice == 'b') {
    printf("You decline the challenge and continue on your way.\n");
  }
  else {
    printf("You didn't make a valid choice. Please try again.\n");
  }
  
  printf("Final Stats:\n");
  printf("-----------\n");
  printf("Strength: %d\n", strength);
  printf("Agility: %d\n", agility);
  printf("Intelligence: %d\n", intelligence);
  printf("Health: %d/%d\n", health, health);
  printf("Mana: %d/%d\n", mana, mana);
  printf("-----------\n");
  
  return 0;
}