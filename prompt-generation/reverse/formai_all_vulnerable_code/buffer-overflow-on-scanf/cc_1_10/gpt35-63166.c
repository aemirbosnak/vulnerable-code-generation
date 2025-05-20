//FormAI DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if the given URL is valid or not
int isUrlValid(char* url) {
    int length = strlen(url);
    if(length < 7 || (strncmp(url, "http://", 7) && strncmp(url, "https://", 8))) {
        return 0; // URL not valid
    }
    return 1; // URL valid
}

// function to print error message and exit program with status 1
void error(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

// main function
int main() {

    // variables to store user input and selected option
    int option = 0;
    char url[100];

    // loop until the user exits
    while(1) {
        // print menu options
        printf("\n===== C Browser Plugin =====\n");
        printf("1. Browse URL\n");
        printf("2. Exit\n");

        // get user input
        printf("Enter option: ");
        scanf("%d", &option);

        // check selected option
        switch(option) {
            case 1:
                // get URL from user
                printf("Enter URL: ");
                scanf("%s", url);
                
                // check if URL is valid or not
                if(!isUrlValid(url)) {
                    error("Invalid URL");
                }

                // open browser window with the given URL
                printf("Opening %s in browser...\n", url);
                // code to open browser window goes here
                break;
            case 2:
                // exit program
                printf("Exiting...\n");
                exit(0);
            default:
                // invalid option selected
                error("Invalid option");
        }
    }

    return 0;
}