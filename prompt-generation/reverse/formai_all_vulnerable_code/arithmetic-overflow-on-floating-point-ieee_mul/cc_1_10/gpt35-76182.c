//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
// C program for implementation of public-key algorithm
 
#include <stdio.h>
#include <math.h>
 
// Euclidean algorithm to find GCD
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}
 
// Extended Euclidean algorithm to find private key
int findPrivateKey(int e, int phi)
{
    int d=0;
    int x1=0, y1=1, x2=1, y2=0;
    int q, r, x, y;
    while (e>0)
    {
        q = phi/e;
        r = phi - q*e;
        x = x2 - q*x1;
        y = y2 - q*y1;
        phi = e;
        e = r;
        x2 = x1; x1 = x;
        y2 = y1; y1 = y;
    }
    d = y2;
    return d;
}
 
// RSA algorithm to encrypt the message
int encryptMsg(int msg, int e, int n)
{
    int cipher = pow(msg, e);
    cipher %= n;
    return cipher;
}
 
// RSA algorithm to decrypt the message
int decryptMsg(int cipher, int d, int n)
{
    int msg = pow(cipher, d);
    msg %= n;
    return msg;
}
 
int main()
{
    int p = 3;
    int q = 7;
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e = 2;
    while (e < phi)
    {
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }
    int d = findPrivateKey(e, phi);
    int msg = 12;
    printf("Original Message: %d", msg);
    int cipher = encryptMsg(msg, e, n);
    printf("\nEncrypted Message: %d", cipher);
    int decMsg = decryptMsg(cipher, d, n);
    printf("\nDecrypted Message: %d", decMsg);
    return 0;
}