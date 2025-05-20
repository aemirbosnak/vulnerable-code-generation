//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEY_SIZE 100

// Function to check if a number is prime or not
bool isPrime(int n) {
    int i;
    bool flag = true;
  
    for(i = 2; i <= n / 2; ++i) {
        if(n % i == 0) {
            flag = false;
            break;
        }
    }
  
    return flag;
}

// Function to generate public and private keys
void generate_keypair(int p, int q, int *rsa_public_key, int *rsa_private_key) {
    int n = p * q;
    int euler = (p - 1) * (q - 1);
    int e, d;
  
    // Generate a random prime number less than Euler's totient
    do{
        e = rand() % euler;
    }
    while(e <= 1 || !isPrime(e) || e == p || e == q);
  
    // Calculate d such that (d * e) % Euler's totient = 1
    int k = 1;
  
    do{
        k += euler;
        d = (k * euler + 1) / e;
    }
    while(d == p || d == q || ((d * e) % euler != 1));
  
    *rsa_public_key = e;
    *rsa_private_key = d;
}

// Function to encrypt the message using public key
void encrypt_message(char *message, int length, int key, int n) {
    int i, c;
  
    for(i = 0; i < length; ++i) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            c = message[i] - 'A';
            c = (c * key) % n;
            message[i] = c + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            c = message[i] - 'a';
            c = (c * key) % n;
            message[i] = c + 'a';
        }
    }
}

// Function to decrypt the message using private key
void decrypt_message(char *message, int length, int key, int n) {
    int i, c;
    int inverse_key = n - key + 1;
  
    for(i = 0; i < length; ++i) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            c = message[i] - 'A';
            c = (c * inverse_key) % n;
            message[i] = c + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            c = message[i] - 'a';
            c = (c * inverse_key) % n;
            message[i] = c + 'a';
        }
    }
}

int main() {
    int p, q, rsa_public_key, rsa_private_key;
    char message[MAX_KEY_SIZE];
    int message_length;
  
    printf("Enter two prime numbers (p and q) separated by a space: ");
    scanf("%d %d", &p, &q);
  
    if(!isPrime(p) || !isPrime(q)) {
        printf("Invalid input! Both numbers should be prime.\n");
        return 0;
    }
  
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
  
    rsa_public_key = 0;
    rsa_private_key = 0;
  
    generate_keypair(p, q, &rsa_public_key, &rsa_private_key);
  
    printf("Public Key: %d\nPrivate Key: %d\n", rsa_public_key, rsa_private_key);
  
    message_length = strlen(message);
  
    encrypt_message(message, message_length, rsa_public_key, p * q);
  
    printf("Encrypted Message: %s\n", message);
  
    decrypt_message(message, message_length, rsa_private_key, p * q);
  
    printf("Decrypted Message: %s\n", message);
  
    return 0;
}