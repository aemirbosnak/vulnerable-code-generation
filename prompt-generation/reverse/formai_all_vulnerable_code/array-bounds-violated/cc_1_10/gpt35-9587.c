//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the maximum size for the message and the watermark
#define MAXMSG 100
#define MAXWATERMARK 20

// Function to embed the watermark into the message
void embedWatermark(char *message, char *watermark){
    // Finding the length of the message and the watermark
    int msgLen = strlen(message);
    int wmLen = strlen(watermark);

    // Creating a copy of the message before modifying it
    char copyMessage[MAXMSG];
    strcpy(copyMessage, message);

    // Creating a binary copy of the watermark
    int binaryWatermark[MAXWATERMARK];
    for (int i = 0; i < wmLen; i++){
        binaryWatermark[i] = (int)watermark[i];
    }

    // Embedding the watermark into the message by alternating the last character with the binary value of the watermark
    for (int i = 0; i < wmLen; i++){
        if (binaryWatermark[i] % 2 == 0){
            copyMessage[msgLen-wmLen+i] = binaryWatermark[i] + 1;
        } else {
            copyMessage[msgLen-wmLen+i] = binaryWatermark[i] - 1;
        }
    }

    // Printing out the original message and the watermarked message
    printf("Original Message: %s\n", message);
    printf("Watermarked Message: %s\n", copyMessage);
}

// Function to extract the watermark from the watermarked message
void extractWatermark(char *watermarkedMessage, int watermarkLength){
    // Finding the length of the watermarked message
    int wmsgLen = strlen(watermarkedMessage);

    // Creating a copy of the watermarked message before modifying it
    char copyWmsg[MAXMSG];
    strcpy(copyWmsg, watermarkedMessage);

    // Extracting each character of the watermark from the last characters of the watermarked message
    int binaryWatermark[MAXWATERMARK];
    for (int i = watermarkLength-1; i >= 0; i--){
        if ((int)copyWmsg[wmsgLen-watermarkLength+i] % 2 == 0){
            binaryWatermark[i] = (int)copyWmsg[wmsgLen-watermarkLength+i] - 1;
        } else {
            binaryWatermark[i] = (int)copyWmsg[wmsgLen-watermarkLength+i] + 1;
        }
    }

    // Printing out the extracted watermark
    printf("Extracted Watermark:");
    for (int i = 0; i < watermarkLength; i++){
        printf(" %c", (char)binaryWatermark[i]);
    }
    printf("\n");
}

// Main function
int main(){
    char message[MAXMSG];
    char watermark[MAXWATERMARK];

    // Getting user input for the message and watermark
    printf("Enter a message:\n");
    getchar();  // To skip newline character left by previous scanf()
    fgets(message, MAXMSG, stdin);

    printf("Enter a watermark:\n");
    fgets(watermark, MAXWATERMARK, stdin);

    // Embedding the watermark into the message
    embedWatermark(message, watermark);

    // Extracting the watermark from the watermarked message
    char watermarkedMessage[MAXMSG];
    printf("Enter the watermarked message:\n");
    fgets(watermarkedMessage, MAXMSG, stdin);

    extractWatermark(watermarkedMessage, strlen(watermark));

    return 0;
}