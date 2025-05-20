//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to turn on/off the lights
void turnLightOnOff(char * state) {
  if (strcmp(state, "on") == 0) {
    printf("The lights are now on\n");
  } else if (strcmp(state, "off") == 0) {
    printf("The lights are now off\n");
  } else {
    printf("Invalid state\n");
  }
}

//function to adjust the temperature
void adjustTemperature(int temp) {
  if (temp < 60) {
    printf("The temperature is too low\n");
  } else if (temp > 85) {
    printf("The temperature is too high\n");
  } else {
    printf("The temperature is now set to %d\n", temp);
  }
}

int main() {
  //initialize variables
  char lightState[4];
  int temperature;
  
  //welcome message
  printf("Welcome to Smart Home Automation!\n\n");
  
  //get initial state of lights
  printf("What is the current state of the lights? (on/off): ");
  scanf("%s", lightState);
  
  //turn on/off lights
  turnLightOnOff(lightState);
  
  //get desired temperature
  printf("What temperature would you like to set the thermostat to? (60-85): ");
  scanf("%d", &temperature);
  
  //adjust temperature
  adjustTemperature(temperature);
  
  //thank you message
  printf("\nThank you for using Smart Home Automation!\n");
  
  return 0;
}