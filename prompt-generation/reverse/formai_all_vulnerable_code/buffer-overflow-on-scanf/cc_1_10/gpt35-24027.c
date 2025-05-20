//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char msg[], int key) {
    int len = strlen(msg);
    int k = key % 26;
    for(int i=0; i<len; i++) {
        if(msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = ((msg[i] - 'a' + k) % 26) + 'a';
        } else if(msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = ((msg[i] - 'A' + k) % 26) + 'A';
        }
    }
}

void decrypt(char msg[], int key) {
    int len = strlen(msg);
    int k = key % 26;
    for(int i=0; i<len; i++) {
        if(msg[i] >= 'a' && msg[i] <= 'z') {
            msg[i] = ((msg[i] - 'a' - k + 26) % 26) + 'a';
        } else if(msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = ((msg[i] - 'A' - k + 26) % 26) + 'A';
        }
    }
}

int main() {
    char msg[100], c;
    int key;
    printf("Enter the message: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("Original Message: %s", msg);

    encrypt(msg, key);
    printf("Encrypted Message: %s", msg);

    decrypt(msg, key);
    printf("Decrypted Message: %s", msg);

    return 0;
}

/* Example usage:
Enter the message: Hello world!
Enter the key (0-25): 5
Original Message: Hello world!
Encrypted Message: Mjqqt btwqi!
Decrypted Message: Hello world!
*/