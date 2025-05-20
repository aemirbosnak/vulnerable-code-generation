//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
// Welcome to the world of post-apocalyptic image steganography! ☢️

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Our rusty bunker to store secrets...
struct ImageBunker {
    uint8_t *data;      // The desolate wasteland of pixels
    int width, height;  // Dimensions of our forsaken world
    int channels;       // Number of weary travelers (RGB)
};

// Stealthily extract the hidden message from the bunker
char *extractMessage(struct ImageBunker *bunker, int bitIndex) {
    int messageSize;
    fread(&messageSize, sizeof(int), 1, stdin);

    char *message = malloc(messageSize + 1);
    for (int i = 0; i < messageSize; i++) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= ((bunker->data[i + j] >> bitIndex) & 1) << (7 - j);
        }
        message[i] = byte;
    }
    message[messageSize] = '\0';
    return message;
}

// Bury a message in the bunker, marking it with the bones of the past...
void hideMessage(struct ImageBunker *bunker, char *message, int bitIndex) {
    int messageSize = strlen(message);

    // Insert the message size as a guide for the weary
    fwrite(&messageSize, sizeof(int), 1, stdout);

    for (int i = 0; i < messageSize; i++) {
        uint8_t byte = message[i];
        for (int j = 0; j < 8; j++) {
            bunker->data[i + j] |= ((byte >> (7 - j)) & 1) << bitIndex;
        }
    }
}

// Traverse the wasteland, seeking bunkers and whispers
int main() {
    struct ImageBunker bunker;

    // Load the desolate image from the ruins
    fread(&bunker.width, sizeof(int), 1, stdin);
    fread(&bunker.height, sizeof(int), 1, stdin);
    fread(&bunker.channels, sizeof(int), 1, stdin);
    bunker.data = malloc(bunker.width * bunker.height * bunker.channels);
    fread(bunker.data, bunker.width * bunker.height * bunker.channels, 1, stdin);

    // Listen for secrets hidden within the bunker's walls
    char *message;
    int bitIndex;
    fread(&bitIndex, sizeof(int), 1, stdin);
    if (bitIndex != -1) {
        message = extractMessage(&bunker, bitIndex);
        printf("Message from the wasteland: %s\n", message);
    } else {
        printf("No hidden message in this bunker...\n");
    }

    // Bury a new message in the desolate land
    printf("Enter a message to hide (max 255 characters): ");
    char newMessage[256];
    fgets(newMessage, 256, stdin);
    if (strlen(newMessage) > 0) {
        hideMessage(&bunker, newMessage, bitIndex);
        printf("Message buried in the depths of the image.\n");
    }

    // Write the transformed image back to the wasteland
    fwrite(&bunker.width, sizeof(int), 1, stdout);
    fwrite(&bunker.height, sizeof(int), 1, stdout);
    fwrite(&bunker.channels, sizeof(int), 1, stdout);
    fwrite(bunker.data, bunker.width * bunker.height * bunker.channels, 1, stdout);

    return 0;
}