//FormAI DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>

// Function to encrypt the file
void encryptFile(FILE *file)
{
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch += 10; // Shifting characters by 10 places
        fputc(ch, file);
    }
    printf("File encrypted successfully.\n");
}

// Function to decrypt the file
void decryptFile(FILE *file)
{
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch -= 10; // Shifting characters back by 10 places
        fputc(ch, file);
    }
    printf("File decrypted successfully.\n");
}

int main()
{
    char fileName[100];
    FILE *file;
    int choice;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    // Opening the file in read mode
    file = fopen(fileName, "r+");

    if (file == NULL) {
        printf("Error: File not found or cannot be opened.\n");
        return 0;
    }

    printf("1. Encrypt the file\n");
    printf("2. Decrypt the file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encryptFile(file);
            break;
        case 2:
            decryptFile(file);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Closing the file
    fclose(file);
    return 0;
}