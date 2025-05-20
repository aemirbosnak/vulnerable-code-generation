//FormAI DATASET v1.0 Category: Image Steganography ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE_LIMIT 1024

typedef unsigned char BYTE;

void print_header() {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~ BRAVE IMAGE STEGANOGRAPHY ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
}

void encode(char *input_file_name, char *output_file_name, char *message) {
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");
    
    if (input_file == NULL || output_file == NULL) {
        printf("Error: Unable to open the file!\n");
        return;
    }
    
    char *secret_message = malloc(strlen(message)+1);
    strcpy(secret_message, message);
    
    int i = 0, j = 0;
    int message_length = strlen(secret_message);
    BYTE *data = malloc(sizeof(char) * FILE_SIZE_LIMIT);
    
    fread(data, sizeof(char), FILE_SIZE_LIMIT, input_file);
    
    for (i = 0; i < 54; i++) {
        fputc(data[i], output_file);
    }
    
    for (i = 54; i < FILE_SIZE_LIMIT && j < message_length; i++) {
        if (i % 3 == 0) {
            data[i] = secret_message[j];
            j++;
        }
    }
    
    fwrite(data, sizeof(char), FILE_SIZE_LIMIT, output_file);
    
    printf("Message has been encoded successfully!\n");
    
    free(data);
    free(secret_message);
    
    fclose(input_file);
    fclose(output_file);
}

void decode(char *input_file_name) {
    FILE *input_file = fopen(input_file_name, "rb");
    
    if (input_file == NULL) {
        printf("Error: Unable to open the file!\n");
        return;
    }
    
    int i = 0;
    BYTE *data = malloc(sizeof(char) * FILE_SIZE_LIMIT);
    char *message = malloc(FILE_SIZE_LIMIT/3+1);
    
    fread(data, sizeof(char), FILE_SIZE_LIMIT, input_file);
    
    for (i = 54; i < FILE_SIZE_LIMIT; i++) {
        if (i % 3 == 0) {
            int ascii_value = (int) data[i];
            char message_char[2];
            sprintf(message_char, "%c", ascii_value);
            strcat(message, message_char);
        }
    }
    
    printf("The secret message is: %s\n", message);
    
    free(data);
    free(message);
    
    fclose(input_file);
}

int main() {
    print_header();
    
    char *input_file_name = malloc(256 * sizeof(char));
    char *output_file_name = malloc(256 * sizeof(char));
    char *message = malloc(256 * sizeof(char));
    
    printf("Enter the name of the input image file: ");
    scanf("%s", input_file_name);
    
    printf("Enter the name of the output image file: ");
    scanf("%s", output_file_name);
    
    printf("Enter the message to be encoded: ");
    scanf(" %[^\n]%*c", message);
    
    encode(input_file_name, output_file_name, message);
    decode(output_file_name);
    
    free(input_file_name);
    free(output_file_name);
    free(message);
    
    return 0;
}