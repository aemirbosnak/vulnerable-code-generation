//FormAI DATASET v1.0 Category: Image Steganography ; Style: futuristic
/**
 * @file    ImageSteganography.c
 * @author  Your Name
 * @date    01/01/2100
 *
 * @brief   This program performs image steganography by hiding a secret message in an image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 10000
#define MAX_IMG_SIZE 1000000

typedef struct {
    char magic_num[3];
    int width;
    int height;
    int max_val;
    unsigned char *data;
} Image;

/**
 * @brief   This function reads a PPM file and returns a pointer to an Image struct.
 */
Image *read_image(char file_name[]) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file <%s>.\n", file_name);
        exit(1);
    }

    Image *img_ptr = (Image *)malloc(sizeof(Image));
    fscanf(fp, "%s %d %d %d", img_ptr->magic_num, &img_ptr->width, &img_ptr->height, &img_ptr->max_val);

    img_ptr->data = (unsigned char *)malloc(img_ptr->width * img_ptr->height * 3);
    fread(img_ptr->data, 1, img_ptr->width * img_ptr->height * 3, fp);

    fclose(fp);

    return img_ptr;
}

/**
 * @brief   This function writes an Image struct to a PPM file.
 */
void write_image(char file_name[], Image *img_ptr) {
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error: Could not open file <%s>.\n", file_name);
        exit(1);
    }

    fprintf(fp, "%s\n%d %d\n%d\n", img_ptr->magic_num, img_ptr->width, img_ptr->height, img_ptr->max_val);
    fwrite(img_ptr->data, 1, img_ptr->width * img_ptr->height * 3, fp);

    fclose(fp);
}

/**
 * @brief   This function reads a message from a text file.
 */
char *read_message(char file_name[]) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file <%s>.\n", file_name);
        exit(1);
    }

    char *msg_ptr = (char *)malloc(MAX_MSG_LEN * sizeof(char));
    fgets(msg_ptr, MAX_MSG_LEN, fp);

    fclose(fp);

    return msg_ptr;
}

/**
 * @brief   This function hides a message in an image by modifying the lowest bit of each pixel value in the red channel.
 */
void hide_message(Image *img_ptr, char *msg_ptr) {
    int img_size = img_ptr->width * img_ptr->height * 3;
    int msg_len = strlen(msg_ptr);

    if (msg_len * 8 + 8 > img_size) {
        printf("Error: Message is too long to be hidden in this image.\n");
        exit(1);
    }

    int i, j, k, byte_idx, bit_idx, bit_val, pixel_val;
    byte_idx = 0;
    bit_idx = 0;
    bit_val = 0;

    for (i = 0; i < img_size; i += 3) {
        if (byte_idx == msg_len && bit_idx == 8) {
            break;
        }

        pixel_val = (int)img_ptr->data[i];
        bit_val = (byte_idx < msg_len) ? ((msg_ptr[byte_idx] >> bit_idx) & 1) : 0;
        pixel_val = (pixel_val & 0xFE) | bit_val;
        img_ptr->data[i] = (unsigned char)pixel_val;

        bit_idx++;
        if (bit_idx == 8) {
            byte_idx++;
            bit_idx = 0;
        }
    }

    printf("Message hidden successfully!\n");
}

/**
 * @brief   This function extracts a message from an image by reading the lowest bit of each pixel value in the red channel.
 */
char *extract_message(Image *img_ptr) {
    int img_size = img_ptr->width * img_ptr->height * 3;
    char *msg_ptr = (char *)malloc(MAX_MSG_LEN * sizeof(char));

    int i, j, k, byte_idx, bit_idx, bit_val, pixel_val;
    byte_idx = 0;
    bit_idx = 0;
    bit_val = 0;

    for (i = 0; i < img_size; i += 3) {
        if (byte_idx == MAX_MSG_LEN && bit_idx == 8) {
            break;
        }

        pixel_val = (int)img_ptr->data[i];
        bit_val = pixel_val & 1;
        msg_ptr[byte_idx] = (msg_ptr[byte_idx] << 1) | bit_val;

        bit_idx++;
        if (bit_idx == 8) {
            byte_idx++;
            bit_idx = 0;
        }
    }

    printf("Message extracted successfully!\n");

    return msg_ptr;
}

int main() {
    char img_file_name[] = "image.ppm";
    char msg_file_name[] = "message.txt";

    Image *img_ptr = read_image(img_file_name);
    char *msg_ptr = read_message(msg_file_name);

    printf("Image dimensions: %d x %d\n", img_ptr->width, img_ptr->height);
    printf("Max pixel value: %d\n", img_ptr->max_val);
    printf("Message length: %d\n", strlen(msg_ptr));

    hide_message(img_ptr, msg_ptr);
    char *extracted_msg_ptr = extract_message(img_ptr);

    printf("Extracted message: %s\n", extracted_msg_ptr);

    write_image("image_with_msg.ppm", img_ptr);

    free(img_ptr->data);
    free(img_ptr);
    free(msg_ptr);
    free(extracted_msg_ptr);

    return 0;
}