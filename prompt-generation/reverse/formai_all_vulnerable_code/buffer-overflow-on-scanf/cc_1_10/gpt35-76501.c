//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt message using digital watermark
char* encrypt(char* message, char* watermark){
    int msg_len = strlen(message); // Length of message
    int wm_len = strlen(watermark); // Length of watermark
    
    // Allocate memory for encrypted message
    char* encrypted = (char*)malloc((msg_len + wm_len + 1) * sizeof(char));
    
    // Loop through message and add watermark to it
    int i, j = 0;
    for(i = 0; i < msg_len; i++){
        if(j < wm_len){
            // Add next character of watermark to encrypted message
            encrypted[i] = watermark[j]; 
            j++;
        }
        // Add next character of message to encrypted message
        encrypted[i + j] = message[i];
    }
    // Add null character to end of encrypted message
    encrypted[msg_len + wm_len] = '\0';
    
    return encrypted;
}

// Function to decrypt message from digital watermark
char* decrypt(char* encrypted, char* watermark){
    int enc_len = strlen(encrypted); // Length of encrypted message
    int wm_len = strlen(watermark); // Length of watermark
    
    // Allocate memory for decrypted message
    char* decrypted = (char*)malloc((enc_len - wm_len + 1) * sizeof(char));
    
    // Loop through encrypted message and remove watermark from it
    int i, j = 0;
    for(i = wm_len; i < enc_len; i++){
        decrypted[j] = encrypted[i];
        j++;
    }
    // Add null character to end of decrypted message
    decrypted[enc_len - wm_len] = '\0';
    
    return decrypted;
}

int main(){
    // User inputs message and watermark
    char message[100], watermark[20];
    printf("Enter message to be encrypted:\n");
    scanf("%[^\n]s", message);
    getchar(); // Clear input buffer
    printf("Enter watermark to use:\n");
    scanf("%[^\n]s", watermark);
    getchar(); // Clear input buffer
    
    // Encrypt message using watermark
    char* encrypted_message = encrypt(message, watermark);
    printf("\nEncrypted message:\n%s\n", encrypted_message);
    
    // Decrypt message from encrypted message and watermark
    char* decrypted_message = decrypt(encrypted_message, watermark);
    printf("\nDecrypted message:\n%s\n", decrypted_message);
    
    // Free allocated memory
    free(encrypted_message);
    free(decrypted_message);
    
    return 0;
}