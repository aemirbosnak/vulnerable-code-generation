//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
struct Keys {
    int publicKey;  
    int privateKey; 
};
 
struct Keys generateKeys() {
    struct Keys keys;
    int p, q, n, t, flag, e, d;
 
    // p and q are large prime numbers
    printf("Enter two prime numbers:\n");
    scanf("%d %d", &p, &q);
 
    // calculating n and t
    n = p * q;
    t = (p - 1) * (q - 1);
 
    // finding a number e such that gcd of e and t is 1
    printf("Choose a number for public key: ");
    scanf("%d", &e);
 
    flag = 0;
    for (int i = 2; i < e; i++) {
        if (t % i == 0) continue;
        flag = 1;
 
        for (int j = 2; j < e; j++) {
            if (i != j && e % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) break;
    }
 
    // calculate private key
    d = 0;
    while ((d * e) % t != 1) d++;
 
    keys.publicKey = e;
    keys.privateKey = d;
 
    return keys;
}
 
void encryption(int publicKey, char message[]) {
    int i, length = strlen(message), encryptedMessage[length];
    printf("Encrypted message: ");
 
    for (i = 0; i < length; i++) {
        encryptedMessage[i] = pow(message[i], publicKey);
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");
}
 
void decryption(int privateKey, char message[]) {
    int i, length = strlen(message), decryptedMessage[length];
    printf("Decrypted message: ");
 
    for (i = 0; i < length; i++) {
        decryptedMessage[i] = pow(message[i], privateKey);
        printf("%c", decryptedMessage[i]);
    }
    printf("\n");
}
 
int main() {
    char message[100];
    struct Keys keys;
 
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
 
    keys = generateKeys();
 
    printf("Public Key: %d\n", keys.publicKey);
    printf("Private key: %d\n", keys.privateKey);
 
    encryption(keys.publicKey, message);
    decryption(keys.privateKey, message);
 
    return 0;
}