//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include<stdio.h>
#include<limits.h>

//Function to get the binary representation of an integer
void getBinary(int num, int binary[])
{
    int i=0;
    while(num>0)
    {
        binary[i++] = num % 2;
        num = num / 2;
    }
    //Padding with zeros if necessary
    while(i<CHAR_BIT)
    {
        binary[i++] = 0;
    }
}

int main()
{
    char msg[256], steg[256], cover[256], fileIn[20], fileOut[20];
    int length, i, j, k, binary[CHAR_BIT], bitCount=0, buffer=0;
    FILE *fpIn, *fpOut;

    //Get the secret message to be embedded
    printf("Enter the secret message: ");
    fgets(msg, 256, stdin);

    //Get the file name of the cover image
    printf("Enter the file name of the cover image: ");
    fgets(fileIn, 20, stdin);

    //Get the file name of the steganographed image
    printf("Enter the file name of the steganographed image: ");
    fgets(fileOut, 20, stdin);

    //Open the cover image file
    fpIn = fopen(fileIn, "rb");

    //Read the contents of the cover image file
    length = fread(cover, 1, 256, fpIn);
    
    //Close the cover image file
    fclose(fpIn);

    //Embedding process
    for(i=0; i<length; i++)
    {
        //Get the binary representation of the cover byte
        getBinary(cover[i], binary);
        for(j=0; j<CHAR_BIT; j++)
        {
            if(bitCount>=strlen(msg)*CHAR_BIT)
            {
                //If all bits of the secret message is already embedded, break the loop
                break;
            }
            if(j>=CHAR_BIT-8)
            {
                //Embed the secret message bits
                binary[j] = msg[bitCount/CHAR_BIT] & (1 << bitCount % CHAR_BIT);
                bitCount++;
            }
            //Update the buffer
            buffer |= binary[j] << (CHAR_BIT-1-j);
            if(bitCount % CHAR_BIT == 0)
            {
                //When the buffer is full, embed it to the steganographed image
                steg[k++] = buffer;
                buffer = 0;
            }
        }
    }

    //Copy the remaining bytes of the cover image to the steganographed image
    for(i=length; i<256; i++)
    {
        steg[k++] = cover[i];
    }

    //Write the contents of the steganographed image to the output file
    fpOut = fopen(fileOut, "wb");
    fwrite(steg, 1, k, fpOut);
    fclose(fpOut);

    printf("Steganography successful!\n");

    return 0;
}