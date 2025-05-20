//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char message[100];
    unsigned char image[100];
} StegoObject;

int main(void) {
    StegoObject stegoObject;
    char message[100];
    unsigned char image[100];
    unsigned int messageLength = 0;
    unsigned int imageLength = 0;
    int i = 0;

    printf("Enter the message you want to hide: ");
    scanf("%s", message);
    messageLength = strlen(message);

    printf("Enter the image you want to hide the message in: ");
    scanf("%s", image);
    imageLength = strlen(image);

    printf("Generating StegoObject...\n");
    for (i = 0; i < 100; i++) {
        stegoObject.image[i] = image[i];
    }
    for (i = 0; i < 100; i++) {
        stegoObject.message[i] = message[i];
    }
    printf("StegoObject generated successfully!\n");

    // Add the message to the image
    for (i = 0; i < messageLength; i++) {
        int index = 0;
        while (index < 100) {
            if (stegoObject.image[index] == '1') {
                stegoObject.image[index] = '0';
                stegoObject.message[i] = '1';
                break;
            }
            index++;
        }
    }

    printf("Message successfully hidden!\n");

    // Output the stego image
    printf("Stego image: %s\n", stegoObject.image);
    printf("Message: %s\n", stegoObject.message);

    return 0;
}