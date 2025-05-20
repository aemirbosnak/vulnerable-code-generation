//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main() {

    char message[100];
    int p, q, n, z, d, e, i, j, flag;
    printf("Enter a message: ");
    scanf("%[^\n]", message);
    
    // Generate two large prime numbers
    p = 17;
    q = 19;

    // Calculate n and z
    n = p * q;
    z = (p-1) * (q-1);

    // Find e such that gcd(e, z) = 1
    e = 7;

    // Find d such that d*e mod z = 1
    d = 23;

    // Encrypt the message using public key (n, e)
    long int encrypted_message[strlen(message)];
    for(i = 0; message[i] != '\0'; i++) {
        int m = message[i];
        long int c = 1;
        for(j = 0; j < e; j++) {
            c = c * m;
            c = c % n;
        }
        encrypted_message[i] = c;
    }
    encrypted_message[i] = -1;

    printf("\nEncrypted message: ");
    for(i = 0; encrypted_message[i] != -1; i++) {
        printf("%ld ", encrypted_message[i]);
    }

    // Decrypt the message using private key (n, d)
    char decrypted_message[strlen(message)];
    for(i = 0; encrypted_message[i] != -1; i++) {
        int c = encrypted_message[i];
        int m = 1;
        for(j = 0; j < d; j++) {
            m = m * c;
            m = m % n;
        }
        decrypted_message[i] = m;
    }
    decrypted_message[i] = '\0';

    printf("\nDecrypted message: %s\n", decrypted_message);
    return 0;
}