//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000 // max length of message
#define MAX_PRIME 1000 // max value of prime numbers

int pow_mod(int base, int exp, int mod) // function for calculating ((base^exp) mod mod)
{
    int res = 1;
    while(exp > 0)
    {
        if(exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return res;
}

void generate_keys(int p, int q, int *public_key, int *private_key) // function for generating public and private keys
{
    int n = p * q; // calculate n
    int phi = (p - 1) * (q - 1); // calculate euler's totient function
    int e = 3; // set e to default value
    
    // find a value for e such that e is coprime to phi
    while(e < phi)
    {
        int gcd = 1;
        for(int i = 2; i <= e && i <= phi; i++)
        {
            if(e % i == 0 && phi % i == 0)
            {
                gcd = i;
            }
        }
        if(gcd == 1)
        {
            break;
        }
        else
        {
            e++;
        }
    }
    
    // calculate d such that (e*d) mod phi = 1
    int k = 2;
    int d = (1 + (k * phi)) / e;
    while(d < n)
    {
        int check = (e * d) % phi;
        if(check == 1)
        {
            break;
        }
        else
        {
            k++;
            d = (1 + (k * phi)) / e;
        }
    }
    
    // set public and private keys
    *public_key = e;
    *private_key = d;
}

void encrypt_message(char *message, int *encrypted_message, int length, int public_key, int n) // function for encrypting message
{
    for(int i = 0; i < length; i++)
    {
        int m = message[i]; // get ascii value of character
        int c = pow_mod(m, public_key, n); // calculate encrypted value using public key
        encrypted_message[i] = c;
    }
}

void decrypt_message(int *encrypted_message, char *decrypted_message, int length, int private_key, int n) // function for decrypting message
{
    for(int i = 0; i < length; i++)
    {
        int c = encrypted_message[i]; // get encrypted value
        int m = pow_mod(c, private_key, n); // calculate decrypted value using private key
        decrypted_message[i] = (char)m; // convert ascii value to character
    }
}

int main(void)
{
    int p, q, public_key, private_key, n;
    char message[MAX_LENGTH];
    int encrypted_message[MAX_LENGTH];
    char decrypted_message[MAX_LENGTH];
    
    // get prime values for p and q
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter another prime number (q): ");
    scanf("%d", &q);
    
    // check if p and q are prime
    int flag1 = 1, flag2 = 1;
    for(int i = 2; i <= sqrt(p); i++)
    {
        if(p % i == 0)
        {
            flag1 = 0;
            break;
        }
    }
    for(int i = 2; i <= sqrt(q); i++)
    {
        if(q % i == 0)
        {
            flag2 = 0;
            break;
        }
    }
    if(flag1 == 0 || flag2 == 0 || p > MAX_PRIME || q > MAX_PRIME)
    {
        printf("Invalid prime values.\n");
        return 0;
    }
    
    // generate public and private keys
    generate_keys(p, q, &public_key, &private_key);
    n = p * q;
    
    // get message to encrypt
    printf("Enter a message to encrypt: ");
    getchar();
    fgets(message, MAX_LENGTH, stdin);
    int length = strlen(message) - 1; // remove \n from end of message
    
    // encrypt message using public key
    encrypt_message(message, encrypted_message, length, public_key, n);
    
    // print encrypted message
    printf("Encrypted message: ");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");
    
    // decrypt message using private key
    decrypt_message(encrypted_message, decrypted_message, length, private_key, n);
    
    // print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}