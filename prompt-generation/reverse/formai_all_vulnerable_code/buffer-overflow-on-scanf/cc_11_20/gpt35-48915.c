//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[100];
    unsigned char *image_data;
    unsigned char *output_data;
    unsigned char header[54];
    unsigned int image_width,image_height;
    int brightness,contrast;
    int i,j,k;
    int r,g,b;
    
    printf("Enter the input image filename: ");
    scanf("%s",filename);
    
    printf("Enter the brightness adjustment (-255 to 255): ");
    scanf("%d",&brightness);
    
    printf("Enter the contrast adjustment (-100 to 100): ");
    scanf("%d",&contrast);
    
    file = fopen(filename,"rb");
    
    if(file == NULL)
    {
        printf("Error: Unable to open file!\n");
        return 1;
    }
    
    for(i = 0; i < 54; i++)
    {
        header[i] = getc(file);
    }
    
    image_width = header[18] + (header[19] * 256) + (header[20] * 256 * 256) + (header[21] * 256 * 256 * 256);
    image_height = header[22] + (header[23] * 256) + (header[24] * 256 * 256) + (header[25] * 256 * 256 * 256);
    
    image_data = (unsigned char*)malloc(image_width * image_height * 3);
    output_data = (unsigned char*)malloc(image_width * image_height * 3);
    
    fread(image_data,1,image_width * image_height * 3,file);
    fclose(file);
    
    for(i = 0; i < image_height; i++)
    {
        for(j = 0; j < image_width; j++)
        {
            r = image_data[(i * image_width + j) * 3];
            g = image_data[(i * image_width + j) * 3 + 1];
            b = image_data[(i * image_width + j) * 3 + 2];
            
            r += brightness;
            g += brightness;
            b += brightness;
            
            r = r * (100 + contrast) / 100;
            g = g * (100 + contrast) / 100;
            b = b * (100 + contrast) / 100;
            
            if(r > 255)
                r = 255;
            if(g > 255)
                g = 255;
            if(b > 255)
                b = 255;
            if(r < 0)
                r = 0;
            if(g < 0)
                g = 0;
            if(b < 0)
                b = 0;
                
            output_data[(i * image_width + j) * 3] = r;
            output_data[(i * image_width + j) * 3 + 1] = g;
            output_data[(i * image_width + j) * 3 + 2] = b;
        }
    }
    
    // image flipping task
    for(i = 0; i < image_height/2; i++)
    {
        for(j = 0; j < image_width; j++)
        {
            k = (image_height - 1 - i) * image_width + j;
            int temp_r = output_data[(i * image_width + j) * 3];
            int temp_g = output_data[(i * image_width + j) * 3 + 1];
            int temp_b = output_data[(i * image_width + j) * 3 + 2];
            
            output_data[(i * image_width + j) * 3] = output_data[(k) * 3];
            output_data[(i * image_width + j) * 3 + 1] = output_data[(k) * 3 + 1];
            output_data[(i * image_width + j) * 3 + 2] = output_data[(k) * 3 + 2];
            
            output_data[(k) * 3] = temp_r;
            output_data[(k) * 3 + 1] = temp_g;
            output_data[(k) * 3 + 2] = temp_b;
        }
    }
    
    // write the output image
    char output_filename[] = "output.bmp";
    FILE *fp;
    fp = fopen(output_filename,"wb");
    fwrite(header,1,54,fp);
    fwrite(output_data,1,image_width * image_height * 3,fp);
    fclose(fp);
    
    printf("Image processing completed successfully!\n");
    
    return 0;
}