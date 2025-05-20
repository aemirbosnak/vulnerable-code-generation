//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT 10000

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int p, q, n, phi_n, e, d, i, j, flag, option;
    char input[MAX_INPUT], message[MAX_INPUT];
    printf("Choose the operation you want to perform:\n1. Generate public and private keys\n2. Encrypt a message\n3. Decrypt a message\n");
    scanf("%d", &option);
    switch (option) {
        case 1: 
            srand(time(NULL));
            /* Generate two prime numbers p and q */
            do {
                p = rand() % 1000 + 1000;
            } while ((p % 2) == 0 || (p % 3) == 0);

            do {
                q = rand() % 1000 + 1000;
            } while ((q % 2) == 0 || (q % 3) == 0 || q == p);

            /* Calculate n and phi(n) */
            n = p * q;
            phi_n = (p - 1) * (q - 1);

            /* Find a value for e such that it is relatively prime to phi(n) */
            do {
                e = rand() % phi_n;
            } while (gcd(e, phi_n) != 1);

            /* Calculate d, the multiplicative inverse of e (mod phi_n) */
            for (i = 1; i < phi_n; i++) {
                if ((e * i) % phi_n == 1) {
                    d = i;
                    break;
                }
            }
            printf("Public key: (%d, %d)\nPrivate key: (%d, %d)\n", n, e, n, d);
            break;
        case 2:
            printf("Enter the message you want to encrypt:\n");
            scanf(" %[^\n]s", input);
            for (i = 0; input[i] != '\0'; i++) {
                message[i] = (int) input[i];
            }
            message[i] = '\0';
            printf("Enter the public key (n, e):\n");
            scanf("%d %d", &n, &e);
            printf("Encrypted message: ");
            for (i = 0; message[i] != '\0'; i++) {
                flag = 0;
                /* Calculate c = m^e % n */
                int m = message[i];
                int c = 1;
                for (j = 0; j < e; j++) {
                    c = (c * m) % n;
                }
                printf("%d ", c);
            }
            printf("\n");
            break;
        case 3:
            printf("Enter the encrypted message:\n");
            i = 0;
            do {
                scanf("%d", &d);
                /* Calculate m = c^d % n */
                int c = d;
                int m = 1;
                for (j = 0; j < d; j++) {
                    m = (m * c) % n;
                }
                message[i] = (char) m;
                i++;
            } while (getchar() != '\n');
            message[i] = '\0';
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid option.\n");
    }
    return 0;
}