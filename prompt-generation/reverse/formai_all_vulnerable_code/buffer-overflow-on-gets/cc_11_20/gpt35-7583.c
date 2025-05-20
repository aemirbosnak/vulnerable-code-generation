//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[1000], key[1000], cipher_text[1000], decrypted_text[1000];
    int i, j = 0, k = 0, msg_length, key_length, ascii_value;
    
    printf("Enter message to be encrypted: ");
    gets(message);
    printf("Enter key for encryption: ");
    gets(key);
    
    msg_length = strlen(message);
    key_length = strlen(key);
    
    for(i = 0; i < msg_length; i++) {
        if(message[i] == ' ' || message[i] == '\t' || message[i] == '\n') {
            cipher_text[i] = message[i];
        }
        else {
            ascii_value = (int) message[i] + (int) key[j];
            if(ascii_value > 122) {
                ascii_value = ascii_value - 122 + 96;
            }
            cipher_text[i] = (char) ascii_value;
            j++;
            if(j >= key_length) {
                j = 0;
            }
        }
    }
    cipher_text[i] = '\0';
    
    printf("Encrypted message is: %s\n", cipher_text);
    
    for(i = 0; i < msg_length; i++) {
        if(cipher_text[i] == ' ' || cipher_text[i] == '\t' || cipher_text[i] == '\n') {
            decrypted_text[i] = cipher_text[i];
        }
        else {
            ascii_value = (int) cipher_text[i] - (int) key[k];
            if(ascii_value < 97) {
                ascii_value = ascii_value + 122 - 96;
            }
            decrypted_text[i] = (char) ascii_value;
            k++;
            if(k >= key_length) {
                k = 0;
            }
        }
    }
    decrypted_text[i] = '\0';
    
    printf("Decrypted message is: %s\n", decrypted_text);
    
    return 0;
}