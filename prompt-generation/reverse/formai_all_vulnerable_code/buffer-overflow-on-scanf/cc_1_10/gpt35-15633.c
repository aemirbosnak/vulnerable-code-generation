//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LENGTH 100

void encrypt(char *str, int key){
    if(*str == '\0'){
        return;
    }

    // If character is uppercase
    if(*str >= 'A' && *str <= 'Z'){
        *str = ((*str - 'A' + key) % 26) + 'A';
    }
    // If character is lowercase
    else if(*str >= 'a' && *str <= 'z'){
        *str = ((*str - 'a' + key) % 26) + 'a';
    }

    encrypt(str+1, key);
}

void decrypt(char *str, int key){
    if(*str == '\0'){
        return;
    }

    // If character is uppercase
    if(*str >= 'A' && *str <= 'Z'){
        *str = ((*str - 'A' - key + 26) % 26) + 'A';
    }
    // If character is lowercase
    else if(*str >= 'a' && *str <= 'z'){
        *str = ((*str - 'a' - key + 26) % 26) + 'a';
    }

    decrypt(str+1, key);
}

int main(){
    char str[MAX_STR_LENGTH];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(str, MAX_STR_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}