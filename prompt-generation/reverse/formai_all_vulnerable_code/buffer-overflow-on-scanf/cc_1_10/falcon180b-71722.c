//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRAME_SIZE 1024

// Calculate the checksum for a given frame
unsigned short calculate_checksum(unsigned char *frame, int frame_size) {
    unsigned short sum = 0;
    for (int i = 0; i < frame_size; i++) {
        sum += frame[i];
    }
    return sum;
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file contents into memory
    char *buffer = malloc(MAX_FRAME_SIZE);
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_FRAME_SIZE, fp)) > 0) {
        // Calculate the checksum for each frame
        int frame_size = bytes_read;
        unsigned short checksum = calculate_checksum(buffer, frame_size);

        // Print the frame data and checksum
        printf("Frame %d:\n", bytes_read / MAX_FRAME_SIZE);
        for (int i = 0; i < frame_size; i++) {
            printf("%02X ", buffer[i]);
        }
        printf("\nChecksum: %04X\n", checksum);

        // Reset the buffer for the next frame
        memset(buffer, 0, MAX_FRAME_SIZE);
    }

    // Close the file
    fclose(fp);

    return 0;
}