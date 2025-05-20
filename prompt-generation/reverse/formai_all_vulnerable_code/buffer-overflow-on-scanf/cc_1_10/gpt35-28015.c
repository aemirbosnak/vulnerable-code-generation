//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define WATERMARK_LENGTH 10
#define CHECKSUM_SIZE 16

/* Function to calculate checksum of the message */
unsigned char *calculateChecksum(char *msg) {
    unsigned char *checksum;
    checksum = calloc(CHECKSUM_SIZE, sizeof(unsigned char));

    int msgLength = strlen(msg);
    int i, j;

    /* Taking XOR of every 2 consecutive characters of the message */
    for (i = 0, j = 0; i < msgLength; i += 2, j++) {
        checksum[j] = msg[i] ^ msg[i+1];
    }

    return checksum;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    unsigned char *watermark;
    unsigned char *checksum;
    int i;

    /* Taking input of message from user */
    printf("Enter the message: ");
    scanf("%[^\n]", message);

    /* Generating a random watermark of length 8 */
    srand(time(0));
    watermark = calloc(WATERMARK_LENGTH, sizeof(unsigned char));
    for (i = 0; i < WATERMARK_LENGTH; i++) {
        watermark[i] = rand() % 255;
    }

    /* Concatenating the message and the watermark */
    int msgLength = strlen(message);
    char *watermarkedMessage = calloc(msgLength + WATERMARK_LENGTH + 1, sizeof(char));
    strcpy(watermarkedMessage, message);
    for (i = 0; i < WATERMARK_LENGTH; i++) {
        watermarkedMessage[msgLength + i] = watermark[i];
    }

    /* Calculating the checksum of the watermarked message */
    checksum = calculateChecksum(watermarkedMessage);

    /* Printing the watermarked message with checksum */
    printf("\nWatermarked message: %s\n", watermarkedMessage);
    printf("Checksum: ");
    for (i = 0; i < CHECKSUM_SIZE; i++) {
        printf("%02x ", checksum[i]);
    }

    return 0;
}