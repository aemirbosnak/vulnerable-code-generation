//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>

int main()
{
  int lightStatus = 0; // 0 for off, 1 for on
  int brightness = 0; // 0 - 100 range
  
  printf("Welcome to the Smart Home Light Control Program!\n");
  printf("Enter 'on' or 'off' to control the light, or 'brightness' to adjust brightness.\n");
  
  char input[20];
  
  while(1)
  {
    printf("\n> ");
    scanf("%s", input);
    
    if(strcmp(input, "on") == 0)
    {
      lightStatus = 1;
      printf("The light is now on.\n");
    }
    else if(strcmp(input, "off") == 0)
    {
      lightStatus = 0;
      printf("The light is now off.\n");
    }
    else if(strcmp(input, "brightness") == 0)
    {
      printf("Enter a brightness level (0-100): ");
      scanf("%d", &brightness);
      if(brightness < 0)
      {
        brightness = 0;
      }
      else if(brightness > 100)
      {
        brightness = 100;
      }
      printf("Brightness set to %d.\n", brightness);
    }
    else
    {
      printf("Invalid command.\n");
    }
    
    // Control the light
    if(lightStatus == 1)
    {
      printf("Light is on");
      if(brightness == 0)
      {
        printf(" but brightness is set to 0.\n");
      }
      else if(brightness < 30)
      {
        printf(" with dim light.\n");
      }
      else if(brightness < 70)
      {
        printf(" with moderate brightness.\n");
      }
      else
      {
        printf(" with bright light.\n");
      }
    }
    else
    {
      printf("Light is off.\n");
    }
  }
  
  return 0;
}