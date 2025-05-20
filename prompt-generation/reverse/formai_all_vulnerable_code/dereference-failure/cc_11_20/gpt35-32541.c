//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fIn = fopen("input_image.bmp","r");  // Input image file name
    FILE *fOut = fopen("output_image.bmp","w+");  // Output image file name

    int i;
    unsigned char header[54];  // BMP header
    unsigned int dataPos;  // Image data position
    unsigned int width, height;  
    unsigned int imageSize;  // Image size = width * height * 3
    unsigned char *data;  

   if (fIn == NULL)  // Check if image file exists
      exit(EXIT_FAILURE);

   if (fread(header, 1, 54, fIn) != 54)  // Read BMP header
      exit(EXIT_FAILURE);

   if (header[0] != 'B' || header[1] != 'M')  // Check if BMP format is correct
      exit(EXIT_FAILURE);

   dataPos = *(int*)&(header[0x0A]);
   imageSize = *(int*)&(header[0x22]);
   width = *(int*)&(header[0x12]);
   height = *(int*)&(header[0x16]);

    if (imageSize == 0)                           
        imageSize = width * height * 3;            

    if (dataPos == 0)                             
        dataPos = 54;                               

    data = (unsigned char *)malloc(imageSize);    
    fread(data, 1, imageSize, fIn);                

    // Flip image vertically
    unsigned char *flippedData = (unsigned char *)malloc(imageSize);
    for(i = 0; i < height; i++){
        memcpy(flippedData+(height-1-i)*width*3, data+i*width*3, width*3);
    }
    // Adjust brightness and contrast
    for(i = 0; i < imageSize; i+=3){
        int newValue = (int)data[i] + 50;  // Increase brightness by 50
        if(newValue > 255){
            newValue = 255;
        }
        flippedData[i] = (unsigned char)newValue;

        newValue = ((int)data[i+1] - 128)*2 + 128;  // Increase contrast by 2
        if(newValue > 255){
            newValue = 255;
        }
        else if(newValue < 0){
            newValue = 0;
        }
        flippedData[i+1] = (unsigned char)newValue;

        newValue = ((int)data[i+2] - 128)*0.5 + 128;  // Decrease contrast by half
        if(newValue > 255){
            newValue = 255;
        }
        else if(newValue < 0){
            newValue = 0;
        }
        flippedData[i+2] = (unsigned char)newValue;
    }

    // Write output image
    fwrite(header, 1, 54, fOut);
    fwrite(flippedData, 1, imageSize, fOut);

    fclose(fIn);
    fclose(fOut);
    free(data);
    free(flippedData);

    return 0;
}