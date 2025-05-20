//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array of possible destinations
  char *destinations[] = {
    "The Roaring Twenties",
    "The Victorian Era",
    "The Renaissance",
    "Ancient Egypt",
    "The Future"
  };

  // Get the user's name
  char name[20];
  printf("What is your name, traveler?\n");
  gets(name);

  // Get the user's desired destination
  int destinationIndex;
  printf("Where would you like to go, %s?\n", name);
  for (int i = 0; i < 5; i++) {
    printf("%d. %s\n", i + 1, destinations[i]);
  }
  scanf("%d", &destinationIndex);

  // Send the user to their destination
  printf("Your journey begins now, %s...\n", name);
  switch (destinationIndex) {
    case 1:
      printf("You arrive in the Roaring Twenties, a time of flappers and jazz. The streets are filled with the sound of music and laughter, and the air is thick with the scent of perfume.");
      break;
    case 2:
      printf("You arrive in the Victorian Era, a time of elegance and propriety. The ladies wear long dresses and bonnets, and the gentlemen wear top hats and waistcoats. The streets are lined with horse-drawn carriages, and the air is filled with the sound of church bells.");
      break;
    case 3:
      printf("You arrive in the Renaissance, a time of art and science. The streets are filled with artists and scholars, and the air is thick with the smell of paint and ink. The buildings are adorned with beautiful frescoes, and the churches are filled with stunning stained glass windows.");
      break;
    case 4:
      printf("You arrive in Ancient Egypt, a time of pyramids and pharaohs. The streets are filled with the sound of construction, and the air is thick with the smell of incense. The temples are adorned with hieroglyphs, and the tombs are filled with treasures.");
      break;
    case 5:
      printf("You arrive in the Future, a time of flying cars and robots. The streets are filled with the sound of traffic, and the air is thick with the smell of pollution. The buildings are towering skyscrapers, and the sky is filled with drones.");
      break;
  }

  // Return the user to the present
  printf("Your journey is now complete, %s. Welcome back to the present.", name);

  return 0;
}