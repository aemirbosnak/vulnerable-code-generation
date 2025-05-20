//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1000

// Function to Compute power a^b mod m
long long int power(long long int a,long long int b,long long int m){    
    long long int res = 1;    
    while(b > 0){        
        if(b % 2 == 1){        
            res = (res * a) % m;            
        }        
        a = (a * a) % m;
        b /= 2;    
    }
    return res;
}

// Function to check if a number is prime or not
int isPrime(long long int n){    
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;    
    for(long long int i = 3; i * i <= n; i += 2){
        if(n % i == 0) return 0;
    }    
    return 1;
}

// Function to generate Random Prime Number between min and max
long long int generatePrime(long long int min, long long int max){    
    srand(time(NULL));    
    long long int p = 0;    
    while(!isPrime(p)){        
        p = rand() % (max - min) + min;    
    }    
    return p;
}

// Function to generate Public Key
void generatePublicKey(long long int *n, long long int *e){    
    long long int phi, p, q;    
    p = generatePrime(1000, 5000); // generate a prime number between 1000 and 5000
    q = generatePrime(5000, 10000); // generate a prime number between 5000 and 10000    
    *n = p * q; // modulus    
    // calculate phi
    phi = (p - 1) * (q - 1);    
    // Finding Public key e such that 1 < e < phi and gcd(e, phi) = 1
    do{       
        *e = rand() % (phi - 2) + 2; // Generate a random integer from 2 to phi - 1        
    } while((phi % *e == 0) || power(*e, phi, phi) != 1);
}

// Function to encrypt a message
void encrypt(char *message, long long int *encrypted_message, long long int n, long long int e){    
    while(*message){        
        *encrypted_message = power((long long int)(*message), e, n);        
        ++message;        
        ++encrypted_message;    
    }    
    *encrypted_message = '\0';
}

// Function to decrypt a message
void decrypt(long long int *encrypted_message, char *decrypted_message, long long int n, long long int d){    
    while(*encrypted_message){        
        *decrypted_message = (char)power(*encrypted_message, d, n);        
        ++encrypted_message;        
        ++decrypted_message;    
    }    
    *decrypted_message = '\0';
}

int main(){    
    char message[MAX_SIZE], decrypted_message[MAX_SIZE];    
    long long int encrypted_message[MAX_SIZE] = {0}, n, e, d;    
    printf("Enter a message to encrypt: ");    
    scanf("%[^\n]s", message);    
    generatePublicKey(&n, &e);
    printf("Public Key (n, e) = (%lld, %lld)\n", n, e);
    // Compute private key d such that d*e = 1 mod (p-1)*(q-1)
    long long int phi, p, q;
    p = generatePrime(1000, 5000); // generate a prime number between 1000 and 5000
    q = generatePrime(5000, 10000); // generate a prime number between 5000 and 10000
    phi = (p - 1) * (q - 1);
    d = power(e, phi - 1, phi);
    printf("Private Key (d) = %lld\n", d);
    encrypt(message, encrypted_message, n, e);    
    printf("Encrypted Message: ");    
    for(int i = 0; encrypted_message[i]; ++i){        
        printf("%lld ", encrypted_message[i]);    
    }    
    printf("\n");    
    decrypt(encrypted_message, decrypted_message, n, d);    
    printf("Decrypted Message: %s\n", decrypted_message);    
    return 0;
}