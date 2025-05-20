//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//function to insert binary watermark
int watermarkInsertion(int pixel, int bit)
{
    if(bit == 0)
        pixel = pixel & ~(1 << 0); //clears the LSB
    else
        pixel = pixel | (1 << 0); //sets the LSB
    
    return pixel;
}

//function to extract binary watermark
int watermarkExtraction(int pixel)
{
    int bit = pixel & 1; //extracts the LSB
    return bit;
}

int main()
{
    FILE *inputImage, *outputImage; //file pointers for input and output image
    int height, width, maxVal; //variables to store image height, weight and max value
    int red, green, blue; //variables to store RGB values
    int watermark = 1010010101010101; //binary watermark to be inserted
    
    inputImage = fopen("inputImage.ppm", "rb");
    outputImage = fopen("outputImage.ppm", "wb");
    
    fscanf(inputImage, "%*s %d %d %d", &width, &height, &maxVal); //skips P6 and reads width, height, maxVal
    
    //writes header and dimensions of output image
    fprintf(outputImage, "P6\n%d %d\n%d\n", width, height, maxVal);
    
    //iterating over each pixel
    for(int i = 0; i < width*height; i++)
    {
        fread(&red, 1, 1, inputImage); //reads red pixel
        fread(&green, 1, 1, inputImage); //reads green pixel
        fread(&blue, 1, 1, inputImage); //reads blue pixel
        
        //inserting watermark in blue pixel
        blue = watermarkInsertion(blue, watermarkExtraction(watermark));
        watermark = watermark >> 1; //right shift by 1 bit for next iteration
        
        //writing RGB values to output image
        fwrite(&red, 1, 1, outputImage);
        fwrite(&green, 1, 1, outputImage);
        fwrite(&blue, 1, 1, outputImage);
    }
    
    fclose(inputImage); //closing input image file
    fclose(outputImage); //closing output image file
    
    printf("Watermark inserted successfully!");
    return 0;
}