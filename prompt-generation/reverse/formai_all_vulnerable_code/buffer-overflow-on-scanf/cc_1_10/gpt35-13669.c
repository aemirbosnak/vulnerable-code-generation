//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include<stdio.h>
#include<math.h>

// Function to calculate exponentiation
int exponentiation(int base, int expo, int mod)
{
    int result = 1;

    while(expo > 0)
    {
        // If the current bit is 1, update the result
        if(expo & 1)
            result = (result*base)%mod;

        // Move to next bit position
        expo = expo >> 1;

        // Calculate the new base value
        base = (base*base)%mod;
    }

    return result;
}

// Function to check if a number is prime
int isPrime(int number)
{
    if(number <= 1)
        return 0;

    for(int i=2; i<sqrt(number); i++)
        if(number%i == 0)
            return 0;

    return 1;
}

// Function to find gcd of 2 numbers
int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a%b);
}

int main()
{
    int p, q, n, phi_n, e, d, message, encrypted_message, decrypted_message, p_minus_1, q_minus_1, l;

    // Key generation
    do{
        printf("Enter a prime number (p): ");
        scanf("%d", &p);
    }while(!isPrime(p));

    do{
        printf("Enter another prime number (q): ");
        scanf("%d", &q);
    }while(!isPrime(q));

    n = p*q;
    phi_n = (p-1)*(q-1);

    // Find a number e (1<e<phi_n) that is coprime to phi_n
    for(int i=2; i<phi_n; i++)
        if(gcd(i, phi_n) == 1)
        {
            e = i;
            break;
        }

    // Find d such that (d*e)%phi_n = 1
    p_minus_1 = p-1;
    q_minus_1 = q-1;
    l = (p_minus_1)*(q_minus_1)/gcd(p_minus_1, q_minus_1);

    for(int i=1; i<=phi_n; i++)
        if((l*i + 1)%e == 0)
        {
            d = (l*i + 1)/e;
            break;
        }

    printf("\nPublic key: {%d, %d}\n", e, n);
    printf("Private key: {%d, %d}\n", d, n);

    // Message encryption
    printf("\nEnter a message (integer): ");
    scanf("%d", &message);

    encrypted_message = exponentiation(message, e, n);
    printf("Encrypted message: %d\n", encrypted_message);

    // Message decryption
    decrypted_message = exponentiation(encrypted_message, d, n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}