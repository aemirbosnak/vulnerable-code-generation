//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int p,q,n,phi,e,d;
int prime[MAX],prime_count = 0;

int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int isPrime(int num)
{
    int i;
    for(i=2;i<num;i++)
    {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

void generatePrime()
{
    int i,j;
    for(i=2;i<MAX;i++)
    {
        if(isPrime(i))
        {
            prime[prime_count++] = i;
        }
    }
}

int generateKeys()
{
    int i,j,temp;
    p = prime[rand()%prime_count];
    q = prime[rand()%prime_count];
    n = p*q;
    phi = (p-1)*(q-1);

    for(i=2;i<phi;i++)
    {
        if(gcd(i,phi) == 1)
            break;
    }

    e = i;

    for(i = 1;i<phi;i++)
    {
        temp = (e*i)%phi;
        if(temp == 1)
        {
            d = i;
            break;
        }
    }

    if(i == phi - 1)
        return 0;
    else
        return 1;
}

int main()
{
    int i,j,len;
    char message[100];

    printf("Enter the plain text:\n");
    gets(message);

    len = strlen(message);

    generatePrime();

    if(!generateKeys())
    {
        printf("Key generation failed. Please try again.\n");
        return 0;
    }

    printf("p: %d, q: %d, n: %d, phi: %d, e: %d, d: %d\n",p,q,n,phi,e,d);

    int cipher[len],plain[len];

    for(i=0;i<len;i++)
    {
        plain[i] = message[i]-97;
    }

    //Encryption
    for(i=0;i<len;i++)
    {
        cipher[i] = pow(plain[i],e);
        cipher[i] = cipher[i] % n;
    }

    printf("Cipher text:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",cipher[i]);
    }
    printf("\n");

    //Decryption
    for(i=0;i<len;i++)
    {
        plain[i] = pow(cipher[i],d);
        plain[i] = plain[i] % n;
    }

    printf("Plain text:\n");
    for(i=0;i<len;i++)
    {
        printf("%c",plain[i]+97);
    }
    printf("\n");

    return 0;
}