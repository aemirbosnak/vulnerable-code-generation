//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to calculate gcd of two numbers
int gcd(int a,int b)
{
  if (b == 0) 
    return a;
  return gcd(b,a%b);
}

//function to calculate modular exponentiation
int mod_exp(int x,int y,int n)
{
  int result = 1;
  while (y > 0) {
    if (y % 2 == 1) 
      result = (result * x) % n;
    x = (x * x) % n;
    y = y / 2;
  }
  return result;
}

int main(void)
{
  int p, q, n, phi_n, e, d, message, encrypted, decrypted;

  //generate two random prime numbers
  p = rand() % 100 + 1;
  q = rand() % 100 + 1;

  //calculate n and phi(n)
  n = p*q;
  phi_n = (p-1)*(q-1);

  //calculate public key 'e' such that 1 < e < phi(n) and e is coprime with phi(n)
  for (e = 2; e < phi_n; e++) {
    if(gcd(e,phi_n) == 1)
      break;
  }

  //calculate private key 'd' such that d is the multiplicative inverse of e mod phi(n)
  int k=1;
  while(1) {
    k+=phi_n;
    if(k%e==0) 
      {
        d=k/e;
        break;
      }
  }

  //take the message input from user
  printf("\nEnter the message you want to encrypt: ");
  scanf("%d",&message);

  //encrypt the message
  encrypted = mod_exp(message,e,n);

  //print the encrypted message
  printf("\nEncrypted message is : %d",encrypted);

  //decrypt the message
  decrypted = mod_exp(encrypted,d,n);

  //print the decrypted message
  printf("\nDecrypted message is : %d\n",decrypted);

  return 0;
}