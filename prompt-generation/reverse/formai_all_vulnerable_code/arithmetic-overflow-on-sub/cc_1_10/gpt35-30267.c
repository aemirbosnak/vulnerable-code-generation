//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
char *encrypt(char *str, int key);
char *decrypt(char *str, int key);

int main()
{
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    char *encrypted = encrypt(message, key);
    char *decrypted = decrypt(encrypted, key);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}

/* Function to encrypt a message */
char *encrypt(char *str, int key)
{
    int len = strlen(str);
    char *result = (char *)malloc(len * sizeof(char));
    int i;
    for (i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            result[i] = (str[i] + key - 'a') % 26 + 'a';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            result[i] = (str[i] + key - 'A') % 26 + 'A';
        else
            result[i] = str[i];
    }
    result[i] = '\0';
    return result;
}

/* Function to decrypt a message */
char *decrypt(char *str, int key)
{
    key = 26 - key;
    return encrypt(str, key);
}