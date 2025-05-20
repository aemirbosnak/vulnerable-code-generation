//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int find_gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return find_gcd(b, a % b);
}

int main(){
    int p, q, n, phi, e, d, msg, cipher, decrypt;
    printf("Enter two prime numbers p and q: \n");
    scanf("%d %d", &p, &q);

    //calculating n and phi
    n = p*q;
    phi = (p-1)*(q-1);

    //finding e
    for(e=2; e<phi; e++){
        if(find_gcd(e, phi) == 1)
            break;
    }

    //finding d
    d = 0;
    int k = 1;
    while(d == 0){
        k = k + phi;
        if(k % e == 0)
            d = k/e;
    }

    printf("Public Key : {%d,%d}\n", n, e);
    printf("Private Key : {%d,%d}\n", n, d);

    //Encrypting the message
    printf("Enter the message to be encrypted : ");
    scanf("%d", &msg);
    cipher = pow(msg,e);
    cipher = cipher % n;

    printf("\nEncrypted Message : %d", cipher);

    //decrypting the message
    decrypt = pow(cipher, d);
    decrypt = decrypt % n;

    printf("\nDecrypted Message : %d\n", decrypt);

    return 0;
}