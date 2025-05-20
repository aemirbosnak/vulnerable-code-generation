//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char message[100], password[25], encrypted_message[100], decrypted_message[100];
    int i, j, key_len, msg_len, pwd_len;

    printf("Welcome to the File Encryptor 3000!\n");
    printf("Make sure you have the necessary permissions to access the file you want to encrypt.\n\n");

    printf("Enter the password to encrypt your file: ");
    scanf("%s", password);
    pwd_len = strlen(password);
    printf("\nEnter the name of the file you want to encrypt (including the extension): ");
    scanf("%s", message);

    /* Encrypt the file */
    FILE *fp1 = fopen(message, "r");
    if (fp1 == NULL)
    {
        printf("Error: Unable to open file. Please try again.\n");
        return 1;
    }

    FILE *fp2 = fopen(strcat(message, ".enc"), "w");
    if (fp2 == NULL)
    {
        printf("Error: Unable to create encrypted file. Please try again.\n");
        return 1;
    }

    fseek(fp1, 0L, SEEK_END);
    msg_len = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);

    fprintf(fp2, "%d", msg_len);

    for (i = 0, j = 0; j < msg_len; i++, j++)
    {
        if (i == pwd_len)
        {
            i = 0;
        }

        key_len = password[i];

        encrypted_message[j] = fgetc(fp1) + key_len;
        fprintf(fp2, "%d", key_len);
    }

    fprintf(fp2, "%s", encrypted_message);
    fclose(fp1);
    fclose(fp2);

    printf("\nYour file has been encrypted successfully!\n");

    /* Decrypt the file */
    printf("\n\n************* Here comes the fun part! **************\n");
    printf("Do you want to decrypt your file? [yes/no]: ");
    char answer[10];
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0)
    {
        printf("\nEnter the password to decrypt your file (case sensitive): ");
        scanf("%s", password);
        printf("\nEnter the name of the encrypted file (including the extension): ");
        scanf("%s", message);

        FILE *fp3 = fopen(message, "r");
        if (fp3 == NULL)
        {
            printf("Error: Unable to open file. Please try again.\n");
            return 1;
        }

        fscanf(fp3, "%d", &msg_len);

        for (i = 0, j = 0; j < msg_len; i++, j++)
        {
            if (i == pwd_len)
            {
                i = 0;
            }

            key_len = password[i];

            fscanf(fp3, "%d", &key_len);
            decrypted_message[j] = fgetc(fp3) - key_len;
        }

        fclose(fp3);

        printf("\nYour file has been decrypted successfully!\n");
    }
    else
    {
        printf("\nThank you for using the File Encryptor 3000. Goodbye!\n");
        return 0;
    }

    FILE *fp4 = fopen(strncpy(message, message, strlen(message) - 4), "w");
    if (fp4 == NULL)
    {
        printf("Error: Unable to create decrypted file. Please try again.\n");
        return 1;
    }

    fprintf(fp4, "%s", decrypted_message);
    fclose(fp4);

    printf("\nThe decrypted file has been saved successfully!\n");
    printf("Thank you for using the File Encryptor 3000. Goodbye!\n");

    return 0;
}