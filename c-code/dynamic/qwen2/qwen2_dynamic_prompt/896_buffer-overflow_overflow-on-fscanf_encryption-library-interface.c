#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char filename[20];
    char password[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    printf("Enter the encryption key: ");
    int key;
    fscanf(file, "%d", &key); // Vulnerability here

    fclose(file);

    printf("Enter the password to encrypt: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    encrypt(password, key);

    printf("Encrypted password: %s\n", password);

    return EXIT_SUCCESS;
}
