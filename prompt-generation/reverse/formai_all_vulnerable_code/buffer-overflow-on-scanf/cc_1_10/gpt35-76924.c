//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    int length = strlen(message);
    char encrypted[length];

    for(i = 0; i < length; i++) {
        encrypted[i] = (message[i] + key) % 128;
    }
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char message[], int key) {
    int i;
    int length = strlen(message);
    char decrypted[length];

    for(i = 0; i < length; i++) {
        decrypted[i] = (message[i] - key + 128) % 128;
    }
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[50];
    int key;

    printf("Hello! I'm happy to encrypt your message for you. What message would you like me to encrypt? (50 character max)\n");
    scanf("%s", message);

    printf("Great! Now, what key would you like to use to encrypt your message?\n");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Yay! I'm excited to tell you that your message is now encrypted with the key %d.\n", key);

    printf("\nUh-oh... do you need me to decrypt your message for you? Just say yes or no!\n");
    char response[5];
    scanf("%s", response);

    if(strcmp(response, "yes") == 0) {
        printf("Awesome! Let's get started. What was the key you used to encrypt the message?\n");
        scanf("%d", &key);
        decrypt(message, key);
        printf("Perfect! You just decrypted your message with the key %d!\n", key);
    } else {
        printf("No problem at all! I'm happy to encrypt more messages for you anytime.\n");
    }

    return 0;
}