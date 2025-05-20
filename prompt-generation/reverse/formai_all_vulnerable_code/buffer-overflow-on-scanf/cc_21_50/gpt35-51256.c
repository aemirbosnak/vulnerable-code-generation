//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define HEADER 54

int main()
{
    FILE *fptrIn, *fptrOut;
    unsigned char image[HEADER], colorTable[1024], R, G, B, temp;
    int width, height, bitDepth;
    int i, j, r, angle, count = 0;

    char inputFile[100], outputFile[100], choice, rename;
    printf("Enter the name of input file: ");
    scanf("%s", inputFile);

    fptrIn = fopen(inputFile, "rb");

    if (fptrIn == NULL)
    {
        printf("File open error!");
        exit(0);
    }

    //Reading image headers
    for (i = 0; i < HEADER; i++)
    {
        image[i] = getc(fptrIn);
    }

    width = *(int *)&image[18];
    height = *(int *)&image[22];
    bitDepth = *(int *)&image[28];

    // Checking for valid bit depth
    if (bitDepth <= 8)
    {
        printf("%d bit images are not supported.\n", bitDepth);
        fclose(fptrIn);
        exit(0);
    }

    //Allocating memory to store RGB image
    unsigned char img[height][width][3];

    //Reading color table
    if (bitDepth > 8)
    {
        fread(colorTable, sizeof(unsigned char), 1024, fptrIn);
    }

    //read RGB image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            R = getc(fptrIn);
            G = getc(fptrIn);
            B = getc(fptrIn);

            img[i][j][0] = B;
            img[i][j][1] = G;
            img[i][j][2] = R;
        }
    }

    fclose(fptrIn);

    printf("Enter your choice:\n");
    printf("a. Apply grayscale filter\n");
    printf("b. Invert the image\n");
    printf("c. Rotate the image\n");

    scanf("\n%c", &choice);

    switch (choice)
    {
    case 'a': //Grayscale filter
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                temp = 0.21f * img[i][j][2] + 0.72f * img[i][j][1] + 0.07f * img[i][j][0];

                img[i][j][0] = img[i][j][1] = img[i][j][2] = temp;
            }
        }
        printf("Grayscale filter applied.\n");
        break;

    case 'b': //Invert the image
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                img[i][j][0] = 255 - img[i][j][0];
                img[i][j][1] = 255 - img[i][j][1];
                img[i][j][2] = 255 - img[i][j][2];
            }
        }
        printf("Image inverted.\n");
        break;

    case 'c': //Rotate the image
        printf("Enter the angle of rotation: ");
        scanf("%d", &angle);

        angle = angle % 360;
        r = (int)((angle * (3.14159265359 / 180)));

        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                //Rotate about image center
                int cx = height / 2;
                int cy = width / 2;

                int dx = abs(i - cx);
                int dy = abs(j - cy);

                count++; //Counter for testing purposes

                int dxx = (dx * cos(r)) - (dy * sin(r));
                int dyy = (dx * sin(r)) + (dy * cos(r));

                int x_ = dxx + cx;
                int y_ = dyy + cy;

                // Boundary check
                if (x_ < 0 || x_ >= height || y_ < 0 || y_ >= width)
                {
                    continue;
                }

                img[i][j][0] = img[x_][y_][0];
                img[i][j][1] = img[x_][y_][1];
                img[i][j][2] = img[x_][y_][2];
            }
        }
        printf("Image rotated by %d degrees.\n", angle);
        break;
    }

    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    fptrOut = fopen(outputFile, "wb");

    fwrite(image, sizeof(unsigned char), HEADER, fptrOut);

    if (bitDepth > 8)
    {
        fwrite(colorTable, sizeof(unsigned char), 1024, fptrOut);
    }

    //Writing the output image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            putc(img[i][j][0], fptrOut);
            putc(img[i][j][1], fptrOut);
            putc(img[i][j][2], fptrOut);
        }
    }

    fclose(fptrOut);

    printf("Image saved successfully.\n");

    return 0;
}