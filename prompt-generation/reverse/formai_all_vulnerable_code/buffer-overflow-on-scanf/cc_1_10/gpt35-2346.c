//FormAI DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// function to convert decimal to binary
void decimalToBinary(int n, int binaryNum[])
{
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
}

// function to convert binary to decimal
int binaryToDecimal(int binaryNum[])
{
    int decimalNum = 0, base = 1, i;
    for (i = 0; i < 8; i++) {
        decimalNum += binaryNum[i] * base;
        base = base * 2;
    }
    return decimalNum;
}

int main()
{
    char input_file[MAX_SIZE], output_file[MAX_SIZE], message[MAX_SIZE], ch;
    int i = 0, j = 0, binaryNum[8], pixel[3];

    printf("Enter name of input image file (with extension): ");
    scanf("%s", input_file);
    printf("Enter name of output image file (with extension): ");
    scanf("%s", output_file);
    printf("Enter a message to hide in the image: ");
    scanf(" %[^\n]s", message); // read message with spaces

    // open input file in read mode
    FILE *fptr = fopen(input_file, "rb");
    if (fptr == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // open output file in write mode
    FILE *fp = fopen(output_file, "wb");
    if (fp == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // read header of input file and write to output file
    for (i = 0; i < 54; i++) {
        ch = getc(fptr);
        putc(ch, fp);
    }

    // hide message in image pixels
    i = 0;
    while (message[i] != '\0') {
        decimalToBinary((int)message[i], binaryNum);
        for (j = 0; j < 8; j += 3) {
            // read pixel value from input file
            pixel[0] = getc(fptr);
            pixel[1] = getc(fptr);
            pixel[2] = getc(fptr);

            // modify pixel values to hide message
            if (j < 8 && binaryNum[j] == 1 && pixel[0] % 2 == 0) {
                pixel[0]++;
            }
            else if (j < 8 && binaryNum[j] == 0 && pixel[0] % 2 == 1) {
                pixel[0]--;
            }

            if (j + 1 < 8 && binaryNum[j+1] == 1 && pixel[1] % 2 == 0) {
                pixel[1]++;
            }
            else if (j + 1 < 8 && binaryNum[j+1] == 0 && pixel[1] % 2 == 1) {
                pixel[1]--;
            }

            if (j + 2 < 8 && binaryNum[j+2] == 1 && pixel[2] % 2 == 0) {
                pixel[2]++;
            }
            else if (j + 2 < 8 && binaryNum[j+2] == 0 && pixel[2] % 2 == 1) {
                pixel[2]--;
            }

            // write modified pixel values to output file
            putc(pixel[0], fp);
            putc(pixel[1], fp);
            putc(pixel[2], fp);
        }
        i++;
    }

    // copy any remaining pixel values from input file to output file
    while ((ch = getc(fptr)) != EOF) {
        putc(ch, fp);
    }

    printf("Message hidden in image successfully!\n");

    // close input and output files
    fclose(fptr);
    fclose(fp);
    return 0;
}