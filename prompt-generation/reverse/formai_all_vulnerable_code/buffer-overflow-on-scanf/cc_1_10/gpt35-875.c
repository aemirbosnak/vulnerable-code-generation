//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>

void encode(char* message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        if(message[i] != ' ') {
            message[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
    }
}

void decode(char* message, int key) {
    int len = strlen(message);
    for(int i = 0; i < len; i++) {
        if(message[i] != ' ') {
            message[i] = (((message[i] - 'a') - key) + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[100];
    int key, ch;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    printf("\nSelect an option:\n");
    printf("1. Encode\n2. Decode\n3. Quit\n");

    while(1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                encode(message, key);
                printf("Encoded message: %s\n", message);
                break;
            case 2:
                decode(message, key);
                printf("Decoded message: %s\n", message);
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}