//FormAI DATASET v1.0 Category: QR code generator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<qrencode.h>

int main(){

    char input[200];
    QRcode *qrcode = NULL;
    unsigned char *qrcode_data = NULL;
    int qrcode_version = 0;
    int qrcode_width = 0;
    int i, j;

    printf("Welcome to the cheerful QR code generator!\n");

    do{
        printf("Enter text to convert to QR code (or type 'exit' to quit): ");
        scanf("%s", input);

        if(strcmp(input, "exit") == 0){
            printf("Thank you for using the cheerful QR code generator. Goodbye!\n");
            return 0;
        }

        qrcode = QRcode_encodeString(input, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

        if(qrcode){
            printf("\nQR code for %s:\n", input);
            qrcode_data = qrcode->data;
            qrcode_version = qrcode->version;
            qrcode_width = qrcode->width;

            for(i = 0; i < qrcode_width; i++){
                for(j = 0; j < qrcode_width; j++){
                    if(*qrcode_data & 1){
                        printf("%c%c", 219, 219);
                    }else{
                        printf("  ");
                    }
                    qrcode_data++;
                }
                printf("\n");
            }
            QRcode_free(qrcode);
        }else{
            printf("Error generating QR code for %s. Please try again.\n", input);
        }
    }while(1); // infinite loop until user exits with 'exit'

    return 0;
}