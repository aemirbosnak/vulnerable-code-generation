//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 100

// function to find gcd of two numbers
int gcd(int a, int b) 
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// function to generate public and private key
void generate_key(char *public_key, char *private_key) 
{
    srand(time(NULL));
    int p = rand() % MAX + 1;
    int q = rand() % MAX + 1;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = rand() % phi + 1;
    while (gcd(e, phi) != 1) 
    {
        e = rand() % phi + 1;
    }
    int d = 0;
    int k = 1;
    while (d == 0) 
    {
        d = (k * phi + 1) / e;
        k++;
    }
    sprintf(public_key, "%d,%d", n, e);
    sprintf(private_key, "%d,%d", n, d);
}

// function to encrypt the message
char *encrypt_msg(char *msg, char *public_key) 
{
    char *encrypted_msg = (char*) malloc(strlen(msg)*sizeof(char));
    char *token = strtok(public_key, ",");
    int n = atoi(token);
    token = strtok(NULL, ",");
    int e = atoi(token);
    int i, j, len = strlen(msg);
    int *encrypted = (int*) malloc(len*sizeof(int));
    for (i = 0; i < len; i++) 
    {
        encrypted[i] = 1;
        for (j = 0; j < msg[i]; j++) 
        {
            encrypted[i] = (encrypted[i] * e) % n;
        }
    }
    for (i = 0; i < len; i++) 
    {
        sprintf(&encrypted_msg[i*2], "%02d", encrypted[i]);
    }
    free(encrypted);
    return encrypted_msg;
}

// function to decrypt the message
char *decrypt_msg(char *encrypted_msg, char *private_key) 
{
    char *decrypted_msg = (char*) malloc(strlen(encrypted_msg)*sizeof(char)/2+1);
    char *token = strtok(private_key, ",");
    int n = atoi(token);
    token = strtok(NULL, ",");
    int d = atoi(token);
    int i, j, k, len = strlen(encrypted_msg)/2;
    int *encrypted = (int*) malloc(len*sizeof(int));
    for (i = 0; i < len; i++) 
    {
        sscanf(&encrypted_msg[i*2], "%02d", &encrypted[i]);
    }
    for (i = 0; i < len; i++) 
    {
        k = 1;
        for (j = 0; j < d; j++) 
        {
            k = (k * encrypted[i]) % n;
        }
        decrypted_msg[i] = k;
    }
    decrypted_msg[i] = '\0';
    free(encrypted);
    return decrypted_msg;
}

// main function
int main() 
{
    char msg[MAX], public_key[MAX], private_key[MAX], *encrypted_msg, *decrypted_msg;
    printf("Enter a message to encrypt: ");
    fgets(msg, MAX, stdin);
    msg[strcspn(msg, "\n")] = 0;
    generate_key(public_key, private_key);
    printf("\nPublic Key: %s\n", public_key);
    printf("Private Key: %s\n\n", private_key);
    encrypted_msg = encrypt_msg(msg, public_key);
    printf("Encrypted Message: %s\n", encrypted_msg);
    decrypted_msg = decrypt_msg(encrypted_msg, private_key);
    printf("Decrypted Message: %s\n", decrypted_msg);
    free(encrypted_msg);
    free(decrypted_msg);
    return 0;
}