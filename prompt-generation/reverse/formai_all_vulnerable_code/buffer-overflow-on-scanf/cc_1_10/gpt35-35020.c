//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define MAX 100

void encode(char message[], char key[]); //function prototype
void decode(char message[], char key[]); //function prototype

int main()
{
    char message[MAX], key[MAX];    //declaration of variables
    int choice = 0;
    printf("Welcome to Digital Watermarking Example Program!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Encode message\n");
        printf("2. Decode message\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        while(getchar() != '\n');

        switch(choice)
        {
            case 1:
                printf("\nEnter a message to encode: ");
                fgets(message, MAX, stdin);
                printf("Enter a key: ");
                fgets(key, MAX, stdin);
                encode(message, key);
                printf("\nEncoded message: %s", message);
                break;

            case 2:
                printf("\nEnter a message to decode: ");
                fgets(message, MAX, stdin);
                printf("Enter the key: ");
                fgets(key, MAX, stdin);
                decode(message, key);
                printf("\nDecoded message: %s", message);
                break;

            case 3:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid input, please try again.");
        }
    }while(choice!=3);

    return 0;
}

void encode(char message[], char key[])
{
    int i, j = 0, len_message, len_key, sum = 0, value;
    len_message = strlen(message);
    len_key = strlen(key);

    for(i = 0; i < len_message; i++)
    {
        if(isspace(message[i]) || message[i] == '\n') //if space or new line then skip
        {
            continue;
        }

        value = (message[i] + key[j%len_key] + sum)%128; //add the ASCII values of message i and key j then modulo 128
        sum += value; //add the result to sum
        message[i] = value; //replace the current value of message i with the result
        j++; //increment j
    }
}

void decode(char message[], char key[])
{
    int i, j = 0, len_message, len_key, copy = 0, value;
    char temp[MAX];
    len_message = strlen(message);
    len_key = strlen(key);

    for(i = 0; i < len_message; i++)
    {
        if(isspace(message[i]) || message[i] == '\n') //if space or new line then skip
        {
            continue;
        }

        value = message[i] - key[j%len_key] - copy;
        copy += message[i]%len_key; //add message i modulo length of key to copy
        temp[i] = value;
        j++; //increment j
    }

    temp[i] = '\0';
    strcpy(message, temp); //copy contents of temp to message
}