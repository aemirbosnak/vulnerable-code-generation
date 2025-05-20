//FormAI DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

void encrypt(char *string, int key) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = ((string[i] - 'a' + key) % 26) + 'a';
        }
        else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = ((string[i] - 'A' + key) % 26) + 'A';
        }
    }
}

void decrypt(char *string, int key) {
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = ((string[i] - 'a' - key + 26) % 26) + 'a';
        }
        else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = ((string[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

void encrypt_file(char *filename, int key) {
    FILE *file;
    char file_data[MAX_FILE_SIZE];

    // Open file for reading
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: File could not be read\n");
        return;
    }

    // Read file contents into memory
    int index = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && index < MAX_FILE_SIZE) {
        file_data[index++] = ch;
    }
    file_data[index] = '\0';

    // Close file
    fclose(file);

    // Encrypt data
    encrypt(file_data, key);

    // Open file for writing
    if ((file = fopen(filename, "w")) == NULL) {
        printf("Error: File could not be written\n");
        return;
    }

    // Write encrypted data to file
    fprintf(file, "%s", file_data);

    // Close file
    fclose(file);
}

void decrypt_file(char *filename, int key) {
    FILE *file;
    char file_data[MAX_FILE_SIZE];

    // Open file for reading
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: File could not be read\n");
        return;
    }

    // Read file contents into memory
    int index = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && index < MAX_FILE_SIZE) {
        file_data[index++] = ch;
    }
    file_data[index] = '\0';

    // Close file
    fclose(file);

    // Decrypt data
    decrypt(file_data, key);

    // Open file for writing
    if ((file = fopen(filename, "w")) == NULL) {
        printf("Error: File could not be written\n");
        return;
    }

    // Write decrypted data to file
    fprintf(file, "%s", file_data);

    // Close file
    fclose(file);
}

int main() {
    char filename[100];
    int key, choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    printf("Enter your choice:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    printf("Choice (1/2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt_file(filename, key);
            printf("File encrypted successfully\n");
            break;
        case 2:
            decrypt_file(filename, key);
            printf("File decrypted successfully\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}