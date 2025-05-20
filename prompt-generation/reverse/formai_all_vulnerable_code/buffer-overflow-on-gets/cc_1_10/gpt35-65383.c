//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions of the Maximum Message Length and Watermark Length
#define MAX_MSG_LENGTH 100
#define WATERMARK_LENGTH 10

// Method to add watermark to message
void addWatermark(char* msg, char* watermark) {
    int len = strlen(msg);
    int wm_len = strlen(watermark);

    // Check if message length is greater than or equal to (watermark length + 1)
    if(len >= (wm_len + 1)) {
        // Add watermark to the end of message
        strcat(msg, watermark);
        // Calculate and add checksum to the end of message
        char checksum_str[3];
        int checksum = len % 10;
        sprintf(checksum_str, "%d", checksum);
        strcat(msg, checksum_str);
    } else {
        printf("Watermark cannot be added to message because of length constraint\n");
    }
}

// Method to extract watermark from message
char* extractWatermark(char* msg) {
    int len = strlen(msg);

    // Check if message length is greater than or equal to (watermark length + checksum length)
    if(len >= (WATERMARK_LENGTH + 1)) {
        // Extract watermark from the end of message
        char* watermark = malloc(sizeof(char) * (WATERMARK_LENGTH + 1));
        strncpy(watermark, msg + len - (WATERMARK_LENGTH + 1), WATERMARK_LENGTH);
        watermark[WATERMARK_LENGTH] = '\0';
        
        // Calculate actual length of message
        int actual_len = len - WATERMARK_LENGTH - 1;
        char checksum_str[3];
        strncpy(checksum_str, msg + actual_len, 2);
        checksum_str[2] = '\0';
        int checksum = atoi(checksum_str);

        // Verify checksum
        if(actual_len % 10 == checksum) {
            return watermark;
        } else {
            printf("Message has been corrupted\n");
            return NULL;
        }
    } else {
        printf("Watermark cannot be extracted from message because of length constraint\n");
        return NULL;
    }
}

int main() {
    char message[MAX_MSG_LENGTH];
    char watermark[WATERMARK_LENGTH];
    char* extracted_watermark;

    // Take input for message and watermark from user
    printf("Enter message (max length %d): ", MAX_MSG_LENGTH - WATERMARK_LENGTH - 1);
    gets(message);
    printf("Enter watermark (length %d): ", WATERMARK_LENGTH);
    gets(watermark);

    // Add watermark to message
    addWatermark(message, watermark);
    printf("Message with watermark: %s\n", message);

    // Extract watermark from message and verify it
    extracted_watermark = extractWatermark(message);

    if(extracted_watermark != NULL) {
        printf("Extracted watermark: %s\n", extracted_watermark);
    }

    return 0;
}