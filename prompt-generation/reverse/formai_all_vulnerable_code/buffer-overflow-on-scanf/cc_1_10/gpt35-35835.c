//FormAI DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//my cute file encryption program ^_^

//encryption function
void encryptFile(char* filename, int key)
{
    FILE *fp, *fptr;
    char ch;
    fp = fopen(filename, "r");
    fptr = fopen("temp.txt", "w");

    while((ch=getc(fp))!=EOF)
    {
        ch = ch+key;
        putc(ch, fptr);
    }
    fclose(fp);
    fclose(fptr);
    remove(filename);
    rename("temp.txt", filename);
    printf("\nEncryption Successful :)");
}

//decryption function
void decryptFile(char* filename, int key)
{
    FILE *fp, *fptr;
    char ch;
    fp = fopen(filename, "r");
    fptr = fopen("temp.txt", "w");

    while((ch=getc(fp))!=EOF)
    {
        ch = ch-key;
        putc(ch, fptr);
    }
    fclose(fp);
    fclose(fptr);
    remove(filename);
    rename("temp.txt", filename);
    printf("\nDecryption Successful :)");
}

int main()
{
    printf("\n\tWelcome! Let's Encrypt a file. ^_^ ");
    printf("\n\nEnter the following details:");
    char filename[50];
    int key;

    //file name input
    printf("\nFile Name (max 50 characters): ");
    scanf("%s", filename);

    //key input
    printf("\nEnter a key (1-100): ");
    scanf("%d", &key);

    //check key validity
    if(key<=0 || key>100)
    {
        printf("\nInvalid key! Please enter a key between 1-100.");
        exit(0);
    }

    //check file validity
    FILE *fp;
    fp = fopen(filename, "r");

    if(fp==NULL)
    {
        printf("\nFile not found! Please enter a valid file name.");
        exit(0);
    }
    else
    {
        fclose(fp);
    }

    //menu
    int choice;
    printf("\nWhat do you want to do?");
    printf("\n1. Encrypt");
    printf("\n2. Decrypt");
    printf("\n\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    //perform encryption or decryption based on user's choice
    if(choice==1)
    {
        encryptFile(filename, key);
    }
    else if(choice==2)
    {
        decryptFile(filename, key);
    }
    else
    {
        printf("\nInvalid Choice! Please enter a valid choice.");
        exit(0);
    }

    printf("\n\nThank you for encrypting/decrypting. Stay Safe! ^_^");
    return 0;
}