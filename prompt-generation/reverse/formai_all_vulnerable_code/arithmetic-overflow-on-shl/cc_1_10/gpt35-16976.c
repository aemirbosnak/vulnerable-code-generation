//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Size of the watermark (in bits)
#define WATERMARK_SIZE 32

// Structure to store the position of a bit in an integer
typedef struct {
    int byte;
    int bit;
} bit_position;

// Function to get the position of a bit in an integer
bit_position get_bit_position(int bit_index) {
    bit_position position;
    position.byte = bit_index / 8;
    position.bit = bit_index % 8;
    return position;
}

// Function to embed a watermark in an integer
int embed_watermark(int original_value, int watermark) {
    // Embed the watermark bit by bit
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        // Get the position of the bit in the original value
        bit_position position = get_bit_position(i);
        // Get the value of the bit in the original value
        int original_bit = (original_value >> (7 - position.bit)) & 1;
        // Get the value of the bit in the watermark
        int watermark_bit = (watermark >> (WATERMARK_SIZE - 1 - i)) & 1;
        // Embed the watermark bit in the original value
        if (watermark_bit == 1 && original_bit == 0) {
            original_value = original_value | (1 << (7 - position.bit));
        }
        else if (watermark_bit == 0 && original_bit == 1) {
            original_value = original_value & ~(1 << (7 - position.bit));
        }
    }
    // Return the value with the watermark embedded
    return original_value;
}

// Function to extract a watermark from an integer
int extract_watermark(int value) {
    int watermark = 0;
    // Extract the watermark bit by bit
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        // Get the position of the bit in the value
        bit_position position = get_bit_position(i);
        // Get the value of the bit in the value
        int bit = (value >> (7 - position.bit)) & 1;
        // Set the bit in the watermark
        watermark = watermark | (bit << (WATERMARK_SIZE - 1 - i));
    }
    // Return the extracted watermark
    return watermark;
}

int main() {
    // Original value to embed the watermark in
    int original_value = 12345;
    printf("Original value: %d\n", original_value);
    // Watermark to embed
    int watermark = 6789;
    printf("Watermark to embed: %d\n", watermark);
    // Embed the watermark in the original value
    int watermarked_value = embed_watermark(original_value, watermark);
    printf("Watermarked value: %d\n", watermarked_value);
    // Extract the watermark from the watermarked value
    int extracted_watermark = extract_watermark(watermarked_value);
    printf("Extracted watermark: %d\n", extracted_watermark);
    // Check if the extracted watermark matches the original watermark
    if (extracted_watermark == watermark) {
        printf("Watermark verified!\n");
    }
    else {
        printf("Watermark verification failed.\n");
    }
    return 0;
}