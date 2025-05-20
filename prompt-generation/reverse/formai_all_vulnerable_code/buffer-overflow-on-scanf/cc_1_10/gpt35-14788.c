//FormAI DATASET v1.0 Category: Image compression ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

uint8_t pixel_data[MAX_HEIGHT][MAX_WIDTH]; // 2D Array to hold pixel values
uint8_t compressed_data[MAX_HEIGHT * MAX_WIDTH / 8]; // Array to hold compressed data
int compressed_size = 0;

// Function to compress the pixel data
void compress_data(int height, int width){
    int index = 0;
    uint8_t count = 0;
    uint8_t current_byte = 0;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(pixel_data[i][j] == 0){
                count++;
            } else {
                // Add count and pixel value to compressed data byte
                current_byte = current_byte << 1;
                current_byte |= (count > 0 ? 1 : 0);

                if(count > 0){
                    count = count << 1;
                    count |= (pixel_data[i][j] & 0x01);
                } else {
                    current_byte = current_byte << 1;
                    current_byte |= (pixel_data[i][j] & 0x01);
                }

                count = 0;
                index++;

                // Add compressed data byte to array and reset variables
                if(index % 8 == 0){
                    compressed_data[compressed_size++] = current_byte;
                    current_byte = 0;
                }
            }
        }
    }
}

int main(){
    int height, width;

    printf("Enter image height and width: ");
    scanf("%d %d", &height, &width);

    printf("Enter pixel data (1 or 0) row by row:\n");

    // Take input for pixel data
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            scanf("%d", &pixel_data[i][j]);
        }
    }

    // Compress the pixel data
    compress_data(height, width);

    // Print compressed data
    printf("Compressed data: ");
    for(int i=0; i<compressed_size; i++){
        printf("%x ", compressed_data[i]);
    }
    printf("\n");

    return 0;
}