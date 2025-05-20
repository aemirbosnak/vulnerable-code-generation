//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to turn on the lights
void turnOnLights() {
  printf("Lights on! Time to party!\n");
}

// Function to turn off the lights
void turnOffLights() {
  printf("Lights off! Time to sleep...or play pranks on your friends.\n");
}

// Function to open the curtains
void openCurtains() {
  printf("Curtains open! Let the sunshine in!\n");
}

// Function to close the curtains
void closeCurtains() {
  printf("Curtains closed! Time to watch a movie...or hide from the sun.\n");
}

// Function to start the coffee maker
void startCoffeeMaker() {
  printf("Coffee maker started! Wakey wakey, eggs and bakey!\n");
}

// Function to stop the coffee maker
void stopCoffeeMaker() {
  printf("Coffee maker stopped! Time for a nap...or a second cup.\n");
}

// Function to play music
void playMusic() {
  printf("Music on! Time to dance like nobody's watching...\nor just listen to some tunes.\n");
}

// Function to stop playing music
void stopMusic() {
  printf("Music off! Time for some peace and quiet...or to sneak up on your unsuspecting family members.\n");
}

int main() {
  // Greeting the user
  printf("Welcome to your Smart Home! Where you can control everything with a snap of your fingers...or a click of a button.\n");

  // Getting input from the user
  int choice;
  while (1) {
    printf("\nWhat do you want to do today?\n");
    printf("1. Turn on the lights\n");
    printf("2. Turn off the lights\n");
    printf("3. Open the curtains\n");
    printf("4. Close the curtains\n");
    printf("5. Start the coffee maker\n");
    printf("6. Stop the coffee maker\n");
    printf("7. Play music\n");
    printf("8. Stop playing music\n");
    printf("9. Exit\n");
    scanf("%d", &choice);

    // Calling the appropriate function based on the user's choice
    switch (choice) {
      case 1:
        turnOnLights();
        break;
      case 2:
        turnOffLights();
        break;
      case 3:
        openCurtains();
        break;
      case 4:
        closeCurtains();
        break;
      case 5:
        startCoffeeMaker();
        break;
      case 6:
        stopCoffeeMaker();
        break;
      case 7:
        playMusic();
        break;
      case 8:
        stopMusic();
        break;
      case 9:
        printf("Goodbye! See you next time!\n");
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}