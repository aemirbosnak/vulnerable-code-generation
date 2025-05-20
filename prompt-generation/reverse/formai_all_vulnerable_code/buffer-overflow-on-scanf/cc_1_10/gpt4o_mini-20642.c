//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SERVER_URL "http://localhost:8080"
#define BUFFER_SIZE 256

// Function to send a command to the web server
void send_command(const char *command) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        char url[BUFFER_SIZE];
        snprintf(url, sizeof(url), "%s/%s", SERVER_URL, command);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

// Function to display the interface
void display_interface() {
    printf("Music Control Plugin\n");
    printf("---------------------\n");
    printf("1. Play\n");
    printf("2. Pause\n");
    printf("3. Stop\n");
    printf("4. Next Track\n");
    printf("5. Previous Track\n");
    printf("6. Exit\n");
}

// Main function to control music playback
int main() {
    int choice;
    
    while (1) {
        display_interface();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                send_command("play");
                break;
            case 2:
                send_command("pause");
                break;
            case 3:
                send_command("stop");
                break;
            case 4:
                send_command("next");
                break;
            case 5:
                send_command("previous");
                break;
            case 6:
                printf("Exiting Music Control Plugin...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose between 1 and 6.\n");
                break;
        }
    }

    return 0;
}