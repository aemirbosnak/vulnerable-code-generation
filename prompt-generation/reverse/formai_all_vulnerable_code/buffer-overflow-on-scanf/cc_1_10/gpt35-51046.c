//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUM_BITS 8
#define MAX_MSG_LEN 1000

// function to print binary representation of a byte
void print_byte_binary(uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf(" ");
}

// function to set a bit at a particular position in a byte
void set_bit(uint8_t *byte, int pos, int bit) {
    if (bit == 0) {
        *byte &= ~(1 << pos);
    } else {
        *byte |= (1 << pos);
    }
}

// function to extract a bit from a byte at a particular position
int get_bit(uint8_t byte, int pos) {
    return (byte >> pos) & 1;
}

// function to calculate the length of the message
int get_msg_len(char *msg) {
    int len = 0;
    while (msg[len] != '\0') {
        len++;
    }
    return len;
}

// main function
int main() {
    // declare variables
    FILE *input_file, *output_file;
    char original_filename[100], modified_filename[100], message[MAX_MSG_LEN], msg_len_str[4];
    uint8_t pixel, msg_len_byte, msg_byte, bit;
    int msg_len, msg_idx, bit_idx, pixel_idx, end_of_msg_reached;

    // get user input
    printf("Enter the name of the input file: ");
    scanf("%s", original_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", modified_filename);
    printf("Enter the message to hide: ");
    getchar();
    fgets(message, MAX_MSG_LEN, stdin);

    // open input file
    input_file = fopen(original_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    // open output file
    output_file = fopen(modified_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Unable to open output file\n");
        exit(1);
    }

    // convert message length to byte
    msg_len = get_msg_len(message);
    if (msg_len > 255) {
        printf("Error: Message too long\n");
        exit(1);
    }
    msg_len_str[0] = (msg_len >> 8) & 0xFF;
    msg_len_str[1] = msg_len & 0xFF;
    msg_len_byte = atoi(msg_len_str);

    // write message length byte to output file
    fwrite(&msg_len_byte, sizeof(uint8_t), 1, output_file);

    // write message to output file
    for (msg_idx = 0; msg_idx < msg_len; msg_idx++) {
        msg_byte = message[msg_idx];

        // hide message byte in LSB of image pixel
        for (bit_idx = 0; bit_idx < NUM_BITS; bit_idx++) {
            // read next pixel from input file
            if (fread(&pixel, sizeof(uint8_t), 1, input_file) != 1) {
                printf("Error: Unexpected end of input file\n");
                exit(1);
            }

            // extract LSB of pixel value
            bit = get_bit(pixel, 0);

            // set current bit of message byte in LSB of pixel value
            set_bit(&pixel, 0, get_bit(msg_byte, bit_idx));

            // write modified pixel to output file
            fwrite(&pixel, sizeof(uint8_t), 1, output_file);

            // check if end of message has been reached
            if (msg_idx == msg_len - 1 && bit_idx == 7) {
                end_of_msg_reached = 1;
                break;
            }
        }

        if (end_of_msg_reached) {
            break;
        }
    }

    // copy remaining pixels from input file to output file
    while (fread(&pixel, sizeof(uint8_t), 1, input_file) == 1) {
        fwrite(&pixel, sizeof(uint8_t), 1, output_file);
    }

    // close files
    fclose(input_file);
    fclose(output_file);

    // print success message
    printf("Message hidden successfully\n");

    return 0;
}