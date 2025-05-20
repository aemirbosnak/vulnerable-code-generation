//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }
    
    char* text = argv[1];
    int length = strlen(text);
    int i, j, k;
    int code[16][16];
    
    // initialize code matrix
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            code[i][j] = 0;
        }
    }
    
    // add border pixels
    for (i = 0; i < 16; i++) {
        code[i][0] = 1;
        code[i][15] = 1;
    }
    
    // add quiet zone pixels
    for (i = 1; i < 15; i++) {
        code[0][i] = 1;
        code[15][i] = 1;
    }
    
    // add data pixels
    for (i = 1; i < length; i++) {
        k = (i / 4) % 4;
        code[k][(i / 4) % 4] = 1;
    }
    
    // add error correction code
    for (i = 0; i < 16; i++) {
        code[i][i] = 1;
        for (j = 1; j < 16; j++) {
            code[i][j] = (code[i][j - 1] ^ code[i][j + 1]) & 1;
        }
    }
    
    // print QR code
    printf("QR Code: ");
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            if (code[i][j]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}