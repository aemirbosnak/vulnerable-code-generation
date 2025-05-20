//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
// The Case of the Missing Website
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_SITES 10
#define MAX_URL 50

// Struct for storing Website data
struct website {
    char url[MAX_URL];
    int status;
    int last_status;
    int count;
};

// Global Variables
struct website websites[MAX_SITES];
int num_sites = 0;

// Function Declarations
void add_site();
void remove_site();
void display_sites();
void check_sites();
void update_status(struct website *site);

// Main Function
int main() {
    CURL *curl;
    int choice;
    
    printf("Welcome, my dear Watson, to the Website Uptime Monitor.\n");
    
    // Loop until user chooses to exit
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add Website\n");
        printf("2. Remove Website\n");
        printf("3. Display Websites\n");
        printf("4. Check Websites\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_site();
                break;
            case 2:
                remove_site();
                break;
            case 3:
                display_sites();
                break;
            case 4:
                check_sites();
                break;
            case 5:
                printf("Thank you, Watson, for your assistance in this case.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

// Function Definitions

/* Add Site Function */
void add_site() {
    char url[MAX_URL];
    
    // Check if max number of sites added
    if (num_sites == MAX_SITES) {
        printf("I'm sorry, Watson, but the maximum number of sites has already been reached.\n");
        return;
    }
    
    // Prompt user for website URL
    printf("Please enter the website URL: ");
    scanf("%s", url);
    
    // Check if website already exists
    for (int i = 0; i < num_sites; i++) {
        if (strcmp(websites[i].url, url) == 0) {
            printf("I'm sorry, Watson, but that website already exists in our system.\n");
            return;
        }
    }
    
    // Add website to list
    strcpy(websites[num_sites].url, url);
    websites[num_sites].status = 0;
    websites[num_sites].last_status = 0;
    websites[num_sites].count = 0;
    
    printf("Website '%s' has been added to the system.\n", url);
    
    // Increment number of sites
    num_sites++;
}

/* Remove Site Function */
void remove_site() {
    char url[MAX_URL];
    int index = -1;
    
    // Prompt user for website URL
    printf("Please enter the website URL: ");
    scanf("%s", url);
    
    // Search for website and remove if found
    for (int i = 0; i < num_sites; i++) {
        if (strcmp(websites[i].url, url) == 0) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        // Shift remaining sites up
        for (int i = index; i < num_sites-1; i++) {
            websites[i] = websites[i+1];
        }
        
        // Clear last site
        strcpy(websites[num_sites-1].url, "");
        websites[num_sites-1].status = 0;
        websites[num_sites-1].last_status = 0;
        websites[num_sites-1].count = 0;
        
        // Decrement number of sites
        num_sites--;
        
        printf("Website '%s' has been removed from the system.\n", url);
    } else {
        printf("I'm sorry, Watson, but that website does not exist in our system.\n");
    }
}

/* Display Sites Function */
void display_sites() {
    if (num_sites == 0) {
        printf("I'm sorry, Watson, but there are no websites added to the system.\n");
        return;
    }
    
    printf("\nWebsites in the system:\n");
    for (int i = 0; i < num_sites; i++) {
        printf("%d. %s\n", i+1, websites[i].url);
    }
}

/* Check Sites Function */
void check_sites() {
    CURL *curl;
    
    // Check if any sites added
    if (num_sites == 0) {
        printf("I'm sorry, Watson, but there are no websites added to the system to check.\n");
        return;
    }
    
    // Loop through all sites and check status
    for (int i = 0; i < num_sites; i++) {
        curl = curl_easy_init();
        if (curl) {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, websites[i].url);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
            res = curl_easy_perform(curl);
            
            if(res == CURLE_OK) {
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                websites[i].status = (int) response_code;
            } else {
                printf("I'm sorry, Watson, there was an error checking the status of website '%s'.\n", websites[i].url);
            }
            
            curl_easy_cleanup(curl);
        } else {
            printf("I'm sorry, Watson, there was an error initializing the CURL library.\n");
        }
        
        // Update status of website
        update_status(&websites[i]);
    }
}

/* Update Site Status Function */
void update_status(struct website *site) {
    // Increment count
    site->count++;
    
    // Check if status changed
    if (site->status != site->last_status) {
        printf("Website '%s' status changed from %d to %d (count=%d).\n", site->url, site->last_status, site->status, site->count);
        site->last_status = site->status;
    }
}