//FormAI DATASET v1.0 Category: File Encyptor ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000 //Max length of filename or file content

void encrypt_file(char* filename, char* key);
void decrypt_file(char* filename, char* key);

int main()
{
    char filename[MAX_LEN], key[MAX_LEN];
    int choice;
    
    while(1)
    {
        printf("Enter choice:\n1. Encrypt File\n2. Decrypt File\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter name of file to encrypt: ");
                scanf("%s", filename);
                printf("Enter key for encryption: ");
                scanf("%s", key);
                encrypt_file(filename, key);
                break;

            case 2:
                printf("Enter name of file to decrypt: ");
                scanf("%s", filename);
                printf("Enter key for decryption: ");
                scanf("%s", key);
                decrypt_file(filename, key);
                break;

            case 3:
                printf("Exiting program...");
                exit(0);

            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }
    return 0;
}

void encrypt_file(char* filename, char* key)
{
    FILE *fpin, *fpout;
    char ch, output[MAX_LEN];
    int i, k = 0, keylen;

    fpin = fopen(filename,"r");
    if(fpin==NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fpout = fopen(strcat(filename,".enc"),"w");
    if(fpout==NULL)
    {
        printf("Error creating encrypted file!\n");
        return;
    }

    keylen = strlen(key); //Find length of key

    //Process each character in the file
    while((ch=fgetc(fpin))!=EOF)
    {
        //XOR operation with the key
        output[k++] = ch ^ key[i%keylen];
        i++;
    }
    output[k] = '\0'; //Add null terminator

    //Write encrypted content to file
    fputs(output, fpout);

    printf("Encrypted file created successfully!\n");

    //Close files
    fclose(fpin);
    fclose(fpout);
    return;
}

void decrypt_file(char* filename, char* key)
{
    FILE *fpin, *fpout;
    char ch, output[MAX_LEN];
    int i, k = 0, keylen;

    fpin = fopen(filename,"r");
    if(fpin==NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fpout = fopen(strcat(filename,".decrypted"),"w");
    if(fpout==NULL)
    {
        printf("Error creating decrypted file!\n");
        return;
    }

    keylen = strlen(key); //Find length of key
    
    //Process each character in the file
    while((ch=fgetc(fpin))!=EOF)
    {
        //XOR operation with the key
        output[k++] = ch ^ key[i%keylen];
        i++;
    }
    output[k] = '\0'; //Add null terminator

    //Write decrypted content to file
    fputs(output, fpout);

    printf("Decrypted file created successfully!\n");

    //Close files
    fclose(fpin);
    fclose(fpout);
    return;
}