//FormAI DATASET v1.0 Category: QR code generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_SIZE 21
#define MAX_TEXT 100

// function to generate QR code from given text
void generate_qr_code(char *text) {
    char qr[QR_SIZE][QR_SIZE];
    memset(qr, ' ', sizeof(qr));

    // add start finder pattern
    qr[0][0] = qr[0][1] = qr[0][2] = qr[0][3] = qr[0][4] = qr[1][0] = qr[2][0] = qr[3][0] = qr[4][0] = qr[17][0] = qr[18][0] = qr[19][0] = qr[20][0] = 'X';
    qr[0][QR_SIZE-1] = qr[1][QR_SIZE-1] = qr[2][QR_SIZE-1] = qr[3][QR_SIZE-1] = qr[4][QR_SIZE-1] = qr[0][QR_SIZE-2] = qr[0][QR_SIZE-3] = qr[0][QR_SIZE-4] = qr[0][QR_SIZE-5] = qr[0][5] = qr[0][6] = qr[0][7] = 'X';
    qr[QR_SIZE-1][0] = qr[QR_SIZE-2][0] = qr[QR_SIZE-3][0] = qr[QR_SIZE-4][0] = qr[QR_SIZE-5][0] = qr[QR_SIZE-1][1] = qr[QR_SIZE-1][2] = qr[QR_SIZE-1][3] = qr[QR_SIZE-1][4] = qr[5][QR_SIZE-1] = qr[6][QR_SIZE-1] = qr[7][QR_SIZE-1] = 'X';

    int i, j;
    int index = 0;

    // add data to QR code
    for(i=QR_SIZE-1;i>=8;i-=2) {
        if(index >= strlen(text)) {
            break;
        }

        for(j=QR_SIZE-1;j>=0;j--) {
            if(qr[i][j] == ' ') {
                qr[i][j] = (text[index] == '1' ? 'X' : 'O');
                index++;

                if(index >= strlen(text)) {
                    break;
                }
            }
        }

        if(index >= strlen(text)) {
            break;
        }

        for(j=0;j<QR_SIZE;j++) {
            if(qr[i][j] == ' ') {
                qr[i][j] = (text[index] == '1' ? 'X' : 'O');
                index++;

                if(index >= strlen(text)) {
                    break;
                }
            }
        }
    }

    // print QR code
    for(i=0;i<QR_SIZE;i++) {
        for(j=0;j<QR_SIZE;j++) {
            printf("%c ", qr[i][j]);
        }

        printf("\n");
    }
}

int main() {
    char text[MAX_TEXT];
    printf("Enter text to generate QR code: ");
    scanf("%s", text);

    generate_qr_code(text);

    return 0;
}