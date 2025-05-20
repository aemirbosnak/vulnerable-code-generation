//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ITEM 5
#define MIN_WAIT_TIME 1
#define MAX_WAIT_TIME 5

const char *items[MAX_ITEM] = {
    "unicorn toenails",
    "galactic taco recipe",
    "invisible ink",
    "left-handed coffee cups",
    "fluffy clouds in a jar"
};

void display_loading_message(const char *item) {
    printf("Testing download speed for %s...\n", item);
    printf("Please wait");
    for (int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

double generate_random_download_time() {
    return (double)(rand() % (MAX_WAIT_TIME * 1000 + 1)) / 1000.0;  // Generate time in seconds
}

void simulate_speed_test() {
    srand(time(NULL)); // Seeding the random number generator

    printf("\nWelcome to the Wacky Internet Speed Test!\n");
    printf("We will be testing how fast you can download some very important items...\n\n");

    for (int i = 0; i < 3; i++) {  // Test three items
        int item_index = rand() % MAX_ITEM;  // Randomly pick an item
        const char *item = items[item_index];

        display_loading_message(item);  // Display loading message
        
        double download_time = generate_random_download_time(); // Simulating download time
        double speed_mbps = (double)(rand() % 101 + 50) / download_time; // Random speed in Mbps

        printf("Congratulations! You downloaded %s in %.2f seconds.\n", item, download_time);
        printf("Your internet speed is: %.2f Mbps!\n\n", speed_mbps);
    }

    printf("Was that fun? Did you enjoy testing your speed with unicorns and tacos?\n");
    printf("If not, blame your Wi-Fi router; it probably needs a vacation!\n");
    printf("Thank you for using the Wacky Internet Speed Test. Bye-bye!\n");
}

int main() {
    simulate_speed_test();  // Start the wacky speed test
    return 0;
}