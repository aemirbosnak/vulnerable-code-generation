//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE unsigned char

/* bit extraction macros */
#define EXTRACT_BIT(x,n) ((x) & (1 << (n)))
#define BITS_TO_BYTE(b7,b6,b5,b4,b3,b2,b1,b0) ((b7 << 7) | (b6 << 6) | (b5 << 5) | (b4 << 4) | (b3 << 3) | (b2 << 2) | (b1 << 1) | b0)

/* image header structure */
typedef struct
{
    BYTE type[2];
    unsigned int fileSize;
    unsigned int reserved;
    unsigned int pixelOffset;
} BMP_HEADER;

/* image data structure */
typedef struct
{
    unsigned int headerSize;
    int width;
    int height;
    unsigned short int numPlanes;
    unsigned short int depth;
    unsigned int compression;
    unsigned int imageSize;
    int xres;
    int yres;
    unsigned int numColors;
    unsigned int importantColors;
} BMP_IMAGE;

/* read bmp header from input file */
void readBmpHeader(FILE *fp, BMP_HEADER *header)
{
    fread(header->type, sizeof(BYTE), 2, fp);
    fread(&(header->fileSize), sizeof(unsigned int), 1, fp);
    fread(&(header->reserved), sizeof(unsigned int), 1, fp);
    fread(&(header->pixelOffset), sizeof(unsigned int), 1, fp);
}

/* read bmp image data from input file */
void readBmpImage(FILE *fp, BMP_IMAGE *image)
{
    fread(&(image->headerSize), sizeof(unsigned int), 1, fp);
    fread(&(image->width), sizeof(int), 1, fp);
    fread(&(image->height), sizeof(int), 1, fp);
    fread(&(image->numPlanes), sizeof(unsigned short int), 1, fp);
    fread(&(image->depth), sizeof(unsigned short int), 1, fp);
    fread(&(image->compression), sizeof(unsigned int), 1, fp);
    fread(&(image->imageSize), sizeof(unsigned int), 1, fp);
    fread(&(image->xres), sizeof(int), 1, fp);
    fread(&(image->yres), sizeof(int), 1, fp);
    fread(&(image->numColors), sizeof(unsigned int), 1, fp);
    fread(&(image->importantColors), sizeof(unsigned int), 1, fp);
}

/* write bmp header to output file */
void writeBmpHeader(FILE *fp, BMP_HEADER *header)
{
    fwrite(header->type, sizeof(BYTE), 2, fp);
    fwrite(&(header->fileSize), sizeof(unsigned int), 1, fp);
    fwrite(&(header->reserved), sizeof(unsigned int), 1, fp);
    fwrite(&(header->pixelOffset), sizeof(unsigned int), 1, fp);
}

/* write bmp image data to output file */
void writeBmpImage(FILE *fp, BMP_IMAGE *image)
{
    fwrite(&(image->headerSize), sizeof(unsigned int), 1, fp);
    fwrite(&(image->width), sizeof(int), 1, fp);
    fwrite(&(image->height), sizeof(int), 1, fp);
    fwrite(&(image->numPlanes), sizeof(unsigned short int), 1, fp);
    fwrite(&(image->depth), sizeof(unsigned short int), 1, fp);
    fwrite(&(image->compression), sizeof(unsigned int), 1, fp);
    fwrite(&(image->imageSize), sizeof(unsigned int), 1, fp);
    fwrite(&(image->xres), sizeof(int), 1, fp);
    fwrite(&(image->yres), sizeof(int), 1, fp);
    fwrite(&(image->numColors), sizeof(unsigned int), 1, fp);
    fwrite(&(image->importantColors), sizeof(unsigned int), 1, fp);
}

/* hide the message in the image */
void hideMessage(FILE *inFile, FILE *outFile, char *message)
{
    BMP_HEADER header;
    BMP_IMAGE image;
    unsigned int numPixels;
    int count = 0;
    int numBitsRemaining = strlen(message) * 8;
    BYTE curByte = 0;
    int bitIndex = 0;

    /* read bmp header and image data */
    readBmpHeader(inFile, &header);
    readBmpImage(inFile, &image);

    /* set up output bmp header and image data */
    BMP_HEADER outHeader = header;
    BMP_IMAGE outImage = image;

    numPixels = image.width * image.height;

    /* write bmp header and image data to output file */
    writeBmpHeader(outFile, &outHeader);
    writeBmpImage(outFile, &outImage);

    /* process each pixel in the image */
    for (unsigned int i = 0; i < numPixels; ++i)
    {
        /* read the pixel color data */
        BYTE blue, green, red;
        fread(&blue, sizeof(BYTE), 1, inFile);
        fread(&green, sizeof(BYTE), 1, inFile);
        fread(&red, sizeof(BYTE), 1, inFile);

        /* hide the message bits in the blue, green, and red values of the pixel */
        for (int j = 0; j < 8; ++j)
        {
            /* check if there are bits remaining in the message */
            if (numBitsRemaining > 0)
            {
                /* extract next bit from message */
                int curBit = EXTRACT_BIT(message[count], bitIndex);
                /* set the corresponding bit in the current byte */
                curByte |= (curBit << (7 - bitIndex));

                ++bitIndex;

                /* check if the current byte is full */
                if (bitIndex == 8)
                {
                    fwrite(&curByte, sizeof(BYTE), 1, outFile);
                    curByte = 0; /* reset current byte */
                    bitIndex = 0; /* reset bit index */
                    ++count; /* increment message character index */
                    numBitsRemaining -= 8; /* decrement remaining bit count */
                }

                /* apply bit to blue value */
                blue &= 0xFE; /* clear LSB */
                blue |= curBit; /* set LSB to message bit */
            }
            /* if there are no bits remaining in message, just copy original pixel data */
            else
            {
                blue &= 0xFE;
            }

            /* repeat process for green and red values */
            if (numBitsRemaining > 0)
            {
                int curBit = EXTRACT_BIT(message[count], bitIndex);
                curByte |= (curBit << (7 - bitIndex));
                ++bitIndex;

                if (bitIndex == 8)
                {
                    fwrite(&curByte, sizeof(BYTE), 1, outFile);
                    curByte = 0;
                    bitIndex = 0;
                    ++count;
                    numBitsRemaining -= 8;
                }

                green &= 0xFE; /* clear LSB */
                green |= curBit; /* set LSB to message bit */
            }
            else
            {
                green &= 0xFE;
            }

            if (numBitsRemaining > 0)
            {
                int curBit = EXTRACT_BIT(message[count], bitIndex);
                curByte |= (curBit << (7 - bitIndex));
                ++bitIndex;

                if (bitIndex == 8)
                {
                    fwrite(&curByte, sizeof(BYTE), 1, outFile);
                    curByte = 0;
                    bitIndex = 0;
                    ++count;
                    numBitsRemaining -= 8;
                }

                red &= 0xFE; /* clear LSB */
                red |= curBit; /* set LSB to message bit */
            }
            else
            {
                red &= 0xFE;
            }
        }

        /* write the transformed pixel color data to the output file */
        fwrite(&blue, sizeof(BYTE), 1, outFile);
        fwrite(&green, sizeof(BYTE), 1, outFile);
        fwrite(&red, sizeof(BYTE), 1, outFile);
    }

    /* if there are any bits remaining in the current byte, write it to the output file */
    if (bitIndex > 0)
    {
        fwrite(&curByte, sizeof(BYTE), 1, outFile);
    }
}

