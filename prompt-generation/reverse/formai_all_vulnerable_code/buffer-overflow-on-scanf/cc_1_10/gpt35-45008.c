//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000 // maximum size of the prime number
#define PRIVATE_KEY_RANGE 100 // range for private key generation

//function to generate random prime number
int random_prime(){
    int n = rand() % MAX + 1;
    int i;
    for(i=2; i*i<=n; i++){
        if(n%i == 0){
            n = rand() % MAX + 1;
            i = 1;
        }
    }
    return n;
}

//function to check if two number are relative prime
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

//function to generate public key
int generate_public_key(int p, int q){
    int n = p*q;
    int e = 2;
    while(e < (p-1)*(q-1)){
        if(gcd(e, (p-1)*(q-1)) == 1) break;
        e++;
    }
    return e;
}

//function to generate private key
int generate_private_key(int p, int q, int e){
    int phi_n = (p-1)*(q-1);
    int d = 2;
    while(d < phi_n){
        if((d*e) % phi_n == 1) break;
        d++;
    }
    return d;
}

//function to encrypt the message
int encrypt_message(int message, int n, int e){
    int result = 1;
    int i;
    for(i=0; i<e; i++){
        result = result * message % n; 
    }
    return result;
}

//function to decrypt the message
int decrypt_message(int encrypted, int n, int d){
    int result = 1;
    int i;
    for(i=0; i<d; i++){
        result = result * encrypted % n; 
    }
    return result;
}

int main(){
    srand(time(0));
    
    int p = random_prime();
    int q = random_prime();
    int n = p*q;
    int e = generate_public_key(p, q);
    int d = generate_private_key(p, q, e);
    
    printf("p: %d\n", p);
    printf("q: %d\n", q);
    printf("n: %d\n", n);
    printf("e: %d\n", e);
    printf("d: %d\n", d);
    
    int message;
    printf("Enter the message to encrypt: ");
    scanf("%d", &message);
    
    int encrypted = encrypt_message(message, n, e);
    printf("Encrypted message: %d\n", encrypted);
    
    int decrypted = decrypt_message(encrypted, n, d);
    printf("Decrypted message: %d\n", decrypted);
    
    return 0;
}