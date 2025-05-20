//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize the random seed

  char* planet_names[10] = {"Nebula Nym", "Galactic Gloom", "Starshine Station", "Celestial City", "Planet Prism", "Orbit Oasis", "Midnight Meteor", "Cosmic Cove", "Spiral Summit", "Moon Maelstrom"};

  int player_fuel = 100;
  int player_health = 100;

  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are the captain of a spaceship on a mission to explore the galaxy and discover new planets.\n");

  while (player_health > 0) {
    int planet_index = rand() % 10; //generate a random planet
    int planet_distance = rand() % 1000 + 1; //generate a random distance between 1 and 1000 light years

    printf("You have arrived at %s, %d light years away.\n", planet_names[planet_index], planet_distance);

    player_fuel -= planet_distance / 10; //consume fuel based on distance
    if (player_fuel <= 0) {
      printf("You have run out of fuel and are stranded in space. Game over.\n");
      break;
    }

    int random_event = rand() % 3; //generate a random event
    switch(random_event) {
      case 0:
        printf("You discover a new species that is friendly and offers to trade with you.\n");
        break;
      case 1:
        printf("Your ship is hit by meteor shower and takes damage. You must repair it before continuing.\n");
        player_health -= 10; //take damage
        if (player_health <= 0) {
          printf("Your ship has been destroyed. Game over.\n");
          break;
        }
        break;
      case 2:
        printf("You come across a planet that is covered in a mysterious fog. Will you explore it?\n");
        int decision;
        scanf("%d", &decision);
        if (decision == 1) {
          printf("You explore the planet and find a rare mineral that can be used to upgrade your ship.\n");
          player_fuel += 50; //refund some fuel to the player
          player_health += 10; //restore some health to the player
        } else {
          printf("You decide not to take the risk and continue on your journey.\n");
        }
        break;
    }
  }

  printf("Thank you for playing Procedural Space Adventure!\n");
  return 0;
}