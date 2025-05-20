//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_KEY_LENGTH 100

// Function to generate a random key
void generateKey(char *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int key_length = strlen(charset);
    int i;
    for(i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = charset[rand() % key_length];
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

// Function to encrypt the file
void encryptFile(FILE *input_file, FILE *output_file, char *key) {
    char ch;
    int i;
    while((ch = fgetc(input_file))!= EOF) {
        for(i = 0; i < strlen(key); i++) {
            ch = ch + key[i] - 'A';
            if(ch > 'Z') {
                ch = ch - 26;
            }
        }
        fputc(ch, output_file);
    }
}

// Function to decrypt the file
void decryptFile(FILE *input_file, FILE *output_file, char *key) {
    char ch;
    int i;
    while((ch = fgetc(input_file))!= EOF) {
        for(i = 0; i < strlen(key); i++) {
            ch = ch - key[i] + 'A';
            if(ch < 'A') {
                ch = ch + 26;
            }
        }
        fputc(ch, output_file);
    }
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    char key[MAX_KEY_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    generateKey(key);

    FILE *input_file = fopen(input_file_name, "rb");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(output_file_name, "wb");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    char choice;
    scanf("%c", &choice);

    if(choice == 'e') {
        encryptFile(input_file, output_file, key);
        printf("File encrypted successfully!\n");
    }
    else if(choice == 'd') {
        decryptFile(input_file, output_file, key);
        printf("File decrypted successfully!\n");
    }
    else {
        printf("Invalid choice.\n");
        exit(1);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}