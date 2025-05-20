//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

struct traffic_light
{
  int state;
  int timer;
};

struct traffic_light traffic_lights[4];

void init_traffic_lights()
{
  for (int i = 0; i < 4; i++)
  {
    traffic_lights[i].state = 0;
    traffic_lights[i].timer = 0;
  }
}

void update_traffic_lights()
{
  for (int i = 0; i < 4; i++)
  {
    if (traffic_lights[i].timer > 0)
    {
      traffic_lights[i].timer--;
    }

    if (traffic_lights[i].timer == 0)
    {
      traffic_lights[i].state = (traffic_lights[i].state + 1) % 3;
      traffic_lights[i].timer = rand() % 10 + 1;
    }
  }
}

void draw_traffic_lights(int width, int height)
{
  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      int i = (y * width) + x;

      if (traffic_lights[i].state == 0)
      {
        printf(RED "%c " RESET, ' ');
      }
      else if (traffic_lights[i].state == 1)
      {
        printf(YELLOW "%c " RESET, ' ');
      }
      else if (traffic_lights[i].state == 2)
      {
        printf(GREEN "%c " RESET, ' ');
      }
    }

    printf("\n");
  }
}

int main()
{
  srand(time(NULL));

  init_traffic_lights();

  while (1)
  {
    update_traffic_lights();
    draw_traffic_lights(10, 10);
    usleep(100000);
  }

  return 0;
}