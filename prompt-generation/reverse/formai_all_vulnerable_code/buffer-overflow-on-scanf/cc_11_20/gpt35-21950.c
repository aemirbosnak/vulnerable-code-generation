//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>

int main() {

  //declare variables
  int light_status = 0; //0 = off, 1 = on
  int brightness_level = 0; //0 = minimum brightness, 10 = maximum brightness
  
  //initial prompt for user
  printf("Welcome to Smart Home Light Control\n");
  printf("Enter 'on' or 'off' to turn the light on or off\n");
  printf("Enter 'bright' followed by a number between 0 and 10 to adjust the brightness level\n");
  
  //loop to continue prompting user until they choose to exit
  while(1) {
    char user_input[20];
    scanf("%s", user_input);
    
    //turn light on
    if(strcmp(user_input, "on") == 0) {
      if(light_status == 0) {
        printf("Turning light on\n");
        light_status = 1;
      }
      else {
        printf("Light is already on\n");
      }
    }
    
    //turn light off
    else if(strcmp(user_input, "off") == 0) {
      if(light_status == 1) {
        printf("Turning light off\n");
        light_status = 0;
      }
      else {
        printf("Light is already off\n");
      }
    }
    
    //adjust brightness level
    else if(strcmp(user_input, "bright") == 0) {
      int new_brightness_level;
      scanf("%d", &new_brightness_level);
      if(new_brightness_level >= 0 && new_brightness_level <= 10) {
        if(brightness_level != new_brightness_level) {
          printf("Adjusting brightness level to %d\n", new_brightness_level);
          brightness_level = new_brightness_level;
        }
        else {
          printf("Brightness level is already set to %d\n", new_brightness_level);
        }
      }
      else {
        printf("Invalid input, brightness level must be between 0 and 10\n");
      }
    }
    
    //exit program
    else if(strcmp(user_input, "exit") == 0) {
      printf("Exiting program\n");
      break;
    }
    
    //unrecognized input
    else {
      printf("Unrecognized input, please try again\n");
    }
    
  }
  return 0;
}