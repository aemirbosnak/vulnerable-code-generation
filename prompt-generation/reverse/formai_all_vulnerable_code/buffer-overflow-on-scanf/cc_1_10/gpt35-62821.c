//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

int current_state = GREEN;

void update_state(int event) {
    switch(current_state) {
        case GREEN:
            if(event == 1) {
                current_state = YELLOW;
            }
            break;
        case YELLOW:
            if(event == 2) {
                current_state = RED;
            }
            else if(event == 3) {
                current_state = GREEN;
            }
            break;
        case RED:
            if(event == 4) {
                current_state = GREEN;
            }
            break;
    }
}

void display_state() {
    switch(current_state) {
        case GREEN:
            printf("Green light\n");
            break;
        case YELLOW:
            printf("Yellow light\n");
            break;
        case RED:
            printf("Red light\n");
            break;
    }
}

int main() {
    int event;
    while(1) {
        display_state();
        printf("Enter event: ");
        scanf("%d", &event);
        update_state(event);
        if(event < 1 || event > 4) {
            printf("Invalid input\n");
            continue;
        }
    }
    return 0;
}