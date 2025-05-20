//FormAI DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<time.h>

int main() {
    int passwordAttempts = 0;
    char password[20];
    char accessCode[20] = "securecode123";
    char userInput[20];
    int lightState = 0; // 0 = off, 1 = on
    int motionDetected = 0; // 0 = no motion, 1 = motion detected
    int brightness = 50;
    int currentHour = 0;
    time_t rawtime;
    struct tm * timeinfo;

    // Get current time
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    currentHour = timeinfo->tm_hour;

    // Prompt for password
    while(passwordAttempts < 3) {
        printf("Enter access code: ");
        scanf("%s", userInput);
        if(strcmp(userInput, accessCode) == 0) {
            printf("Access granted.\n");
            passwordAttempts = 3;
        }
        else {
            passwordAttempts++;
            printf("Invalid access code. Attempts left: %d\n", (3 - passwordAttempts));
        }
    }

    if(passwordAttempts == 3) {
        printf("Too many attempts. Exiting program.\n");
        return 0;
    }

    // Main program loop
    while(1) {
        // Simulate motion detection
        if(currentHour >= 19 || currentHour <= 6) {
            motionDetected = 1;
        }
        else {
            motionDetected = 0;
        }

        // Check if light should be turned on
        if(motionDetected == 1 && lightState == 0) {
            printf("Motion detected. Turning on lights.\n");
            lightState = 1;
        }

        // Check if light should be turned off
        if(motionDetected == 0 && lightState == 1) {
            printf("No motion detected. Turning off lights.\n");
            lightState = 0;
        }

        // Adjust brightness based on time of day
        if(currentHour >= 0 && currentHour <= 6) {
            brightness = 10;
        }
        else if(currentHour >= 7 && currentHour <= 12) {
            brightness = 25;
        }
        else if(currentHour >= 13 && currentHour <= 18) {
            brightness = 50;
        }
        else if(currentHour >= 19 && currentHour <= 23) {
            brightness = 75;
        }

        // Display current settings
        printf("Light State: %d | Motion Detected: %d | Brightness: %d\n", lightState, motionDetected, brightness);

        // Update current time
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        currentHour = timeinfo->tm_hour;
    }

    return 0;
}