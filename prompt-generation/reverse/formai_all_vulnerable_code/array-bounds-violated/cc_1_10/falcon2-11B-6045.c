//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    // Define variables
    char email[100];
    char password[100];
    char recipient[100];

    // Prompt user for email and password
    printf("Enter your email address: ");
    fgets(email, sizeof(email), stdin);
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    printf("Enter recipient's email address: ");
    fgets(recipient, sizeof(recipient), stdin);

    // Encrypt email and password using Ada Lovelace's cipher
    char encrypted_email[strlen(email) + 1];
    char encrypted_password[strlen(password) + 1];
    char encrypted_recipient[strlen(recipient) + 1];

    for (int i = 0; i < strlen(email); i++) {
        encrypted_email[i] = email[i] + (i * 5);
    }
    encrypted_email[strlen(email)] = '\0';

    for (int i = 0; i < strlen(password); i++) {
        encrypted_password[i] = password[i] - (i * 3);
    }
    encrypted_password[strlen(password)] = '\0';

    for (int i = 0; i < strlen(recipient); i++) {
        encrypted_recipient[i] = recipient[i] + (i * 2);
    }
    encrypted_recipient[strlen(recipient)] = '\0';

    // Send encrypted email to recipient
    printf("Sending email to %s...\n", encrypted_recipient);

    // Decrypt email and password using Ada Lovelace's cipher
    char decrypted_email[strlen(encrypted_email)];
    char decrypted_password[strlen(encrypted_password)];
    char decrypted_recipient[strlen(encrypted_recipient)];

    for (int i = 0; i < strlen(encrypted_email); i++) {
        decrypted_email[i] = encrypted_email[i] - (i * 5);
    }
    decrypted_email[strlen(encrypted_email)] = '\0';

    for (int i = 0; i < strlen(encrypted_password); i++) {
        decrypted_password[i] = encrypted_password[i] + (i * 3);
    }
    decrypted_password[strlen(encrypted_password)] = '\0';

    for (int i = 0; i < strlen(encrypted_recipient); i++) {
        decrypted_recipient[i] = encrypted_recipient[i] - (i * 2);
    }
    decrypted_recipient[strlen(encrypted_recipient)] = '\0';

    // Display decrypted email and password
    printf("Email: %s\nPassword: %s\nRecipient: %s\n", decrypted_email, decrypted_password, decrypted_recipient);

    return 0;
}