//FormAI DATASET v1.0 Category: Image Steganography ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr, *fptr2;
    char filename[100], filename2[100];
    char ch, data[100], newch, temp, temp1;
    int count = 0, i, j;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fptr = fopen(filename, "rb");

    printf("Enter the name of the output file: ");
    scanf("%s", filename2);

    fptr2 = fopen(filename2, "wb");

    printf("Enter data to be hidden in the image: ");
    scanf("%s", data);

    // loop through the data to be hidden
    for (i = 0; data[i] != '\0'; i++)
    {
        // loop through the bits of the character
        for (j = 7; j >= 0; j--)
        {
            // read a character from the image file
            fread(&ch, sizeof(ch), 1, fptr);

            // get the LSB of the current character
            temp = ch & 1;

            // get the bit at the current position in the data
            temp1 = (data[i] >> j) & 1;

            // if the bit in the data is 1, set the LSB of the character to 1
            if (temp1 == 1)
            {
                ch = ch | 1;
            }
            // if the bit in the data is 0, set the LSB of the character to 0
            else
            {
                ch = ch & ~1;
            }

            // write the modified character to the output file
            fwrite(&ch, sizeof(ch), 1, fptr2);

            // increment the count of bits written
            count++;

            // if all the data has been written, exit loop
            if (data[i+1] == '\0' && j == 0)
            {
                break;
            }
            // if a full byte has been written, move to the next byte of data
            if (count == 8)
            {
                i++;
                count = 0;
            }
        }
    }

    fclose(fptr);
    fclose(fptr2);

    return 0;
}