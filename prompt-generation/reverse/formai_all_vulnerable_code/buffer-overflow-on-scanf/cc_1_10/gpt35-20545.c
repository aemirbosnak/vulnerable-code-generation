//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This is the world's most secure public-key encryption algorithm.
 * It is so secure, that even the developers cannot read the encrypted message.
 * Feel free to use it to store your deepest darkest secrets.
 **/

int generatePublicKey(int p, int q){
    int n = p * q;
    int phi = (p-1)*(q-1);

    int e = 3;
    while(phi % e == 0){
        e += 2;
    }
    return e;
}

int generatePrivateKey(int e, int p, int q){
    int n = p * q;
    int phi = (p-1)*(q-1);

    int k = 1;
    while((1 + k * phi) % e != 0){
        k++;
    }

    return (1 + k * phi) / e;
}

int encrypt(int message, int e, int n){
    int result = 1;
    for(int i = 0; i < e; i++){
        result = (result * message) % n;
    }
    return result;
}

int decrypt(int message, int d, int n){
    int result = 1;
    for(int i = 0; i < d; i++){
        result = (result * message) % n;
    }
    return result;
}

int main(){
    printf("Welcome to the ultra-secure public-key encryption algorithm!\n");
    printf("Enter your message: ");

    char message[1000];
    scanf("%[^\n]", message);

    int p = 17;
    int q = 19;

    int n = p * q;
    int phi = (p-1)*(q-1);

    int e = generatePublicKey(p, q);
    int d = generatePrivateKey(e, p, q);

    printf("\nEncrypting...\n\n");

    int encrypted[strlen(message)];
    for(int i = 0; i < strlen(message); i++){
        encrypted[i] = encrypt(message[i], e, n);
    }

    printf("Encrypted message: ");
    for(int i = 0; i < strlen(message); i++){
        printf("%d ", encrypted[i]);
    }
    printf("\n\n");

    printf("Decrypting...\n\n");

    char decrypted[strlen(message)];
    for(int i = 0; i < strlen(message); i++){
        decrypted[i] = decrypt(encrypted[i], d, n);
    }

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}