/* reveal the message hidden in the image */
void revealMessage(FILE *inFile, char *message, int maxMessageLength)
{
    BMP_HEADER header;
    BMP_IMAGE image;
    unsigned int numPixels;
    int count = 0;
    int numBitsRemaining = maxMessageLength * 8;
    BYTE curByte = 0;
    int bitIndex = 0;

    readBmpHeader(inFile, &header);
    readBmpImage(inFile, &image);

    numPixels = image.width * image.height;

    for (unsigned int i = 0; i < numPixels; ++i)
    {
        BYTE blue, green, red;
        fread(&blue, sizeof(BYTE), 1, inFile);
        fread(&green, sizeof(BYTE), 1, inFile);
        fread(&red, sizeof(BYTE), 1, inFile);

        /* extract message bits from the blue, green, and red values of the pixel */
        for (int j = 0; j < 8; ++j)
        {
            if (numBitsRemaining > 0)
            {
                /* extract the LSB from the blue value */
                int curBit = EXTRACT_BIT(blue, 0);
                /* set the corresponding bit in the current byte */
                curByte |= (curBit << (7 - bitIndex));

                ++bitIndex;

                /* check if the current byte is full */
                if (bitIndex == 8)
                {
                    message[count] = curByte;
                    curByte = 0;
                    bitIndex = 0;
                    ++count;
                    numBitsRemaining -= 8;
                }

                /* extract message bit from green value */
                curBit = EXTRACT_BIT(green, 0);
                curByte |= (curBit << (7 - bitIndex));
                ++bitIndex;

                if (bitIndex == 8)
                {
                    message[count] = curByte;
                    curByte = 0;
                    bitIndex = 0;
                    ++count;
                    numBitsRemaining -= 8;
                }

                /* extract message bit from red value */
                curBit = EXTRACT_BIT(red, 0);
                curByte |= (curBit << (7 - bitIndex));
                ++bitIndex;

                if (bitIndex == 8)
                {
                    message[count] = curByte;
                    curByte = 0;
                    bitIndex = 0;
                    ++count;
                    numBitsRemaining -= 8;
                }
            }
        }
    }

    /* if there are any bits remaining in the current byte, write it to the output file */
    if (bitIndex > 0)
    {
        message[count] = curByte;
    }
}

int main(int argc, char **argv)
{
    /* check command line arguments */
    if (argc != 4)
    {
        printf("Usage: %s <input file> <output file> <message>\n", argv[0]);
        return 0;
    }

    /* open input file */
    FILE *inFile = fopen(argv[1], "rb");
    if (inFile == NULL)
    {
        printf("Error: could not open input file '%s'\n", argv[1]);
        return 0;
    }

    /* open output file */
    FILE *outFile = fopen(argv[2], "wb");
    if (outFile == NULL)
    {
        printf("Error: could not open output file '%s'\n", argv[2]);
        fclose(inFile);
        return 0;
    }

    /* read in the message */
    char *message = argv[3];
    int messageLength = strlen(message);

    /* hide message in the image */
    hideMessage(inFile, outFile, message);

    /* close the input file */
    fclose(inFile);

    /* close the output file */
    fclose(outFile);

    /* reopen the output file */
    outFile = fopen(argv[2], "rb");
    if (outFile == NULL)
    {
        printf("Error: could not open output file '%s'\n", argv[2]);
        return 0;
    }

    /* reveal message hidden in the image */
    char revealedMessage[1024];
    memset(revealedMessage, 0, sizeof(revealedMessage));
    revealMessage(outFile, revealedMessage, messageLength);

    /* display the revealed message */
    printf("Revealed message: %s\n", revealedMessage);

    /* close the output file */
    fclose(outFile);

    return 0;
}