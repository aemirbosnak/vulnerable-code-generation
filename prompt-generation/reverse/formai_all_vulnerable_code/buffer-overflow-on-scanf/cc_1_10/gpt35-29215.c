//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Euclid's algorithm for finding greatest common divisor*/
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/*Generates a random prime number*/
int generatePrime(int n) {
    int i, j, flag;
    srand(time(NULL));
    for (i = n + 1;; i++) {
        flag = 1;
        for (j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            return i;
        }
    }
}

/*Generate public & private keys*/
void generateKeys(int *e, int *d, int *n) {
    int p, q, tn, i;
    p = generatePrime(50);
    q = generatePrime(100);
    *n = p * q;
    tn = (p - 1) * (q - 1);
    *e = 2;
    while(1) {
        if(gcd(*e, tn) == 1) {
            break;
        }
        (*e)++;
    }
    i = 1;
    while(1) {
        if(((i * tn) + 1) % *e == 0) {
            *d = ((i * tn) + 1) / *e;
            break;
        }
        i++;
    }
}

/*Encrypt the message*/
unsigned long long encrypt(int message, int e, int n) {
    unsigned long long temp = 1;
    int i;
    for(i = 0; i < e; i++) {
        temp = (temp * message) % n;
    }
    return temp;
}

/*Decrypt the message*/
int decrypt(unsigned long long message, int d, int n) {
    unsigned long long temp = 1;
    int i;
    for(i = 0; i < d; i++) {
        temp = (temp * message) % n;
    }
    return temp;
}

int main() {
    int e, d, n, m;
    char message[100];
    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);
    printf("Enter value of m: ");
    scanf("%d", &m);
    generateKeys(&e, &d, &n);
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    int len = strlen(message);
    int i, j=0, temp, temp2;
    unsigned long long encryptedMessage[len];
    printf("Encrypted message: ");
    for(i=0; i<len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            temp = message[i] - 'a' + 1;
            temp2 = encrypt(temp, e, n);
            printf("%llu ", temp2);
            encryptedMessage[j++] = temp2;
        }
    }
    printf("\nDecrypted message: ");
    for(i=0; i<j; i++) {
        temp = decrypt(encryptedMessage[i], d, n);
        temp -= 1;
        printf("%c", temp + 'a');
    }
}