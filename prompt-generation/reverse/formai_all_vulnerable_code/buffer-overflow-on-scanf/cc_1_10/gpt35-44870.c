//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAX 100000

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int p = 61, q = 53, n, phi, e, d, i, j, message[MAX], cipher[MAX], decrypted_message[MAX], message_size;
    printf("Enter message size: ");
    scanf("%d", &message_size);
    printf("Enter the message: ");
    for(i = 0; i < message_size; i++) {
        scanf("%d", &message[i]);
    }
    n = p * q;
    phi = (p - 1) * (q - 1);
    for(i = 2; i < phi; i++) {
        if(gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }
    for(i = 1; i < MAX; i++) {
        j = (phi * i) + 1;
        if(j % e == 0) {
            d = j / e;
            break;
        }
    }
    for(i = 0; i < message_size; i++) {
        cipher[i] = pow(message[i], e);
        cipher[i] = cipher[i] % n;
    }
    printf("Encrypted Message: ");
    for(i = 0; i < message_size; i++) {
        printf("%d ", cipher[i]);
    }
    printf("\n");
    for(i = 0; i < message_size; i++) {
        decrypted_message[i] = pow(cipher[i], d);
        decrypted_message[i] = decrypted_message[i] % n;
    }
    printf("Decrypted Message: ");
    for(i = 0; i < message_size; i++) {
        printf("%d ", decrypted_message[i]);
    }
    printf("\n");
    return 0;
}