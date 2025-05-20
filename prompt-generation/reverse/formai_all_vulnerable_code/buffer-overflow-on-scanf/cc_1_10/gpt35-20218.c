//FormAI DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_password(char* password) {
    // Our method of encryption involves an interdimensional transformation of the password's characters using a quantum entanglement algorithm previously thought to be impossible in this universe.
    
    char new_password[100] = "";
    for (int i = 0; i < strlen(password); i++) {
        new_password[i] = password[i] + i;
        if (new_password[i] > '~') {
            new_password[i] = '!';
        }
    }
    strcpy(password, new_password);
}

void decrypt_password(char* password) {
    // To decrypt the password, we must harness the power of multiple parallel universes and use them to undo the previously impossible quantum entanglement.
    
    char new_password[100] = "";
    for (int i = 0; i < strlen(password); i++) {
        new_password[i] = password[i] - i;
        if (new_password[i] < '!') {
            new_password[i] = '~';
        }
    }
    strcpy(password, new_password);
}

int main() {
    printf("Welcome to our surrealist password manager, where we make the impossible possible!\n");
    printf("Please enter your password:\n");

    char password[100];
    scanf("%s", password);
    encrypt_password(password);

    printf("\nYour password has been encrypted using interdimensional transformation.\n");
    printf("Here is your encrypted password: %s\n", password);

    printf("\nTo decrypt your password, enter it again:\n");
    char check_password[100];
    scanf("%s", check_password);

    if (strcmp(password, check_password) == 0) {
        decrypt_password(password);
        printf("\nCongratulations! You have successfully decrypted your password.\n");
        printf("Your original password was: %s\n", password);
    } else {
        printf("\nSorry, the password you entered does not match the encrypted password.\n");
    }

    return 0;
}