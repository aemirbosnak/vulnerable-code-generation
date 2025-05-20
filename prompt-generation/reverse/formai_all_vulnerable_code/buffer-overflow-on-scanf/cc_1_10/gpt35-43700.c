//FormAI DATASET v1.0 Category: Smart home automation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lightsOn = false;
bool acOn = false;
bool tvOn = false;

void turnOnLights() {
  printf("Turning on lights\n");
  lightsOn = true;
}

void turnOffLights() {
  printf("Turning off lights\n");
  lightsOn = false;
}

void turnOnAc() {
  printf("Turning on AC\n");
  acOn = true;
}

void turnOffAc() {
  printf("Turning off AC\n");
  acOn = false;
}

void turnOnTv() {
  printf("Turning on TV\n");
  tvOn = true;
}

void turnOffTv() {
  printf("Turning off TV\n");
  tvOn = false;
}

int main() {
  printf("Welcome to Smart Home\n");
  int choice;
  while (true) {
    printf("\nEnter your choice:\n1. Turn on lights\n2. Turn off lights\n3. Turn on AC\n4. Turn off AC\n5. Turn on TV\n6. Turn off TV\n7. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        if(!lightsOn) turnOnLights();
        else printf("Lights are already on\n");
        break;
      case 2:
        if(lightsOn) turnOffLights();
        else printf("Lights are already off\n");
        break;
      case 3:
        if(!acOn) turnOnAc();
        else printf("AC is already on\n");
        break;
      case 4:
        if(acOn) turnOffAc();
        else printf("AC is already off\n");
        break;
      case 5:
        if(!tvOn) turnOnTv();
        else printf("TV is already on\n");
        break;
      case 6:
        if(tvOn) turnOffTv();
        else printf("TV is already off\n");
        break;
      case 7:
        printf("Exiting Smart Home\n");
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
}