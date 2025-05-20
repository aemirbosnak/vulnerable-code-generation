//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lightOne = false;
bool lightTwo = false;
bool lightThree = false;
bool lightFour = false;

void turnOnLight(int lightNumber) {
  switch(lightNumber) {
    case 1:
      lightOne = true;
      printf("Light One is now turned on.\n");
      break;
    case 2:
      lightTwo = true;
      printf("Light Two is now turned on.\n");
      break;
    case 3:
      lightThree = true;
      printf("Light Three is now turned on.\n");
      break;
    case 4:
      lightFour = true;
      printf("Light Four is now turned on.\n");
      break;
    default:
      printf("Light not found.\n");
  }
}

void turnOffLight(int lightNumber) {
  switch(lightNumber) {
    case 1:
      lightOne = false;
      printf("Light One is now turned off.\n");
      break;
    case 2:
      lightTwo = false;
      printf("Light Two is now turned off.\n");
      break;
    case 3:
      lightThree = false;
      printf("Light Three is now turned off.\n");
      break;
    case 4:
      lightFour = false;
      printf("Light Four is now turned off.\n");
      break;
    default:
      printf("Light not found.\n");
  }
}

int main() {
  int userChoice = 0;
  bool isRunning = true;
  
  printf("Welcome to the Smart Home Light Control Program.\n");
  while(isRunning) {
    printf("Please enter your choice:\n");
    printf("1. Turn on light.\n");
    printf("2. Turn off light.\n");
    printf("3. Exit program.\n");
    scanf("%d", &userChoice);
    
    switch(userChoice) {
      case 1:
        printf("Which light would you like to turn on? (1-4)\n");
        scanf("%d", &userChoice);
        turnOnLight(userChoice);
        break;
      case 2:
        printf("Which light would you like to turn off? (1-4)\n");
        scanf("%d", &userChoice);
        turnOffLight(userChoice);
        break;
      case 3:
        printf("Exiting program.\n");
        isRunning = false;
        break;
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}