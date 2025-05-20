//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LIGHT_ON "ON"
#define LIGHT_OFF "OFF"

void main()
{
  int light_status = 0;
  char input[10];

  while (1)
  {
    printf("What is the status of the light? ");
    scanf("%s", input);

    if (strcmp(input, LIGHT_ON) == 0)
    {
      light_status = 1;
      printf("The light is now on.\n");
    }
    else if (strcmp(input, LIGHT_OFF) == 0)
    {
      light_status = 0;
      printf("The light is now off.\n");
    }
    else
    {
      printf("Invalid input.\n");
    }

    if (light_status)
    {
      printf("The light is on.\n");
    }
    else
    {
      printf("The light is off.\n");
    }

    printf("Do you want to turn the light on or off? ");
    scanf("%s", input);

    if (strcmp(input, LIGHT_ON) == 0)
    {
      light_status = 1;
      printf("The light is now on.\n");
    }
    else if (strcmp(input, LIGHT_OFF) == 0)
    {
      light_status = 0;
      printf("The light is now off.\n");
    }
    else
    {
      printf("Invalid input.\n");
    }

    if (light_status)
    {
      printf("The light is on.\n");
    }
    else
    {
      printf("The light is off.\n");
    }

    printf("Do you want to turn the light on or off? ");
    scanf("%s", input);

    if (strcmp(input, LIGHT_ON) == 0)
    {
      light_status = 1;
      printf("The light is now on.\n");
    }
    else if (strcmp(input, LIGHT_OFF) == 0)
    {
      light_status = 0;
      printf("The light is now off.\n");
    }
    else
    {
      printf("Invalid input.\n");
    }

    if (light_status)
    {
      printf("The light is on.\n");
    }
    else
    {
      printf("The light is off.\n");
    }
  }
}