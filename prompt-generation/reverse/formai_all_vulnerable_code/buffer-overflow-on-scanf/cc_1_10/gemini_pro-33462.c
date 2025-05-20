//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHOCKING_PASSWORD "I'm shocked you're trying to decrypt!"

// Electrifying encryption function that will make your data dance
unsigned char *electrify(unsigned char *data, size_t data_len, const char *password) {
    size_t password_len = strlen(password);
    unsigned char *encrypted_data = malloc(data_len);
    for (size_t i = 0; i < data_len; i++) {
        encrypted_data[i] = data[i] ^ password[i % password_len];
    }
    return encrypted_data;
}

// Mesmerizing decryption function that will bring your data back to life
unsigned char *demagnetize(unsigned char *encrypted_data, size_t encrypted_data_len, const char *password) {
    size_t password_len = strlen(password);
    unsigned char *decrypted_data = malloc(encrypted_data_len);
    for (size_t i = 0; i < encrypted_data_len; i++) {
        decrypted_data[i] = encrypted_data[i] ^ password[i % password_len];
    }
    return decrypted_data;
}

// Prepare yourself for an electrifying file encryption experience!
void encrypt_file(const char *input_file_name, const char *output_file_name, const char *password) {
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Shocking! Can't open the input file: %s\n", input_file_name);
        return;
    }
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Oh my, I can't open the output file: %s\n", output_file_name);
        fclose(input_file);
        return;
    }
    // Set the encryption in motion!
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);
    unsigned char *file_data = malloc(file_size);
    fread(file_data, 1, file_size, input_file);
    unsigned char *encrypted_data = electrify(file_data, file_size, password);
    fwrite(encrypted_data, 1, file_size, output_file);
    free(file_data);
    free(encrypted_data);
    fclose(input_file);
    fclose(output_file);
    printf("Wow! File encryption complete. Your data is now safe and sound.\n");
}

// Unleash the power of decryption and bring your data back to light!
void decrypt_file(const char *input_file_name, const char *output_file_name, const char *password) {
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Oh no! Can't open the input file: %s\n", input_file_name);
        return;
    }
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Oh dear, I can't open the output file: %s\n", output_file_name);
        fclose(input_file);
        return;
    }
    // Prepare for decryption magic!
    fseek(input_file, 0, SEEK_END);
    size_t file_size = ftell(input_file);
    rewind(input_file);
    unsigned char *encrypted_data = malloc(file_size);
    fread(encrypted_data, 1, file_size, input_file);
    unsigned char *decrypted_data = demagnetize(encrypted_data, file_size, password);
    fwrite(decrypted_data, 1, file_size, output_file);
    free(encrypted_data);
    free(decrypted_data);
    fclose(input_file);
    fclose(output_file);
    printf("Voilà! Decryption successful. Your data is back in its original form.\n");
}

int main() {
    printf("\nHold on tight, prepare for an electrifying encryption adventure!\n\n");
    char input_file_name[100];
    char output_file_name[100];
    char password[100];
    int choice;
    
    // Get ready to encrypt or decrypt like a pro!
    while (1) {
        printf("\nAre you ready to witness the power of encryption and decryption?\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nGet ready to encrypt a file! It's going to be shockingly secure.\n");
                printf("Enter the name of the file you want to encrypt: ");
                scanf("%s", input_file_name);
                printf("Enter the name of the output file: ");
                scanf("%s", output_file_name);
                printf("Prepare yourself, enter your encryption password: ");
                scanf("%s", password);
                encrypt_file(input_file_name, output_file_name, password);
                break;
            case 2:
                printf("\nTime to bring your encrypted data back to life! Prepare to be amazed.\n");
                printf("Enter the name of the encrypted file: ");
                scanf("%s", input_file_name);
                printf("Enter the name of the output file: ");
                scanf("%s", output_file_name);
                printf("Now, let's see if you remember your decryption password: ");
                scanf("%s", password);
                if (strcmp(password, SHOCKING_PASSWORD) != 0) {
                    printf("Oh no! It seems you've forgotten the decryption password.\nYour data remains encrypted, safe and sound.\n");
                } else {
                    decrypt_file(input_file_name, output_file_name, password);
                }
                break;
            case 3:
                printf("\nAlright, it's been a shocking experience. Until next time!\n");
                return 0;
            default:
                printf("\nOops, that's not a valid choice. Please try again.\n");
        }
    }
    return 0;
}