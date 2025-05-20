//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000
#define BUFFER_SIZE 256

typedef struct {
    unsigned char data;
    int count;
} RLE_PACKET;

void compress(unsigned char *input, unsigned char *output, int input_size) {
    int i = 0, j = 0;
    RLE_PACKET packet;

    while (i < input_size) {
        if (input[i] != input[i + 1]) { // check if next byte is same
            if (packet.count > 0) { // write previous packet to output
                output[j++] = packet.data;
                output[j++] = packet.count & 0xFF;
                output[j++] = (packet.count >> 8) & 0xFF;
                packet.count = 0;
            }
            if (i > 0) { // write current byte to packet
                packet.data = input[i];
                packet.count = 1;
            }
            i++;
        } else {
            packet.count++;
            i++;
        }
    }

    // write last packet to output
    if (packet.count > 0) {
        output[j++] = packet.data;
        output[j++] = packet.count & 0xFF;
        output[j++] = (packet.count >> 8) & 0xFF;
    }
}

int main(void) {
    unsigned char input[MAX_INPUT_SIZE] = { 0 };
    unsigned char output[MAX_INPUT_SIZE * 3] = { 0 };
    int input_size = 0;

    printf("Enter input data size (max 1000 bytes): ");
    scanf("%d", &input_size);

    if (input_size > MAX_INPUT_SIZE) {
        printf("Error: Input data size exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter input data:\n");
    fread(input, 1, input_size, stdin);

    compress(input, output, input_size);

    printf("\nCompressed data size: %d bytes\n", (int)(sizeof(output) / sizeof(output[0])) - input_size);

    FILE *output_file = fopen("output.bin", "wb");
    fwrite(output, 1, sizeof(output) / sizeof(output[0]), output_file);
    fclose(output_file);

    printf("\nCompressed data written to output.bin\n");

    return 0;
}