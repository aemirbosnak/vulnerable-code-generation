//FormAI DATASET v1.0 Category: Browser Plugin ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for storing website information
typedef struct website {
    char url[50];
    char title[50];
    char description[100];
} website;

// Function for displaying website information
void printWebsite(website w) {
    printf("-------------------------------------\n");
    printf("URL: %s\n", w.url);
    printf("Title: %s\n", w.title);
    printf("Description: %s\n", w.description);
    printf("-------------------------------------\n");
}

// Function for searching websites by keyword
void searchWebsites(website *websites, int numWebsites, char *keyword) {
    bool found = false;
    for (int i = 0; i < numWebsites; i++) {
        if (strstr(websites[i].title, keyword) != NULL || strstr(websites[i].description, keyword) != NULL) {
            found = true;
            printWebsite(websites[i]);
        }
    }
    if (!found) {
        printf("No websites found matching keyword '%s'\n", keyword);
    }
}

int main() {
    // Create an array of websites
    website websites[] = {
        {"https://www.google.com", "Google", "Search engine"},
        {"https://www.facebook.com", "Facebook", "Social media platform"},
        {"https://www.github.com", "GitHub", "Web-based hosting service for version control"},
        {"https://www.youtube.com", "YouTube", "Video sharing platform"},
        {"https://www.wikipedia.org", "Wikipedia", "Online encyclopedia"}
    };

    int numWebsites = sizeof(websites) / sizeof(website);

    // Search for websites by keyword
    char keyword[50];
    printf("Enter a keyword to search for websites: ");
    scanf("%s", keyword);
    printf("\nSearch Results:\n");
    searchWebsites(websites, numWebsites, keyword);

    return 0;
}