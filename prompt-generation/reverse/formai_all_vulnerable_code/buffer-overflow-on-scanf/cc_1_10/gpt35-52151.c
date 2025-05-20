//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to convert decimal to binary
int decimalToBinary(int decimal){
    int binary = 0,rem = 0,base = 1;
    while(decimal > 0){
        rem = decimal % 2;
        binary += rem * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

//Function to convert binary to decimal
int binaryToDecimal(int binary){
    int decimal = 0,base = 1,rem = 0;
    while(binary > 0){
        rem = binary % 10;
        decimal += rem * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

int main(){

    char inputFileName[100],outputFileName[100],message[100],ch;
    int size = 0,i,j,index;
    FILE *inputFile,*outputFile;

    printf("Enter the name of the input file (with extension): ");
    scanf("%s",inputFileName);

    //Opening the input file in binary read mode
    inputFile = fopen(inputFileName,"rb");
    if(inputFile == NULL){
        printf("Could not open the input file\n");
        return 0;
    }

    printf("Enter the message to be hidden (Max 100 characters): ");
    scanf(" %[^\n]",message);

    printf("Enter the name of the output file (with extension): ");
    scanf("%s",outputFileName);

    //Opening the output file in binary write mode
    outputFile = fopen(outputFileName,"wb");
    if(outputFile == NULL){
        printf("Could not open the output file\n");
        return 0;
    }

    //Getting the size of the input file
    fseek(inputFile,0,SEEK_END);
    size = ftell(inputFile);
    rewind(inputFile);

    //Writing the size of the input file to the output file
    fwrite(&size,sizeof(int),1,outputFile);

    //Writing the message to the output file
    fwrite(message,sizeof(char),strlen(message),outputFile);

    //Writing the binary representation of the message to the input file
    index = 0;
    while(fread(&ch,sizeof(char),1,inputFile)){
        if(index == strlen(message)){
            fwrite(&ch,sizeof(char),1,outputFile);
        }
        else{
            int binary = decimalToBinary(ch);
            int newBinary = binary;
            for(i = 7;i >= 0;i--){
                if(index < strlen(message)){
                    int bit = (message[index] >> i) & 1;
                    newBinary = (newBinary / 10) * 10 + bit;
                    index++;
                }
            }
            int decimal = binaryToDecimal(newBinary);
            fwrite(&decimal,sizeof(char),1,outputFile);
        }
    }

    printf("Message hidden successfully\n");

    //Closing the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}