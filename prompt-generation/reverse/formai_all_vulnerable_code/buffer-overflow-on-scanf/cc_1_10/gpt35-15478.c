//FormAI DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char password[20], encrypt[20], decrypt[20];
    int i, choice, length, key = 10;

    printf("======================\n");
    printf("| HAPPY FILE ENCRYPTOR |\n");
    printf("======================\n\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter a password to encrypt the file: ");
                scanf("%s", password);

                length = strlen(password);

                for (i = 0; i < length; i++) {
                    encrypt[i] = password[i] + key;
                }

                FILE *file = fopen("example.txt", "r+");
                if (file == NULL) {
                    printf("Error opening file.");
                    return 1;
                }

                fputs(encrypt, file);
                fclose(file);

                printf("File encrypted successfully!\n");
                break;

            case 2:
                printf("\nEnter the password to decrypt the file: ");
                scanf("%s", password);

                length = strlen(password);

                for (i = 0; i < length; i++) {
                    decrypt[i] = password[i] - key;
                }

                file = fopen("example.txt", "r");
                if (file == NULL) {
                    printf("Error opening file.");
                    return 1;
                }

                fgets(encrypt, 20, file);
                fclose(file);

                if (strcmp(decrypt, encrypt) == 0) {
                    printf("File decrypted successfully!\n");
                } else {
                    printf("Incorrect password. Please try again.\n");
                }

                break;

            case 3:
                printf("\nThank you for using the Happy File Encryptor! Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}