//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to my Smart Home Automation System!\n");
  
  int lights = 0, airConditioner = 0, TV = 0; // initialize devices as off
  int temperature = 25; // Default temperature value
  
  printf("Current status:\nLights: %d\nAir Conditioner: %d\nTV: %d\nTemperature: %d degrees\n", lights, airConditioner, TV, temperature);
  
  printf("Enter a command:\n");
  
  char command[20];
  
  while (1) {
    scanf("%s", command);
    
    if (strcmp(command, "turn on lights") == 0) {
      printf("Turning on lights...\n");
      lights = 1;
      printf("Lights are now on!\n");
    }
    
    else if (strcmp(command, "turn off lights") == 0) {
      printf("Turning off lights...\n");
      lights = 0;
      printf("Lights are now off!\n");
    }
    
    else if (strcmp(command, "turn on AC") == 0) {
      printf("Turning on Air Conditioner...\n");
      airConditioner = 1;
      temperature = 20; // Set temperature to 20 degrees
      printf("Air Conditioner is now on!\n");
    }
    
    else if (strcmp(command, "turn off AC") == 0) {
      printf("Turning off Air Conditioner...\n");
      airConditioner = 0;
      temperature = 25; // Set temperature to default
      printf("Air Conditioner is now off!\n");
    }
    
    else if (strcmp(command, "watch TV") == 0) {
      printf("Turning on TV...\n");
      TV = 1;
      printf("TV is now on!\n");
    }
    
    else if (strcmp(command, "stop TV") == 0) {
      printf("Turning off TV...\n");
      TV = 0;
      printf("TV is now off!\n");
    }
    
    else if (strcmp(command, "set temperature") == 0) {
      printf("Enter a temperature value:\n");
      scanf("%d", &temperature);
      
      printf("Temperature is now set to %d degrees!\n", temperature);
    }
    
    else if (strcmp(command, "make me a sandwich") == 0) {
      printf("No sandwich for you! This is a Smart Home Automation System, not a chef!\n");
    }
    
    else if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      break; // Exit program
    }
    
    else {
      printf("Invalid command, please try again.\n");
    }
    
    printf("Current status:\nLights: %d\nAir Conditioner: %d\nTV: %d\nTemperature: %d degrees\n", lights, airConditioner, TV, temperature);
    printf("Enter a command:\n");
  }
  
  return 0;
}