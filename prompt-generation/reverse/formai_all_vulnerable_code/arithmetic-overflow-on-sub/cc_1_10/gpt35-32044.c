//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int n, int binary[])
{
    int i = 0;
    // loop to convert decimal to binary
    while(n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
}

// function to convert binary to decimal
int binaryToDecimal(int binary[])
{
    int decimal = 0;
    int base = 1;
    // loop to convert binary to decimal
    for(int i=0; i<8; i++) {
        decimal += binary[i] * base;
        base *= 2;
    }
    return decimal;
}

int main()
{
    // sample message to be hidden
    char message[] = "Hello, World!";
    // sample image to be used as a cover
    char img[] = "sample_image.bmp";
    // open the image file
    FILE *image = fopen(img, "rb");
    // check if file can be opened
    if(image == NULL) {
        printf("Error: Could not open image file.");
        return 0;
    }
    // read the image size
    fseek(image, 2, SEEK_SET);
    int size;
    fread(&size, 4, 1, image);
    // read the width of the image
    fseek(image, 18, SEEK_SET);
    int width;
    fread(&width, 4, 1, image);
    // read the height of the image
    fseek(image, 22, SEEK_SET);
    int height;
    fread(&height, 4, 1, image);
    // read the color depth of the image
    fseek(image, 28, SEEK_SET);
    int depth;
    fread(&depth, 2, 1, image);
    // check if image is valid
    if(depth != 24) {
        printf("Error: This program only works with 24-bit BMP files.");
        fclose(image);
        return 0;
    }
    // calculate the total number of bytes in the image
    int numBytes = size - 54;
    // read the image data into a buffer
    fseek(image, 54, SEEK_SET);
    unsigned char buffer[numBytes];
    fread(&buffer, numBytes, 1, image);
    // close the image file
    fclose(image);

    // loop through the message to be hidden
    int msgLen = sizeof(message) - 1; // exclude the null character
    int binary[msgLen * 8];
    int index = 0;
    for(int i=0; i<msgLen; i++) {
        // convert each character to binary and store in array
        decimalToBinary(message[i], &binary[index]);
        index += 8;
    }

    // hide the message in the image
    int bufferIndex = 0;
    for(int i=0; i<msgLen*8; i+=3) {
        // retrieve the next 3 bytes from the image buffer
        unsigned char byte1 = buffer[bufferIndex];
        unsigned char byte2 = buffer[bufferIndex + 1];
        unsigned char byte3 = buffer[bufferIndex + 2];
        // convert the bytes to binary
        int binary1[8], binary2[8], binary3[8];
        decimalToBinary(byte1, binary1);
        decimalToBinary(byte2, binary2);
        decimalToBinary(byte3, binary3);
        // replace the least significant bit (LSB) of each byte with the message bit
        binary1[7] = binary[i];
        binary2[7] = binary[i+1];
        binary3[7] = binary[i+2];
        // convert the modified bytes back to decimal
        int newByte1 = binaryToDecimal(binary1);
        int newByte2 = binaryToDecimal(binary2);
        int newByte3 = binaryToDecimal(binary3);
        // store the new bytes in the image buffer
        buffer[bufferIndex] = newByte1;
        buffer[bufferIndex + 1] = newByte2;
        buffer[bufferIndex + 2] = newByte3;
        // move to the next 3 bytes in the image buffer
        bufferIndex += 3;
    }

    // create a new image file with the hidden message
    FILE *output = fopen("secret_image.bmp", "wb");
    // write the header data
    fwrite(&size, 4, 1, output);
    fwrite(&buffer, numBytes, 1, output);
    // close the output file
    fclose(output);
    printf("Done! Your secret message is now hidden in the image.");
    return 0;
}