//LLAMA2-13B DATASET v1.0 Category: Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define KRAKEN 0x43211234
#define DRAGON  0x21123456
#define PHOENIX 0x12345678

int main() {
  // Initialize the Kraken's lair
  printf("Welcome to the Kraken's lair...\n");
  srand(time(NULL));
  int lair = (rand() % 3) + 1;

  // Choose your weapon
  printf("Choose your weapon... (1) Trident of the Deep, (2) Wave Slayer, or (3) Tentacle Whip.\n");
  int weapon = getchar() - '1';

  // Defeat the Kraken
  switch (lair) {
    case 1:
      // Use the Trident of the Deep
      printf("You hurl the Trident of the Deep at the Kraken, but it dodges out of the way just in time.\n");
      break;
    case 2:
      // Use the Wave Slayer
      printf("You charge the Wave Slayer with all your might, but the Kraken's tentacles are too fast and it dodges your attack.\n");
      break;
    case 3:
      // Use the Tentacle Whip
      printf("You lash out with the Tentacle Whip, but the Kraken's sheer size and strength overwhelm you and you're knocked to the ground.\n");
      break;
    default:
      printf("Invalid choice. Try again.\n");
      return 1;
  }

  // Defeat the Dragon
  printf("The Kraken roars with fury and charges towards you, but you dodge out of the way just in time.\n");
  printf("Now, you must face the Dragon...\n");
  lair++;

  // Choose your next move
  switch (lair) {
    case 2:
      // Use the Wave Slayer
      printf("You charge the Wave Slayer with all your might, but the Dragon's flames are too hot and it melts in your hands.\n");
      break;
    case 3:
      // Use the Tentacle Whip
      printf("You lash out with the Tentacle Whip, but the Dragon's scales are too tough and it breaks apart in your hands.\n");
      break;
    default:
      printf("Invalid choice. Try again.\n");
      return 1;
  }

  // Defeat the Phoenix
  printf("The Dragon roars with fury and charges towards you, but you dodge out of the way just in time.\n");
  printf("Now, you must face the Phoenix...\n");
  lair++;

  // Choose your next move
  switch (lair) {
    case 1:
      // Use the Trident of the Deep
      printf("You hurl the Trident of the Deep at the Phoenix, but it flaps its wings and soars out of the way just in time.\n");
      break;
    case 2:
      // Use the Wave Slayer
      printf("You charge the Wave Slayer with all your might, but the Phoenix's flames are too hot and it melts in your hands.\n");
      break;
    default:
      printf("Invalid choice. Try again.\n");
      return 1;
  }

  // Victory!
  printf("You have defeated the Kraken, the Dragon, and the Phoenix! You are the true hero of the sea...\n");
  return 0;
}