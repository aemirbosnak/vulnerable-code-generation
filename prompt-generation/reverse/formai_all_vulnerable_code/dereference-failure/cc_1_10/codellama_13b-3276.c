//Code Llama-13B DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
// Decentralized Traffic Light Controller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRAFFIC_LIGHT_COUNT 3
#define TRAFFIC_LIGHT_TIMEOUT 5

typedef struct {
  char* name;
  int state;
} TrafficLight;

void traffic_light_init(TrafficLight* traffic_light) {
  traffic_light->state = 0;
}

void traffic_light_update(TrafficLight* traffic_light) {
  if (traffic_light->state == 0) {
    printf("%s: Red\n", traffic_light->name);
    sleep(TRAFFIC_LIGHT_TIMEOUT);
    traffic_light->state = 1;
  } else if (traffic_light->state == 1) {
    printf("%s: Green\n", traffic_light->name);
    sleep(TRAFFIC_LIGHT_TIMEOUT);
    traffic_light->state = 2;
  } else if (traffic_light->state == 2) {
    printf("%s: Yellow\n", traffic_light->name);
    sleep(TRAFFIC_LIGHT_TIMEOUT);
    traffic_light->state = 0;
  }
}

void traffic_light_controller(TrafficLight* traffic_lights[], int count) {
  while (1) {
    for (int i = 0; i < count; i++) {
      traffic_light_update(&traffic_lights[i]);
    }
  }
}

int main(int argc, char* argv[]) {
  TrafficLight* traffic_lights[TRAFFIC_LIGHT_COUNT];

  for (int i = 0; i < TRAFFIC_LIGHT_COUNT; i++) {
    traffic_lights[i] = (TrafficLight*)malloc(sizeof(TrafficLight));
    traffic_light_init(traffic_lights[i]);
  }

  traffic_light_controller(traffic_lights, TRAFFIC_LIGHT_COUNT);

  return 0;
}