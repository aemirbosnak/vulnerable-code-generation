//FormAI DATASET v1.0 Category: Smart home automation ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool lightOn = false;
  bool acOn = false;
  bool musicOn = false;
  bool securityOn = true;
  
  printf("Welcome to Smart Home Automation\n");
  
  while(true) {
    printf("Enter command (light, ac, music, security): ");
    
    char command[10];
    scanf("%s", command);
    
    if(strcmp(command, "light") == 0) {
      if(lightOn) {
        printf("Turning off lights\n");
        lightOn = false;
      } else {
        printf("Turning on lights\n");
        lightOn = true;
      }
    } else if(strcmp(command, "ac") == 0) {
      if(acOn) {
        printf("Turning off AC\n");
        acOn = false;
      } else {
        printf("Turning on AC\n");
        acOn = true;
      }
    } else if(strcmp(command, "music") == 0) {
      if(musicOn) {
        printf("Turning off music\n");
        musicOn = false;
      } else {
        printf("Turning on music\n");
        musicOn = true;
      }
    } else if(strcmp(command, "security") == 0) {
      if(securityOn) {
        printf("Disabling security system\n");
        securityOn = false;
      } else {
        printf("Enabling security system\n");
        securityOn = true;
      }
    } else {
      printf("Invalid command. Please try again\n");
    }
  }
  
  return 0;
}