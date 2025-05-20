//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <string.h>

#define PASSWORD_LENGTH 4
#define MESSAGE_LENGTH 50

void get_password(char password[PASSWORD_LENGTH + 1]);
void encrypt_message(char message[MESSAGE_LENGTH + 1], char password[PASSWORD_LENGTH]);

int main() {
    char message[MESSAGE_LENGTH + 1];
    char password[PASSWORD_LENGTH + 1];

    printf("Enter a 4-digit password: ");
    get_password(password);

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    encrypt_message(message, password);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void get_password(char password[PASSWORD_LENGTH + 1]) {
    char temp[PASSWORD_LENGTH + 1];
    int i;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        do {
            printf("Enter password digit %d: ", i + 1);
            scanf("%c", &temp[i]);
        } while (isdigit(temp[i]) == 0);

        password[i] = temp[i] - '0';
    }

    password[PASSWORD_LENGTH] = '\0';
}

void encrypt_message(char message[MESSAGE_LENGTH + 1], char password[PASSWORD_LENGTH]) {
    int i, j;

    for (i = 0; i < MESSAGE_LENGTH; i++) {
        if (message[i] == '\0') {
            break;
        }

        for (j = 0; j < PASSWORD_LENGTH; j++) {
            message[i] = (char) (message[i] + password[j]);
        }
    }
}