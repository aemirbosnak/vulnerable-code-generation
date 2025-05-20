//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 2000
#define MAX_MESSAGE_LENGTH 100

int get_bit(int num, int bit_index) {
    return (num >> bit_index) & 1;
}

void set_bit(int* num, int bit_index, int bit_value) {
    if (bit_value == 1) {
        *num |= (1 << bit_index);
    } else {
        *num &= ~(1 << bit_index);
    }
}

void encode_message(int* pixels, int num_pixels, char* message) {
    int message_length = strlen(message);
    int message_index = 0;

    // Embed length of message in the first 10 pixels
    for (int i = 0; i < 5; i++) {
        int length_bit = get_bit(message_length, i);
        set_bit(&pixels[i], 0, length_bit);
    }

    // Embed message in remaining pixels
    for (int i = 5; i < num_pixels; i++) {
        if (message_index >= message_length) {
            return;
        }

        char current_char = message[message_index];
        int current_char_int = (int) current_char;
        for (int j = 0; j < 8; j++) {
            int bit = get_bit(current_char_int, j);
            set_bit(&pixels[i], j, bit);
        }

        message_index++;
    }
}

char* decode_message(int* pixels, int num_pixels) {
    int message_length = 0;

    // Extract length of message from the first 10 pixels
    for (int i = 0; i < 5; i++) {
        int length_bit = get_bit(pixels[i], 0);
        set_bit(&message_length, i, length_bit);
    }

    char* message = (char*) calloc(message_length + 1, sizeof(char));

    // Extract message from remaining pixels
    int message_index = 0;
    for (int i = 5; i < num_pixels; i++) {
        if (message_index >= message_length) {
            break;
        }

        char current_char = 0;
        for (int j = 0; j < 8; j++) {
            int bit = get_bit(pixels[i], j);
            set_bit(&current_char, j, bit);
        }

        message[message_index] = current_char;
        message_index++;
    }

    return message;
}

int main() {
    int pixels[MAX_PIXELS] = {0};
    char message[MAX_MESSAGE_LENGTH] = "";
    printf("Enter message to encode (max length %d): ", MAX_MESSAGE_LENGTH);
    scanf("%[^\n]s", message);

    // Encode message in pixels
    encode_message(pixels, MAX_PIXELS, message);

    // Print encoded pixels
    printf("Encoded pixels: ");
    for (int i = 0; i < MAX_PIXELS; i++) {
        printf("%d ", pixels[i]);
    }
    printf("\n");

    // Decode message from pixels
    char* decoded_message = decode_message(pixels, MAX_PIXELS);
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}