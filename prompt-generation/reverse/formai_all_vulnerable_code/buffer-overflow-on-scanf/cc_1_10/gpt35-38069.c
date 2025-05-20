//FormAI DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; i++) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}

void decrypt(char message[], int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

int main() {
    char message[100], encrypted_message[100], decrypted_message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Store encrypted message in a file
    FILE *fp;
    fp = fopen("encrypted_message.txt", "w+");
    fprintf(fp, "%s", message);
    fclose(fp);

    // Read encrypted message from file
    char ch;
    int i = 0;
    fp = fopen("encrypted_message.txt", "r");
    while((ch = fgetc(fp)) != EOF) {
        encrypted_message[i] = ch;
        i++;
    }
    encrypted_message[i] = '\0';
    fclose(fp);

    // Decrypt message from file
    decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", encrypted_message);

    return 0;
}