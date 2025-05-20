//Gemma-7B DATASET v1.0 Category: Traffic Light Controller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define MAX_TIME 5

typedef struct TrafficLight {
  int current_state;
  int next_state;
  int timer;
  int lanes[NUM_LANES];
} TrafficLight;

TrafficLight traffic_light;

void update_traffic_light() {
  traffic_light.timer++;

  if (traffic_light.timer >= traffic_light.next_state) {
    traffic_light.current_state = traffic_light.next_state;
    traffic_light.timer = 0;
  }

  switch (traffic_light.current_state) {
    case 0:
      traffic_light.lanes[0] = 1;
      traffic_light.lanes[1] = 0;
      traffic_light.lanes[2] = 0;
      break;
    case 1:
      traffic_light.lanes[0] = 0;
      traffic_light.lanes[1] = 1;
      traffic_light.lanes[2] = 0;
      break;
    case 2:
      traffic_light.lanes[0] = 0;
      traffic_light.lanes[1] = 0;
      traffic_light.lanes[2] = 1;
      break;
  }
}

int main() {
  traffic_light.current_state = 0;
  traffic_light.next_state = 1;
  traffic_light.timer = 0;
  traffic_light.lanes[0] = 0;
  traffic_light.lanes[1] = 0;
  traffic_light.lanes[2] = 0;

  for (int i = 0; i < MAX_TIME; i++) {
    update_traffic_light();
    printf("Lane %d: %d\n", i, traffic_light.lanes[i]);
  }

  return 0;
}