//FormAI DATASET v1.0 Category: Image Editor ; Style: curious
#include<stdio.h>

// A curious C program for image editing

int main() {

    printf("Welcome to Curious Image Editor\n");
    
    char fileName[50];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    
    FILE *filePointer;
    filePointer = fopen(fileName, "rb");
    
    if(filePointer == NULL) {
        printf("Error: File not found.");
        return 0;
    }
    
    printf("\n1. Black and white\n");
    printf("2. Invert colors\n");
    printf("3. Sepia\n");
    printf("4. Grayscale\n");
    printf("5. Exit\n");
    
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            // Convert image to black and white
            printf("\nConverting image to black and white...\n");
            unsigned char header[54];
            fread(header, sizeof(unsigned char), 54, filePointer);
            int width = *(int*)&header[18];
            int height = *(int*)&header[22];
            int padding = 0;
            if ((width * 3) % 4 != 0) {
                padding = 4 - (width * 3) % 4;
            }
            FILE* newFilePointer;
            newFilePointer = fopen("new_image.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, newFilePointer);
            unsigned char pixel[3];
            int average;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    fread(pixel, sizeof(unsigned char), 3, filePointer);
                    average = (pixel[0] + pixel[1] + pixel[2]) / 3;
                    pixel[0] = pixel[1] = pixel[2] = average;
                    fwrite(pixel, sizeof(unsigned char), 3, newFilePointer);
                }
                fread(pixel, sizeof(unsigned char), padding, filePointer);
                fwrite(pixel, sizeof(unsigned char), padding, newFilePointer);
            }
            printf("Image converted to black and white successfully.");
            fclose(newFilePointer);
            break;
        }
        case 2: {
            // Invert image colors
            printf("\nInverting image colors...\n");
            unsigned char header[54];
            fread(header, sizeof(unsigned char), 54, filePointer);
            int width = *(int*)&header[18];
            int height = *(int*)&header[22];
            int padding = 0;
            if ((width * 3) % 4 != 0) {
                padding = 4 - (width * 3) % 4;
            }
            FILE* newFilePointer;
            newFilePointer = fopen("new_image.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, newFilePointer);
            unsigned char pixel[3];
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    fread(pixel, sizeof(unsigned char), 3, filePointer);
                    pixel[0] = 255 - pixel[0];
                    pixel[1] = 255 - pixel[1];
                    pixel[2] = 255 - pixel[2];
                    fwrite(pixel, sizeof(unsigned char), 3, newFilePointer);
                }
                fread(pixel, sizeof(unsigned char), padding, filePointer);
                fwrite(pixel, sizeof(unsigned char), padding, newFilePointer);
            }
            printf("Image colors inverted successfully.");
            fclose(newFilePointer);
            break;
        }
        case 3: {
            // Convert image to sepia
            printf("\nConverting image to sepia...\n");
            unsigned char header[54];
            fread(header, sizeof(unsigned char), 54, filePointer);
            int width = *(int*)&header[18];
            int height = *(int*)&header[22];
            int padding = 0;
            if ((width * 3) % 4 != 0) {
                padding = 4 - (width * 3) % 4;
            }
            FILE* newFilePointer;
            newFilePointer = fopen("new_image.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, newFilePointer);
            unsigned char pixel[3];
            int red, green, blue;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    fread(pixel, sizeof(unsigned char), 3, filePointer);
                    red = pixel[0] * 0.393 + pixel[1] * 0.769 + pixel[2] * 0.189;
                    green = pixel[0] * 0.349 + pixel[1] * 0.686 + pixel[2] * 0.168;
                    blue = pixel[0] * 0.272 + pixel[1] * 0.534 + pixel[2] * 0.131;
                    if (red > 255) {
                        red = 255;
                    }
                    if (green > 255) {
                        green = 255;
                    }
                    if (blue > 255) {
                        blue = 255;
                    }
                    pixel[0] = red;
                    pixel[1] = green;
                    pixel[2] = blue;
                    fwrite(pixel, sizeof(unsigned char), 3, newFilePointer);
                }
                fread(pixel, sizeof(unsigned char), padding, filePointer);
                fwrite(pixel, sizeof(unsigned char), padding, newFilePointer);
            }
            printf("Image converted to sepia successfully.");
            fclose(newFilePointer);
            break;
        }
        case 4: {
            // Convert image to grayscale
            printf("\nConverting image to grayscale...\n");
            unsigned char header[54];
            fread(header, sizeof(unsigned char), 54, filePointer);
            int width = *(int*)&header[18];
            int height = *(int*)&header[22];
            int padding = 0;
            if ((width * 3) % 4 != 0) {
                padding = 4 - (width * 3) % 4;
            }
            FILE* newFilePointer;
            newFilePointer = fopen("new_image.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, newFilePointer);
            unsigned char pixel[3];
            int average;
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    fread(pixel, sizeof(unsigned char), 3, filePointer);
                    average = (pixel[0] + pixel[1] + pixel[2]) / 3;
                    pixel[0] = pixel[1] = pixel[2] = average;
                    fwrite(pixel, sizeof(unsigned char), 3, newFilePointer);
                }
                fread(pixel, sizeof(unsigned char), padding, filePointer);
                fwrite(pixel, sizeof(unsigned char), padding, newFilePointer);
            }
            printf("Image converted to grayscale successfully.");
            fclose(newFilePointer);
            break;
        }
        case 5: {
            // Exit
            printf("\nExiting Curious Image Editor...");
            break;
        }
        default:
            printf("\nInvalid choice.");
            break;
    }
    
    fclose(filePointer);
    
    return 0;
}