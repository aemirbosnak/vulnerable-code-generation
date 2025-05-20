//FormAI DATASET v1.0 Category: QR code generator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<qrencode.h>

int main() {

    //initialize variables
    int version = 5;
    QRecLevel level = QR_ECLEVEL_Q;
    QRencodeMode mode = QR_MODE_8;

    //enter message to be encoded
    char message[1000];
    printf("Enter the message to be encoded: ");
    fgets(message, 1000, stdin);

    //create QR code
    QRcode *code = QRcode_encodeString(message, version, level, mode, 1);

    if(code == NULL) {
        printf("Error: unable to encode message\n");
        return 0;
    }

    //display QR code as ASCII art
    for(int i = 0; i < code->width + 4; i++)
        printf("*");
    printf("\n");

    for(int i = 0; i < code->width; i++) {
        printf("*  ");
        for(int j = 0; j < code->width; j++) {
            if(code->data[i * code->width + j] & 1) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("  *\n");
    }

    for(int i = 0; i < code->width + 4; i++)
        printf("*");
    printf("\n");

    //free memory
    QRcode_free(code);

    return 0;
}