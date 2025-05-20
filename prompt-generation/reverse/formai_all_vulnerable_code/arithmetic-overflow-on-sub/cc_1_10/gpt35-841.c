//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

//define overall limit of the message to be hidden
#define MAX_CHAR 100

//function to convert integer to binary representation
void decToBinary(int num, int binary_arr[]){

    for(int i=0; num>0; i++){
        binary_arr[i] = num%2;
        num = num/2;
    }
}

//function to convert binary to decimal representation
int binaryToDec(int binary_arr[], int size){
    int decimal=0;
    int power=1;
    for(int i=0; i<size; i++){
        decimal += binary_arr[i]*power;
        power = power*2;
    }
    return decimal;
}

int main(){

    //open original image file for reading
    FILE* fptr1 = fopen("original_image.bmp", "rb");
    if(fptr1 == NULL){
        printf("Error while opening file!");
        exit(1);
    }

    //open copy of original image file for writing
    FILE* fptr2 = fopen("stego_image.bmp", "wb");
    if(fptr2 == NULL){
        printf("Error while opening file!");
        exit(1);
    }

    //find size of image
    fseek(fptr1, 0, SEEK_END);
    int total_size = ftell(fptr1);
    fseek(fptr1, 0, SEEK_SET);

    //read header of original image and write it to copy file as it is
    char* header = (char*) malloc(total_size*sizeof(char));
    fread(header, 1, total_size, fptr1);
    fwrite(header, 1, total_size, fptr2);
    free(header);

    //seek to the offset when actual image data begins in files
    fseek(fptr1, 54, SEEK_SET);
    fseek(fptr2, 54, SEEK_SET);

    //message to be hidden
    char msg[MAX_CHAR];
    printf("Enter message to be hidden in the image: ");
    fgets(msg, MAX_CHAR, stdin);

    //convert message to binary representation
    int binary_msg[MAX_CHAR*8];
    int size_binary_msg = 0;
    for(int i=0; i<MAX_CHAR; i++){
        if(msg[i] == '\0')
            break;
        decToBinary((int)msg[i], &binary_msg[size_binary_msg]);
        size_binary_msg += 8;
    }

    //get size of message to be hidden
    int size_msg = size_binary_msg/8;

    //check if message could be fit in the image
    if(total_size-54 < size_msg*8){
        printf("Message too big to fit in the image!");
        exit(1);
    }

    //write the message to the copy of the image
    int c=0, bit=0;
    for(int i=0; i<size_msg; i++){
        for(int j=0; j<8; j++){
            fread(&c, 1, 1, fptr1);
            bit = binary_msg[i*8+j];
            c = (c & 0xFE) | bit;
            fwrite(&c, 1, 1, fptr2);
        }
    }

    //write remaining bytes as it is, including padding bytes if any
    while(ftell(fptr1) != total_size){
        fread(&c, 1, 1, fptr1);
        fwrite(&c, 1, 1, fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}