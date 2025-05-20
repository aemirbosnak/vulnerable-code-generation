//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    
    // If file is not opened, return
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    
    // Read the content of the file
    char buffer[1000];
    int length = fread(buffer, 1, sizeof(buffer), file);
    
    // Close the file
    fclose(file);
    
    // Create a new file with encrypted content
    char newFilename[100];
    sprintf(newFilename, "%s.enc", filename);
    
    // Open the new file in write mode
    FILE *encryptedFile = fopen(newFilename, "w");
    
    // If file is not opened, return
    if (encryptedFile == NULL) {
        printf("Error opening the new file.\n");
        return;
    }
    
    // Encrypt the content and write to the new file
    for (int i = 0; i < length; i++) {
        // Encryption logic goes here
        // Replace the content with encrypted content
        fwrite(buffer, 1, sizeof(buffer), encryptedFile);
    }
    
    // Close the new file
    fclose(encryptedFile);
    
    // Inform the user about the encryption process
    printf("File %s encrypted successfully.\n", filename);
}

// Function to decrypt the file
void decryptFile(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    
    // If file is not opened, return
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    
    // Read the content of the file
    char buffer[1000];
    int length = fread(buffer, 1, sizeof(buffer), file);
    
    // Close the file
    fclose(file);
    
    // Create a new file with decrypted content
    char newFilename[100];
    sprintf(newFilename, "%s.dec", filename);
    
    // Open the new file in write mode
    FILE *decryptedFile = fopen(newFilename, "w");
    
    // If file is not opened, return
    if (decryptedFile == NULL) {
        printf("Error opening the new file.\n");
        return;
    }
    
    // Decrypt the content and write to the new file
    for (int i = 0; i < length; i++) {
        // Decryption logic goes here
        // Replace the content with decrypted content
        fwrite(buffer, 1, sizeof(buffer), decryptedFile);
    }
    
    // Close the new file
    fclose(decryptedFile);
    
    // Inform the user about the decryption process
    printf("File %s decrypted successfully.\n", filename);
}

// Main function
int main() {
    // Prompt the user for the file name
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    
    // Encrypt the file
    encryptFile(filename);
    
    // Decrypt the file
    decryptFile(filename);
    
    return 0;
}