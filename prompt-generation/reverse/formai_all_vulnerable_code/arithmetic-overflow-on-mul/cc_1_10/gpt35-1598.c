//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>

// Function to calculate gcd (Greatest Common Divisor)
int gcd(int a, int b) {
   if (a == 0)
      return b;
   return gcd(b % a, a);
}

// Function to generate public key
int public_key(int phi) {
   int e = 2;
   while (e < phi) {
      if (gcd(e, phi) == 1)
         return e;
      else
         e++;
   }
   return -1;
}

// Function to generate private key
int private_key(int e, int phi) {
   int d = 1;
   while (1) {
      if ((d * e) % phi == 1)
         return d;
      else
         d++;
   }
}

// Function to encrypt the message
int encrypt(int message, int e, int n) {
   int cipher = 1;
   for (int i = 0; i < e; i++) 
      cipher = (cipher * message) % n;
   return cipher;
}

// Function to decrypt the message
int decrypt(int cipher, int d, int n) {
   int message = 1;
   for (int i = 0; i < d; i++) 
      message = (message * cipher) % n;
   return message;
}

// Function to display the generated keys
void display_keys(int e, int d, int n) {
   printf("\nPublic key: {%d, %d}\n", e, n);
   printf("Private key: {%d, %d}\n", d, n);
}

int main() {
   int p, q;
   printf("Enter two prime numbers (p and q): ");
   scanf("%d %d", &p, &q);

   // Calculate n (modulus)
   int n = p * q;

   // Calculate phi
   int phi = (p - 1) * (q - 1);

   // Generate public and private keys
   int e = public_key(phi);
   int d = private_key(e, phi);

   // Display the generated keys
   display_keys(e, d, n);

   // Encryption
   int message;
   printf("\nEnter a message to encrypt: ");
   scanf("%d", &message);

   // Check if message is within range (0 <= message < n)
   if (message < 0 || message >= n) {
      printf("Invalid input. Message should be in the range of 0 to %d.\n", n - 1);
      return -1;
   }

   int cipher = encrypt(message, e, n);
   printf("Encrypted message: %d\n", cipher);

   // Decryption
   int decrypted_message = decrypt(cipher, d, n);
   printf("Decrypted message: %d\n", decrypted_message);

   return 0;
}