//FormAI DATASET v1.0 Category: Image Steganography ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Image struct to hold image data
typedef struct {
    int width;
    int height;
    int maxval;
    unsigned char *data;
} Image;

//Function to read image from file
Image* readImage(char *filename) {
    FILE *fp;
    char magicNum[3];
    int width, height, maxval;
    unsigned char *data;
    Image *img;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!");
        return NULL;
    }

    fscanf(fp, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

    if (strcmp(magicNum, "P6") != 0) {
        printf("Error: Wrong file format!");
        return NULL;
    }

    data = (unsigned char *) malloc(width * height * 3);

    fread(data, sizeof(unsigned char), width * height * 3, fp);

    fclose(fp);

    img = (Image *) malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->maxval = maxval;
    img->data = data;

    return img;
}

//Function to write image to file
int writeImage(char *filename, Image *img) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) return -1;

    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, img->maxval);

    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, fp);

    fclose(fp);

    return 0;
}

//Function to hide message in image
void hideMessage(Image *img, char *msg) {
    int i, j, k, index = 0, bit;
    char c;
    int msgLength = strlen(msg);

    //Iterate through each pixel in the image
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            //Iterate through the RGB values of the pixel
            for (k = 0; k < 3; k++) {
                if (index >= msgLength * 8) return; //If no more message to hide, return
                bit = (msg[index / 8] >> (index % 8)) & 1; //Get next bit in message
                index++;

                if (bit) {
                    if (img->data[(i * img->width + j) * 3 + k] < 255) img->data[(i * img->width + j) * 3 + k]++; //If bit is 1, increase value by 1 if it is not already at max
                } else {
                    if (img->data[(i * img->width + j) * 3 + k] > 0) img->data[(i * img->width + j) * 3 + k]--; //If bit is 0, decrease value by 1 if it is not already at min
                }
            }
        }
    }
}

//Function to retrieve message from image
char* retrieveMessage(Image *img) {
    int i, j, k, index = 0, bit;
    char c = 0;
    char *msg = (char *) malloc(sizeof(char) * ((img->width * img->height * 3) / 8));

    //Iterate through each pixel in the image
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            //Iterate through the RGB values of the pixel
            for (k = 0; k < 3; k++) {
                bit = img->data[(i * img->width + j) * 3 + k] & 1; //Get the least significant bit of the RGB value
                c |= bit << (index % 8); //Add the bit to the current character being formed
                index++;

                if (index % 8 == 0) { //If the current character is complete, add it to the message
                    msg[(index / 8) - 1] = c;
                    c = 0;
                }
            }
        }
    }

    return msg;
}

//Main method
int main() {
    Image *img;
    char *msg = "This is a secret message";
    char *retMsg;

    //Read image from file
    img = readImage("image.ppm");

    //Hide message in image
    hideMessage(img, msg);

    //Write image with hidden message to file
    writeImage("image_hidden.ppm", img);

    //Retrieve message from image
    retMsg = retrieveMessage(img);

    printf("Original message: %s\nRetrieved message: %s\n", msg, retMsg);

    free(img->data);
    free(img);
    free(retMsg);

    return 0;
}