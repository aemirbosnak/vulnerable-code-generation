//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_file(char *filename)
{
    FILE *fp;
    char key[20], plaintext[1024], ciphertext[1024];
    int i, n, key_length = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("Enter the key: ");
    scanf("%s", key);

    key_length = strlen(key);
    n = key_length;

    while (n < 20)
    {
        key[n++] = key[n - 1];
    }

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        ciphertext[i] = (plaintext[i] - 'a' + key[i % key_length]) % 26 + 'a';
    }

    fclose(fp);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error writing to file");
        exit(1);
    }

    fprintf(fp, "%s", ciphertext);

    fclose(fp);

    printf("File encrypted successfully!\n");
}

int main()
{
    char filename[256];

    printf("Enter the filename: ");
    scanf("%s", filename);

    encrypt_file(filename);

    return 0;
}