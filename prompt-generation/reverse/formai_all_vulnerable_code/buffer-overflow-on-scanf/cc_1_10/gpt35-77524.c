//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player {
  char name[20];
  int age;
  int weight;
  int height;
  int calories;
  int steps;
};

int main() {
  int num_players;
  srand(time(NULL));

  printf("How many players will be playing?\n");
  scanf("%d", &num_players);

  struct player players[num_players];

  for (int i = 0; i < num_players; i++) {
    printf("Enter player %d's name: ", i+1);
    scanf("%s", players[i].name);
    printf("Enter player %d's age: ", i+1);
    scanf("%d", &players[i].age);
    printf("Enter player %d's weight (in pounds): ", i+1);
    scanf("%d", &players[i].weight);
    printf("Enter player %d's height (in inches): ", i+1);
    scanf("%d", &players[i].height);
    players[i].calories = 0;
    players[i].steps = 0;
  }

  printf("Day 1\n");
  for (int i = 0; i < num_players; i++) {
    int random_steps = rand() % 5000 + 1000;
    int random_calories = rand() % 500 + 100;
    players[i].steps += random_steps;
    players[i].calories += random_calories;
    printf("%s took %d steps and burned %d calories.\n", players[i].name, random_steps, random_calories);
  }

  //Day 2 
  //Continues for n days

  printf("Final Results:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s took %d steps and burned %d calories overall.\n", players[i].name, players[i].steps, players[i].calories);
  }

  return 0;
}