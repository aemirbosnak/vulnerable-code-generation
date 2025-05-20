//FormAI DATASET v1.0 Category: QR code generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[128];
    int i, j, k, r;
    
    printf("Welcome to the C QR code generator! Enter your text: ");
    scanf("%s", input);

    int len = strlen(input);
    // create the QR code string
    char qr[32][32];

    // set the qr array to all zeros
    for(i = 0; i < 32; i++) {
        for(j = 0; j < 32; j++) {
            qr[i][j] = 0;
        }
    }
    
    // add some personality to your QR code
    printf("Generating your unique QR code...\n");
    printf("*insert dramatic music*\n");
    printf("This is taking longer than expected! Lets add some random characters to our QR code\n");
    
    // fill the qr array with some random characters
    for(i = 0; i < 32; i++) {
        for(j = 0; j < 32; j++) {
            r = rand() % 10;
            if(r == 1) {
                qr[i][j] = 'X';
            } else if(r == 2) {
                qr[i][j] = 'O';
            } else if(r == 3) {
                qr[i][j] = '>';
            } else if(r == 4) {
                qr[i][j] = '<';
            } else if(r == 5) {
                qr[i][j] = '=';
            } else if(r == 6) {
                qr[i][j] = '^';
            } else if(r == 7) {
                qr[i][j] = '|';
            } else if(r == 8) {
                qr[i][j] = '_';
            } else if(r == 9) {
                qr[i][j] = '?';
            }
        }
    }
    
    // add our input to the QR code
    k = 0;
    for(i = 0; i < len+2; i++) {
        for(j = 0; j < 32; j++) {
            if(k < len) {
                qr[i][j] = input[k++];
            } else {
                qr[i][j] = '*';
            }
        }
    }
    
    // print the QR code
    printf("\nHere is your unique QR code:\n");
    for(i = 0; i < 32; i++) {
        for(j = 0; j < 32; j++) {
            printf("%c  ", qr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}