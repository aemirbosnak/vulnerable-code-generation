//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "secret_key"

void encrypt(char *file_name) {
    FILE *file;
    char ch;
    int i, j, key_index;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the encryption key: ");
    scanf("%s", KEY);

    while ((ch = fgetc(file))!= EOF) {
        i = tolower(ch);
        key_index = tolower(KEY[0]) - 97;

        if (isalpha(ch)) {
            j = (i - key_index + 26) % 26;
            if (isupper(ch)) {
                printf("%c", toupper(j + 65));
            } else {
                printf("%c", toupper(j + 97));
            }
        } else {
            printf("%c", ch);
        }
    }

    fclose(file);
}

void decrypt(char *file_name) {
    FILE *file;
    char ch;
    int i, j, key_index;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the decryption key: ");
    scanf("%s", KEY);

    while ((ch = fgetc(file))!= EOF) {
        i = tolower(ch);
        key_index = tolower(KEY[0]) - 97;

        if (isalpha(ch)) {
            j = (i - key_index - 26 + 26) % 26;
            if (isupper(ch)) {
                printf("%c", toupper(j + 65));
            } else {
                printf("%c", toupper(j + 97));
            }
        } else {
            printf("%c", ch);
        }
    }

    fclose(file);
}

int main() {
    char choice;
    char file_name[100];

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%c", &choice);

    if (choice == 'e' || choice == 'E') {
        encrypt(file_name);
    } else if (choice == 'd' || choice == 'D') {
        decrypt(file_name);
    } else {
        printf("Invalid choice.\n");
        exit(1);
    }

    return 0;
}