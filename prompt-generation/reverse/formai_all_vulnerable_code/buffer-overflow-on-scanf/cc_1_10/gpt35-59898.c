//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

bool isPrime(int n) {
    if(n <= 1)
        return false;
    else if(n <= 3)
        return true;
    else if(n % 2 == 0 || n % 3 == 0)
        return false;
    
    int i = 5;
    while(i*i <= n) {
        if(n % i == 0 || n % (i+2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int generatePrimeNumber() {
    int primeNumber, num;
    do {
        printf("Enter a prime number: ");
        scanf("%d",&num);

        if(isPrime(num) == true) {
            primeNumber = num;
            break;
        } else {
            printf("%d is not a prime number.\n",num);
        }
    } while(1);

    return primeNumber;
}

int generatePublicKey(int phiN, int e) {
    int publicKey = 0;
    while(gcd(phiN, e) != 1) {
        e++;
    }
    
    publicKey = e;
    return publicKey;
}

int generatePrivateKey(int phiN, int n, int e) {
    int privateKey = 0;
    int j = 1;

    while((j*phiN + 1) % e) {
        j++;
    }
    
    privateKey = ((j*phiN) + 1) / e;
    return privateKey;
}

void encryptMessage(int publicKey, int n, char *message) {
    int i = 0, encryptedNum = 0;

    printf("Encrypted message: ");
    while(message[i] != '\0') {
        int m = message[i];
        encryptedNum = fmod(pow(m,publicKey),n);
        printf("%d ",encryptedNum);
        i++;
    }
    printf("\n");
}

void decryptMessage(int privateKey, int n, int *encryptedMessage, int messageLength) {
    int i = 0, decryptedNum = 0;
    char decryptedMessage[messageLength];

    while(i < messageLength) {
        decryptedNum = fmod(pow(encryptedMessage[i],privateKey),n);
        decryptedMessage[i] = decryptedNum;
        i++;
    }
    decryptedMessage[i] = '\0';

    printf("Decrypted message: %s\n", decryptedMessage);
}

int main() {
    int p = 0, q = 0, n = 0, phiN = 0, e = 2, encryptedMessage[100];
    char message[100];

    printf("RSA Public-Key Algorithm Implementation\n");
    printf("=======================================\n");

    p = generatePrimeNumber();
    printf("p = %d\n",p);

    q = generatePrimeNumber();
    printf("q = %d\n",q);

    n = p * q;
    printf("n = %d\n",n);

    phiN = (p-1) * (q-1);
    printf("phi(n) = %d\n",phiN);   

    int publicKey = generatePublicKey(phiN, e);
    printf("Public key: %d\n",publicKey);

    int privateKey = generatePrivateKey(phiN, n, publicKey);
    printf("Private key: %d\n",privateKey);  

    printf("Enter message to encrypt: ");
    scanf(" %[^\n]s", message);
    
    int i = 0;
    while(message[i] != '\0') {
        int m = message[i];
        encryptedMessage[i] = fmod(pow(m, publicKey), n);
        i++;
    }

    encryptMessage(publicKey, n, message);
    decryptMessage(privateKey, n, encryptedMessage, i);

    return 0;
}