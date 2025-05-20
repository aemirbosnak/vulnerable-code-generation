//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Returns a random integer between min and max */
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Returns a random internet speed in Mbps */
float get_internet_speed() {
    float speed = (float) random_num(2, 100);  // Generate a random speed between 2 and 100 Mbps
    int rand_num = random_num(1, 10);
    if (rand_num <= 3) {  // Simulate slow internet connection 30% of the time
        speed -= (float) random_num(0, 1);  // Decrease speed by 0.1 or 0.2 randomly
    }
    return speed;
}

/* Prints a message depending on the internet speed */
void print_speed_message(float speed) {
    if (speed >= 70.0) {
        printf("Your internet speed is extremely fast! Great job!\n");
    } else if (speed >= 50.0) {
        printf("Your internet speed is pretty fast. Keep it up!\n");
    } else if (speed >= 20.0) {
        printf("Your internet speed is moderate. You may experience some buffering.\n");
    } else {
        printf("Your internet speed is slow. You may have trouble streaming videos.\n");
    }
}

int main() {
    srand(time(0));  // Seed random number generator

    printf("Welcome to the Internet Speed Test Application!\n\n");

    char name[100];
    printf("What is your name? ");
    scanf("%s", name);

    // Generate a random internet speed between 2 and 100 Mbps
    float speed = get_internet_speed();
    printf("\n%s, your internet speed is %.1f Mbps.\n", name, speed);

    // Print a message depending on the internet speed
    print_speed_message(speed);

    return 0;
}