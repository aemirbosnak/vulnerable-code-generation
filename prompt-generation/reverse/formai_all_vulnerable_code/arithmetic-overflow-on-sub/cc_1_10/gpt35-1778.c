//FormAI DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

//Function to perform image steganography
void imageSteganography(char* imageName, char* secretMessage) 
{
    FILE* fptr = fopen(imageName, "rb");
    if(fptr == NULL) 
    {
        printf("File not found!\n");
        return;
    }
 
    fseek(fptr, 0, SEEK_END);
    int endPos = ftell(fptr);
    rewind(fptr);

    //Reading the image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fptr);

    //Extracting the width and height of the image from the header data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int pixelSize = 3;
    int dataSize = width * height * pixelSize;

    if(dataSize >= endPos - 54) 
    {
        printf("Secret Message cannot be encoded!\n");
        return;
    }

    //Reading the data from the image
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * dataSize);
    fread(imageData, sizeof(unsigned char), dataSize, fptr);

    //Encoding the Secret Message into the image data
    for(int i=0, j=0; i<dataSize && j<strlen(secretMessage); i+=3, j++) 
    {
        imageData[i] = (imageData[i] & 0xFE) | ((secretMessage[j] >> 7) & 0x01);
        imageData[i+1] = (imageData[i+1] & 0xFE) | ((secretMessage[j] >> 6) & 0x01);
        imageData[i+2] = (imageData[i+2] & 0xFE) | ((secretMessage[j] >> 5) & 0x01);
    }

    //Creating a new image file for saving the steganographic image
    FILE* newImage = fopen("newImage.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, newImage);
    fwrite(imageData, sizeof(unsigned char), dataSize, newImage);

    fclose(fptr);
    fclose(newImage);
    free(imageData);

    printf("Secret Message successfully encoded in the image!\n");
    printf("New Image saved in the current directory as 'newImage.bmp'\n");
} 

int main() 
{
    printf("Welcome to the world of Image Steganography!\n");
    printf("Where secrets hide in plain sight.\n");

    char imageName[] = "sherlockHolmes.bmp";
    char secretMessage[] = "The game is afoot!";

    printf("Image selected: %s\n", imageName);
    printf("Secret Message to be encoded: %s\n", secretMessage);

    imageSteganography(imageName, secretMessage);

    return 0;
}