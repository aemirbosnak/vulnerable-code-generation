//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IMAGE_SIZE 1000024
#define MAX_DATA_SIZE 1000000

/* Function to hide data in image */
void hideData(char *imgPath, char *dataPath){
    
    FILE *imgFile = fopen(imgPath, "rb");  // Open image file in read binary mode
    if(!imgFile){                         // Check if image file exists or not
        printf("\nUnable to open image file!\n");
        return;
    }
    
    FILE *dataFile = fopen(dataPath, "rb"); // Open data file in read binary mode
    if(!dataFile){                        // Check if data file exists or not
        printf("\nUnable to open data file!\n");
        fclose(imgFile);                  // Close image file
        return;
    }

    /* Read image data into buffer */
    char imgBuffer[MAX_IMAGE_SIZE];
    int imgBytesRead = fread(imgBuffer, sizeof(char), MAX_IMAGE_SIZE, imgFile);
    fclose(imgFile);                      // Close image file
    
    /* Read data into buffer */
    char dataBuffer[MAX_DATA_SIZE];
    int dataBytesRead = fread(dataBuffer, sizeof(char), MAX_DATA_SIZE, dataFile);
    fclose(dataFile);                     // Close data file
    
    /* Check if data size is less than image size */
    if(dataBytesRead > (imgBytesRead/8)){                // Divide by 8 because we need 8 bits to represent one character
        printf("\nData size is too large to hide in the given image!\n");
        return;
    }
    
    int i;
    for(i=0; i<dataBytesRead; i++){     // Iterate through each character in data buffer
        
        /* Convert current character to 8 bits (one byte) in binary format */
        int j, k;
        char binaryData[9];
        for(j=7, k=0; j>=0; j--, k++){
            binaryData[k] = (dataBuffer[i] >> j) & 1 ? '1' : '0';   
        }
        binaryData[k] = '\0';
        
        /* Hide each bit of current character in the image buffer */
        int bitIndex = 0;
        int bufferIndex = (i*8)+8;
        while(binaryData[bitIndex] != '\0'){
            imgBuffer[bufferIndex] = (imgBuffer[bufferIndex] & 0xFE) | (binaryData[bitIndex] - '0');   // Clear last bit (0xFE) and put current bit
            bitIndex++;
            bufferIndex++;
        }
    }
    
    /* Write modified image buffer to a new image file */
    FILE *encodedImgFile = fopen("encoded_image.bmp", "wb");   // Open new image file in write binary mode
    fwrite(imgBuffer, sizeof(char), imgBytesRead, encodedImgFile);   // Write encoded image data to file
    fclose(encodedImgFile);                // Close new image file
    
    printf("\nData hiding successful!\n");
    
}   // End of hideData()

/* Function to extract hidden data from image */
void extractData(char *imgPath){
    
    FILE *imgFile = fopen(imgPath, "rb");  // Open encoded image file in read binary mode
    if(!imgFile){                         // Check if image file exists or not
        printf("\nUnable to open image file!\n");
        return;
    }
    
    /* Read image data into buffer */
    char imgBuffer[MAX_IMAGE_SIZE];
    int imgBytesRead = fread(imgBuffer, sizeof(char), MAX_IMAGE_SIZE, imgFile);
    fclose(imgFile);                      // Close image file
    
    /* Extract data from image buffer */
    char dataBuffer[MAX_DATA_SIZE];
    int i;
    for(i=0; i<MAX_DATA_SIZE; i++){
        
        /* Extract one bit of current character from the image buffer */
        int bitIndex = 0;
        int bufferIndex = (i*8)+8;
        char binaryData[9] = "";
        while(bitIndex<8){
            binaryData[bitIndex++] = (imgBuffer[bufferIndex++] & 1) + '0';
        }
        binaryData[bitIndex] = '\0';
        
        /* Convert 8 bits (one byte) to a character */
        if(binaryData[0] == '\0'){           // Check if end of data is reached
            break;
        }
        dataBuffer[i] = strtol(binaryData, NULL, 2);
    }
    dataBuffer[i] = '\0';
    
    /* Write extracted data to a new file */
    FILE *decodedDataFile = fopen("decoded_data.txt", "wb");   // Open new data file in write binary mode
    fwrite(dataBuffer, sizeof(char), strlen(dataBuffer), decodedDataFile);   // Write decoded data to file
    fclose(decodedDataFile);                // Close new data file
    
    printf("\nData extraction successful!\n");
    
}   // End of extractData()

/* Main function */
int main(){
    
    printf("****Program to demonstrate image steganography****\n\n");
    
    printf("Enter choice:\n");
    printf("1. Hide data in image\n");
    printf("2. Extract data from image\n\n");
    
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1){
        printf("\nEnter path of image to hide data in: ");
        char imgPath[100];
        scanf("%s", imgPath);
        
        printf("\nEnter path of data file to hide: ");
        char dataPath[100];
        scanf("%s", dataPath);
        
        hideData(imgPath, dataPath);
    }
    else if(choice == 2){
        printf("\nEnter path of encoded image: ");
        char imgPath[100];
        scanf("%s", imgPath);
        
        extractData(imgPath);
    }
    else{
        printf("\nInvalid choice! Program exiting...\n");
    }
    
    return 0;
}   // End of main()