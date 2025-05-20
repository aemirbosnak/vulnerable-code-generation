//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include<stdio.h>
#define BITS 8
#define MAX_SIZE 100

// Binary to decimal conversion
int binaryToDecimal(int binary_num[], int size) {
    int decimal_num = 0;
    int i, j;

    for(i=size-1, j=0; i>=0; i--, j++){
        decimal_num += binary_num[i] * pow(2,j);
    }

    return decimal_num;
}

// Decimal to binary conversion
void decimalToBinary(int decimal_num, int binary_num[]) {
    int quotient, remainder;
    int i = 0;

    while(decimal_num > 0){
        quotient = decimal_num/2;
        remainder = decimal_num % 2;
        binary_num[i++] = remainder;
        decimal_num = quotient;
    }
}

void printBinary(int arr[], int size) {
    int i;

    for(i=size-1; i>=0; i--){
        printf("%d", arr[i]);
    }
}

void embedWatermark(int msg[], int watermark[], int size) {
    int i, j;

    for(i=0; i<size; i++){
        int msg_binary[BITS] = {};
        int watermark_binary[BITS] = {};

        // Convert msg and watermark integer to binary
        decimalToBinary(msg[i], msg_binary);
        decimalToBinary(watermark[i], watermark_binary);

        // Embed watermark in the last bit of msg binary
        for(j=0; j<BITS-1; j++){
            msg_binary[j] = msg_binary[j] & watermark_binary[j];
        }
        msg_binary[BITS-1] = watermark_binary[BITS-1];

        // Convert binary back to decimal
        msg[i] = binaryToDecimal(msg_binary, BITS);
    }
}

void extractWatermark(int msg[], int watermark[], int size) {
    int i, j;

    for(i=0; i<size; i++){
        int msg_binary[BITS] = {};

        // Convert msg integer to binary
        decimalToBinary(msg[i], msg_binary);

        // Extract watermark from the last bit of msg binary
        watermark[i] = msg_binary[BITS-1];
    }
}

int main() {
    int i, n;
    int message[MAX_SIZE] = {};
    int watermark[MAX_SIZE] = {};

    printf("Enter message size: ");
    scanf("%d", &n);

    printf("Enter message: ");
    for(i=0; i<n; i++){
        scanf("%d", &message[i]);
    }

    printf("Enter watermark size: ");
    scanf("%d", &n);

    printf("Enter watermark: ");
    for(i=0; i<n; i++){
        scanf("%d", &watermark[i]);
    }

    // Embed watermark in message
    embedWatermark(message, watermark, n);

    printf("Embedded message: ");
    for(i=0; i<n; i++){
        printf("%d ", message[i]);
    }
    printf("\n");

    // Extract watermark from message
    extractWatermark(message, watermark, n);

    printf("Extracted watermark: ");
    for(i=0; i<n; i++){
        printf("%d ", watermark[i]);
    }
    printf("\n");

    return 0;
}