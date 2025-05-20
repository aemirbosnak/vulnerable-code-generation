//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 5

typedef struct light {
  int id;
  bool on;
} Light;

void printMenu() {
  printf("\n~~~~~~~~~~ Smart Home Light Control ~~~~~~~~~~\n");
  printf("1. Turn on a light\n");
  printf("2. Turn off a light\n");
  printf("3. Get status of a light\n");
  printf("4. Quit\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Enter an option: ");
}

void printStatus(Light lights[]) {
  printf("\n~~~~~~~~~~~~ Light Status ~~~~~~~~~~~~\n");
  for(int i = 0; i < MAX_LIGHTS; i++) {
    printf("Light %d is ", lights[i].id);
    if(lights[i].on) {
      printf("on\n");
    } else {
      printf("off\n");
    }
  }
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void turnOnLight(Light lights[]) {
  int lightId;
  printf("Enter the light ID you want to turn on: ");
  scanf("%d", &lightId);
  
  if(lightId < 1 || lightId > MAX_LIGHTS) {
    printf("Invalid light ID\n");
    return;
  }
  
  if(lights[lightId-1].on) {
    printf("Oops! Light %d is already on\n", lightId);
    return;
  }
  
  lights[lightId-1].on = true;
  printf("Light %d turned on successfully!\n", lightId);
}

void turnOffLight(Light lights[]) {
  int lightId;
  printf("Enter the light ID you want to turn off: ");
  scanf("%d", &lightId);
  
  if(lightId < 1 || lightId > MAX_LIGHTS) {
    printf("Invalid light ID\n");
    return;
  }
  
  if(!lights[lightId-1].on) {
    printf("Oops! Light %d is already off\n", lightId);
    return;
  }
  
  lights[lightId-1].on = false;
  printf("Light %d turned off successfully!\n", lightId);
}

int main() {
  Light lights[MAX_LIGHTS];
  for(int i = 0; i < MAX_LIGHTS; i++) {
    lights[i].id = i+1;
    lights[i].on = false;
  }
  
  bool quit = false;
  while(!quit) {
    printMenu();
    
    int option;
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        turnOnLight(lights);
        break;
      case 2:
        turnOffLight(lights);
        break;
      case 3:
        printStatus(lights);
        break;
      case 4:
        printf("Quitting program. Goodbye!\n");
        quit = true;
        break;
      default:
        printf("Invalid option\n");
        break;
    }
  }
  
  return 0;
}