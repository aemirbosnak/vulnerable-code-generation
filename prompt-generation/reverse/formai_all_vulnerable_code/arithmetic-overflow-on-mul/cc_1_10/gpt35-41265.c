//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct key
{
    int p,q,n,e,d;  //p & q are prime, n=p*q, e as public key, d as private key 
};

bool isprime(int num)  //test whether num is prime
{
    if(num==2)
        return true;
    else if(num%2==0 || num==1)
        return false;
    else
    {
        for(int i=3;i<=num/2;i+=2)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
}

int gcd(int a,int b)  //compute gcd of a and b
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int generate_e(int phi)  //generate public key e 
{
    int e;
    for(e=3;e<phi;e+=2)
    {
        if(gcd(phi,e)==1)
            return e;
    }
    return e;
}

int generate_d(int e,int phi) //generate private key d
{
    int i=0,d;
    bool flag=false;
    while(flag==false)
    {
        i++;
        d = (1+i*phi)/e;
        if((1+i*phi)%e==0)
            flag=true;
    }
    return d;
}

int encrypt(int pt,int e,int n) //encrypt plaintext
{
    int ct=1;
    for(int i=0;i<e;i++)
        ct=(ct*pt)%n;
    return ct;
}

int decrypt(int ct,int d,int n) //decrypt ciphertext
{
    int pt=1;
    for(int i=0;i<d;i++)
        pt=(pt*ct)%n;
    return pt;
}

struct key generate_keypair()  //function to generate public and private key pair
{
    struct key k;
    k.p=13;
    k.q=19;
    k.n=k.p*k.q;
    int phi=(k.p-1)*(k.q-1);
    k.e=generate_e(phi);
    k.d=generate_d(k.e,phi);
    return k;
}

int main()
{
    struct key k=generate_keypair();
    int pt;
    printf("Enter plaintext (0-25): ");
    scanf("%d",&pt);
    int ct=encrypt(pt,k.e,k.n);  //encrypt plaintext
    printf("Ciphertext: %d\n",ct);
    int pt_dec=decrypt(ct,k.d,k.n);  //decrypt ciphertext
    printf("Decrypted plaintext: %d",pt_dec);
    return 0;
}