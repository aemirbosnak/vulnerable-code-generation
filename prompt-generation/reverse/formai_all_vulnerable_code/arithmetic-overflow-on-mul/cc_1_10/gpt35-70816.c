//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int p, q, n, phi_n, e, d, i, message, encrypted_message, decrypted_message;
    p = 7;
    q = 11;
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // Find e such that gcd(e, phi(n)) = 1 and 1 < e < phi(n)
    for (i = 2; i < phi_n; i++) {
        if (gcd(i, phi_n) == 1) {
            e = i;
            break;
        }
    }

    // Find d such that ed ≡ 1mod(phi(n))
    i = 1;
    while (1) {
        if ((i * phi_n + 1) % e == 0) {
            d = (i * phi_n + 1) / e;
            break;
        }
        i++;
    }

    // Encrypt a message
    printf("Enter a number to encrypt: ");
    scanf("%d", &message);
    encrypted_message = 1;
    for (i = 0; i < e; i++) {
        encrypted_message = (encrypted_message * message) % n;
    }
    printf("Encrypted message: %d\n", encrypted_message);

    // Decrypt the message
    decrypted_message = 1;
    for (i = 0; i < d; i++) {
        decrypted_message = (decrypted_message * encrypted_message) % n;
    }
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}