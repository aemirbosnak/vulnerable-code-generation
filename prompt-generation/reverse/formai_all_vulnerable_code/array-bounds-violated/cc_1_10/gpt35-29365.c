//FormAI DATASET v1.0 Category: Image Steganography ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 // Maximum steg image size
#define BYTE 8 // 8 bits per byte

// Function to get bit value of a pixel
int getBitValue(int colorValue, int bitPosition) {
    if(colorValue & (1 << bitPosition))
        return 1;
    else
        return 0;
}

// Function to modify least significant bit of a pixel
int setBitValue(int colorValue, int bitPosition, int bitValue) {
    if(bitValue == 0) {
        // Clear the bit
        return colorValue & ~(1 << bitPosition);
    } else {
        // Set the bit
        return colorValue | (1 << bitPosition);
    }
}

int main() {
    char secretMessage[500]; // String to hold message to be hidden
    char stegImageName[100], secretMessageFileName[100];
    char stegImage[MAX_SIZE], modifiedStegImage[MAX_SIZE];
    FILE *fptr1, *fptr2, *secretMsgFile;
    int bitPosition, bitValue, bitCount = 0, modifiedCount = 0;
    long int imageSize, i, j, k;

    printf("Enter the name of the image file to be used for steganography (including extension): ");
    scanf("%s", stegImageName);

    printf("Enter the secret message to be hidden: ");
    scanf(" %[^\n]%*c", secretMessage);

    // Open the image file in read-binary mode
    fptr1 = fopen(stegImageName, "rb");
    if (fptr1 == NULL) {
        printf("Unable to open file '%s'\n", stegImageName);
        exit(0);
    }

    // Copy the image contents to stegImage array
    fseek(fptr1, 0, SEEK_END);
    imageSize = ftell(fptr1);
    rewind(fptr1);
    fread(stegImage, sizeof(char), imageSize, fptr1);
    fclose(fptr1);

    // Open a file to store the secret message
    printf("\nEnter a name for the secret message file to be created (including extension): ");
    scanf("%s", secretMessageFileName);

    secretMsgFile = fopen(secretMessageFileName, "w");
    if (secretMsgFile == NULL) {
        printf("Unable to create file '%s'\n", secretMessageFileName);
        exit(0);
    }
    fprintf(secretMsgFile, "%s", secretMessage);
    fclose(secretMsgFile);

    // Get the message length in bits
    int secretMsgLengthInBits = 8 * strlen(secretMessage);

    // Hide the message length in last 4 pixels
    for(i=imageSize-16; i<imageSize; i++) {
        if(bitCount == 32) break; // Message length of max 32 bit is allowed
        bitPosition = bitCount % BYTE;
        if(bitPosition == 0) {
            // Move to next color element
            j = i + 1;
            k = j + 1;
        }
        bitValue = getBitValue(stegImage[i], bitPosition);
        if(bitValue != ((secretMsgLengthInBits >> bitCount) & 1)) {
            // Modify the pixel value to hide the bit
            modifiedStegImage[i] = setBitValue(stegImage[i], bitPosition, (secretMsgLengthInBits >> bitCount) & 1);
            modifiedCount++;
        } else {
            modifiedStegImage[i] = stegImage[i];
        }
        bitCount++;
    }

    if(bitCount < 32) {
        printf("ERROR: Message length exceeds 32 bit\n");
        exit(0);
    }

    // Hide the secret message bits
    for(i=0; i<imageSize-16; i++) {
        if(bitCount == secretMsgLengthInBits) {
            // Append the remaining bits from original image
            for(; i<imageSize-16; i++) {
                modifiedStegImage[i] = stegImage[i];
            }
            break;
        }
        bitPosition = bitCount % BYTE;
        if(bitPosition == 0) {
            // Move to next color element
            j = i + 1;
            k = j + 1;
        }
        // Get the bit value of the character to be hidden
        bitValue = getBitValue(secretMessage[bitCount/BYTE], bitPosition);
        if(bitValue != getBitValue(stegImage[i], bitPosition)) {
            // Modify the pixel value to hide the bit
            modifiedStegImage[i] = setBitValue(stegImage[i], bitPosition, bitValue);
            modifiedCount++;
        } else {
            modifiedStegImage[i] = stegImage[i];
        }
        bitCount++;
    }

    // Save the modified steg image
    fptr2 = fopen("modifiedImage.bmp", "wb");
    if(fptr2 == NULL) {
        printf("Unable to create file 'modifiedImage.bmp'\n");
        exit(0);
    }
    fwrite(modifiedStegImage, sizeof(char), imageSize, fptr2);
    fclose(fptr2);

    printf("Successfully hid the message to steg image '%s'\n", stegImageName);
    printf("Secret message encoded using %d bits\n", bitCount);
    printf("Modified %d pixels to hide the message\n", modifiedCount);

    return 0;
}