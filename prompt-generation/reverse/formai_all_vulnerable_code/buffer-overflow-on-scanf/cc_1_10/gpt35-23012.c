//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h> 

int main() {
   int p = 13, q = 11, n = p*q, t = (p-1)*(q-1), gcd, e = 7, d, original, encrypted, decrypted;
   char message[100];

   printf("Enter a message to encrypt: ");
   scanf("%s", message);

   // Finding gcd of t and e
   while(1) {
      gcd = t%e;

      if(gcd == 0) {
         break;
      }
      else {
         t = e;
         e = gcd;
      }
   }

   // Private key calculation
   d = (1+t)/e;

   printf("\nPublic key: %d\nPrivate key: %d\n", e, d);

   for(int i = 0; message[i] != '\0'; i++) {
      original = message[i];

      // Encryption 
      encrypted = 1;

      for(int j = 0; j < e; j++){
         encrypted = encrypted * original;
         encrypted = encrypted % n;
      }

      // Decryption 
      decrypted = 1;

      for(int j = 0; j < d; j++) {
         decrypted = decrypted * encrypted;
         decrypted = decrypted % n;
      }

      message[i] = decrypted;
   } 

   printf("\nEncrypted message: %s\n", message);

   for(int i = 0; message[i] != '\0'; i++) {
      original = message[i];

      // Decryption 
      decrypted = 1;

      for(int j = 0; j < d; j++){
         decrypted = decrypted * original;
         decrypted = decrypted % n;
      }

      message[i] = decrypted;
   } 

   printf("\nDecrypted message: %s\n", message);

   return 0;
}