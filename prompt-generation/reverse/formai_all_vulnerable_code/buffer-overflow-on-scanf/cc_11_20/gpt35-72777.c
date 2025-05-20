//FormAI DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2, *fptr3;
    char filename1[100], filename2[100], filename3[100];
    char c, secret_msg[1000];
    int len=0, i, j=0, bit=0, count=0;
    
    // Input file with secret message
    printf("Enter the file name containing the secret message: ");
    scanf("%s", filename1);
    fptr1 = fopen(filename1, "r");
    
    // Input image file
    printf("Enter the file name of the image: ");
    scanf("%s", filename2);
    fptr2 = fopen(filename2, "rb");
    
    // Output file name with embedded message
    printf("Enter the output file name: ");
    scanf("%s", filename3);
    fptr3 = fopen(filename3, "wb");
    
    if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL)
    {
        printf("Error! Could not open files\n");
        exit(1);
    }
    
    // Read secret message and calculate length
    while ((c = fgetc(fptr1)) != EOF)
    {
        secret_msg[len] = c;
        len++;
    }
    
    // Check if message can be embedded in image file
    fseek(fptr2, 0, SEEK_END);
    int image_size = ftell(fptr2);
    fseek(fptr2, 0, SEEK_SET);
    int max_len = image_size * 0.125;
    if (len > max_len)
    {
        printf("Error! Secret message size too large to be embedded in image\n");
        exit(1);
    }
    
    // Embed the secret message in image
    while ((c = fgetc(fptr2)) != EOF && j < len)
    {
        for (i=0; i<8; i++)
        {
            bit = ((secret_msg[j] >> i) & 1);
            c = ((c & 0xFE) | bit);
            fprintf(fptr3, "%c", c);
            count++;
            if (count == image_size)
            {
                break;
            }
        }
        j++;
        if (count == image_size)
        {
            break;
        }
    }
    
    // Copy remaining image data to output file
    while ((c = fgetc(fptr2)) != EOF)
    {
        fprintf(fptr3, "%c", c);
    }
    
    printf("Secret message embedded successfully\n");
    
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    
    return 0;
}