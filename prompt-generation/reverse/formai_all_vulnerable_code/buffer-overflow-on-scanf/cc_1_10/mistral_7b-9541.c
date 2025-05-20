//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key_size 5
#define max_len 100

int key[key_size];
char encrypt(char plaintext, int index) {
    if (index >= key_size)
        return plaintext;
    return (plaintext + key[index] + encrypt(plaintext, index + 1));
}

char *encryptFile(char *inputFile, char *outputFile) {
    FILE *fp1 = fopen(inputFile, "r");
    FILE *fp2 = fopen(outputFile, "w");
    char ch, plaintext[max_len];
    int i;

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    printf("Enter the encryption key: ");
    for (i = 0; i < key_size; i++)
        scanf("%d", &key[i]);

    while ((ch = fgetc(fp1)) != EOF) {
        strcpy(plaintext, &ch);
        plaintext[1] = '\0';
        fprintf(fp2, "%c%c", encrypt(ch, 0), ch);
    }

    fclose(fp1);
    fclose(fp2);

    return "File encrypted successfully.";
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <inputFile> <outputFile>\n", argv[0]);
        return 1;
    }

    encryptFile(argv[1], argv[2]);
    printf("%s\n", "Encryption complete.");

    return 0;
}