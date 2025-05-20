//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000 // Maximum number of digits in the numbers

// Function to calculate gcd of two numbers
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to check if a number is prime or not
int isPrime(int n){
    if(n <= 1)
        return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generateRandomPrime(){
    int n;
    do{
        n = rand() % 1000 + 1;
    } while(!isPrime(n));
    return n;
}

// Function to generate public and private keys
void generateKeys(int p, int q, int *e, int *d, int *n){
    // Calculating n and totient of n
    *n = p * q;
    int phiN = (p - 1) * (q - 1);

    // Generating random e such that 1 < e < phiN and gcd(e,phiN) = 1
    do{
        *e = rand() % (phiN - 1) + 1;
    } while(gcd(*e, phiN) != 1);

    // Calculating d such that d*e mod phiN = 1
    int k = 1;
    while(1){
        *d = (k * phiN + 1) / *e;
        if((*d) * (*e) % phiN == 1)
            break;
        k++;
    }
}

// Function to calculate power of a number mod n
int powerModulo(int a, int p, int n){
    if(p == 0)
        return 1;
    int t = powerModulo(a, p/2, n);
    if(p % 2 == 0)
        return (t * t) % n;
    else
        return ((a * t * t) % n);
}

int main(){
    printf("**** C Public-Key Algorithm ****\n\n");

    // Getting input from user
    int p, q, e, d, n;
    printf("Enter first prime number: ");
    scanf("%d", &p);
    printf("Enter second prime number: ");
    scanf("%d", &q);

    // Checking if input numbers are prime or not
    if(!isPrime(p) || !isPrime(q)){
        printf("Error: Input numbers should be prime.\n");
        return 0;
    }

    // Generating public and private keys
    generateKeys(p, q, &e, &d, &n);
    printf("\nPublic key: %d, %d\nPrivate key: %d, %d\n\n", e, n, d, n);

    // Getting message from user
    char message[MAX];
    printf("Enter message: ");
    scanf(" %[^\n]", message);

    // Encrypting message
    printf("Encrypted message: ");
    for(int i = 0; i < strlen(message); i++){
        int ascii = (int) message[i];
        int cipher = powerModulo(ascii, e, n);
        printf("%d ", cipher);
    }

    // Decrypting message
    printf("\nDecrypted message: ");
    for(int i = 0; i < strlen(message); i++){
        int cipher = (int) message[i];
        int ascii = powerModulo(cipher, d, n);
        printf("%c", (char) ascii);
    }
    printf("\n");

    return 0;
}