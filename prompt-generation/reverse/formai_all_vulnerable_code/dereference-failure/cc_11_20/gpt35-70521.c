//FormAI DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    char message[100] = "The future is now.";
    char key[10] = "cyberpunk";
    int key_length = strlen(key);
    int message_length = strlen(message);
    
    // Reversing the message
    for(int i=0; i<message_length/2; i++) {
        char temp = message[i];
        message[i] = message[message_length-i-1];
        message[message_length-i-1] = temp;
    }
    
    // XORing the message with the key
    for(int i=0; i<message_length; i++) {
        message[i] = message[i] ^ key[i%key_length];
    }
    
    // Reversing the key
    for(int i=0; i<key_length/2; i++) {
        char temp = key[i];
        key[i] = key[key_length-i-1];
        key[key_length-i-1] = temp;
    }
    
    // Inserting key at random positions in the message
    int key_position = 0;
    for(int i=0; i<message_length+key_length; i++) {
        if(i%3 == 0 && key_position < key_length) {
            memmove(&message[i+key_length], &message[i], message_length-i+1);
            memmove(&message[i], &key[key_position], key_length-key_position);
            key_position++;
            i += key_length-1;
        }
    }
    
    // Printing the final message
    printf("Welcome to the cyberpunk world!\n\n");
    printf("Your message after encryption: %s\n", message);
    
    // Removing the key from the message
    key_position = 0;
    for(int i=0; i<message_length+key_length; i++) {
        if(i%3 == 0 && key_position < key_length) {
            memmove(&message[i], &message[i+key_length], message_length-i-key_length+1);
            key_position++;
            i -= key_length-1;
            message_length -= key_length;
        }
    }
    
    // XORing the message with the key
    for(int i=0; i<message_length; i++) {
        message[i] = message[i] ^ key[i%key_length];
    }
    
    // Reversing the message
    for(int i=0; i<message_length/2; i++) {
        char temp = message[i];
        message[i] = message[message_length-i-1];
        message[message_length-i-1] = temp;
    }
    
    // Printing the final message
    printf("\nYour message after decryption: %s\n", message);
    printf("\nThank you for experiencing the cyberpunk world!\n");
    
    return 0;
}