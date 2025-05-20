//FormAI DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54 // BMP header is 54 bytes
#define MAX_MSG_LEN 256 // Maximum message length

/* Get the least significant bit of a byte */
int lsb(int byte) {
    return byte & 0x1;
}

/* Set the least significant bit of a byte */
int set_lsb(int byte, int bit) {
    if (bit == 0) {
        return byte & 0xFE; // Set the least significant bit to 0
    } else {
        return byte | 0x1; // Set the least significant bit to 1
    }
}

/* Embed a message in the least significant bit of each pixel in an image */
int embed_message(char* img_file_name, char* msg) {
    FILE* img_file = fopen(img_file_name, "rb+");
    if (!img_file) {
        printf("Could not open image file %s\n", img_file_name);
        return 1;
    }
    
    char header[HEADER_SIZE];
    int num_bytes_written;
    
    /* Read the BMP header from the image file */
    size_t num_bytes_read = fread(header, 1, HEADER_SIZE, img_file);
    if (num_bytes_read != HEADER_SIZE) {
        printf("Error reading header from %s\n", img_file_name);
        fclose(img_file);
        return 2;
    }
    
    /* Get the dimensions of the image */
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    /* Make sure the message will fit in the image */
    int max_msg_len = (width * height * 3) / 8;
    if (strlen(msg) > max_msg_len) {
        printf("Message is too long to embed in %s\n", img_file_name);
        fclose(img_file);
        return 3;
    }
    
    /* Embed the message in the least significant bit of each pixel */
    int byte_cnt = 0;
    int bit_cnt = 0;
    int msg_len = strlen(msg);
    for (int i = HEADER_SIZE; i < width * height * 3; i++) {
        int byte = fgetc(img_file);
        if (byte_cnt < msg_len) { // Embed the message in each pixel
            int bit = lsb(byte);
            if (bit_cnt < 8) {
                bit = set_lsb(bit, (msg[byte_cnt] >> bit_cnt) & 0x1);
                bit_cnt++;
            } else {
                byte_cnt++;
                bit_cnt = 0;
            }
            
            byte = set_lsb(byte, bit);
        } else { // Padding to indicate end of message
            byte = set_lsb(byte, 0);
        }
        
        fseek(img_file, -1, SEEK_CUR);
        num_bytes_written = fputc(byte, img_file);
        if (num_bytes_written == EOF) {
            printf("Error writing to %s\n", img_file_name);
            fclose(img_file);
            return 4;
        }
    }
    
    fclose(img_file);
    return 0;
}

/* Extract a message from the least significant bit of each pixel in an image */
int extract_message(char* img_file_name) {
    FILE* img_file = fopen(img_file_name, "rb");
    if (!img_file) {
        printf("Could not open image file %s\n", img_file_name);
        return 1;
    }
    
    char header[HEADER_SIZE];
    int byte_cnt = 0;
    int bit_cnt = 0;
    char msg[MAX_MSG_LEN];
    int msg_len = 0;
    int msg_done = 0;
    
    /* Read the BMP header from the image file */
    size_t num_bytes_read = fread(header, 1, HEADER_SIZE, img_file);
    if (num_bytes_read != HEADER_SIZE) {
        printf("Error reading header from %s\n", img_file_name);
        fclose(img_file);
        return 2;
    }
    
    /* Get the dimensions of the image */
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    /* Extract the message from the least significant bit of each pixel */
    for (int i = HEADER_SIZE; i < width * height * 3; i++) {
        int byte = fgetc(img_file);
        int bit = lsb(byte);
        if (byte_cnt < MAX_MSG_LEN && !msg_done) {
            msg[byte_cnt] |= bit << bit_cnt;
            bit_cnt++;
            if (bit_cnt == 8) {
                byte_cnt++;
                bit_cnt = 0;
                if (msg[byte_cnt-1] == 0) { // End of message
                    msg_done = 1;
                    msg_len = byte_cnt - 1;
                }
            }
        }
    }
    
    /* Print the extracted message */
    printf("Extracted message from %s:\n", img_file_name);
    for (int i = 0; i < msg_len; i++) {
        printf("%c", msg[i]);
    }
    printf("\n");
    
    fclose(img_file);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <img_file_name>\n", argv[0]);
        return 1;
    }
    
    char* img_file_name = argv[1];
    
    char option;
    printf("Choose an option:\n");
    printf("(e) Embed a message\n");
    printf("(x) Extract a message\n");
    scanf("%c", &option);
    
    char msg[MAX_MSG_LEN];
    switch (option) {
        case 'e':
            printf("Enter a message to embed in %s:\n", img_file_name);
            scanf("%s", msg);
            embed_message(img_file_name, msg);
            break;
        case 'x':
            extract_message(img_file_name);
            break;
        default:
            printf("Invalid option %c\n", option);
            return 2;
    }
    
    return 0;
}