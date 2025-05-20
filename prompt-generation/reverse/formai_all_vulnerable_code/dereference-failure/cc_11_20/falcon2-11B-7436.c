//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_SIZE 100
#define MAX_FILE_SIZE 10000

int main(int argc, char *argv[])
{
    if(argc!= 3) {
        printf("Usage: %s <image_file> <message>\n", argv[0]);
        return 1;
    }
    
    FILE *image_file = fopen(argv[1], "rb");
    if(image_file == NULL) {
        printf("Error opening image file\n");
        return 1;
    }
    
    FILE *message_file = fopen(argv[2], "r");
    if(message_file == NULL) {
        printf("Error opening message file\n");
        fclose(image_file);
        return 1;
    }
    
    int message_length = strlen(argv[2]);
    
    unsigned char *image_buffer = malloc(MAX_FILE_SIZE);
    if(image_buffer == NULL) {
        printf("Error allocating memory for image buffer\n");
        fclose(message_file);
        fclose(image_file);
        return 1;
    }
    
    int bytes_read = fread(image_buffer, 1, MAX_FILE_SIZE, image_file);
    if(bytes_read!= MAX_FILE_SIZE) {
        printf("Error reading image file\n");
        fclose(message_file);
        fclose(image_file);
        free(image_buffer);
        return 1;
    }
    
    int secret_bytes_written = 0;
    unsigned char *message_buffer = malloc(MAX_MESSAGE_SIZE);
    if(message_buffer == NULL) {
        printf("Error allocating memory for message buffer\n");
        fclose(message_file);
        fclose(image_file);
        free(image_buffer);
        return 1;
    }
    
    int message_bytes_read = fread(message_buffer, 1, MAX_MESSAGE_SIZE, message_file);
    if(message_bytes_read!= MAX_MESSAGE_SIZE) {
        printf("Error reading message file\n");
        fclose(message_file);
        fclose(image_file);
        free(image_buffer);
        free(message_buffer);
        return 1;
    }
    
    for(int i = 0; i < MAX_MESSAGE_SIZE; i++) {
        if(isalpha(message_buffer[i]) || isdigit(message_buffer[i])) {
            int message_byte = (int) message_buffer[i];
            int index = message_byte % MAX_FILE_SIZE;
            image_buffer[index] ^= (unsigned char) 0x80;
            secret_bytes_written++;
        }
    }
    
    fclose(message_file);
    fclose(image_file);
    fwrite(image_buffer, 1, MAX_FILE_SIZE, stdout);
    printf("Bytes written to image file: %d\n", secret_bytes_written);
    free(image_buffer);
    free(message_buffer);
    
    return 0;
}