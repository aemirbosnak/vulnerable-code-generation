//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define PRIME1 3   //First prime number
#define PRIME2 7   //Second prime number
#define MAX_VALUE 10000  //Maximum value of the random number
#define PUBLIC_KEY 5     //Public key


//Function to generate a random number
int generateRandomNumber() {
    srand(time(NULL));  //Seed to generate random number
    int num = rand() % MAX_VALUE + 1;  //Generate a random number between 1 and MAX_VALUE
    return num;
}

//Function to calculate modular exponentiation
int modularExponentiation(int base, int exponent, int modulo) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    int message, encryptedMessage, decryptedMessage;
    int alicePrivateKey, alicePublicKey, bobPublicKey;
    int sharedSecret1, sharedSecret2;
    int primeProduct = PRIME1 * PRIME2;
    int totient = (PRIME1 - 1) * (PRIME2 - 1);  //Compute totient
    
    //Generate a random number as Alice's private key
    alicePrivateKey = generateRandomNumber();
    
    //Compute Alice's public key 
    alicePublicKey = modularExponentiation(PUBLIC_KEY, alicePrivateKey, primeProduct);
    
    //Generate a random number as Bob's public key
    bobPublicKey = generateRandomNumber();
    
    //Compute shared secret
    sharedSecret1 = modularExponentiation(bobPublicKey, alicePrivateKey, primeProduct);
    sharedSecret2 = modularExponentiation(alicePublicKey, bobPublicKey, primeProduct);
    
    //Check that shared secrets match
    if(sharedSecret1 == sharedSecret2) {
        printf("Shared secret computed successfully!\n");
    }
    else {
        printf("Error computing shared secret\n");
        exit(1);
    }
    
    //Encrypt a message using Bob's public key
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    encryptedMessage = modularExponentiation(message, bobPublicKey, primeProduct);
    printf("Encrypted message: %d\n", encryptedMessage);
    
    //Decrypt the message using Alice's private key
    decryptedMessage = modularExponentiation(encryptedMessage, alicePrivateKey, primeProduct);
    printf("Decrypted message: %d\n", decryptedMessage);
    
    return 0;
}