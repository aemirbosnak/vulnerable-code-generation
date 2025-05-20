//Code Llama-13B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
char player_name[20];
int health = 100;
int mana = 50;
int gold = 0;
int level = 1;

// Function prototypes
void print_welcome_message();
void print_menu();
void print_game_over();
void game_over();
void attack(int enemy_health, int player_attack);

int main() {
  print_welcome_message();
  print_menu();
  return 0;
}

void print_welcome_message() {
  printf("Welcome to the world of Eldoria!\n");
  printf("You are a brave adventurer on a quest to save the kingdom from the evil sorcerer, Kahzul.\n");
  printf("You have been tasked with retrieving the Sword of Light, a powerful weapon that can defeat Kahzul and save the kingdom.\n");
  printf("You must navigate through the land of Eldoria, fighting off monsters and collecting treasure to upgrade your weapons and armor.\n");
  printf("You have a limited amount of health and mana, so be careful in battle!\n");
  printf("What is your name, brave adventurer?\n");
  scanf("%s", player_name);
  printf("Welcome, %s!\n", player_name);
}

void print_menu() {
  printf("You find yourself in a dark forest, surrounded by tall trees and deep shadows.\n");
  printf("You have the following options:\n");
  printf("1. Explore the forest\n");
  printf("2. Rest and recover health\n");
  printf("3. Go to the nearest town to buy supplies\n");
  printf("4. Continue on the road to the sorcerer's castle\n");
  printf("What would you like to do?\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("You explore the forest and find a clearing with a small cave in the center.\n");
      printf("As you approach the cave, you hear a faint growling sound coming from inside.\n");
      printf("You have the following options:\n");
      printf("1. Investigate the source of the sound\n");
      printf("2. Search the cave for treasure\n");
      printf("3. Leave the cave and continue on your journey\n");
      scanf("%d", &choice);
      switch (choice) {
        case 1:
          printf("As you enter the cave, you see a large bear standing on its hind legs, growling at you.\n");
          printf("The bear is blocking your path and won't let you pass.\n");
          printf("You have the following options:\n");
          printf("1. Attack the bear with your sword\n");
          printf("2. Try to sneak past the bear\n");
          printf("3. Use your magic to cast a spell on the bear\n");
          scanf("%d", &choice);
          switch (choice) {
            case 1:
              attack(100, 50);
              break;
            case 2:
              printf("You try to sneak past the bear, but it's too quick and catches you.\n");
              health -= 25;
              break;
            case 3:
              if (mana >= 10) {
                printf("You cast a spell on the bear, causing it to become dizzy and unable to attack.\n");
                mana -= 10;
              } else {
                printf("You don't have enough mana to cast a spell.\n");
              }
              break;
          }
          break;
        case 2:
          printf("You search the cave and find a small chest filled with gold coins.\n");
          gold += 50;
          break;
        case 3:
          printf("You leave the cave and continue on your journey.\n");
          break;
      }
      break;
    case 2:
      printf("You rest and recover some health.\n");
      health += 25;
      break;
    case 3:
      printf("You go to the nearest town to buy supplies.\n");
      printf("You buy a potion of healing for 25 gold coins and a scroll of lightning bolt for 50 gold coins.\n");
      gold -= 75;
      break;
    case 4:
      printf("You continue on the road to the sorcerer's castle.\n");
      break;
  }
  print_menu();
}

void print_game_over() {
  printf("You have died.\n");
  printf("Game over.\n");
}

void game_over() {
  print_game_over();
  exit(0);
}

void attack(int enemy_health, int player_attack) {
  printf("You attack the bear with your sword.\n");
  enemy_health -= player_attack;
  if (enemy_health <= 0) {
    printf("The bear has been defeated!\n");
  } else {
    printf("The bear attacks you back with its paws.\n");
    health -= 25;
  }
  if (health <= 0) {
    game_over();
  }
}