//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char message[1000];          // Maximum 1000 characters allowed in message
    char key[100];              // Key for encryption/decryption
    int watermark_size;          // Watermark size to be inserted
    int secret_key;              // Secret key for authentication
} watermark;

// Function to encrypt message using key
void encrypt_message(watermark *wm) {
    int i, j = 0;
    for (i = 0; i < strlen(wm->message); i++) {
        wm->message[i] = wm->message[i] + wm->key[j];
        j++;
        if (j == strlen(wm->key)) j = 0;   // Reset index of key if it exceeds key length
    }
}

// Function to decrypt message using key
void decrypt_message(watermark *wm) {
    int i, j = 0;
    for (i = 0; i < strlen(wm->message); i++) {
        wm->message[i] = wm->message[i] - wm->key[j];
        j++;
        if (j == strlen(wm->key)) j = 0;   // Reset index of key if it exceeds key length
    }
}

// Function to insert watermark in message
void insert_watermark(watermark *wm) {
    int i, j = 0;
    char watermark[100] = "THIS IS A WATERMARK";   // Hardcoded watermark
    for (i = 0; i < wm->watermark_size; i++) {
        wm->message[j] = watermark[i];   // Insert watermark in message
        j++;
    }
}

// Function to authenticate using secret key
int authenticate(watermark *wm, int input_key) {
    if (input_key == wm->secret_key) return 1;
    else return 0;
}

int main() {
    watermark wm;
    
    // Taking message, key, watermark size and secret key as input from user
    printf("Enter the message:\n");
    fgets(wm.message, sizeof(wm.message), stdin);
    printf("Enter the key:\n");
    fgets(wm.key, sizeof(wm.key), stdin);
    printf("Enter the watermark size:\n");
    scanf("%d", &wm.watermark_size);
    printf("Enter the secret key:\n");
    scanf("%d", &wm.secret_key);
    
    encrypt_message(&wm);   // Encrypting message
    
    insert_watermark(&wm);  // Inserting watermark in message
    
    if (authenticate(&wm, wm.secret_key)) {   // Authenticating using secret key
        printf("The watermarked message is:\n");
        printf("%s\n", wm.message);    // Displaying watermarked message
        
        decrypt_message(&wm);   // Decrypting message
        printf("The original message is:\n");
        printf("%s\n", wm.message);    // Displaying original message
    }
    else {
        printf("Authentication failed!\n");
    }
    
    return 0;
}