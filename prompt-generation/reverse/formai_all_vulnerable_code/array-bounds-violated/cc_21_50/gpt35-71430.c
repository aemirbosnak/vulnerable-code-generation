//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100

int main()
{
    FILE *file;
    char filename[MAX_FILE_NAME];
    int choice;

    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    printf("Select a task to perform:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Flip the image vertically\n");
    printf("3. Increase image brightness\n");
    printf("4. Decrease image brightness\n");
    printf("5. Increase image contrast\n");
    printf("6. Decrease image contrast\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("Error: Couldn't open file.\n");
        exit(0);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];
    int size = 3 * width * height;

    unsigned char imgData[size];
    fread(imgData, sizeof(unsigned char), size, file);
    fclose(file);
	
   switch (choice)
    {
        case 1: // flip the image horizontally
            for(int i = 0, j = 2; i < size; i += 3, j += 3)
            {
                if(j >= width*3)
                {
                    i += (width * 3) - j;
                    j = 0;
                }
                unsigned char temp = imgData[i];
                imgData[i] = imgData[j];
                imgData[j] = temp;
            }
            printf("Image flipped horizontally and saved!\n");
            file = fopen("flipped_horizontal.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, file);
            fwrite(imgData, sizeof(unsigned char), size, file);
            fclose(file);
            break;

        case 2: // flip the image vertically
            for(int i = 0, j = (height-1) * width * 3; i < j; i += width * 3, j -= width * 3)
            {
                for(int k = 0; k < width * 3; k++)
                {
                    unsigned char temp = imgData[i+k];
                    imgData[i+k] = imgData[j+k];
                    imgData[j+k] = temp;
                }
            }
            printf("Image flipped vertically and saved!\n");
            file = fopen("flipped_vertical.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, file);
            fwrite(imgData, sizeof(unsigned char), size, file);
            fclose(file);
            break;

        case 3: // increase image brightness
            for(int i = 0; i < size; i++)
            {
                if(i%3 == 0 && imgData[i] < 255) imgData[i]++;
                if(i%3 == 1 && imgData[i] < 255) imgData[i]++;
                if(i%3 == 2 && imgData[i] < 255) imgData[i]++;
            }
            printf("Image brightness increased and saved!\n");
            file = fopen("brightened.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, file);
            fwrite(imgData, sizeof(unsigned char), size, file);
            fclose(file);
            break;

        case 4: // decrease image brightness
            for(int i = 0; i < size; i++)
            {
                if(i%3 == 0 && imgData[i] > 0) imgData[i]--;
                if(i%3 == 1 && imgData[i] > 0) imgData[i]--;
                if(i%3 == 2 && imgData[i] > 0) imgData[i]--;
            }
            printf("Image brightness decreased and saved!\n");
            file = fopen("darkened.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, file);
            fwrite(imgData, sizeof(unsigned char), size, file);
            fclose(file);
            break;

        case 5: // increase image contrast
            for(int i = 0; i < size; i++)
            {
                if(i%3 == 0) imgData[i] = (imgData[i] - 128) * 1.5 + 128;
                if(i%3 == 1) imgData[i] = (imgData[i] - 128) * 1.5 + 128;
                if(i%3 == 2) imgData[i] = (imgData[i] - 128) * 1.5 + 128;
            }
            printf("Image contrast increased and saved!\n");
            file = fopen("increased_contrast.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, file);
            fwrite(imgData, sizeof(unsigned char), size, file);
            fclose(file);
            break;

        case 6: // decrease image contrast
            for(int i = 0; i < size; i++)
            {
                if(i%3 == 0) imgData[i] = (imgData[i] - 128) / 1.5 + 128;
                if(i%3 == 1) imgData[i] = (imgData[i] - 128) / 1.5 + 128;
                if(i%3 == 2) imgData[i] = (imgData[i] - 128) / 1.5 + 128;
            }
            printf("Image contrast decreased and saved!\n");
            file = fopen("decreased_contrast.bmp", "wb");
            fwrite(header, sizeof(unsigned char), 54, file);
            fwrite(imgData, sizeof(unsigned char), size, file);
            fclose(file);
            break;

        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}