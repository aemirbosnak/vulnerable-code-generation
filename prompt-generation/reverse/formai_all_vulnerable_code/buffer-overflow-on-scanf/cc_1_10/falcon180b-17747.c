//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define PRIME 101

int isPrime(int num);
void generateKeys(int *pubKey, int *privKey);
int encrypt(int pubKey, int message);
int decrypt(int privKey, int encryptedMessage);

int main()
{
    int pubKey, privKey, message, encryptedMessage, decryptedMessage;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    generateKeys(&pubKey, &privKey);
    encryptedMessage = encrypt(pubKey, message);
    printf("Encrypted message: %d\n", encryptedMessage);
    decryptedMessage = decrypt(privKey, encryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);
    return 0;
}

int isPrime(int num)
{
    int i;
    for(i=2; i<=num/2; i++)
    {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

void generateKeys(int *pubKey, int *privKey)
{
    int i, j;
    srand(time(NULL));
    for(i=0; i<MAX; i++)
    {
        if(isPrime(i))
        {
            *pubKey = i;
            break;
        }
    }
    for(j=0; j<MAX; j++)
    {
        if(isPrime(j))
        {
            *privKey = j;
            break;
        }
    }
}

int encrypt(int pubKey, int message)
{
    int encryptedMessage = 0;
    int i;
    for(i=0; i<MAX; i++)
    {
        if(isPrime(i))
        {
            encryptedMessage += message*pow(pubKey, i);
        }
    }
    return encryptedMessage;
}

int decrypt(int privKey, int encryptedMessage)
{
    int decryptedMessage = 0;
    int i;
    for(i=0; i<MAX; i++)
    {
        if(isPrime(i))
        {
            decryptedMessage += encryptedMessage/pow(privKey, i);
        }
    }
    return decryptedMessage;
}