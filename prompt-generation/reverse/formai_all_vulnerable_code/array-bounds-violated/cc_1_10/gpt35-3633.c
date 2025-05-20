//FormAI DATASET v1.0 Category: QR code generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 21
#define HEIGHT 21

void print_code(char qr[WIDTH][HEIGHT]) {
    int x,y;
    for(x = 0; x < WIDTH; x++) {
        for(y = 0; y < HEIGHT; y++) {
            printf("%c", qr[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Generate QR code */
void generate_qr(char* data) {
    int x,y;
    char qr[WIDTH][HEIGHT];
    memset(qr, ' ', sizeof(qr));

    /* Add start square */
    qr[0][0] = qr[0][WIDTH-1] = qr[WIDTH-1][0] = qr[WIDTH-1][WIDTH-1] = '+';

    /* Add data */
    int i,j;
    for(i = 0; i < strlen(data); i++) {
        int d = data[i] - '0';
        for(j = 0; j < 3; j++) {
            int px = (i*3) + (d >> (2-j) & 1);
            int py = j+1;
            qr[px][py] = '#';
        }
    }

    /* Add border */
    for(i = 0; i < HEIGHT; i++) qr[0][i] = qr[WIDTH-1][i] = qr[i][0] = qr[i][WIDTH-1] = '+';

    print_code(qr);
}

int main() {

    char data[] = "0123456789";
    generate_qr(data);

    return 0;
}