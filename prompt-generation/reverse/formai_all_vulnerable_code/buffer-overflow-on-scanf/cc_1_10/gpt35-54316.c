//FormAI DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_LENGTH 1000
#define MAX_KEY_LENGTH 50

char* shiftEncrypt(char* message, int key);
char* shiftDecrypt(char* message, int key);
char* substitutionEncrypt(char* message, char subKey[]);
char* substitutionDecrypt(char* message, char subKey[]);

int main() {
    int choice;
    char message[MAX_MSG_LENGTH];
    char subKey[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    int shiftKey;
    srand(time(NULL));
    
    printf("Enter your message: ");
    fgets(message, MAX_MSG_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0;
    
    printf("\nSelect an option:\n");
    printf("1. Shift encryption\n");
    printf("2. Substitution encryption\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            shiftKey = rand() % 25 + 1;
            printf("\nShift Key: %d\n", shiftKey);
            printf("Encrypted message: %s\n", shiftEncrypt(message, shiftKey));
            printf("Decrypted message: %s\n", shiftDecrypt(shiftEncrypt(message, shiftKey), shiftKey));
            break;
        case 2:
            printf("Substitution Key: QWERTYUIOPASDFGHJKLZXCVBNM\n");
            printf("Encrypted message: %s\n", substitutionEncrypt(message, subKey));
            printf("Decrypted message: %s\n", substitutionDecrypt(substitutionEncrypt(message, subKey), subKey));
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
    
    return 0;
}

char* shiftEncrypt(char* message, int key) {
    int i;
    char* encrypted = (char*) malloc(MAX_MSG_LENGTH);
    
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = 'A' + ((message[i] - 'A' + key) % 26);
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = 'a' + ((message[i] - 'a' + key) % 26);
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';
    
    return encrypted;
}

char* shiftDecrypt(char* message, int key) {
    int i;
    char* decrypted = (char*) malloc(MAX_MSG_LENGTH);
    
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = 'A' + ((message[i] - 'A' + 26 - key) % 26);
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = 'a' + ((message[i] - 'a' + 26 - key) % 26);
        } else {
            decrypted[i] = message[i];
        }
    }
    decrypted[i] = '\0';
    
    return decrypted;
}

char* substitutionEncrypt(char* message, char subKey[]) {
    int i, index;
    char* encrypted = (char*) malloc(MAX_MSG_LENGTH);
    
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            index = message[i] - 'A';
            encrypted[i] = subKey[index];
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            index = message[i] - 'a';
            encrypted[i] = tolower(subKey[index]);
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';
    
    return encrypted;
}

char* substitutionDecrypt(char* message, char subKey[]) {
    int i, j, index;
    char* decrypted = (char*) malloc(MAX_MSG_LENGTH);
    
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'A' && message[i] <= 'Z') {
            for(j = 0; j < 26; j++) {
                if(message[i] == subKey[j]) {
                    index = j;
                    break;
                }
            }
            decrypted[i] = 'A' + index;
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            for(j = 0; j < 26; j++) {
                if(tolower(message[i]) == subKey[j]) {
                    index = j;
                    break;
                }
            }
            decrypted[i] = 'a' + index;
        } else {
            decrypted[i] = message[i];
        }
    }
    decrypted[i] = '\0';
    
    return decrypted;
}