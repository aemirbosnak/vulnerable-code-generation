//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining our own version of a "Big Int" - because why not!
typedef struct {
    unsigned char *digits;
    int length;
} BigInt;

// Ah, the mystery of primes! 
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Generate a random prime number (with a sprinkle of luck)
int generate_random_prime() {
    int prime;
    srand(time(NULL)); // Seeds randomness – or rubbishness, depending on supply!
    
    do {
        prime = rand() % 100 + 2; // Generate a number between 2 and 101
    } while (!is_prime(prime));

    return prime;
}

// Compute the greatest common divisor (or "how to split pizza fairly")
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Extended Euclidean Algorithm, because why not extend the fun too!
int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd_val = extended_gcd(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
    
    return gcd_val;
}

// Modulo inverse - the secret handshake for the cool kids
int mod_inverse(int a, int m) {
    int x, y; 
    int gcd_val = extended_gcd(a, m, &x, &y);
    if (gcd_val != 1) {
        printf("Inverse doesn't exist! Just like my love life...\n");
        return -1; // Inverse doesn't exist
    }
    
    return (x % m + m) % m;
}

// The keypair generator that makes it all happen like magic!
void generate_keypair(int *publicKey, int *privateKey, int *n) {
    int p = generate_random_prime();
    int q = generate_random_prime();

    *n = p * q; // Our n, not to be confused with 'naps'.
    int phi = (p - 1) * (q - 1); // The friend of n, but way cooler

    do {
        *publicKey = rand() % (phi - 1) + 2; // Random e
    } while (gcd(*publicKey, phi) != 1); // Finding a best buddy

    // And now, the mysterious private key!
    *privateKey = mod_inverse(*publicKey, phi);
}

// A function to encrypt a message (or as some call it, "sending a secret text to my dog")
BigInt encrypt(BigInt plaintext, int publicKey, int n) {
    BigInt ciphertext;
    ciphertext.length = plaintext.length;
    ciphertext.digits = malloc(ciphertext.length);
    
    for (int i = 0; i < plaintext.length; i++) {
        // Simple encryption (because we like to keep it easy)
        ciphertext.digits[i] = (plaintext.digits[i] ^ publicKey) % n; 
    }
    return ciphertext;
}

// A function to decrypt a message (or translating dog barks back to human speech)
BigInt decrypt(BigInt ciphertext, int privateKey, int n) {
    BigInt decryptedtext;
    decryptedtext.length = ciphertext.length;
    decryptedtext.digits = malloc(decryptedtext.length);
    
    for (int i = 0; i < ciphertext.length; i++) {
        // Simple decryption (because who needs complexity in life?)
        decryptedtext.digits[i] = (ciphertext.digits[i] ^ privateKey) % n; 
    }
    return decryptedtext;
}

int main() {
    printf("Welcome to the Wacky World of C Public-Key Encryption!\n");
    int publicKey, privateKey, n;
    
    generate_keypair(&publicKey, &privateKey, &n);
    
    printf("Generated Public Key: %d\n", publicKey);
    printf("Generated Private Key: %d\n", privateKey);
    printf("Value of n: %d\n", n);

    // Let's pretend we have a message
    BigInt message;
    message.length = 5; // Message length
    message.digits = (unsigned char *)malloc(message.length);
    
    // "HELLO" in ASCII
    message.digits[0] = 'H'; 
    message.digits[1] = 'E';
    message.digits[2] = 'L';
    message.digits[3] = 'L';
    message.digits[4] = 'O';

    printf("Original Message: HELLO\n");

    // Encrypt the message
    BigInt encrypted = encrypt(message, publicKey, n);
    printf("Encrypted Message: ");
    for (int i = 0; i < encrypted.length; i++) {
        printf("%d ", encrypted.digits[i]);
    }
    printf("\n");

    // Decrypt the message
    BigInt decrypted = decrypt(encrypted, privateKey, n);
    printf("Decrypted Message: ");
    for (int i = 0; i < decrypted.length; i++) {
        printf("%c", decrypted.digits[i]);
    }
    printf("\n");

    // Free the memory (because we care!)
    free(message.digits);
    free(encrypted.digits);
    free(decrypted.digits);

    return 0;
}