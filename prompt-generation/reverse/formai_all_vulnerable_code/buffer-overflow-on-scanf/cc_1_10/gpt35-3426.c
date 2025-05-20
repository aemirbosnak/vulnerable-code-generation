//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
// Romeo and Juliet: Website Uptime Monitor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check website availability
int check_website_availability(char website[]) {
    // Use system ping command to check website availability
    char command[100];
    sprintf(command, "ping -c 1 %s > /dev/null", website);
    int response = system(command);

    // Return 1 if website is available, else 0
    return (response == 0);
}

// Main function
int main() {
    // Initialize website and uptime variables
    char website[50];
    int uptime = 0;

    // Prompt the user to enter the website to check
    printf("Oh, my love, what website would you check? \n");
    scanf("%s", website);

    // Prompt the user to enter the monitoring duration
    printf("How long shall I monitor this site? Tell me truly. \n");
    int duration;
    scanf("%d", &duration);

    // Get current time
    time_t start = time(NULL);

    // Start monitoring
    while ((time(NULL) - start) < duration) {
        // Check website availability
        if (check_website_availability(website)) {
            printf("Oh, how beautiful is my love's website! It is up and above!\n");

            // Increment uptime counter
            uptime++;
        } else {
            printf("Alas, the heavens weep! My love's website is down!\n");
        }

        // Wait for some time before checking again
        sleep(10);
    }

    // Compute and display website uptime
    float website_uptime = (float) uptime / (float) (duration / 60);
    printf("Dear website, your uptime is %.2f minutes per hour. May you stay up forever!\n", website_uptime);

    return 0;
}