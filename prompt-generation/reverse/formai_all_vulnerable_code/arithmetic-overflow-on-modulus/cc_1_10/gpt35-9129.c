//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>

//Function to compute the greatest common divisor of two numbers
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

//Function to check if a number is prime or not
int is_prime(int num, int i){
    if(i == 1){
        return 1;
    }
    else{
        if(num % i == 0){
            return 0;
        }
        else{
            return is_prime(num, i-1);
        }
    }
}

//Function to generate the public keys
void generate_public_key(int * n, int * e){
    int p, q, z, phi;
    printf("Enter two prime numbers p and q: ");
    scanf("%d %d", &p, &q);
    *n = p * q;
    z = (p-1) * (q-1);
    printf("The value of Z is: %d\n", z);
    for(int i=2; i<z; i++){
        if(gcd(i,z) == 1){
            if(is_prime(i, i/2) == 1){
                *e = i;
                printf("The value of public key e is: %d\n", *e);
                break;
            }
        }
    }
}

//Function to compute the private key
int generate_private_key(int e, int n){
    int k=1;
    while(1){
        int d = (1 + (k * n))/e;
        if((e * d - 1) % n == 0){
            return d;
        }
        k++;
    }
}

int main(){

    int n, e, d, message, encrypted_message, decrypted_message;
    generate_public_key(&n, &e);
    d = generate_private_key(e, n);

    printf("\nEnter the message to be encrypted: ");
    scanf("%d", &message);

    //Encryption process
    encrypted_message = 1;
    for(int i=0; i<e; i++){
        encrypted_message = (encrypted_message * message) % n;
    }
    printf("\nThe encrypted message is: %d", encrypted_message);

    //Decryption process
    decrypted_message = 1;
    for(int i=0; i<d; i++){
        decrypted_message = (decrypted_message * encrypted_message) % n;
    }
    printf("\nThe decrypted message is: %d", decrypted_message);

    return 0;
}