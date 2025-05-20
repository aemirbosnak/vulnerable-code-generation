//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: irregular
#include <stdio.h>

int main() {

// Setting up the traffic light
printf("Welcome to the Traffic Light Controller Program\n\n");

printf("Please insert the number of minutes that you want to set the lights for:\n");
int time_input;
scanf("%d", &time_input);

printf("Initializing the traffic light...\n\n");

// Main while-loop
while (1) {

int time_remaining = time_input * 60;

// Red Light
printf("Red light is on. Please stop.\n");
while (time_remaining > 0) {
    printf("Time remaining: %d seconds\n", time_remaining);
    time_remaining--;
}

// Yellow Light
printf("\nYellow light is on. Please prepare to go.\n");
time_remaining = 30;
while (time_remaining > 0) {
    printf("Time remaining: %d seconds\n", time_remaining);
    time_remaining--;
}

// Green Light
printf("\nGreen light is on. Please go.\n");
time_remaining = time_input * 60 - 30;
while (time_remaining > 0) {
    printf("Time remaining: %d seconds\n", time_remaining);
    time_remaining--;
    if (time_remaining < 10) {
        printf("Green light is about to turn off!\n");
    }
}

// Reset
printf("\nTraffic light is resetting...\n\n");
}

return 0;
}