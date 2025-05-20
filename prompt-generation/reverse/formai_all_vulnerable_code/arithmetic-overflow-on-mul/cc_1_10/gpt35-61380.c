//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int p = rand() % 1000 + 1;
    int q = rand() % 1000 + 1;
    int n = p*q;
    int e;
    int totient = (p-1)*(q-1);
    for(int i=2; i<totient; i++){
        if(totient%i != 0 && n%i != 0 && e%i != 0){
            e = i;
            break;
        }
    }
    int d;
    for(int i=2; i<totient; i++){
        if((e*i)%totient == 1){
            d = i;
            break;
        }
    }

    printf("-- PUBLIC KEY ALGORITHM IN A POST-APOCALYPTIC WORLD --\n");
    printf("---------------------------------------------------\n");
    printf("A virus has wiped out most of the world's technology, but somehow we managed to salvage an old computer!\n");
    printf("We need to implement a Public-Key Algorithm to encrypt our messages.\n\n");

    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("totient = %d\n", totient);
    printf("e = %d\n", e);
    printf("d = %d\n\n", d);

    printf("Enter your message: ");
    char message[1000];
    fgets(message, 1000, stdin);

    int encrypted[1000];
    int decrypted[1000];
    printf("\n-- ENCRYPTION --\n");
    printf("----------------\n");
    for(int i=0; i<strlen(message); i++){
        encrypted[i] = ((int)message[i])^e%n;
        printf("%d ", encrypted[i]);
    }

    printf("\n\n-- DECRYPTION --\n");
    printf("----------------\n");
    for(int i=0; i<strlen(message); i++){
        decrypted[i] = ((int)encrypted[i])^d%n;
        printf("%c", decrypted[i]);
    }

    printf("\n");
    return 0;
}