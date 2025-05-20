//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <string.h>

void reverse(char *x, int begin, int end) {
    char c;
    if (begin >= end)
        return;
    c = *(x+begin);
    *(x+begin) = *(x+end);
    *(x+end) = c;
    reverse(x, ++begin, --end);
}

int main() {
    char plaintext[100], key[100], ciphertext[100];
    int i, j, choice;
    
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    
    printf("Enter the key: ");
    scanf("%s", key);
    
    printf("1. Encrypt\n2. Decrypt\nChoose an operation: ");
    scanf("%d", &choice);
    
    // encryption
    if (choice == 1) {
        int len_plaintext = strlen(plaintext);
        int len_key = strlen(key);
        
        for (i = 0, j = 0; i < len_plaintext; i++, j++) {
            if (j == len_key)
                j = 0;
            ciphertext[i] = (plaintext[i] + key[j]) % 26 + 'A';
        }
        ciphertext[len_plaintext] = '\0';
        printf("Ciphertext: %s\n", ciphertext);
    }
    
    // decryption
    else if (choice == 2) {
        int len_ciphertext = strlen(plaintext);
        int len_key = strlen(key);
        char decrypted[len_ciphertext];
        int k;
        for (k = 0, j = 0; k < len_ciphertext; k++, j++) {
            if (j == len_key)
                j = 0;
            decrypted[k] = ((ciphertext[k] - key[j] + 26) % 26) + 'A';
        }
        decrypted[len_ciphertext] = '\0';
        reverse(decrypted, 0, len_ciphertext - 1);
        printf("Decrypted text: %s\n", decrypted);
    }
    
    // incorrect operation choice selected
    else {
        printf("Invalid choice! Please select either 1 or 2.\n");
    }
    
    return 0;
}