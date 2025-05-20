//FormAI DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds);
int random_number(int min_num, int max_num);

int main() {
    int light_state = 0;
    int threshold = 10;

    srand(time(0)); // Seed the random number generator with the current time

    printf("Welcome to the paranoid smart home light control system\n");

    while (1) {
        int random_num = random_number(1, 20); // Generate a random number between 1 and 20

        if (random_num > threshold) {
            // Turn on the lights if they are off
            if (light_state == 0) {
                printf("Intruder detected! Turning on lights...\n");
                light_state = 1;
            }
        }
        else {
            // Turn off the lights if they are on
            if (light_state == 1) {
                printf("Intruder not detected. Turning off lights...\n");
                light_state = 0;
            }
        }
        
        delay(1); // Wait 1 second before checking again
    }

    return 0;
}

// Delay function using the time library
void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

// Function to generate a random number within a range
int random_number(int min_num, int max_num) {
    int result = (rand() % (max_num - min_num + 1)) + min_num;
    return result;
}