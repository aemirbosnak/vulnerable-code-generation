//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Function to display the menu */
void displayMenu() {
    printf("\n1. Encryption");
    printf("\n2. Decryption");
    printf("\n3. Exit");
}

/* Function to perform encryption */
char* encrypt(char* message) {
    int n = strlen(message);
    char* cipher = (char*)malloc(n*sizeof(char));
    int i;
    for(i=0;i<n;i++) {
        int c = (int)message[i];
        cipher[i] = (char)(c+1);
    }
    return cipher;
}

/* Function to perform decryption */
char* decrypt(char* cipher) {
    int n = strlen(cipher);
    char* message = (char*)malloc(n*sizeof(char));
    int i;
    for(i=0;i<n;i++) {
        int c = (int)cipher[i];
        message[i] = (char)(c-1);
    }
    return message;
}

/* Main function */
int main() {
    int choice;
    do {
        displayMenu();
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                char message[100];
                printf("\nEnter the message to encrypt : ");
                scanf(" %[^\n]s",message);
                char* cipher = encrypt(message);
                printf("\nThe encrypted message is : %s",cipher);
                free(cipher);
                break;
            }
            case 2: {
                char cipher[100];
                printf("\nEnter the message to decrypt : ");
                scanf(" %[^\n]s",cipher);
                char* message = decrypt(cipher);
                printf("\nThe decrypted message is : %s",message);
                free(message);
                break;
            }
            case 3: {
                printf("\nExiting the program...");
                break;
            }
            default: {
                printf("\nInvalid choice, Please enter a valid choice!");
            }
        }
    } while(choice!=3);
    return 0;
}