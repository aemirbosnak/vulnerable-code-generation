//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    int temp;
    while(b != 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int p, q, n, e, d, totient, plain_text, ciphertext, decrypted_text;
    
    //Generate two large prime numbers
    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);
    
    //Calculate n
    n = p * q;
    
    //Calculate totient of n
    totient = (p-1) * (q-1);
    
    //Find e which is coprime to totient
    printf("Enter a number (e) which is coprime to totient: ");
    scanf("%d", &e);
    
    while(gcd(totient, e) != 1){
        printf("%d is not coprime to %d. Please enter another number: ", e, totient);
        scanf("%d", &e);
    }

    //Find d which is the modular multiplicative inverse of e
    int k = 1;
    while(1){
        k += totient;
        if(k % e == 0){
            d = k / e;
            break;
        }
    }
        
    //Encrypt message using public key (n, e)
    printf("Enter a message to encrypt: ");
    scanf("%d", &plain_text);
    
    ciphertext = 1;
    for(int i=0; i<e; i++){
        ciphertext = (ciphertext * plain_text) % n;
    }
    printf("Encrypted message: %d\n", ciphertext);
    
    //Decrypt message using private key (n, d)
    decrypted_text = 1;
    for(int i=0; i<d; i++){
        decrypted_text = (decrypted_text * ciphertext) % n;
    }
    printf("Decrypted message: %d\n", decrypted_text);

    return 0;
}