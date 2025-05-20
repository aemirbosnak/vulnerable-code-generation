//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
// Welcome to 221B Baker Street, the abode of the world's greatest detective!

#include <stdio.h>
#include <stdlib.h>

// Let us define some constants
#define MAX_MESSAGE_LENGTH 1024
#define MAX_CHECKSUM_LENGTH 32

// Function to calculate the checksum
int calculateChecksum(char *message, int length) {
    int checksum = 0;

    // Time to deduce the checksum
    for (int i = 0; i < length; i++) {
        checksum += (int)message[i];
    }

    return checksum;
}

// Function to print the results in a Watson-approved manner
void printResults(char *message, int checksum) {
    printf("\nElementary, my dear Watson! The checksum is: %d\n", checksum);
}

// Function to request the message from the user
char *requestMessage() {
    char *message = (char *)malloc(MAX_MESSAGE_LENGTH * sizeof(char));

    // Time to gather some evidence
    printf("Kindly provide the message whose checksum you seek: ");
    scanf("%s", message);

    return message;
}

// Function to get ready for the investigation
void prepareForInvestigation() {
    // Setting the stage
    printf("\nMy esteemed client, welcome to 221B Baker Street.\n");
    printf("It is my pleasure to assist you in your quest for a checksum.\n");
    printf("Pray, provide the message you wish to scrutinize.\n");
}

// Let us commence the investigation
int main() {
    // Setting the scene
    prepareForInvestigation();

    // Requesting the message from the user
    char *message = requestMessage();

    // Calculating the checksum
    int checksum = calculateChecksum(message, strlen(message));

    // Printing the results
    printResults(message, checksum);

    // Farewell
    printf("\nThe case is closed, my friend. Until next time!\n");

    return 0;
}