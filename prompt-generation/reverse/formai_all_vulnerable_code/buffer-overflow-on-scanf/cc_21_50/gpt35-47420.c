//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *input, *output;
    int width, height, img_type, quality, i, j, brightness, contrast;
    unsigned char *pixels, *dpixels, *ipixels;
    char infile[255], outfile[255];

    printf("\nEnter the input filename: ");
    scanf("%s", infile);

    printf("\nEnter the output filename: ");
    scanf("%s", outfile);

    printf("\nEnter the brightness level (0-255): ");
    scanf("%d", &brightness);

    printf("\nEnter the contrast level (-127 to 127): ");
    scanf("%d", &contrast);

    input = fopen(infile, "rb");
    output = fopen(outfile, "wb");

    if(!input)
    {
        printf("\nError opening input file!");
        return -1;
    }

    if(!output)
    {
        printf("\nError opening output file!");
        fclose(input);
        return -1;
    }

    fread(&img_type, sizeof(unsigned char), 1, input);

    if(img_type != 'P' && img_type != 'p')
    {
        printf("\nInvalid image format!");
        fclose(input);
        fclose(output);
        return -1;
    }

    fread(&img_type, sizeof(char), 1, input);

    if(img_type != '6')
    {
        printf("\nInvalid image format!");
        fclose(input);
        fclose(output);
        return -1;
    }

    fscanf(input, "%d %d %d", &width, &height, &quality);

    if(quality != 255)
    {
        printf("\nInvalid image format!");
        fclose(input);
        fclose(output);
        return -1;
    }

    pixels = (unsigned char*)malloc(width*height*3);
    dpixels = (unsigned char*)malloc(width*height*3);
    ipixels = (unsigned char*)malloc(width*height*3);

    fread(pixels, sizeof(unsigned char), width*height*3, input);
    fclose(input);

    if(brightness != 0)
    {
        for(i = 0; i<height; i++)
        {
            for(j = 0; j<width; j++)
            {
                if(pixels[i*width*3+j*3]+brightness <0)
                {
                    dpixels[i*width*3+j*3] = 0;
                }
                else if(pixels[i*width*3+j*3]+brightness > 255)
                {
                    dpixels[i*width*3+j*3] = 255;
                }
                else
                {
                    dpixels[i*width*3+j*3] = pixels[i*width*3+j*3]+brightness;
                }

                if(pixels[i*width*3+j*3+1]+brightness <0)
                {
                    dpixels[i*width*3+j*3+1] = 0;
                }
                else if(pixels[i*width*3+j*3+1]+brightness > 255)
                {
                    dpixels[i*width*3+j*3+1] = 255;
                }
                else
                {
                    dpixels[i*width*3+j*3+1] = pixels[i*width*3+j*3+1]+brightness;
                }

                if(pixels[i*width*3+j*3+2]+brightness <0)
                {
                    dpixels[i*width*3+j*3+2] = 0;
                }
                else if(pixels[i*width*3+j*3+2]+brightness > 255)
                {
                    dpixels[i*width*3+j*3+2] = 255;
                }
                else
                {
                    dpixels[i*width*3+j*3+2] = pixels[i*width*3+j*3+2]+brightness;
                }
            }
        }
    }
    else
    {
        for(i = 0; i<height; i++)
        {
            for(j = 0; j<width; j++)
            {
                dpixels[i*width*3+j*3] = pixels[i*width*3+j*3];
                dpixels[i*width*3+j*3+1] = pixels[i*width*3+j*3+1];
                dpixels[i*width*3+j*3+2] = pixels[i*width*3+j*3+2];
            }
        }
    }

    if(contrast != 0)
    {
        float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

        for(i = 0; i<height; i++)
        {
            for(j = 0; j<width; j++)
            {
                int r = dpixels[i*width*3+j*3], g = dpixels[i*width*3+j*3+1], b = dpixels[i*width*3+j*3+2];

                r = factor * (r - 128) + 128;
                g = factor * (g - 128) + 128;
                b = factor * (b - 128) + 128;

                if(r<0)
                {
                    r = 0;
                }
                else if(r>255)
                {
                    r = 255;
                }

                if(g<0)
                {
                    g = 0;
                }
                else if(g>255)
                {
                    g = 255;
                }

                if(b<0)
                {
                    b = 0;
                }
                else if(b>255)
                {
                    b = 255;
                }

                ipixels[i*width*3+j*3] = r;
                ipixels[i*width*3+j*3+1] = g;
                ipixels[i*width*3+j*3+2] = b;
            }
        }
    }
    else
    {
        for(i = 0; i<height; i++)
        {
            for(j = 0; j<width; j++)
            {
                ipixels[i*width*3+j*3] = dpixels[i*width*3+j*3];
                ipixels[i*width*3+j*3+1] = dpixels[i*width*3+j*3+1];
                ipixels[i*width*3+j*3+2] = dpixels[i*width*3+j*3+2];
            }
        }
    }

    fwrite("P6\n", sizeof(char), 3, output);

    char string[255];
    sprintf(string,"%d %d\n", width, height);
    fwrite(string, sizeof(char), strlen(string), output);

    fwrite("255\n", sizeof(char), 4, output);
    fwrite(ipixels, sizeof(unsigned char), width*height*3, output);
    fclose(output);

    free(pixels);
    free(dpixels);
    free(ipixels);

    printf("\nImage Processing Done!");

    return 0;
}