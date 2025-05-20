//FormAI DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

// This function generates a unique C QR code based on user input
void generateQRCode(int n, int *arr) {
    /* This function can only generate QR codes of length up to 10 digits */
    if(n > 10) {
        printf("QR code cannot be generated due to input size limit");
        return;
    }

    /* This variable stores the final binary value */
    int binary = 0;
    /* This variable stores the factor used to calculate the binary value */
    int factor = 1;

    for(int i = 0; i < n; i++) {
        /* Only single digits in the range 0-9 are allowed */
        if(arr[i] < 0 || arr[i] > 9) {
            printf("QR code cannot be generated due to invalid input");
            return;
        }
        binary += arr[i] * factor;
        factor *= 10;
    }

    /* This variable stores the final decimal value */
    int decimal = 0;
    factor = 1;

    /* Reverse binary to obtain decimal */
    while(binary) {
        decimal += (binary % 10) * factor;
        binary /= 10;
        factor *= 2;
    }

    /* This variable stores the hexadecimal value */
    char hex[25];
    int i = 0;

    /* Convert decimal to hexadecimal */
    while(decimal) {
        int temp = decimal % 16;
        if(temp < 10) {
            hex[i] = temp + 48;
            i++;
        }
        else {
            hex[i] = temp + 55;
            i++;
        }
        decimal /= 16;
    }

    printf("Generated QR code: %s\n", hex);
}

int main() {
    int n;
    int arr[10];

    printf("Enter the number of digits: ");
    scanf("%d", &n);

    printf("Enter the digits (separated by spaces): ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    generateQRCode(n, arr);

    return 0;
}