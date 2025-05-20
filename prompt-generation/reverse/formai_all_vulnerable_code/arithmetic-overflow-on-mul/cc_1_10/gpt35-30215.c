//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int prime[9]={2,3,5,7,11,13,17,19,23};      // set of prime numbers to generate keys
int publicKey[2], privateKey[2], n, phi_n;

// function to calculate greatest common divisor of two numbers
int greatestCommonDivisor(int a, int b){     
    if(b==0){
        return a;
    }
    return greatestCommonDivisor(b, a%b);
}

// function to calculate phi(n)
int calculatePhiN(int p, int q){                
    return (p-1)*(q-1);
}

// function to calculate public and private keys
void calculateKeys(int p, int q){               
    n = p*q;
    phi_n = calculatePhiN(p,q);
    int e = 2, gcd_res;
    while(e < phi_n){
        gcd_res = greatestCommonDivisor(e, phi_n);
        if(gcd_res == 1){
            break;
        }
        e++;
    }
    publicKey[0] = e;
    publicKey[1] = n;
    int d = 1;
    while((d*e%phi_n) != 1){
        d++;
    }
    privateKey[0] = d;
    privateKey[1] = n;
}

// function to encrypt the message using public key
int encryptMessage(int msg){                     
    int encrypted_msg = 1;
    for(int i=0; i<publicKey[0]; i++){
        encrypted_msg = (encrypted_msg * msg) % publicKey[1];
    }
    return encrypted_msg;
}

// function to decrypt the message using private key
int decryptMessage(int encrypted_msg){        
    int decrypted_msg = 1;
    for(int i=0; i<privateKey[0]; i++){
        decrypted_msg = (decrypted_msg * encrypted_msg) % privateKey[1];
    }
    return decrypted_msg;
}

void main(){
    char message[MAX];                          
    int p,q;
    printf("Enter prime numbers for key generation (between 2-23):\n");
    printf("p: ");
    scanf("%d",&p);
    printf("q: ");
    scanf("%d",&q);
    calculateKeys(p,q);
    printf("Public key: (%d,%d)\n", publicKey[0], publicKey[1]);
    printf("Private key: (%d,%d)\n", privateKey[0], privateKey[1]);
    printf("Enter message to encrypt (max 100 characters):\n");
    fflush(stdin);
    fgets(message, MAX, stdin);
    int messageLength = strlen(message)-1;
    int encryptedMessage[messageLength], decryptedMessage[messageLength];
    printf("\nMessage to encrypt: %s\n", message);
    for(int i=0; i<messageLength; i++){        
        encryptedMessage[i] = encryptMessage(message[i]);
    }
    printf("\nEncrypted message: ");
    for(int i=0; i<messageLength; i++){
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");
    printf("\n");
    printf("Decrypted message: ");
    for(int i=0; i<messageLength; i++){        
        decryptedMessage[i] = decryptMessage(encryptedMessage[i]);
        printf("%c", decryptedMessage[i]);
    }   
}