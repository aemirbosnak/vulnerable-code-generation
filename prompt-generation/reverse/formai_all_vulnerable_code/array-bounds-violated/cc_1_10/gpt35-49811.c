//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

int main() {
    int p = 3, q = 7, n, z, d, e = 2, i;
    char message[1000], msg[1000];
    printf("Enter message: ");
    fgets(msg, 100, stdin);
    for (i = 0; msg[i] != '\0'; i++) {
        message[i] = msg[i];
    }
    message[i - 1] = '\0';
    printf("Entered message: %s\n", message);
    n = p * q;
    z = (p - 1) * (q - 1);
    while (e < z) {
        if (gcd(e, z) == 1)
            break;
        else
            e++;
    }
    i = 1;
    while (1) {
        d = (z * i + 1) / e;
        if (d * e == (z * i + 1))
            break;
        else
            i++;
    }
    int len = strlen(message);
    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        int m = message[i];
        m = m - 96;
        int c = 1;
        for (int j = 0; j < e; j++) {
            c *= m;
            c %= n;
        }
        printf("%d ", c);
    }
    printf("\n");
    printf("Decrypted message: ");
    for (i = 0; i < len; i++) {
        int c = message[i];
        c -= 96;
        int m = 1;
        for (int j = 0; j < d; j++) {
            m *= c;
            m %= n;
        }
        printf("%c", m + 96);
    }
    printf("\n");
    return 0;
}