//FormAI DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIZE 1000
#define MAX_MSG_LENGTH 200

int message_to_binary(char *message, int message_length, char *binary_output){
    // Convert the message to binary
    int i, j, k;
    for (i=0, k=0; i<message_length; i++){
        char character = message[i];
        for (j=0; j<8; j++){
            binary_output[k++] = (character & (1 << j)) ? '1' : '0';
        }
    }
    // Add stop bits to the end of the message
    binary_output[k++] = '1';
    binary_output[k++] = '1';
    binary_output[k++] = '1';
    binary_output[k++] = '0';
    return k;
}

int binary_to_message(char *binary_input, char *message_output){
    // Convert binary to message
    int i, j, k;
    for (i=0, k=0; binary_input[i]!='\0'; i+=8){
        char character = 0;
        for (j=0; j<8; j++){
            character |= (binary_input[i+j] - '0') << j;
        }
        message_output[k++] = character;
    }
    // Remove stop bits from end of message
    message_output[k-4] = '\0';
    return k-4;
}

void hide_message(char *image_file_name, char *message){
    FILE *image_file = fopen(image_file_name, "rb");
    char image_data[IMAGE_SIZE];
    fread(image_data, sizeof(char), IMAGE_SIZE, image_file);
    fclose(image_file);
    char binary_msg[MAX_MSG_LENGTH*8+4];
    int msg_length = message_to_binary(message, strlen(message), binary_msg);  
    printf("Message in binary: %s\n", binary_msg);
    int i, j;
    for (i=0, j=0; i<IMAGE_SIZE && j<msg_length; i+=3, j+=2){
        char *pixel1 = &image_data[i];
        char *pixel2 = &image_data[i+3];
        pixel1[0] = (pixel1[0] & 0xfc) | (binary_msg[j] - '0');
        pixel1[1] = (pixel1[1] & 0xfc) | (binary_msg[j+1] - '0');
        pixel2[0] = (pixel2[0] & 0xfc) | (binary_msg[j+2] - '0');
    }
    FILE *output_file = fopen("output.bmp", "wb");
    fwrite(image_data, sizeof(char), IMAGE_SIZE, output_file);
    fclose(output_file);
}

void reveal_message(char *image_file_name){
    FILE *image_file = fopen(image_file_name, "rb");
    char image_data[IMAGE_SIZE];
    fread(image_data, sizeof(char), IMAGE_SIZE, image_file);
    fclose(image_file);
    char binary_msg[MAX_MSG_LENGTH*8+4];
    int i, j;
    for (i=0, j=0; i<IMAGE_SIZE && j<(MAX_MSG_LENGTH*8+4); i+=3, j+=2){
        char *pixel1 = &image_data[i];
        char *pixel2 = &image_data[i+3];
        binary_msg[j] = ((pixel1[0] & 0x03) + '0');
        binary_msg[j+1] = ((pixel1[1] & 0x03) + '0');
        binary_msg[j+2] = ((pixel2[0] & 0x03) + '0');
    }
    char message[MAX_MSG_LENGTH];
    int msg_length = binary_to_message(binary_msg, message);
    printf("Message hidden in the image: %s\n", message);
}

int main(){
    printf("Enter command (hide/reveal/quit): ");
    char command[MAX_MSG_LENGTH];
    scanf("%s", command);
    while (strcmp(command, "quit")!=0){
        if (strcmp(command, "hide")==0){
            char message[MAX_MSG_LENGTH];
            printf("Enter message to hide: ");
            scanf(" %[^\n]s", message);
            hide_message("image.bmp", message);
            printf("Message successfully hidden in the image.\n");
        } else if (strcmp(command, "reveal")==0){
            reveal_message("output.bmp");
        } else {
            printf("Invalid command.\n");
        }
        printf("Enter command (hide/reveal/quit): ");
        scanf("%s", command);
    }
    return 0;
}