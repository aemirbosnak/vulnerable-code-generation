//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int gcd(int num1, int num2) {
    int temp;
    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int extended_gcd(int num1, int num2, int *x, int *y) {
    if (num2 == 0) {
        *x = 1; *y = 1;
        return num1;
    }
    int x1, y1;
    int gcd = extended_gcd(num2, num1 % num2, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (num1 / num2);
    return gcd;
}

int main() {
    int p, q, n, phi, e, d;
    char input[MAX_SIZE], output[MAX_SIZE];
    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    printf("Enter an integer e (1 < e < %d and gcd(e, %d) = 1): ", phi, phi);
    do {
        scanf("%d", &e);
    } while (gcd(e, phi) != 1 || e <= 1 || e >= phi);

    int x, y;
    extended_gcd(e, phi, &x, &y);
    
    if (x < 0) {
        x = phi + x;
    }

    printf("Public Key: (%d, %d)\n", n, e);
    printf("Private Key: (%d, %d)\n", n, x);
    printf("Enter the message you want to encrypt: ");
    scanf("%s", input);

    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        int m = (int) input[i];
        int c = 1;
        for (int j = 0; j < e; j++) {
            c = (c * m) % n;
        }
        output[i] = (char) c;
    }
    printf("Encrypted Message: %s\n", output);

    for (int i = 0; i < len; i++) {
        int c = (int) output[i];
        int m = 1;
        for (int j = 0; j < x; j++) {
            m = (m * c) % n;
        }
        input[i] = (char) m;
    }
    printf("Decrypted Message: %s\n", input);

    return 0;
}