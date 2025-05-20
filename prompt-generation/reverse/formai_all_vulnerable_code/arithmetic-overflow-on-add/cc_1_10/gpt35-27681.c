//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

// Euclid's Algorithm to find the Greatest Common Divisor of two numbers
int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

//Exponentiation by Squaring Algorithm to compute modular exponentiation
int exp_by_squaring(int base, int exponent, int mod){
    int res = 1;
 
    while (exponent > 0){
        if ((exponent % 2) == 1)
            res = (res * base) % mod;
 
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
 
    return res;
}

// Function to check if a number is prime or not using Miller-Rabin Algorithm
bool is_prime(int n, int k){
    // k is the number of iterations
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d = d / 2;
 
    for (int i = 0; i < k; i++){
        int a = 2 + rand() % (n - 4);
        int x = exp_by_squaring(a, d, n);
 
        if (x == 1 || x == n - 1)
            continue;
 
        for (int j = 0; j < d - 1; j++){
            x = exp_by_squaring(x, 2, n);
            if (x == n - 1)
                break;
            if (x == 1)
                return false;
        }
 
        if (x != n - 1)
            return false;
    }
 
    return true;
}

int main(){
    srand(time(NULL));
    int p, q, n, phi, e, d, message, cipher;
    printf("Enter two distinct prime numbers p and q: ");
    scanf("%d %d", &p, &q);

    if(!is_prime(p, 10) || !is_prime(q, 10)){
        printf("\nInvalid choice of prime numbers. Please try again.");
        exit(0);
    }

    n = p * q;
    phi = (p-1) * (q-1);

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    do{
        e = rand()%(phi-2)+2;
    }while(gcd(e,phi)!=1);
    
    //Compute d such that d*e = 1 mod phi
    int k = 1;
    while((k*phi + 1)%e!=0)
        k++;
    d = (k*phi + 1)/e;

    printf("\nEnter the message to be encrypted: ");
    scanf("%d", &message);

    //Encryption
    cipher = exp_by_squaring(message, e, n);
    printf("\nThe encrypted message is: %d", cipher);

    //Decryption
    int decrypted_message = exp_by_squaring(cipher, d, n);
    printf("\nThe decrypted message is: %d", decrypted_message);

    return 0;
}