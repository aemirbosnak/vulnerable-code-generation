//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PAGES 500

int main() {
    int current_page = 0;
    bool ebook_loaded = false;
    bool user_logged_in = false;
    bool suspicious_activity_detected = false;

    printf("Welcome to the Paranoid Ebook Reader\n");

    // Loop until user logs in successfully
    while (!user_logged_in) {
        printf("Please enter your username: ");
        char username[20];
        scanf("%s", username);

        printf("Please enter your password: ");
        char password[20];
        scanf("%s", password);
        
        // Simulate login process
        printf("Logging in...\n");
        printf("Checking for suspicious activity...\n");
        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
            user_logged_in = true;
            printf("Login successful!\n");
        } else {
            printf("Invalid username or password. Please try again.\n");
        }
    }

    // Simulate loading ebook
    printf("Loading ebook...\n");
    printf("Checking file integrity...\n");
    printf("Scanning for viruses and malware...\n");
    ebook_loaded = true;

    // Loop through pages until suspicious activity detected or end of ebook
    while (current_page < MAX_PAGES && !suspicious_activity_detected) {
        printf("Page %d\n", current_page+1);

        // Simulate user selecting an action
        printf("Options: [f]orward, [b]ack, [q]uit\n");
        char input;
        scanf(" %c", &input);

        // Handle user's selected action
        switch(input) {
            case 'f':
                current_page++;
                break;
            case 'b':
                current_page--;
                break;
            case 'q':
                printf("Quitting ebook...\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Check for suspicious activity every 5 pages
        if (current_page % 5 == 0) {
            printf("Checking for suspicious activity...\n");
            suspicious_activity_detected = true; // For demonstration purposes only
        }
    }

    // If suspicious activity detected, take action
    if (suspicious_activity_detected) {
        printf("WARNING! Suspicious activity detected. Terminating ebook...\n");
    } else {
        printf("End of ebook. Thanks for reading!\n");
    }

    return 0;
}