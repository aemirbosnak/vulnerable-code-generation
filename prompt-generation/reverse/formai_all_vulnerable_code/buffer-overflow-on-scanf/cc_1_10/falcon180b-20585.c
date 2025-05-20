//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int power(int base,int exponent)
{
    int result=1;
    for(int i=0;i<exponent;i++)
    {
        result=(result*base)%MAX;
    }
    return result;
}

int inverse(int num,int mod)
{
    int temp=num;
    int divisor=mod;
    int remainder=0;
    while(divisor!=0)
    {
        int quotient=temp/divisor;
        temp=divisor;
        divisor=remainder;
        remainder=temp%divisor;
    }
    return remainder;
}

void generate_key(int *public_key,int *private_key)
{
    int p=0,q=0,n=0,phi=0;
    int e=0,d=0;
    do
    {
        p=rand()%MAX;
        q=rand()%MAX;
        n=p*q;
        phi=(p-1)*(q-1);
        e=rand()%phi;
        d=inverse(e,phi);
    }while(gcd(e,phi)!=1);

    *public_key=n;
    *private_key=d;
}

int encrypt(int plaintext,int public_key)
{
    return power(plaintext,public_key)%MAX;
}

int decrypt(int ciphertext,int private_key)
{
    return power(ciphertext,private_key)% MAX;
}

int main()
{
    int public_key,private_key;
    generate_key(&public_key,&private_key);
    int plaintext,ciphertext;
    printf("Enter the plaintext: ");
    scanf("%d",&plaintext);
    ciphertext=encrypt(plaintext,public_key);
    printf("Ciphertext: %d\n",ciphertext);
    int decrypted_text=decrypt(ciphertext,private_key);
    printf("Decrypted text: %d\n",decrypted_text);
    return 0;
}