//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>

typedef struct {
    int red, yellow, green;
    int counter;
} TrafficLight;

void update_lights(TrafficLight* tl) {
    tl->counter++;
    if (tl->counter == 1) {
        tl->red = 1;
        tl->yellow = 0;
        tl->green = 0;
    } else if (tl->counter == 2) {
        tl->red = 0;
        tl->yellow = 1;
        tl->green = 0;
    } else if (tl->counter == 3) {
        tl->red = 0;
        tl->yellow = 0;
        tl->green = 1;
    }
}

void handle_input(TrafficLight* tl) {
    printf("Enter a color (red, yellow, or green): ");
    int color;
    scanf("%d", &color);
    if (color == 1) {
        tl->red = 1;
        tl->yellow = 0;
        tl->green = 0;
    } else if (color == 2) {
        tl->red = 0;
        tl->yellow = 1;
        tl->green = 0;
    } else if (color == 3) {
        tl->red = 0;
        tl->yellow = 0;
        tl->green = 1;
    } else {
        printf("Invalid color!\n");
    }
    tl->counter = 1;
}

void display_lights(TrafficLight* tl) {
    printf("Current state of the traffic lights:\n");
    if (tl->red == 1) {
        printf("Red\n");
    } else if (tl->yellow == 1) {
        printf("Yellow\n");
    } else if (tl->green == 1) {
        printf("Green\n");
    }
}

int main() {
    TrafficLight tl;
    update_lights(&tl);
    do {
        display_lights(&tl);
        handle_input(&tl);
    } while (tolower(getchar())!= 'q');
    return 0;
}