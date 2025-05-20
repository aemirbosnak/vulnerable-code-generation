//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare global variables
int p, q, n, e, d, totient;

// Function to check if a number is prime
int is_prime(int number)
{
    int i;
    
    for(i=2; i<=number/2; i++)
    {
        if(number%i == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

// Function to generate two distinct prime numbers
void generate_primes()
{
    int i, flag = 0;
    
    while(flag == 0)
    {
        printf("Enter the value of p (a prime number): ");
        scanf("%d", &p);
        
        if(is_prime(p) == 0)
        {
            printf("p must be a prime number!\n");
            continue;
        }
        
        printf("Enter the value of q (a prime number): ");
        scanf("%d", &q);
        
        if(is_prime(q) == 0)
        {
            printf("q must be a prime number!\n");
            continue;
        }
        
        if(p == q)
        {
            printf("p and q must be distinct prime numbers!\n");
            continue;
        }
        
        flag = 1;
    }
}

// Function to calculate n and totient
void calculate_n_and_totient()
{
    n = p * q;
    totient = (p-1) * (q-1);
}

// Function to generate the public key
void generate_public_key()
{
    int i, flag = 0;
    
    while(flag == 0)
    {
        printf("Enter the value of e (a positive integer such that 1 < e < %d and gcd(e, %d) = 1): ", totient, totient);
        scanf("%d", &e);
        
        for(i=2; i<totient; i++)
        {
            if((totient%i == 0) && (e%i == 0))
            {
                flag = 0;
                printf("e must be a positive integer coprime with %d!\n", totient);
                break;
            }
        }
        
        if(i == totient)
        {
            flag = 1;
        }
    }
}

// Function to generate the private key
void generate_private_key()
{
    int k = 1;
    
    while(1)
    {
        k = k + totient;
        
        if(k%e == 0)
        {
            d = k/e;
            return;
        }
    }
}

// Function to encrypt a message
void encrypt()
{
    char message[100];
    int i, cipher[100];
    
    printf("Enter the message to encrypt: ");
    scanf("%s", message);
    
    for(i=0; i<strlen(message); i++)
    {
        cipher[i] = (int)message[i];
        cipher[i] = cipher[i]^e%n;
    }
    
    printf("The encrypted message is: ");
    
    for(i=0; i<strlen(message); i++)
    {
        printf("%d ", cipher[i]);
    }
    
    printf("\n");
}

// Function to decrypt a message
void decrypt()
{
    int cipher[100];
    char message[100];
    int i;
    
    printf("Enter the message to decrypt: ");
    
    for(i=0; ; i++)
    {
        scanf("%d", &cipher[i]);
        
        if(getchar() == '\n')
        {
            break;
        }
    }
    
    for(i=0; i<strlen(message); i++)
    {
        message[i] = (char)(cipher[i]^d%n);
    }
    
    printf("The decrypted message is: %s\n", message);
}

// Main function
int main()
{
    generate_primes();
    calculate_n_and_totient();
    generate_public_key();
    generate_private_key();
    
    int choice;
    
    while(1)
    {
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                encrypt();
                break;
                
            case 2:
                decrypt();
                break;
                
            case 3:
                printf("Exiting...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}