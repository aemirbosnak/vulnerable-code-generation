//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define BMPHEADER_SIZE 54

int main(int argc, char* argv[])
{
    if(argc < 5)
    {
        printf("Usage: %s <input_image.bmp> <output_image.bmp> <bri_adj> <con_adj>\n", argv[0]);
        printf("Note: bri_adj = brightness adjustment, con_adj = contrast adjustment\n");
        return 1;
    }
    
    char* input_file = argv[1];
    char* output_file = argv[2];
    int bri_adj = atoi(argv[3]);
    float con_adj = atof(argv[4]);
    
    FILE* fin = fopen(input_file, "rb");
    if(!fin)
    {
        printf("Error! Cannot open %s for reading\n", input_file);
        return 1;
    }
    
    fseek(fin, 0, SEEK_END);
    int size = ftell(fin) - BMPHEADER_SIZE;
    fseek(fin, BMPHEADER_SIZE, SEEK_SET);
    unsigned char* buffer = (unsigned char*)malloc(size);
    fread(buffer, size, 1, fin);
    fclose(fin);
    
    int width = *(int*)&buffer[18];
    int height = *(int*)&buffer[22];
    int bit_depth = *(int*)&buffer[28];
    
    if(bit_depth != 24)
    {
        printf("Error! Invalid bit depth\n");
        return 1;
    }
    
    int padding = (4 - (width * 3) % 4) % 4;
    
    unsigned char* output_buffer = (unsigned char*)malloc(size);
    for(int i = 0; i < size; i++) output_buffer[i] = buffer[i];
    
    unsigned char* p = output_buffer;
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int index = y * (width * 3 + padding) + x * 3;
            unsigned char blue = buffer[index];
            unsigned char green = buffer[index+1];
            unsigned char red = buffer[index+2];
            
            // Brightness adjustment
            blue += bri_adj;
            if(blue > 255) blue = 255;
            if(blue < 0) blue = 0;
            green += bri_adj;
            if(green > 255) green = 255;
            if(green < 0) green = 0;
            red += bri_adj;
            if(red > 255) red = 255;
            if(red < 0) red = 0;
            
            // Contrast adjustment
            blue = (unsigned char)((blue - 128) * con_adj + 128);
            if(blue > 255) blue = 255;
            if(blue < 0) blue = 0;
            green = (unsigned char)((green - 128) * con_adj + 128);
            if(green > 255) green = 255;
            if(green < 0) green = 0;
            red = (unsigned char)((red - 128) * con_adj + 128);
            if(red > 255) red = 255;
            if(red < 0) red = 0;
            
            p[index] = blue;
            p[index+1] = green;
            p[index+2] = red;
        }
    }
    
    free(buffer);
    
    FILE* fout = fopen(output_file, "wb");
    if(!fout)
    {
        printf("Error! Cannot open %s for writing\n", output_file);
        return 1;
    }
    fwrite(output_buffer, size, 1, fout);
    fclose(fout);
    
    free(output_buffer);
    
    return 0;
}