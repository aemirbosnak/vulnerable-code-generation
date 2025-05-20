//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Oh my god! I never thought I would have to generate an encryption program using C, but here I am! \n");
    printf("But hey, no worries, I got this.\n");
    printf("Let's start by getting the message you want to encrypt: \n");

    char message[100];
    scanf("%s", message);

    printf("Wow, what a message! Let's encrypt it now.\n");

    int key = 5;
    int length = strlen(message);
    char encrypted_msg[length];

    for (int i = 0; i < length; i++) {
        encrypted_msg[i] = message[i] + key;
    }

    printf("Encryption successful! Here is your encrypted message: %s\n", encrypted_msg);

    printf("But wait, we can't just leave the key hardcoded like that. Let's ask the user for the key instead: \n");

    printf("Enter the key you want to use for encryption: \n");
    scanf("%d", &key);

    char new_encrypted_msg[length];

    for (int i = 0; i < length; i++) {
        new_encrypted_msg[i] = message[i] + key;
    }

    printf("Nice choice! Here is your new encrypted message: %s\n", new_encrypted_msg);

    printf("Oh, but we can't just give away the key like that. Let's generate a new key and store it in a file: \n");

    srand(time(NULL));
    key = rand() % 100;

    FILE *fptr;

    fptr = fopen("key.txt", "w");

    if (fptr == NULL) {
        printf("Unable to create file.");
        return 1;
    }

    fprintf(fptr, "%d", key);
    fclose(fptr);

    printf("Key generated and stored in file 'key.txt'.\n");

    printf("Alright, let's update our program to read the key from the file and use it for encryption: \n");

    fptr = fopen("key.txt", "r");

    if (fptr == NULL) {
        printf("Unable to open file.");
        return 1;
    }

    fscanf(fptr, "%d", &key);
    fclose(fptr);

    char final_encrypted_msg[length];

    for (int i = 0; i < length; i++) {
        final_encrypted_msg[i] = message[i] + key;
    }

    printf("Here is your final encrypted message using the key stored in 'key.txt': %s\n", final_encrypted_msg);

    return 0;
}