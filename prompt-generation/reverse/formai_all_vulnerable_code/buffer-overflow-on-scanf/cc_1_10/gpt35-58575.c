//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defining variables for prime numbers
int p, q, n, totient, e, d;

//Function to calculate greatest common factor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

//Function to encrypt data using public key
void Encryp(int *a, int n, int e) {
    int j;
    for (j = 0; j < strlen(a); j++) {
        int ch;
        ch = a[j];
        int i, k;

        //Encrypting data with public key
        k = 1;
        for (i = 0; i < e; i++) {
            k *= ch;
            k %= n;
        }
        a[j] = k;
    }
}

//Function to decrypt data using private key
void Decryp(int *a, int n, int d) {
    int j;
    for (j = 0; j < strlen(a); j++) {
        int ch;
        ch = a[j];
        int i, k;

        //Decrypting data with private key
        k = 1;
        for (i = 0; i < d; i++) {
            k *= ch;
            k %= n;
        }
        a[j] = k;
    }
}

//Function to generate prime numbers
int GeneratePrime() {
    int num, i, flag;
    num = (rand() % 100) + 1;
    while (1) {
        flag = 0;
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return num;
        else
            num++;
    }
}

int main() {
    //Generating prime numbers
    srand(time(NULL));
    p = GeneratePrime();
    q = GeneratePrime();

    //Calculating RSA parameters
    n = p * q;
    totient = (p - 1) * (q - 1);

    //Selecting public key e
    for (e = 2; e < totient; e++) {
        if (gcd(e, totient) == 1)
            break;
    }

    //Calculating private key d
    int k = 1;
    while (1) {
        k = k + totient;
        if (k % e == 0) {
            d = k / e;
            break;
        }
    }

    //Taking user input for data
    char data[1000];
    printf("Enter data to be encrypted: ");
    scanf("%s", data);

    //Encrypting data
    Encryp(data, n, e);
    printf("Encrypted data: %s\n", data);

    //Decrypting data
    Decryp(data, n, d);
    printf("Decrypted data: %s\n", data);
    return 0;
}