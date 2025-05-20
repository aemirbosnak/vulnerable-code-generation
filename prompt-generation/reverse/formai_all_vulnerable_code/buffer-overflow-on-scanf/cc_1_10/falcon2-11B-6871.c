//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function prototypes
void change_state(int state);
void check_input(char c);
void red();
void yellow();
void green();
void traffic_light_controller();

int main() {
    traffic_light_controller();
    return 0;
}

void change_state(int state) {
    printf("Changing state to %d\n", state);
}

void check_input(char c) {
    if (c == 'r') {
        red();
        return;
    } else if (c == 'y') {
        yellow();
        return;
    } else if (c == 'g') {
        green();
        return;
    } else {
        printf("Invalid input\n");
        return;
    }
}

void red() {
    printf("Red light\n");
    change_state(1);
}

void yellow() {
    printf("Yellow light\n");
    change_state(2);
}

void green() {
    printf("Green light\n");
    change_state(3);
}

void traffic_light_controller() {
    int state = 1;
    while (true) {
        char c;
        scanf("%c", &c);
        check_input(c);
    }
}