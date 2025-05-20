//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int brightness = 100;
int lights_on = 1;

void handle_ctrl_c(int sig) {
    printf("Program interrupted by user\n");
    exit(1);
}

void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
    exit(1);
}

void handle_input() {
    char input[100];
    printf("Enter command: ");
    scanf("%s", input);
    
    if (strcmp(input, "on") == 0) {
        printf("Lights turned on\n");
        lights_on = 1;
    } else if (strcmp(input, "off") == 0) {
        printf("Lights turned off\n");
        lights_on = 0;
    } else if (strcmp(input, "brightness") == 0) {
        printf("Enter brightness level (0-100): ");
        scanf("%d", &brightness);
        printf("Brightness set to %d\n", brightness);
    } else if (strcmp(input, "help") == 0) {
        printf("Commands:\n\ton - turn lights on\n\toff - turn lights off\n\tbrightness <level> - set brightness level (0-100)\n");
    } else {
        printf("Invalid command\n");
    }
}

int main() {
    signal(SIGINT, handle_ctrl_c);
    signal(SIGTERM, handle_signal);
    
    printf("Lights are off\n");
    
    while (1) {
        handle_input();
    }
    
    return 0;
}