//FormAI DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, n, k, q = 1;
    char qr[25];
    
    printf("Enter the data you want to encode in QR code: ");
    scanf("%s", qr);

    n = strlen(qr);
    
    // printing the QR code header
    printf("\n\n\t\t********************************************\n");
    printf("\t\t\t   QR Code Generator\n");
    printf("\t\t********************************************\n\n");
    
    // generating the QR code matrix 
    for(i=0; i<(n+12); i++) {
        if(i==0 || i==7 || i==(n+6) || i==(n+12)-1) {
            printf("  ");
            for(j=0; j<(n+12); j++) {
                printf("*");
            }
            printf("\n");
        }
        else if(i==1 || i==6 || i==(n+6)-1) {
            printf("  ");
            for(j=0; j<(n+12); j++) {
                if(j==0 || j==7 || j==(n+12)-1) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else if(i==2) {
            printf("  ");
            for(j=0; j<(n+12); j++) {
                if(j==0 || j==7) {
                    printf("*");
                }
                else if(j>7 && j<(n+5)) {
                    if((j-8)%2 == 0) {
                        printf("*");
                    }
                    else {
                        printf(" ");
                    }
                }
                else if(j==(n+5)) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else if(i==3) {
            printf("**");
            for(j=0; j<3; j++) {
                printf(" ");
            }
            for(j=4; j<(n+8); j++) {
                if((j-4)%2 == 0) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            for(j=(n+8); j<(n+12); j++) {
                printf(" ");
            }
            printf("**\n");
        }
        else if(i==4) {
            printf("  ");
            for(j=0; j<(n+12); j++) {
                if(j==0 || j==7 || j==(n+12)-1) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else if(i==5) {
            printf("**");
            for(j=n+8; j<(n+12); j++) {
                printf(" ");
            }
            for(j=7; j>3; j--) {
                if((j-4)%2 == 0) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            for(j=3; j>=0; j--) {
                printf(" ");
            }
            printf("**\n");
        }
        else if(i>6 && i<(n+6)) {
            if(q%2 == 1) {
                printf("* ");
                for(j=0; j<(n+4); j++) {
                    printf("%c ", qr[k]);
                    k++;
                }
                if((n%2) == 1) {
                    printf(" ");
                }
                printf("*\n");
            }
            else {
                printf("  ");
                for(j=0; j<(n+4); j++) {
                    printf("%c ", qr[k]);
                    k++;
                }
                if((n%2) == 1) {
                    printf(" ");
                }
                printf(" \n");
            }
            q++;
        }
    }

    // printing the QR code footer
    printf("\n\n\t\t********************************************\n");
    printf("\t\t\t   QR Code Generated\n");
    printf("\t\t********************************************\n\n");

    return 0;
}