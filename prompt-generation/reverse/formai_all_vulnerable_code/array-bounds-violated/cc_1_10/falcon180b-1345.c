//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define NUM_LIGHTS 5

typedef struct {
    char* name;
    bool is_on;
    int brightness;
} Light;

void init_lights(Light* lights) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].name = malloc(sizeof(char) * 20);
        sprintf(lights[i].name, "Light %d", i + 1);
        lights[i].is_on = false;
        lights[i].brightness = 0;
    }
}

void print_lights(Light* lights) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].is_on? "On" : "Off");
    }
}

void set_brightness(Light* lights, int light_num, int brightness) {
    if (light_num >= 0 && light_num < NUM_LIGHTS) {
        lights[light_num].brightness = brightness;
    } else {
        printf("Invalid light number.\n");
    }
}

int main() {
    Light lights[NUM_LIGHTS];
    init_lights(lights);
    
    while (true) {
        printf("Enter command:\n");
        printf("1. Turn light on/off\n");
        printf("2. Set brightness\n");
        printf("3. Print light status\n");
        printf("4. Exit\n");
        
        char command[20];
        scanf("%s", command);
        
        switch (command[0]) {
            case '1':
                {
                    int light_num;
                    scanf("%d", &light_num);
                    lights[light_num - 1].is_on =!lights[light_num - 1].is_on;
                    printf("Light %d %s.\n", light_num, lights[light_num - 1].is_on? "turned on" : "turned off");
                }
                break;
            case '2':
                {
                    int light_num, brightness;
                    scanf("%d %d", &light_num, &brightness);
                    set_brightness(lights, light_num - 1, brightness);
                }
                break;
            case '3':
                print_lights(lights);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }
    
    return 0;
}