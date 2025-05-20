//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

int main() {
    char file_name[30], key[30], ch, encrypted[MAX_FILE_SIZE], decrypted[MAX_FILE_SIZE];
    int i, length;

    FILE *file_pointer, *encrypted_file_pointer, *decrypted_file_pointer;

    // Get filename and key from user
    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter key: ");
    scanf("%s", key);

    // Open file in read mode
    file_pointer = fopen(file_name, "r");

    // Check if file exists
    if (file_pointer == NULL) {
        printf("Error: File does not exist.\n");
        return 1;
    }

    // Copy contents of file to buffer
    i = 0;
    while((ch = fgetc(file_pointer)) != EOF) {
        encrypted[i] = ch;
        i++;
    }
    encrypted[i] = '\0';
    length = i;

    // Encrypt the file contents
    for (i = 0; i < length && key[i] != '\0'; i++) {
        encrypted[i] = encrypted[i] ^ key[i];
    }

    // Create encrypted file
    encrypted_file_pointer = fopen("encrypted.txt", "w");

    // Write encrypted contents to file
    fprintf(encrypted_file_pointer, "%s", encrypted);

    // Close files
    fclose(file_pointer);
    fclose(encrypted_file_pointer);

    printf("File encrypted successfully.\n");

    // Open encrypted file in read mode
    encrypted_file_pointer = fopen("encrypted.txt", "r");

    // Copy contents of encrypted file to buffer
    i = 0;
    while((ch = fgetc(encrypted_file_pointer)) != EOF) {
        decrypted[i] = ch;
        i++;
    }
    decrypted[i] = '\0';
    length = i;

    // Decrypt the file contents
    for (i = 0; i < length && key[i] != '\0'; i++) {
        decrypted[i] = decrypted[i] ^ key[i];
    }

    // Create decrypted file
    decrypted_file_pointer = fopen("decrypted.txt", "w");

    // Write decrypted contents to file
    fprintf(decrypted_file_pointer, "%s", decrypted);

    // Close files
    fclose(encrypted_file_pointer);
    fclose(decrypted_file_pointer);

    printf("File decrypted successfully.\n");

    return 0;
}