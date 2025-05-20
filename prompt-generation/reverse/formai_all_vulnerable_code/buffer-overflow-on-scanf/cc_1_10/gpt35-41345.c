//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 10000 // Maximum number of digits allowed in the input message

int is_prime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int generate_keys(int p, int q, int *p_n, int *p_e, int *p_d) {
    int n, phi_n, e, d;
    if(!is_prime(p) || !is_prime(q)) {
        printf("Error: Both p and q should be prime numbers\n");
        return 0;
    }
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    e = 2;
    while(e < phi_n && gcd(e, phi_n) != 1) {
        e++;
    }
    if(e >= phi_n) {
        printf("Error: Could not generate the public key\n");
        return 0;
    }
    d = 0;
    while((e * d) % phi_n != 1) {
        d++;
    }
    *p_n = n;
    *p_e = e;
    *p_d = d;
    return 1;
}

int mod_pow(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void encrypt_message(char *msg, int msg_len, int n, int e) {
    int i, j;
    int *digits = (int *)malloc(msg_len * sizeof(int));
    int *encrypted_digits = (int *)malloc(msg_len * sizeof(int));
    for(i = 0; i < msg_len; i++) {
        digits[i] = msg[i] - '0'; // convert character to integer
    }
    for(i = 0; i < msg_len; i++) {
        encrypted_digits[i] = mod_pow(digits[i], e, n);
    }
    printf("Encrypted message: ");
    for(i = 0; i < msg_len; i++) {
        printf("%d", encrypted_digits[i]);
    }
    printf("\n");
    free(digits);
    free(encrypted_digits);
}

void decrypt_message(int *encrypted_digits, int msg_len, int n, int d) {
    int i;
    int *decrypted_digits = (int *)malloc(msg_len * sizeof(int));
    for(i = 0; i < msg_len; i++) {
        decrypted_digits[i] = mod_pow(encrypted_digits[i], d, n);
    }
    printf("Decrypted message: ");
    for(i = 0; i < msg_len; i++) {
        printf("%c", decrypted_digits[i] + '0'); // convert integer to character
    }
    printf("\n");
    free(decrypted_digits);
}

int main() {
    int p, q, n, e, d;
    char msg[MAX_DIGITS];
    int i, msg_len;
    printf("Enter two prime numbers p and q: ");
    scanf("%d%d", &p, &q);
    if(!generate_keys(p, q, &n, &e, &d)) {
        return 1;
    }
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);
    printf("Enter a message to encrypt: ");
    scanf("%s", msg);
    msg_len = strlen(msg);
    encrypt_message(msg, msg_len, n, e);
    int *encrypted_digits = (int *)malloc(msg_len * sizeof(int));
    for(i = 0; i < msg_len; i++) {
        encrypted_digits[i] = msg[i] - '0'; // convert character to integer
    }
    decrypt_message(encrypted_digits, msg_len, n, d);
    free(encrypted_digits);
    return 0;
}