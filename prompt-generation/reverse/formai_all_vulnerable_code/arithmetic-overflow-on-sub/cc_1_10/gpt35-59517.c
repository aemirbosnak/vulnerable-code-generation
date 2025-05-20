//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to check if a number is prime or not
int is_prime(int num) {
   int i;
   for(i = 2; i <= sqrt(num); i++) {
      if(num % i == 0) {
         return 0;
      }
   }
   return 1;
}

//function to find gcd of two numbers
int gcd(int a, int b) {
   int temp;
   while(1) {
      temp = a % b;
      if(temp == 0) {
         return b;
      }
      a = b;
      b = temp;
   }
}

//function to generate public and private keys
void generate_key_pairs(int p, int q, int *n, int *e, int *d) {
   int phi, flag;
   
   //checking if p and q are prime numbers
   flag = is_prime(p);
   if(flag == 0) {
      printf("Error: p is not a prime number\n");
      exit(1);
   }
   flag = is_prime(q);
   if(flag == 0) {
      printf("Error: q is not a prime number\n");
      exit(1);
   }
   
   //calculating n
   *n = p * q;
   
   //calculating phi
   phi = (p - 1) * (q - 1);
   
   //choosing e such that 1 < e < phi and gcd(e, phi) = 1
   do {
      *e = rand() % phi;
   } while(gcd(*e, phi) != 1);
   
   //calculating d such that d * e ≡ 1 (mod phi)
   *d = 0;
   while((*d * *e) % phi != 1) {
      (*d)++;
   }
}

//function to encrypt the plain text using public key
int encrypt(int plain_text, int e, int n) {
   int cipher_text = 1;
   while(e > 0) {
      cipher_text *= plain_text;
      cipher_text %= n;
      e--;
   }
   return cipher_text;
}

//function to decrypt the cipher text using private key
int decrypt(int cipher_text, int d, int n) {
   int plain_text = 1;
   while(d > 0) {
      plain_text *= cipher_text;
      plain_text %= n;
      d--;
   }
   return plain_text;
}

int main() {
   int p, q, n, e, d;
   int plain_text, cipher_text, decrypted_text;
   
   //getting input values for p and q
   printf("Enter a prime number for p: ");
   scanf("%d", &p);
   printf("Enter a prime number for q: ");
   scanf("%d", &q);
   
   //generating public and private keys
   generate_key_pairs(p, q, &n, &e, &d);
   
   //getting input plain text
   printf("Enter the plain text: ");
   scanf("%d", &plain_text);
   
   //encrypting the plain text using public key
   cipher_text = encrypt(plain_text, e, n);
   printf("The cipher text is: %d\n", cipher_text);
   
   //decrypting the cipher text using private key
   decrypted_text = decrypt(cipher_text, d, n);
   printf("The decrypted text is: %d\n", decrypted_text);
   
   return 0;
}