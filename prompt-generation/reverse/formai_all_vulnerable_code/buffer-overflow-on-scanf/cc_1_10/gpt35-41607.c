//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Interoperable Procedural Space Adventure

  In this program, the user will navigate through a randomly generated
  galaxy, encountering various alien species and obstacles along the way.
  The user's ultimate goal is to reach the center of the galaxy and discover
  its secrets. The program will be written in a procedural style, allowing
  for easy interoperability between different programming languages.
*/

// Randomly generates a number between min and max (inclusive)
int random_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Returns the name of a random alien species
char* generate_species_name() {
  char *species[] = {"Zoraxians", "Sylpharians", "Talaxians", "Jenarans", "Krynnites"};
  return species[random_range(0, 4)];
}

// The main game loop
void play_game() {
  // Generate the galaxy
  int galaxy_size = random_range(10, 20);
  int center_x = galaxy_size / 2;
  int center_y = galaxy_size / 2;

  // Initialize the player's ship
  int player_x = random_range(0, galaxy_size - 1);
  int player_y = random_range(0, galaxy_size - 1);
  int fuel = 100;

  // Start the game
  printf("Welcome to the Interoperable Procedural Space Adventure!\n\n");
  printf("You are the captain of the starship %s.\n", generate_species_name());
  
  while (1) {
    // Print the current location and fuel level
    printf("\nCurrent Location: (%d, %d)\n", player_x, player_y);
    printf("Fuel: %d\n", fuel);

    // Check if the player has made it to the center of the galaxy
    if (player_x == center_x && player_y == center_y) {
      printf("\nCongratulations! You have reached the center of the galaxy!\n");
      break;
    }

    // Check if the player has run out of fuel
    if (fuel <= 0) {
      printf("\nYou have run out of fuel and are stranded in space. Game over.\n");
      break;
    }

    // Generate a random event (0 = nothing, 1 = alien encounter, 2 = asteroid field)
    int event = random_range(0, 2);

    if (event == 1) {
      // Alien Encounter
      printf("\nYou have encountered a ship from the %s species!\n", generate_species_name());
      printf("What do you want to do? (1 = negotiate, 2 = attack, 3 = flee)\n");

      int choice;
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          printf("\nYou successfully negotiated with the aliens and they have given you a fuel boost.\n");
          fuel += random_range(10, 20);
          break;
        case 2:
          printf("\nYou attacked the aliens, but they were too strong. You lost 20 fuel and were forced to flee.\n");
          fuel -= 20;
          player_x += random_range(-2, 2);
          player_y += random_range(-2, 2);
          break;
        case 3:
          printf("\nYou successfully fled from the aliens.\n");
          player_x += random_range(-2, 2);
          player_y += random_range(-2, 2);
          break;
        default:
          printf("Invalid choice. Please choose again.\n");
      }
    } else if (event == 2) {
      // Asteroid Field
      printf("\nYou have entered an asteroid field and are taking damage!\n");
      printf("What do you want to do? (1 = try to dodge, 2 = use shields)\n");

      int choice;
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          if (random_range(0, 1)) {
            printf("\nYou successfully dodged the asteroids and took no damage.\n");
          } else {
            printf("\nYou were hit by asteroids and took 10 damage to your ship.\n");
            fuel -= 10;
          }
          break;
        case 2:
          printf("\nYou activated your shields and took no damage.\n");
          break;
        default:
          printf("Invalid choice. Please choose again.\n");
      }

      // Move the player's ship
      player_x += random_range(-1, 1);
      player_y += random_range(-1, 1);

      // Consume fuel
      fuel -= random_range(1, 5);
    } else {
      // Nothing
      printf("\nNothing of interest was found here... moving on.\n");

      // Move the player's ship
      player_x += random_range(-1, 1);
      player_y += random_range(-1, 1);

      // Consume fuel
      fuel -= random_range(1, 5);
    }
  }
}

int main() {
  srand(time(NULL));
  play_game();
  return 0;
}