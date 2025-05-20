//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define constants
#define MARKER "Watermark"
#define MARKER_SIZE strlen(MARKER)
#define BITS_PER_BYTE 8

// Function to encode message into the least significant bits of byte data
void encodeMessage(unsigned char *data, char *message, int message_size){
    unsigned char *current_byte = data;
    int bit_count = 0, i;

    // Encode the watermark marker
    for(i=0; i<MARKER_SIZE; i++){
        bit_count = i * BITS_PER_BYTE;

        while(bit_count < (i+1)*BITS_PER_BYTE){
            *current_byte = (*current_byte & ~(1 << bit_count)) | ((MARKER[i] >> (bit_count % BITS_PER_BYTE)) & 1);
            bit_count++;
            current_byte++;
        }

        // Reset bit count to zero if it exceeds BITS_PER_BYTE
        bit_count = 0;
    }

    // Encode the message
    for(i=0; i<message_size; i++){
        bit_count = i * BITS_PER_BYTE;

        while(bit_count < (i+1)*BITS_PER_BYTE){
            *current_byte = (*current_byte & ~(1 << bit_count)) | ((message[i] >> (bit_count % BITS_PER_BYTE)) & 1);
            bit_count++;
            current_byte++;
        }

        // Reset bit count to zero if it exceeds BITS_PER_BYTE
        bit_count = 0;
    }
}

// Function to decode message from the least significant bits of byte data
char *decodeMessage(unsigned char *data, int data_size){
    int i, j, bit_count = 0;
    char *message;
    unsigned char current_byte;
    message = (char*)malloc(data_size/BITS_PER_BYTE);

    // Iterate through the data to extract the watermark marker
    for(i=0; i<data_size; i+=(BITS_PER_BYTE*MARKER_SIZE)){
        current_byte = 0;

        for(j=0; j<BITS_PER_BYTE*MARKER_SIZE; j++){
            current_byte |= ((*(data + i + j) & 1) << (j % BITS_PER_BYTE));
        }

        // Check if the current bytes match the watermark marker
        if(strncmp(MARKER, (char*)&current_byte, MARKER_SIZE) == 0){
            // We've found the watermark, so decode and return the message
            bit_count = i + (BITS_PER_BYTE*MARKER_SIZE);
            break;
        }
    }

    // Iterate through the data to extract the message
    for(i=bit_count; i<data_size; i+=(BITS_PER_BYTE)){
        current_byte = 0;

        for(j=0; j<BITS_PER_BYTE; j++){
            current_byte |= ((*(data + i + j) & 1) << j);
        }

        // Append the decoded character to the message string
        message[i/BITS_PER_BYTE - bit_count/BITS_PER_BYTE] = current_byte;
    }

    return message;
}

int main(){
    unsigned char data[256];
    char message[128];
    char *decoded_message;

    printf("Enter the message to be encoded:\n");
    fgets(message, sizeof(message), stdin);

    encodeMessage(data, message, strlen(message));

    printf("\nEncoded data:\n");
    for(int i=0; i<strlen(message)+MARKER_SIZE; i++){
        printf("%02X ", data[i]);
    }

    decoded_message = decodeMessage(data, strlen(message)+MARKER_SIZE);

    printf("\n\nDecoded message:\n%s", decoded_message);

    free(decoded_message);

    return 0;
}