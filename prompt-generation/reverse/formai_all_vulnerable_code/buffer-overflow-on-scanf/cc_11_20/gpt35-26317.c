//FormAI DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_MESSAGE_SIZE 512

int main() {
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE], message[MAX_MESSAGE_SIZE], temp_message[MAX_MESSAGE_SIZE], hidden_message[MAX_MESSAGE_SIZE];
    int image_width, image_height, message_length, hidden_message_length, i, j, k, l, m, n;
    int temp = 0, index = 0, code = 0, count = 0;
    float average = 0.0, deviation = 0.0, variance = 0.0;
    char filename[100];

    // Read image file name
    printf("Enter the image file name: ");
    scanf("%s", filename);

    // Read image size
    printf("Enter image width: ");
    scanf("%d", &image_width);
    printf("Enter image height: ");
    scanf("%d", &image_height);

    // Read the message to be hidden
    printf("Enter the message to be hidden: ");
    scanf("%s", message);
    message_length = strlen(message);

    // Calculate the hidden message length
    hidden_message_length = (message_length * sizeof(char) * 8) / 3;

    // Validate if the message can be hidden in the image
    if (hidden_message_length > (image_width * image_height)) {
        printf("ERROR: message size exceeds image capacity!");
        return 1;
    }

    // Read the image pixel values
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            printf("Enter pixel value for row %d and column %d: ", i, j);
            scanf("%d", &image[i][j]);
            average += image[i][j];
        }
    }

    // Calculate image average brightness
    average /= (image_width * image_height);

    // Calculate image variance and standard deviation
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            temp = image[i][j] - average;
            variance += temp * temp;
        }
    }
    variance /= (image_width * image_height);
    deviation = sqrt(variance);

    // Encode the message using steganography algorithm
    index = 0;
    for (i = 0; i < message_length; i++) {
        for (j = 0; j < 8; j += 3) {
            code = (message[i] >> j) & 0x07;
            temp_message[index++] = code;
        }
    }

    // Hide the message in the image using LSB technique
    count = 0;
    index = 0;
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            if (count < hidden_message_length) {
                image[i][j] = ((image[i][j] >> 3) << 3) | temp_message[index++];
                count++;
            } else {
                break;
            }
        }
        if (count >= hidden_message_length) {
            break;
        }
    }

    // Print the encoded image pixels
    printf("Encoded image:\n");
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Decode the hidden message from the image
    index = 0;
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            if (index < hidden_message_length) {
                hidden_message[index++] = image[i][j] & 0x07;
            } else {
                break;
            }
        }
        if (index >= hidden_message_length) {
            break;
        }
    }

    // Decode the original message from the hidden message bits
    index = 0;
    for (i = 0; i < message_length; i++) {
        for (j = 0; j < 8; j += 3) {
            code = (hidden_message[index++] << j);
            temp += code;
        }
        message[i] = temp;
        temp = 0;
    }

    // Print the original message
    printf("Decoded message: %s\n", message);

    return 0;
}