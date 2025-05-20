//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void encryptDecrypt(char *inputFile, char *outputFile, char *key);
void displayMenu();
void performAction(int choice);

// Main function
int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Choose an action (1-3): ");
        scanf("%d", &choice);
        performAction(choice);
    } while (choice != 3);
    
    printf("Thank you for playing with file magic! Goodbye!\n");
    return 0;
}

// Encrypt or decrypt the file based on the user's choice
void performAction(int choice) {
    char inputFile[100];
    char outputFile[100];
    char key[100];

    switch (choice) {
        case 1:
            printf("Enter the input file name for encryption: ");
            scanf("%s", inputFile);
            printf("Enter the output file name for encrypted data: ");
            scanf("%s", outputFile);
            printf("Enter the encryption key: ");
            scanf("%s", key);
            encryptDecrypt(inputFile, outputFile, key);
            printf("Encryption complete! Your secret file awaits...\n");
            break;
        case 2:
            printf("Enter the input file name for decryption: ");
            scanf("%s", inputFile);
            printf("Enter the output file name for decrypted data: ");
            scanf("%s", outputFile);
            printf("Enter the decryption key: ");
            scanf("%s", key);
            encryptDecrypt(inputFile, outputFile, key);
            printf("Decryption complete! Your plain text is restored...\n");
            break;
        case 3:
            // Exit the program
            break;
        default:
            printf("Invalid choice! Please select again.\n");
    }
}

// Display the menu
void displayMenu() {
    printf("\n--- Secret File Encrypter/Decrypter ---\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
}

// Encrypt and decrypt the file using XOR
void encryptDecrypt(char *inputFile, char *outputFile, char *key) {
    FILE *inFile, *outFile;
    int keyLen = strlen(key);
    int i = 0;
    char ch;

    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(inFile)) != EOF) {
        // XOR encryption/decryption
        fputc(ch ^ key[i % keyLen], outFile);
        i++;
    }

    fclose(inFile);
    fclose(outFile);
}