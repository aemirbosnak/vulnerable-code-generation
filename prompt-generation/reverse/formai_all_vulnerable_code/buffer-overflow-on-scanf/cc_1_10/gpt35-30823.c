//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to encrypt the file
void encrypt(char *file_name, char key[])
{
    FILE *file = fopen(file_name, "r");
    FILE *encrypted = fopen("encrypted_file.txt", "w");
    int c;
    int i=0;
    while ((c = fgetc(file)) != EOF)
    {
        fputc(c ^ key[i], encrypted);
        i++;
        if(i==strlen(key))
            i=0;
    }
    fclose(file);
    fclose(encrypted);
}

//function to decrypt the file
void decrypt(char *file_name, char key[])
{
    FILE *encrypted = fopen(file_name, "r");
    FILE *decrypted = fopen("decrypted_file.txt", "w");
    int c;
    int i=0;
    while ((c = fgetc(encrypted)) != EOF)
    {
        fputc(c ^ key[i], decrypted);
        i++;
        if(i==strlen(key))
            i=0;
    }
    fclose(encrypted);
    fclose(decrypted);
}

int main()
{
    char file_name[20], key[20];

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(file_name, key);
    printf("File encrypted and saved as encrypted_file.txt\n");
    decrypt("encrypted_file.txt", key);
    printf("File decrypted and saved as decrypted_file.txt\n");

    return 0;
}