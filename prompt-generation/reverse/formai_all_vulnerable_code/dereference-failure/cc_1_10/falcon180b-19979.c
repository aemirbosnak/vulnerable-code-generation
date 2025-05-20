//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of given length
char* generateRandomString(int length) {
    char *result = (char*)malloc(length + 1);
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    int i;
    for (i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26;
    }
    result[length] = '\0';
    return result;
}

// Function to print a message with a timestamp
void printMessage(char* message) {
    time_t now = time(NULL);
    char* timestamp = asctime(localtime(&now));
    printf("%s %s", timestamp, message);
}

// Function to log a message to a file
void logMessage(char* message) {
    FILE* logFile = fopen("intrusion.log", "a");
    if (logFile == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }
    fprintf(logFile, "%s\n", message);
    fclose(logFile);
}

// Function to detect an intrusion
void detectIntrusion(char* userInput, char* expectedInput) {
    if (strcmp(userInput, expectedInput)!= 0) {
        printMessage("Intrusion detected! ");
        logMessage("Intrusion detected: User input did not match expected input");
    } else {
        printMessage("Access granted. ");
        logMessage("Access granted: User input matched expected input");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Define expected input
    char* expectedInput = "password123";

    // Prompt the user for input
    char* userInput = generateRandomString(10);
    printf("Enter the password: ");
    scanf("%s", userInput);

    // Detect intrusion
    detectIntrusion(userInput, expectedInput);

    return 0;
}