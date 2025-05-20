//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_LEN 1000

int main()
{
    char message[MAX_WATERMARK_LEN];
    char key[50] = "the_one_and_only_key";
    char encrypted_message[MAX_WATERMARK_LEN], decrypted_message[MAX_WATERMARK_LEN];
    int choice, i, key_len, message_len;

    printf("Oh Romeo, what is thy choice of action today?\n");
    printf("1. Digital Watermarking\n2. Decrypt Watermark\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("What message dost thou want to add to the picture?\n");
        scanf(" %[^\n]", message);
        message_len = strlen(message);
        key_len = strlen(key);
        for (i = 0; i < message_len; i++)
        {
            encrypted_message[i] = message[i] ^ key[i % key_len];
        }
        encrypted_message[i] = '\0';
        printf("The message hath been marked with thine key...:\n%s\n", encrypted_message);
    }
    else if (choice == 2)
    {
        printf("What watermark dost thou wish to decrypt my beloved?\n");
        scanf(" %[^\n]", encrypted_message);
        message_len = strlen(encrypted_message);
        key_len = strlen(key);
        for (i = 0; i < message_len; i++)
        {
            decrypted_message[i] = encrypted_message[i] ^ key[i % key_len];
        }
        decrypted_message[i] = '\0';
        printf("My dear Juliet, the watermark dost reveal the following:\n%s\n", decrypted_message);
    }
    else
    {
        printf("Oh, woe is me! Thy choice doth not conform to the rules!\n");
        exit(1);
    }

    return 0;
}