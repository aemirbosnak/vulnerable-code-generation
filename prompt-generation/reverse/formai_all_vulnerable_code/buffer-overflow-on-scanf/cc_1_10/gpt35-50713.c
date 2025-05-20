//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void printIntro();
int menu();
void generateRandomPlanet(char planetName[]);
void visitPlanet(char planetName[]);
void printEnding();

int main() {
  srand(time(NULL)); // seed the random number generator
  char planetName[20];

  printIntro();
  
  while(1) {
    int choice = menu();

    switch(choice) {
      case 1:
        generateRandomPlanet(planetName);
        visitPlanet(planetName);
        break;
      case 2:
        printf("You have elected to go back to Earth.\n");
        printEnding();
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

void printIntro() {
  printf("Welcome to Procedural Space Adventure! You have been tasked with exploring the galaxy.\n");
  printf("You will be given a random planet to visit. Happy exploring!\n");
}

int menu() {
  int choice;
  printf("What would you like to do?\n");
  printf("1. Visit a random planet.\n");
  printf("2. Return to Earth.\n");
  scanf("%d", &choice);

  return choice;
}

void generateRandomPlanet(char planetName[]) {
  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
  int size1 = sizeof(vowels)/sizeof(char);
  int size2 = sizeof(consonants)/sizeof(char);
  int nameLen = rand() % 10 + 5; // random planet name length between 5-14 characters
  int randIndex;
  
  for(int i=0; i<nameLen; i++) {
    if(i % 2 == 0) { // even index, so choose a consonant
      randIndex = rand() % size2;
      planetName[i] = consonants[randIndex];
    } else { // odd index, so choose a vowel
      randIndex = rand() % size1;
      planetName[i] = vowels[randIndex];
    }
  }
  
  planetName[nameLen] = '\0'; // add null terminator at the end
}

void visitPlanet(char planetName[]) {
  printf("You have arrived at planet %s.\n", planetName);
  printf("It is a beautiful and vibrant planet with lush vegetation and diverse wildlife.\n");
  printf("However, you notice strange energy readings emanating from a nearby mountain range.\n");
  printf("Do you want to investigate the energy readings?\n");
  
  char choice;
  do {
    printf("Enter 'y' for yes, or 'n' for no.\n");
    scanf(" %c", &choice);
  } while(choice != 'y' && choice != 'n');

  if(choice == 'y') {
    printf("You make your way towards the mountain range, but the terrain becomes increasingly hazardous.\n");
    printf("Suddenly, you hear the sound of metal clanging against metal.\n");
    printf("You cautiously approach a cave and peek inside.\n");
    printf("To your surprise, you see a group of alien miners extracting precious minerals from deep within the mountain.\n");
    printf("You are greeted warmly by the alien foreman, who offers you a tour of the mining operation.\n");
    printf("After the tour, you bid farewell to your new extraterrestrial friends and blast off into the stars once again.\n");
  } else {
    printf("You decide to explore more of the planet and come across a vast ocean with technicolor coral reefs.\n");
    printf("You also encounter a friendly pod of space whales, who sing you a beautiful song before you continue on your journey.\n");
  }
}

void printEnding() {
  printf("Thank you for playing Procedural Space Adventure!\n");
}