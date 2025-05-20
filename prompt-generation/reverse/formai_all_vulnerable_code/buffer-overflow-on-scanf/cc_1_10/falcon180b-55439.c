//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define IMAGE_WIDTH 1000
#define IMAGE_HEIGHT 1000
#define MAX_PIXEL_VALUE 255
#define MAX_MESSAGE_LENGTH 1000

int main() {
    int message_length;
    char message[MAX_MESSAGE_LENGTH];
    char message_file[20];
    char image_file[20];
    FILE *message_fp, *image_fp;
    int i, j, pixel_value, message_index;
    unsigned char message_char;
    unsigned char *image_data;
    unsigned int image_size;
    unsigned int message_size;
    time_t current_time;
    struct tm *time_info;
    char time_str[20];

    // Get message from user
    printf("Enter message to hide in image: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // Create message file
    sprintf(message_file, "message.txt");
    message_fp = fopen(message_file, "w");
    fputs(message, message_fp);
    fclose(message_fp);

    // Set image file name
    printf("Enter image file name: ");
    scanf("%s", image_file);

    // Open image file
    image_fp = fopen(image_file, "rb");
    fseek(image_fp, 0, SEEK_END);
    image_size = ftell(image_file);
    fseek(image_fp, 0, SEEK_SET);
    image_data = malloc(image_size);
    fread(image_data, image_size, 1, image_fp);
    fclose(image_fp);

    // Convert message to binary
    message_size = message_length / 8 + (message_length % 8 == 0? 0 : 1);
    for (i = 0; i < message_size; i++) {
        message_char = message[i];
        for (j = 0; j < 8; j++) {
            if (message_char & (1 << j)) {
                pixel_value = MAX_PIXEL_VALUE;
            } else {
                pixel_value = 0;
            }
            image_data[i * 8 + j] = pixel_value;
        }
    }

    // Save modified image
    sprintf(message_file, "message_%d.bmp", time(NULL));
    message_fp = fopen(message_file, "wb");
    fwrite(image_data, image_size, 1, message_fp);
    fclose(message_fp);

    printf("Image saved as %s\n", message_file);

    return 0;
}