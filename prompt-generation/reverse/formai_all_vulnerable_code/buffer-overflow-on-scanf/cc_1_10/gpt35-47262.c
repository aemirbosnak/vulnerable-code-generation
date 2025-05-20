//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program demonstrates an example of image steganography in C programming language. 
   Image steganography is the process of hiding a secret message inside a digital image
   without altering the image itself. */

// Maximum size of the message that can be hidden
#define MAX_SIZE 200

/* Function to hide the message in the image */
void hideMessage(char *image_path, char *message) {
    FILE *image_file, *output_file;
    char output_path[100];
    int image_data, message_len, bit_count = 0, x, y, i;
    char c, pixel_data;
    
    // Open the image file in read mode
    image_file = fopen(image_path, "r");
    if (image_file == NULL) {
        fprintf(stderr, "Error: Could not open %s file\n", image_path);
        return;
    }
    
    // Calculate the length of the message
    message_len = strlen(message);
    if (message_len > MAX_SIZE) {
        fprintf(stderr, "Error: Message is too long\n");
        return;
    }
    
    // Open the output file in write mode
    strcpy(output_path, image_path);
    strcat(output_path, ".out");
    output_file = fopen(output_path, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not create %s file\n", output_path);
        return;
    }
    
    // Read the image pixel-by-pixel and hide the message
    while ((image_data = fgetc(image_file)) != EOF) {
        if (bit_count < message_len * 8) {     // If we haven't hidden the entire message yet
            c = message[bit_count / 8];        // Get the next character from the message
            pixel_data = (char)image_data;     // Cast the pixel value to char data type
            
            // Code to hide the message bit-by-bit in the pixel data
            for (i = 0; i < 8; i++) {
                if (bit_count < message_len * 8) {
                    x = ((int)pixel_data >> i) & 1;
                    y = (int)c >> (7 - (bit_count % 8)) & 1;
                    if (x != y) {
                        pixel_data ^= 1 << i;
                    }
                    bit_count++;
                }
            }
            fputc(pixel_data, output_file);    // Write the modified pixel data to the output file
        }
        else {
            putc(image_data, output_file);     // Copy the remaining image data to the output file
        }
    }
    
    // Close the files
    fclose(image_file);
    fclose(output_file);
    
    printf("Message hidden successfully in %s file.\n", image_path);
    printf("Output file: %s\n", output_path);
}

/* Function to extract the message from the image */
void extractMessage(char *image_path) {
    FILE *image_file;
    int image_data, bit_count = 0, x, i;
    char pixel_data, message[MAX_SIZE + 1];
    
    // Open the image file in read mode
    image_file = fopen(image_path, "r");
    if (image_file == NULL) {
        fprintf(stderr, "Error: Could not open %s file\n", image_path);
        return;
    }
    
    // Read the image pixel-by-pixel and extract the message
    while ((image_data = fgetc(image_file)) != EOF && bit_count < MAX_SIZE * 8) {
        pixel_data = (char)image_data;         // Cast the pixel value to char data type
        
        // Code to extract the message bit-by-bit from the pixel data
        for (i = 0; i < 8; i++) {
            x = ((int)pixel_data >> i) & 1;
            message[bit_count / 8] |= x << (7 - (bit_count % 8));
            bit_count++;
            if (bit_count == MAX_SIZE * 8 || pixel_data == EOF) {
                break;
            }
        }
    }
    message[bit_count / 8] = '\0';             // Add the null terminator to the message
    
    // Close the file
    fclose(image_file);
    
    if (strlen(message) == 0) {
        printf("No hidden message found in %s file.\n", image_path);
    } else {
        printf("Hidden message in %s file: %s\n", image_path, message);
    }
}

/* Main function */
int main() {
    char image_path[100], message[MAX_SIZE + 1];
    int choice;
    
    printf("Welcome to Image Steganography program!\n");
    
    do {
        printf("\nSelect an option:\n");
        printf("1. Hide message in an image\n");
        printf("2. Extract message from an image\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the path of the image file: ");
                scanf("%s", image_path);
                printf("Enter the message to be hidden (maximum %d characters): ", MAX_SIZE);
                scanf("%s", message);
                hideMessage(image_path, message);
                break;
                
            case 2:
                printf("Enter the path of the image file: ");
                scanf("%s", image_path);
                extractMessage(image_path);
                break;
                
            case 3:
                printf("Exiting the program...\n");
                break;
                
            default:
                printf("Invalid choice, try again\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}