//FormAI DATASET v1.0 Category: QR code reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21 //QR code size for C is 21 integers

int main() {

    int i, j, sum;
    char qr_string[QR_CODE_SIZE];
    int qr_code[QR_CODE_SIZE];

    //Read QR code from user and convert it to integers
    printf("Please enter your C QR code (consist of 21 integers): \n");
    scanf("%s", qr_string);

    for (i = 0; i < QR_CODE_SIZE; i++) {
        qr_code[i] = qr_string[i] - '0'; //Convert char to int
    }

    //Calculate the checksum
    sum = 0;
    for (i = 0; i < QR_CODE_SIZE - 1; i++) { //Exclude the last entry (checksum)
        if (i % 2 == 0) { //Even index
            sum += qr_code[i] * 1;
        }
        else { //Odd index
            sum += qr_code[i] * 3;
        }
    }
    int remainder = sum % 10;
    int checksum = (10 - remainder) % 10;

    //Check if the checksum matches
    if (qr_code[QR_CODE_SIZE - 1] != checksum) {
        printf("Invalid QR code - Checksum does not match!\n");
        exit(0);
    }

    //Print the QR code
    printf("QR Code: ");
    for (i = 0; i < QR_CODE_SIZE - 1; i++) { //Exclude the last entry (checksum)
        printf("%d", qr_code[i]);
    }
    printf("\n");

    //Decode the QR code
    char decoded_text[20];

    for (i = 0; i < QR_CODE_SIZE - 1; i += 2) { //Combine pairs of integers
        j = i / 2;
        int n = qr_code[i] * 100 + qr_code[i + 1]; //Combine two digits into number
        decoded_text[j] = n;
    }
    decoded_text[j] = '\0'; //Add null character at the end

    printf("Decoded Text: %s\n", decoded_text);

   return 0;
}