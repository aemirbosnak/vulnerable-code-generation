//FormAI DATASET v1.0 Category: QR code reader ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

int main(){
    char qrCode[MAX_LENGTH];
    char qrCodeScanner[MAX_LENGTH];
    int i, j, n;
    int codeMatrix[MAX_LENGTH][MAX_LENGTH]; //to store QR code matrix
    int currentRow = 0; 
    int currentCol = 0;
    int isFilled[MAX_LENGTH][MAX_LENGTH] = {0}; //to check if position in matrix is filled

    //prompt user to input QR code image in the form of a string
    printf("Please input the QR Code image as a string:\n");
    scanf("%s", qrCode);

    //iterate through string and populate QR code matrix
    n = strlen(qrCode);
    for(i = 0; i < n; i++){
        //check if current position in matrix is filled
        if(!isFilled[currentRow][currentCol]){
            codeMatrix[currentRow][currentCol] = qrCode[i] - '0'; //convert char to int and store in matrix
            isFilled[currentRow][currentCol] = 1;
            //determine next position in matrix
            if((currentRow + currentCol) % 2 == 0){
                //even positioning
                if(currentRow == 0){
                    currentCol++;
                } else {
                    currentRow--;
                    currentCol++;
                }
            } else {
                //odd positioning
                if(currentRow == MAX_LENGTH - 1){
                    currentCol++;
                } else if(currentCol == 0){
                    currentRow++;
                } else {
                    currentRow++;
                    currentCol--;
                }
            }
        } else {
            //if current position in matrix is filled, move to next position
            if((currentRow + currentCol) % 2 == 0){
                //even positioning
                if(currentRow == MAX_LENGTH - 1){
                    currentCol++;
                } else {
                    currentRow++;
                    currentCol--;
                }
            } else {
                //odd positioning
                if(currentCol == MAX_LENGTH - 1){
                    currentRow++;
                } else {
                    currentRow--;
                    currentCol++;
                }
            }
            i--; //decrement i to insert char at empty position
        }
    }

    //prompt user to scan QR code using their scanner
    printf("Please scan the QR Code using your scanner:\n");
    scanf("%s", qrCodeScanner);

    //iterate through scanned QR code and compare to original QR code
    n = strlen(qrCodeScanner);
    i = j = 0;
    while(i < n && j < MAX_LENGTH * MAX_LENGTH){
        if(qrCodeScanner[i] - '0' == codeMatrix[j/MAX_LENGTH][j%MAX_LENGTH]){
            i++;
            j++;
        } else {
            j++;
        }
    }

    if(i == n){
        //scanned QR code matches original QR code
        printf("QR Code scan successful!\n");
    } else {
        //scanned QR code does not match original QR code
        printf("QR Code scan failed. Please try again.\n");
    }

    return 0;
}