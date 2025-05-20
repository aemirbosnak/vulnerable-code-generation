//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21

/* Function to print QR code */
void print_qrcode(char qrcode[WIDTH][HEIGHT]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (qrcode[i][j] == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

/* Function to generate QR code */
void generate_qrcode(char input[100], char qrcode[WIDTH][HEIGHT]) {
    int i, j, k, n, m, s, value;
    char temp[100];

    /* Copy input string to temporary string */
    strcpy(temp, input);

    /* Reverse the temporary string */
    for (i = strlen(temp) - 1, j = 0; i >= 0; i--, j++) {
        temp[j] = temp[i];
    }

    /* Add padding to temporary string */
    n = strlen(temp);
    m = n % 3;
    if (m == 0) {
        m = 3;
    }
    k = n + m - 1;
    temp[k] = '\0';
    for (i = k - 1, s = 0; i >= k - m; i--, s++) {
        temp[i] = '0' + s;
    }

    /* Initialize QR code */
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            qrcode[i][j] = 0;
        }
    }

    /* Set position and value of elements */
    i = 0;
    j = 0;
    value = 1;
    while (i < HEIGHT) {
        while (j < WIDTH && value > 0) {
            if (temp[k] == '1') {
                qrcode[i][j] = 1;
            }
            value--;
            j++;
        }
        i++;
        j = 0;
        value += 2;
    }
}

/* Function to main */
int main() {
    char input[100], qrcode[WIDTH][HEIGHT];
    printf("Enter the message: ");
    scanf("%s", input);

    /* Generate QR code */
    generate_qrcode(input, qrcode);

    /* Print QR code */
    printf("\nQR code:\n");
    print_qrcode(qrcode);

    return 0;
}