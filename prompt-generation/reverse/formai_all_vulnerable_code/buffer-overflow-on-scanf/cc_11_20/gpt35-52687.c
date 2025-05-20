//FormAI DATASET v1.0 Category: QR code generator ; Style: unmistakable
// This program generates a QR code in C language

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Defines for the QR code layout
#define QR_CODE_SIZE 29
#define QUIET_ZONE 4

// QR Code mask types
typedef enum {
    MASK_000 = 0,
    MASK_001 = 1,
    MASK_010 = 2,
    MASK_011 = 3,
    MASK_100 = 4,
    MASK_101 = 5,
    MASK_110 = 6,
    MASK_111 = 7
} MaskType;

// Function to convert decimal to binary
void decToBinary(int n, int* binary) {

    int i = 0;
    while(n != 0) {
        binary[i++] = n % 2;
        n = n / 2;
    }

    // Inserting leading zeros
    while(i < 8) {
        binary[i++] = 0;
    }

    // Reversing the binary array
    for(int j = 0; j < 4; j++) {
        int temp = binary[j];
        binary[j] = binary[7-j];
        binary[7-j] = temp;
    }
}

// Function to generate QR Code
void generateQRCode(char* data, int dataLen, MaskType mask) {

    int binaryData[(QR_CODE_SIZE - QUIET_ZONE * 2) * (QR_CODE_SIZE - QUIET_ZONE * 2)] = {0};
    
    // Padding and Encoding data
    for(int i = 0; i < dataLen; i++) {
        int binary[8] = {0};
        decToBinary(data[i], binary);

        for(int j = 0; j < 8; j++) {
            binaryData[((i*8+j)/2) + (QR_CODE_SIZE - QUIET_ZONE * 2 + QUIET_ZONE) * ((i*8+j)%2 + QUIET_ZONE)] = binary[j];
        }
    }

    // Adding format string
    int format[15] = {0};
    decToBinary(0x02, format);
    decToBinary(mask, format + 3);
    for(int i = 0; i < 5; i++) {
        binaryData[i + QUIET_ZONE * (QR_CODE_SIZE - QUIET_ZONE * 2)] = format[i];
        binaryData[i * (QR_CODE_SIZE - QUIET_ZONE * 2) + QUIET_ZONE] = format[i];
    }
    binaryData[QUIET_ZONE * (QR_CODE_SIZE - QUIET_ZONE * 2) + QUIET_ZONE] = format[5];


    // Adding alignment pattern
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i != 2 || j != 2) {
                for(int x = 0; x < 5; x++) {
                    for(int y = 0; y < 5; y++) {
                        binaryData[(i*6 + x) * (QR_CODE_SIZE - QUIET_ZONE * 2) + j*6 + y] = 1;
                    }
                }
            }
        }
    }

    // Module
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            int x = i - QUIET_ZONE;
            int y = j - QUIET_ZONE;
            int xPos = i;
            int yPos = j;

            if(x >= 0 && y >= 0 && x < QR_CODE_SIZE - QUIET_ZONE * 2 && y < QR_CODE_SIZE - QUIET_ZONE * 2) {
                int dataBit = binaryData[x * (QR_CODE_SIZE - QUIET_ZONE * 2) + y];
                int maskBit = 0;

                switch(mask) {
                    case MASK_000: maskBit = (xPos + yPos) % 2 == 0; break;
                    case MASK_001: maskBit = yPos % 2 == 0; break;
                    case MASK_010: maskBit = xPos % 3 == 0; break;
                    case MASK_011: maskBit = (xPos + yPos) % 3 == 0; break;
                    case MASK_100: maskBit = (xPos / 3 + yPos / 2) % 2 == 0; break;
                    case MASK_101: maskBit = (xPos * yPos) % 2 + (xPos * yPos) % 3 == 0; break;
                    case MASK_110: maskBit = ((xPos * yPos) % 2 + (xPos * yPos) % 3) % 2 == 0; break;
                    case MASK_111: maskBit = ((xPos + yPos) % 2 + (xPos * yPos) % 3) % 2 == 0; break;
                }

                if(maskBit == 1) {
                    dataBit = (dataBit + 1) % 2;
                }

                binaryData[x * (QR_CODE_SIZE - QUIET_ZONE * 2) + y] = dataBit;
            }   
        }
    }

    // Print QR Code
    printf("\n");
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", (binaryData[i * QR_CODE_SIZE + j]) ? 219 : 32);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    char data[100];
    printf("Enter data to generate QR Code: ");
    scanf("%[^\n]", data);
    int dataLen = strlen(data);

    MaskType mask = MASK_000;  // Default mask
    
    // Print masks
    printf("\nMasks\n");
    printf("===============\n");
    printf("0 : 0b000\n");
    printf("1 : 0b001\n");
    printf("2 : 0b010\n");
    printf("3 : 0b011\n");
    printf("4 : 0b100\n");
    printf("5 : 0b101\n");
    printf("6 : 0b110\n");
    printf("7 : 0b111\n");
    printf("===============\n");
    printf("Enter Mask number (0-7): ");
    scanf("%d", &mask);
    
    generateQRCode(data, dataLen, mask);

    return 0;
}