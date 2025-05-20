//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int visits = 0; // count of visits to the current webpage

// Function to display a pop-up window
void popUp(char* message) {
    printf("Alert: %s", message);
}

// Function to check if the current webpage is in a list of banned sites
int checkBanned(char* url) {
    char* bannedSites[] = {"www.facebook.com", "www.twitter.com", "www.instagram.com"};
    int numBannedSites = sizeof(bannedSites) / sizeof(bannedSites[0]);
    for (int i = 0; i < numBannedSites; i++) {
        if (strcmp(url, bannedSites[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to track visits to the current webpage
void trackVisits(char* url) {
    visits++;
    printf("%s\nTotal visits: %d\n", url, visits);
}

// Main function
int main() {
    char currentSite[100];
    printf("Welcome to MyBrowser Plugin!\n");

    // Loop to simulate browsing
    for (int i = 0; i < 5; i++) {
        printf("\nEnter a website: ");
        scanf("%s", currentSite);

        // Check if the site is banned
        if (checkBanned(currentSite)) {
            popUp("You are not allowed to access this site!");
            continue;
        }

        // Track visits to the site
        trackVisits(currentSite);

        // Display the website
        printf("Displaying website: %s\n", currentSite);
    }
    
    return 0;
}