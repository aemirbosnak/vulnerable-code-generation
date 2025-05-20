//FormAI DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the exciting world of C encryption!\n");
    printf("Today, we will be encrypting a message using a unique algorithm that I've created just for you!\n");

    char msg[1000], encrypted_msg[1000];
    int key, i;

    printf("Please enter your message: ");
    scanf("%[^\n]s", msg);

    printf("Enter the key to encrypt your message: ");
    scanf("%d", &key);

    // Exciting encryption algorithm
    for (i = 0; msg[i] != '\0'; ++i) {
        if (msg[i] >= 'a' && msg[i] <= 'z') {
            encrypted_msg[i] = ((msg[i] - 'a' + key) % 26) + 'a';
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z') {
            encrypted_msg[i] = ((msg[i] - 'A' + key) % 26) + 'A';
        }
        else {
            encrypted_msg[i] = msg[i];
        }
    }
    encrypted_msg[i] = '\0';

    // Display encrypted message
    printf("Your encrypted message is: %s\n", encrypted_msg);

    printf("Wasn't that exciting? But wait, there's more!\n");
    printf("Let's decrypt your message using the same key and algorithm!\n");

    char decrypted_msg[1000];
    
    // Exciting decryption algorithm
    for (i = 0; encrypted_msg[i] != '\0'; ++i) {
        if (encrypted_msg[i] >= 'a' && encrypted_msg[i] <= 'z') {
            decrypted_msg[i] = ((encrypted_msg[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if (encrypted_msg[i] >= 'A' && encrypted_msg[i] <= 'Z') {
            decrypted_msg[i] = ((encrypted_msg[i] - 'A' - key + 26) % 26) + 'A';
        }
        else {
            decrypted_msg[i] = encrypted_msg[i];
        }
    }
    decrypted_msg[i] = '\0';

    // Display decrypted message
    printf("Your decrypted message is: %s\n", decrypted_msg);

    printf("Wasn't that an exciting program? You are now a master of encryption and decryption!\n");
    return 0;
}