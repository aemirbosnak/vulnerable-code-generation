//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* A prime number checker function */
int isPrime(int num)
{
    int i;
    for(i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            return 0; //not a prime number
        }
    }
    return 1; //prime number
}

/* Function to find GCD of two numbers */
int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}

/* C program for RSA public key encryption algorithm implementation */
int main()
{
    int p,q,n,m,phi,e,d,ciphertext,message;
    printf("Enter two prime numbers p and q:\n");
    scanf("%d %d",&p,&q);

    /* Check if p and q are prime numbers */
    if(!isPrime(p) || !isPrime(q))
    {
        printf("Invalid input! Both numbers have to be prime numbers.\n");
        exit(0);
    }

    /* Calculate n = p*q */
    n = p*q;

    /* Calculate phi = (p-1)*(q-1) */
    phi = (p-1)*(q-1);

    /* Find an integer e such that 1 < e < phi and gcd(e,phi) = 1 */
    for(e=2;e<phi;e++)
    {
        if(gcd(e,phi)==1)
        {
            break;
        }
    }

    /* Calculate d such that d*e % phi = 1 */
    d = 0;
    while((d*e)%phi != 1)
    {
        d++;
    }

    printf("Enter a message to be encrypted:\n");
    scanf("%d",&message);

    /* Encrypt the message using Public key */
    ciphertext = pow(message,e);
    ciphertext = ciphertext%n;
    printf("Encrypted message: %d\n",ciphertext);

    /* Decrypt the message using Private key */
    m = pow(ciphertext,d);
    m = m%n;
    printf("Decrypted message: %d\n",m);

    return 0;
}