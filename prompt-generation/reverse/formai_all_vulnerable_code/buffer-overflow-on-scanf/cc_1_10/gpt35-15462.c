//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 100

/**
 * Function that applies the digital watermarking technique to a message
 **/
void apply_watermark(char* message) {
    // Original message
    printf("Original message: %s\n", message);

    // Generate a random key
    int key = rand() % 100;

    // Apply key to each character in the message
    for(int i=0; i<MAX_MESSAGE_LENGTH; i++) {
        message[i] += key;
    }

    // Watermarked message
    printf("Watermarked message: %s\n", message);

    // Save key and watermarked message in separate files
    FILE* key_file = fopen("watermark_key.txt", "w");
    fprintf(key_file, "%d", key);
    fclose(key_file);

    FILE* message_file = fopen("watermarked_message.txt", "w");
    fprintf(message_file, "%s", message);
    fclose(message_file);

    printf("Watermark applied and saved in files.\n");
}

/**
 * Function that removes the digital watermark from a message
 **/
void remove_watermark(char* message) {
    // Open key file and read key
    FILE* key_file = fopen("watermark_key.txt", "r");
    int key;
    fscanf(key_file, "%d", &key);
    fclose(key_file);

    // Remove key from each character in the message
    for(int i=0; i<MAX_MESSAGE_LENGTH; i++) {
        message[i] -= key;
    }

    // Original message
    printf("Original message: %s\n", message);
}

int main() {
    // Message to be watermarked
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter your message (max 100 characters):\n");
    scanf("%[^\n]", message);

    // Apply watermark
    apply_watermark(message);

    // Remove watermark
    remove_watermark(message);

    return 0;
}