//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 1000 // Maximum Internet Speed (in Mbps)
#define MIN_SPEED 1 // Minimum Internet Speed (in Mbps)
#define MAX_TRIES 5 // Maximum number of tries for each user
#define WAIT_TIME 2 // Time (in seconds) to wait during each try

// Function to generate a random internet speed (in Mbps)
int generate_internet_speed() {
    return (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
}

int main() {
    int user_input;
    int speed;
    int user_try;
    int total_tries = 0;
    float total_time = 0.0;
    float avg_time;
    
    srand(time(NULL)); // Seed for random number generator
    
    printf("Welcome to the Internet Speed Test App!\n");
    printf("Please press any key to start the test...\n");
    getchar(); // Wait for user input
    
    // Loop to allow multiple users to test their internet speed
    while (1) {
        total_tries = 0;
        total_time = 0.0;
        
        printf("\nPlease enter the number of users to test (or 0 to exit): ");
        scanf("%d", &user_input);
        
        if (user_input == 0) {
            printf("Thank you for using the Internet Speed Test App!\n");
            break;
        }
        
        printf("Testing for %d user(s)...\n", user_input);
        
        // Loop to test internet speed for each user
        for (int i = 1; i <= user_input; i++) {
            user_try = 1;
            
            printf("\nTesting for User %d\n", i);
            
            // Loop to allow multiple tries for each user
            while (user_try <= MAX_TRIES) {
                printf("Try %d: ", user_try);
                
                // Generate random internet speed and print the result
                speed = generate_internet_speed();
                printf("%d Mbps\n", speed);
                
                // Calculate and print the time taken for the test
                total_time += WAIT_TIME;
                printf("Time Taken: %.2f seconds\n", total_time);
                
                // Check if the internet speed is above 500 Mbps
                if (speed >= 500) {
                    printf("Congratulations! You have a great internet connection!\n");
                    break;
                }
                
                user_try++;
            }
            
            // Check if the user was able to achieve a speed above 500 Mbps in all tries
            if (user_try > MAX_TRIES) {
                printf("Sorry! You were not able to achieve a speed above 500 Mbps after %d tries.\n", MAX_TRIES);
            }
            
            total_tries += user_try - 1;
        }
        
        // Calculate average time taken for each user
        avg_time = total_time / user_input;
        printf("\nAverage Time: %.2f seconds\n", avg_time);
        printf("Total Tries: %d\n", total_tries);
    }
    
    return 0;
}