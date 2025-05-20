//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char* data, int key) {
    int len = strlen(data);
    for(int i=0;i<len;i++) {
        data[i] = ((data[i] - 'a') + key) % 26 + 'a';  // apply encryption
    }
}

void decrypt(char* data, int key) {
    int len = strlen(data);
    for(int i=0;i<len;i++) {
        data[i] = ((data[i] - 'a') - key + 26) % 26 + 'a';  // apply decryption
    }
}

int main() {
    printf("Welcome to the Happy Encryption Program!\n");
    char data[100];
    int key=0, choice=0;
    while(1) {
        printf("\nWhat do you want to do? Enter 1 for encryption, 2 for decryption, 3 to exit: ");
        scanf("%d",&choice);
        getchar();
        if(choice == 1) {
            printf("Enter the data you want to encrypt: ");
            fgets(data, 100, stdin);
            printf("Enter the encryption key (integer between 1 and 25): ");
            scanf("%d",&key);
            getchar(); //to clear the keyboard buffer
            encrypt(data, key);
            printf("Encrypted data: %s",data);
        }
        else if(choice == 2) {
            printf("Enter the data you want to decrypt: ");
            fgets(data, 100, stdin);
            printf("Enter the decryption key (integer between 1 and 25): ");
            scanf("%d",&key);
            getchar(); //to clear the keyboard buffer
            decrypt(data, key);
            printf("Decrypted data: %s",data);
        }
        else if(choice == 3) {
            printf("Thank you for using the Happy Encryption Program!\n");
            exit(0);
        }
        else {
            printf("Invalid input! Please try again.\n");
        }
    }
    return 0; //to indicate successful completion of program
}