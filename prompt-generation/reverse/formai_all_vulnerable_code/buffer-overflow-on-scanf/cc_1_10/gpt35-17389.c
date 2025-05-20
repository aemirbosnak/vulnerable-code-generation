//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
void logFile(char* message);
void alert(char* message);
void intrusion(char* message);

int main() {
    char input[100];
    char password[9];
    int attempt = 0;
    time_t currentTime;

    // Set the password
    strcpy(password, "password");

    while(attempt < 3) {
        printf("Enter the password: ");
        scanf("%s", input);

        // Check if the password is correct
        if(strcmp(input, password) == 0) {
            printf("Welcome to the system.\n");
            
            // Log successful login attempt
            currentTime = time(NULL);
            logFile("Successful login attempt.");
            intrusion("Successful login attempt.");

            break;
        } else {
            attempt++;
            printf("Incorrect password. Try again.\n");

            // Log unsuccessful login attempt
            currentTime = time(NULL);
            logFile("Unsuccessful login attempt.");
            
            // Alert the user if there have been 3 unsuccessful attempts
            if(attempt == 3) {
                alert("Three unsuccessful login attempts.");
                intrusion("Three unsuccessful login attempts.");
            }
        }
    }
    
    return 0;
}

// Log message to file
void logFile(char* message) {
    FILE* filePtr;

    filePtr = fopen("log.txt", "a");
    if(filePtr == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    fprintf(filePtr, "%s\n", message);

    fclose(filePtr);
}

// Alert the user
void alert(char* message) {
    printf("%s\n", message);
}

// Notify of intrusion
void intrusion(char* message) {
    printf("Intrusion detected: %s\n", message);
}