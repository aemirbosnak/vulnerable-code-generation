//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert decimal to binary
int *decToBinary(int num, int array[]){
    for(int i=0; i<8; i++){
        array[i] = num % 2;
        num = num / 2;
    }
    return array;
}

// function to convert binary to decimal
int binaryToDec(int array[]){
    int num = 0, pow = 1;
    for(int i=0; i<8; i++){
        num = num + array[i] * pow;
        pow = pow * 2;
    }
    return num;
}

// function to hide message in image
void hideMessage(char message[], char imageName[]){
    FILE *fp1, *fp2;
    int count = 0, byte, pos = 0, binaryMessage[8], binaryByte[8], length;
    fp1 = fopen(imageName, "rb");
    fp2 = fopen("output.bmp", "wb");
    int headerSize;
    fread(&headerSize, 4, 1, fp1);
    fwrite(&headerSize, 4, 1, fp2);
    fseek(fp1, 4, SEEK_CUR);
    fread(&length, 4, 1, fp1);
    fwrite(&length, 4, 1, fp2);
    fseek(fp1, 12, SEEK_CUR);
    while(1){
        byte = fgetc(fp1);
        if(byte == EOF)
            break;
        decToBinary(byte, binaryByte);
        if(count < strlen(message)){
            decToBinary(message[count], binaryMessage);
            binaryByte[7] = binaryMessage[pos++];
            if(pos == 8){
                pos = 0;
                count++;
            }
        }
        byte = binaryToDec(binaryByte);
        fputc(byte, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("Message hidden successfully in %s image!", imageName);
}

// function to reveal message from image
void revealMessage(char imageName[]){
    FILE *fp;
    int byte, binaryByte[8], count = 0, pos = 0, length;
    char message[100];
    fp = fopen(imageName, "rb");
    int headerSize;
    fread(&headerSize, 4, 1, fp);
    fseek(fp, 4, SEEK_CUR);
    fread(&length, 4, 1, fp);
    fseek(fp, 12, SEEK_CUR);
    while(1){
        byte = fgetc(fp);
        if(byte == EOF)
            break;
        decToBinary(byte, binaryByte);
        if(count < length){
            message[count] = binaryByte[7] + '0';
            pos++;
            if(pos == 8){
                pos = 0;
                count++;
            }
        }
    }
    printf("Message revealed from %s image: %.*s", imageName, length, message);
}

int main(){
    char message[100], imageName[20];
    int choice;
    printf("Enter message to hide (max 100 characters): ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = 0;
    printf("Enter name of image file to hide message in (max 20 characters): ");
    fgets(imageName, 20, stdin);
    imageName[strcspn(imageName, "\n")] = 0;
    printf("Do you want to hide message or reveal message?\n");
    printf("1. Hide message\n");
    printf("2. Reveal message\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            hideMessage(message, imageName);
            break;
        case 2:
            revealMessage(imageName);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}