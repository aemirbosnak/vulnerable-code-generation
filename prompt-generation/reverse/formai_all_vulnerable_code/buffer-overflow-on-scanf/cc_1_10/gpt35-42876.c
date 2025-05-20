//FormAI DATASET v1.0 Category: QR code reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct QRCode{
    char code[10];
    bool isRead;
} QRCode;

#define NUM_QR_CODES 5

int main(){
    QRCode qrCodes[NUM_QR_CODES];
    memset(qrCodes, 0, sizeof(qrCodes));
    
    printf("===QR Code Reader Program===\n");
    printf("Please enter the 5 QR Codes:");
    for(int i=0; i<NUM_QR_CODES; i++){
        scanf("%s", qrCodes[i].code);
    }
    
    printf("\n Scanning codes....\n");
    bool allCodesRead = false;
    while(!allCodesRead){
        char input[10];
        printf("Please enter a QR code to scan: ");
        scanf("%s", input);
        
        for(int i=0; i<NUM_QR_CODES; i++){
            if(strcmp(qrCodes[i].code, input) == 0){
                if(qrCodes[i].isRead){
                    printf("This QR code has already been scanned.\n");
                }
                else{
                    qrCodes[i].isRead = true;
                    printf("QR code %s has been successfully scanned!\n", input);
                }
                break;
            }
            
            if(i == NUM_QR_CODES - 1){
                printf("Invalid QR code.\n");
            }
        }
        
        allCodesRead = true;
        for(int i=0; i<NUM_QR_CODES; i++){
            if(!qrCodes[i].isRead){
                allCodesRead = false;
            }
        }
        
        if(allCodesRead){
            printf("All QR codes have been successfully scanned!\n");
        }
    }
    return 0;
}