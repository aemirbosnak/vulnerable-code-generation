//FormAI DATASET v1.0 Category: modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A') + key) % 26 + 'A';
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a') + key) % 26 + 'a';
        }
    }
}

void decrypt(char *str, int key) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A') - key + 26) % 26 + 'A';
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a') - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char str[100], choice;
    int key;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    printf("Enter an integer as a key: ");
    scanf("%d", &key);

    printf("Do you want to encrypt or decrypt the string (e/d)? ");
    scanf(" %c", &choice);

    if(choice == 'e' || choice == 'E') {
        encrypt(str, key);
        printf("Encrypted string: %s", str);
    }
    else if(choice == 'd' || choice == 'D') {
        decrypt(str, key);
        printf("Decrypted string: %s", str);
    }
    else {
        printf("Invalid choice!");
        exit(1);
    }

    return 0;
}