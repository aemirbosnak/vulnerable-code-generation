//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_LIGHTS 10
#define MIN_LIGHT 5
#define MAX_LIGHT 50
#define INCREMENT 5

typedef struct {
    int light_id;
    int brightness;
} light_t;

int main() {
    int num_lights;
    printf("Enter the number of lights in your smart home:\n");
    scanf("%d", &num_lights);

    if(num_lights < MIN_LIGHT || num_lights > MAX_LIGHT) {
        printf("Invalid number of lights. Please enter a number between %d and %d.\n", MIN_LIGHT, MAX_LIGHT);
        return 1;
    }

    light_t lights[MAX_LIGHTS];
    for(int i=0; i<num_lights; i++) {
        printf("Enter the ID of light %d:\n", i+1);
        scanf("%d", &lights[i].light_id);
        printf("Enter the brightness level for light %d (1-100):\n", i+1);
        scanf("%d", &lights[i].brightness);
    }

    printf("Enter the desired brightness level (1-100):\n");
    int desired_brightness;
    scanf("%d", &desired_brightness);

    int total_brightness = 0;
    for(int i=0; i<num_lights; i++) {
        total_brightness += lights[i].brightness;
    }

    float brightness_ratio = (float)desired_brightness / total_brightness;

    for(int i=0; i<num_lights; i++) {
        lights[i].brightness = (int)(brightness_ratio * lights[i].brightness);
        printf("Light %d brightness set to %d\n", lights[i].light_id, lights[i].brightness);
    }

    return 0;
}