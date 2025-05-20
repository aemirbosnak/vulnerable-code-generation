//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int n, i, j;
    printf("Enter the number of characters to be encrypted: ");
    scanf("%d", &n);

    char msg[n], enc_msg[n], dec_msg[n];
    printf("Enter the message to be encrypted: ");
    scanf("%s", msg);

    srand(time(0));

    //Encrypting the message using Ceaser Cipher
    int key = rand() % 26;
    printf("\nKey: %d\n", key);
    for(i=0; i<n; i++) {
        if(msg[i] >= 'a' && msg[i] <= 'z') {
            enc_msg[i] = (msg[i] + key - 'a') % 26 + 'a';
        }
        else if(msg[i] >= 'A' && msg[i] <= 'Z') {
            enc_msg[i] = (msg[i] + key - 'A') % 26 + 'A';
        }
        else {
            enc_msg[i] = msg[i];
        }
    }
    enc_msg[n] = '\0';

    //Decrypting the message
    for(i=0; i<n; i++) {
        if(enc_msg[i] >= 'a' && enc_msg[i] <= 'z') {
            dec_msg[i] = (enc_msg[i] - key - 'a' + 26) % 26 + 'a';
        }
        else if(enc_msg[i] >= 'A' && enc_msg[i] <= 'Z') {
            dec_msg[i] = (enc_msg[i] - key - 'A' + 26) % 26 + 'A';
        }
        else {
            dec_msg[i] = enc_msg[i];
        }
    }
    dec_msg[n] = '\0';

    //Printing the results
    printf("\nOriginal Message: %s\n", msg);
    printf("Encrypted Message: %s\n", enc_msg);
    printf("Decrypted Message: %s\n", dec_msg);

    return 0;
}