//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *input_file, char *output_file, char key) {
    FILE *ifp, *ofp;
    ifp = fopen(input_file, "r");
    ofp = fopen(output_file, "w");

    if (ifp == NULL || ofp == NULL) {
        printf("Error in file operation.");
        exit(1);
    }

    char ch;
    while((ch = fgetc(ifp)) != EOF) {
        ch ^= key; //XOR operation with the key
        fputc(ch, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

void decrypt(char *input_file, char *output_file, char key) {
    FILE *ifp, *ofp;
    ifp = fopen(input_file, "r");
    ofp = fopen(output_file, "w");

    if (ifp == NULL || ofp == NULL) {
        printf("Error in file operation.");
        exit(1);
    }

    char ch;
    while((ch = fgetc(ifp)) != EOF) {
        ch ^= key; //XOR operation with the key
        fputc(ch, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

int main() {

    char input_file[100], output_file[100];
    char key;

    printf("Enter name of file to encrypt: ");
    scanf("%s", input_file);

    printf("Enter name of file to save encrypted data: ");
    scanf("%s", output_file);

    printf("Enter a key to encrypt the file: ");
    scanf("%s", &key);

    encrypt(input_file, output_file, key);

    printf("File encrypt operation is successful.\n");

    printf("Enter name of file to decrypt: ");
    scanf("%s", input_file);

    printf("Enter name of file to save decrypted data: ");
    scanf("%s", output_file);

    printf("Enter a key to decrypt the file: ");
    scanf("%s", &key);

    decrypt(input_file, output_file, key);

    printf("File decrypt operation is successful.\n");

    return 0;
}