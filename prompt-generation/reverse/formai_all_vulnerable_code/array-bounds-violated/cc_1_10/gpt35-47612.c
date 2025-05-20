//FormAI DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100], ciphertext[100], key[100], key_cpy[100];
    int i, j, len_msg, len_key;

    printf("Enter the message you want to encrypt: \n");
    fgets(message, 100, stdin);
    len_msg = strlen(message);

    printf("Enter the key: \n");
    fgets(key, 100, stdin);
    len_key = strlen(key);

    /* Removing the newline character from message & key */
    if(message[len_msg-1] == '\n')
    {
        message[len_msg-1] = '\0';
        len_msg--;
    }

    if(key[len_key-1] == '\n')
    {
        key[len_key-1] = '\0';
        len_key--;
    }

    /* Copying key to key_cpy to wrap the key around message */
    strcpy(key_cpy, key);

    /* Wrapping the key around message */
    while(len_key < len_msg)
    {
        strcat(key, key_cpy);
        len_key = strlen(key);
    }

    /* Encryption */
    for(i=0; i<len_msg; i++)
    {
        int value = message[i] + key[i];
        if(value > 122) /* Looping back to 'a' after 'z' */
        {
            value = (value % 123) + 97;
        }

        ciphertext[i] = (char)value;
    }
    ciphertext[len_msg] = '\0';

    printf("\nEncrypted message:\n%s", ciphertext);

    return 0;
}