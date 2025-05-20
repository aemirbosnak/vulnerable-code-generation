//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int num){
    int i;
    for(i = 2; i <= num/2; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int find_e(int phi_n){
    int e;
    for(e = 2; e < phi_n; e++){
        if(is_prime(e) && phi_n % e != 0){
            return e;
        }
    }
    return 0;
}

int find_d(int e, int phi_n){
    int d = 1;
    while((d*e)%phi_n != 1 || d == e){
        d++;
    }
    return d;
}

int public_key(int p, int q){
    return p*q;
}

int private_key(int p, int q, int e){
    int phi_n = (p-1)*(q-1);
    int d = find_d(e, phi_n);
    return d;
}

int encrypt(int message, int public_key){
    return message % public_key;
}

int decrypt(int ciphertext, int private_key, int public_key){
    int phi_n = (private_key*public_key)/(private_key+public_key);
    int d = find_d(public_key, phi_n);
    return ciphertext^d%public_key;
}

int main(){
    int p, q, e, public, private, message, ciphertext, plaintext;
    printf("Enter two prime numbers: ");
    scanf("%d%d", &p, &q);
    while(!is_prime(p) || !is_prime(q)){
        printf("Both numbers must be prime. Enter another pair: ");
        scanf("%d%d", &p, &q);
    }
    public = public_key(p, q);
    private = private_key(p, q, find_e(public));
    printf("Public key: %d\n", public);
    printf("Private key: %d\n", private);
    printf("Enter a message (integer): ");
    scanf("%d", &message);
    ciphertext = encrypt(message, public);
    printf("Ciphertext: %d\n", ciphertext);
    plaintext = decrypt(ciphertext, private, public);
    printf("Plaintext: %d\n", plaintext);
    return 0;
}