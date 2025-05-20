//FormAI DATASET v1.0 Category: QR code generator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to encode a string into a QR code
void generateQRCode(char* inputString){

    int sizeOfInputString = strlen(inputString);
    char *binaryString = (char*)calloc(8*sizeOfInputString + 1, sizeof(char));

    // Converting characters to binary sequence
    int index = 0;
    for(int i=0; i<sizeOfInputString; i++){
        for(int j=7; j>=0; j--){
            binaryString[index++] = ((inputString[i] & (1 << j)) ? '1' : '0');
        }
    }

    // Padding 0s to make the length a multiple of three
    int newLength =  ((8*sizeOfInputString) % 3 == 0) ?  (8*sizeOfInputString)/3 : ((8*sizeOfInputString)/3 + 1);
    int padding = newLength*3 - 8*sizeOfInputString;
    for(int i=0; i<padding; i++){
        binaryString[index++] = '0';
    }

    // Dividing binary sequence into groups of 3 bits
    int numberOfTriplets = newLength;
    char triplet[4];
    index = 0;
    for(int i=0; i<numberOfTriplets; i++){
        for(int j=0; j<3; j++){
            triplet[j] = binaryString[index++];
        }
        triplet[3] = '\0';

        // Converting triplet to integer and corresponding base 45 character
        int valueOfTriplet = strtol(triplet, NULL, 2);
        char character = '0';
        if(valueOfTriplet < 10){
            character = '0' + valueOfTriplet;
        }
        else if(valueOfTriplet >= 10 && valueOfTriplet < 36){
            character = 'A' + (valueOfTriplet - 10);
        }
        else if(valueOfTriplet >= 36 && valueOfTriplet < 45){
            character = 'a' + (valueOfTriplet - 36);
        }
        printf("%c", character);
    }
    free(binaryString);
}

// Tester code
int main(){
    printf("Enter a string to encode into QR code:\n");
    char inputString[100];
    scanf("%[^\n]s", inputString);

    printf("\nQR Code:\n");
    generateQRCode(inputString);
    return 0;
}