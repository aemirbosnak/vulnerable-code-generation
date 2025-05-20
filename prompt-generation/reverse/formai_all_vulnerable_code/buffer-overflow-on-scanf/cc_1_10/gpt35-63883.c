//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILE_SIZE 5242880 //5MB
#define HEADER_SIZE 54 // 24-bit BMP header size
#define BITMAP_START_OFFSET 54 //this can be different for different bmp headers

//Function to check if a file is a BMP image or not
int is_bmp_file(const char *filename)
{
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file\n");
        return 0;
    }

    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, fp);
    fclose(fp);

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a BMP file\n");
        return 0;
    }

    printf("BMP file detected\n");
    return 1;  
}

//Function to hide a message in the least significant bits of the pixels' colour values
void hide_message(char *bmp_filename, char *message)
{
    //Open the bmp file in read-write binary mode
    FILE *fp = fopen(bmp_filename, "rb+");
    if (!fp) {
        perror("Error opening file!");
        return;
    }

    //Get the file size
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    //Check if the file size is within limits
    if (file_size > MAX_FILE_SIZE) {
        printf("File size is too large!\n");
        return;
    }

    //Read the header
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, fp);

    //Get the width and height of the bmp image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //Calculate the image size
    int image_size = width * height * 3; //3 bytes for RGB

    //Allocate memory for the image
    uint8_t *image = (uint8_t*) malloc(sizeof(uint8_t) * image_size);

    //Read the image data
    fseek(fp, BITMAP_START_OFFSET, SEEK_SET);
    fread(image, sizeof(uint8_t), image_size, fp);

    //Compute the size of the message
    int message_size = strlen(message);

    //Check if message can be hidden within image
    int max_stegan_bytes = image_size / 8;
    if ((message_size + 1) > max_stegan_bytes) {
        printf("Error: Message is too large to hide within image\n");
        return;
    }

    //Embed the message in the image
    int byte_counter = 0, bit_counter = 0;
    for (int i = 0; i < message_size; i++) {
        uint8_t cur_char = message[i];
        for (int j = 0; j < 8; j++) {
            uint8_t cur_bit = (cur_char >> j) & 1; //get the jth bit of the current character
            uint8_t cur_byte = image[byte_counter];

            if (cur_bit != ((cur_byte >> bit_counter) & 1)) { //if the bit is different, flip it
                if (cur_bit) {
                    image[byte_counter] |= (1 << bit_counter);
                } else {
                    image[byte_counter] &= ~(1 << bit_counter);
                }
            }

            bit_counter++;
            if (bit_counter == 8) {
                bit_counter = 0;
                byte_counter++;
            }
        }
    }

    //Null-terminate the message in the image
    uint8_t cur_char = '\0';
    for (int j = 0; j < 8; j++) {
        uint8_t cur_bit = (cur_char >> j) & 1; //get the jth bit of null character

        uint8_t cur_byte = image[byte_counter];

        if (cur_bit != ((cur_byte >> bit_counter) & 1)) { //if the bit is different, flip it
            if (cur_bit) {
                image[byte_counter] |= (1 << bit_counter);
            } else {
                image[byte_counter] &= ~(1 << bit_counter);
            }
        }

        bit_counter++;
        if (bit_counter == 8) {
            bit_counter = 0;
            byte_counter++;
        }
    }

    //Rewind to start and write the modified image to the file
    fseek(fp, BITMAP_START_OFFSET, SEEK_SET);
    fwrite(image, sizeof(uint8_t), image_size, fp);

    //Free the allocated memory and close the file
    free(image);
    fclose(fp);

    printf("Message hidden successfully!\n");
}

//Function to extract a message from the image
void extract_message(const char *bmp_filename)
{
    //Open the bmp file in read-only binary mode
    FILE *fp = fopen(bmp_filename, "rb");
    if (!fp) {
        perror("Error opening file!");
        return;
    }

    //Get the file size
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    //Read the header
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, fp);

    //Get the width and height of the bmp image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //Calculate the image size
    int image_size = width * height * 3; //3 bytes for RGB

    //Allocate memory for the image
    uint8_t *image = (uint8_t*) malloc(sizeof(uint8_t) * image_size);

    //Read the image data
    fseek(fp, BITMAP_START_OFFSET, SEEK_SET);
    fread(image, sizeof(uint8_t), image_size, fp);

    //Extract the message from the image
    uint8_t cur_char = 0;
    int byte_counter = 0, bit_counter = 0, message_size = 0;
    while (1) {
        //get the bit at the current position
        uint8_t cur_bit = (image[byte_counter] >> bit_counter) & 1;

        //update the current character with the current bit
        cur_char |= (cur_bit << message_size);

        //increment the message size and bit counter
        message_size++;
        bit_counter++;

        //if the message size is a multiple of 8, it means a character has been extracted
        if (message_size % 8 == 0) {
            //check if the current character is null, indicating the end of the message
            if (cur_char == '\0') {
                break;
            }

            putchar(cur_char);
            cur_char = 0;
        }

        //if the bit counter equals 8, increment the byte counter and reset the bit counter
        if (bit_counter == 8) {
            bit_counter = 0;
            byte_counter++;
        }
    }

    //Free the allocated memory and close the file
    free(image);
    fclose(fp);
}

int main()
{
    char bmp_filename[100], message[1000], choice;
    int is_bmp;
    do {
        printf("\nEnter the BMP file name: ");
        scanf("%s", bmp_filename);

        is_bmp = is_bmp_file(bmp_filename);
        if (!is_bmp) {
            continue;
        }

        printf("\nDo you want to hide (H) or extract (E) a message? ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'H':
            case 'h':
                printf("\nEnter the message to hide: ");
                scanf(" %[^\n]%*c", message);
                hide_message(bmp_filename, message);
                break;
            case 'E':
            case 'e':
                extract_message(bmp_filename);
                break;
            default:
                printf("\nInvalid choice\n");
        }

        printf("\nDo you want to hide or extract another message (Y/N)? ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}