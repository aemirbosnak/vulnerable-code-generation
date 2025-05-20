//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>

int main() {
  int temperature = 25;
  int lightIntensity = 50;
  int motionDetected = 0;
  int doorLocked = 1;
  
  printf("Welcome to your smart home!\n");
  
  while(1) {
    printf("Current temperature: %d\n", temperature);
    printf("Current light intensity: %d\n", lightIntensity);
    printf("Motion detected: %s\n", motionDetected ? "Yes" : "No");
    printf("Door locked: %s\n", doorLocked ? "Yes" : "No");
    printf("Enter command:");
  
    char command;
    scanf("%c", &command);
    
    switch(command) {
      case 'T':
      case 't':
        printf("Enter new temperature:");
        scanf("%d", &temperature);
        break;
      case 'L':
      case 'l':
        printf("Enter new light intensity:");
        scanf("%d", &lightIntensity);
        break;
      case 'M':
      case 'm':
        motionDetected = !motionDetected;
        break;
      case 'D':
      case 'd':
        doorLocked = !doorLocked;
        break;
      case 'Q':
      case 'q':
        printf("Goodbye!");
        return 0;
      default:
        printf("Invalid command\n");
        break;
    }
  }
  
  return 0;
}