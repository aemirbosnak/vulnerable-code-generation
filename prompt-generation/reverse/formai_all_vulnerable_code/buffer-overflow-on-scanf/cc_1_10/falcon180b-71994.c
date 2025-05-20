//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[50];
    int status;
    int brightness;
} Light;

Light lights[MAX_LIGHTS];
int num_lights = 0;

void add_light() {
    if (num_lights == MAX_LIGHTS) {
        printf("Sorry, the maximum number of lights has been reached.\n");
        return;
    }

    printf("Enter the name of the light: ");
    scanf("%s", lights[num_lights].name);

    lights[num_lights].status = 0;
    lights[num_lights].brightness = 0;

    num_lights++;
}

void remove_light(int index) {
    if (index >= num_lights || index < 0) {
        printf("Invalid light index.\n");
        return;
    }

    num_lights--;

    for (int i = index; i < num_lights; i++) {
        lights[i] = lights[i + 1];
    }
}

void toggle_light(int index) {
    if (index >= num_lights || index < 0) {
        printf("Invalid light index.\n");
        return;
    }

    lights[index].status =!lights[index].status;
}

void set_brightness(int index, int brightness) {
    if (index >= num_lights || index < 0) {
        printf("Invalid light index.\n");
        return;
    }

    lights[index].brightness = brightness;
}

void print_lights() {
    printf("Lights:\n");
    for (int i = 0; i < num_lights; i++) {
        printf("%d. %s (%d)\n", i + 1, lights[i].name, lights[i].brightness);
    }
}

int main() {
    add_light();
    add_light();

    print_lights();

    toggle_light(0);
    set_brightness(1, 50);

    print_lights();

    remove_light(1);

    print_lights();

    return 0;
}