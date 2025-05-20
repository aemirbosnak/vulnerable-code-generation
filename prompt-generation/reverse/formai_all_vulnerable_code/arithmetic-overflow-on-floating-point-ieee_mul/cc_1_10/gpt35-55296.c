//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: calm
#include <stdio.h>

//Function to convert integer to binary string 
char *intToBinaryString(int num)
{
    static char binaryString[33]; //max number of bits in unsigned int is 32
    unsigned int mask = 1 << 31; //shift 1 to left 31 times to create mask
    int i;
    for (i = 0; i < 32; i++) {
        binaryString[i] = (num & mask) ? '1' : '0'; //if bit is set, assign '1' else assign '0'
        mask >>= 1; //shift mask to right by 1 bit
    }
    binaryString[i] = '\0'; //terminate string with null character
    return binaryString;
}

int main()
{
    char originalData[100]; //maximum length of original data
    char watermark[100]; //maximum length of watermark
    char watermarkedData[100]; //maximum length of watermarked data
    int i, j;
    
    printf("Enter original data: ");
    fgets(originalData, sizeof(originalData), stdin);
    
    printf("Enter watermark: ");
    fgets(watermark, sizeof(watermark), stdin);
    
    //check if watermark length is less than or equal to original data length
    if (strlen(watermark) > strlen(originalData)) {
        printf("Error: Watermark length is greater than original data length.\n");
        return 1;
    }
    
    //embed watermark in original data using LSB algorithm
    for (i = 0, j = 0; i < strlen(originalData); i++, j++) {
        if (j < strlen(watermark))
            watermarkedData[i] = (originalData[i] & 254) | (watermark[j] & 1);
        else
            watermarkedData[i] = originalData[i];
    }
    
    printf("Original Data: %s", originalData);
    printf("Watermark: %s", watermark);
    printf("Watermarked Data: %s", watermarkedData);
    
    //extract watermark from watermarked data using LSB algorithm
    char extractedWatermark[100];
    for (i = 0, j = 0; i < strlen(watermarkedData); i++, j++) {
        if (j < strlen(watermark))
            extractedWatermark[j] = (watermarkedData[i] & 1) ? '1' : '0';
    }
    extractedWatermark[j] = '\0';
    
    printf("Extracted Watermark: %s", extractedWatermark);
    
    //calculate PSNR
    int mse = 0;
    for (i = 0; i < strlen(originalData); i++) {
        int diff = originalData[i] - watermarkedData[i];
        mse += diff * diff;
    }
    mse /= strlen(originalData);
    double psnr = (mse == 0) ? 100 : 10 * log10(255 * 255 / mse);
    
    printf("PSNR: %lf dB", psnr);
    
    return 0;
}