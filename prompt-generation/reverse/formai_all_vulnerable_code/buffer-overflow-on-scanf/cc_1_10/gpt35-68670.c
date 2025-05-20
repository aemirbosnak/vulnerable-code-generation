//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1000

void encrypt(char[], char[]);
void decrypt(char[], char[]);
int getRandomNumber();
void shift(char[], int);

int main() {
    char txt[MAX_SIZE];
    char key[MAX_SIZE];
    int choice;

    printf("Enter a message to encrypt: ");
    scanf("%[^\n]%*c", txt);

    printf("Enter a key: ");
    scanf("%[^\n]%*c", key);

    printf("\n1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(txt, key);
            break;
        case 2:
            decrypt(txt, key);
            break;
        default:
            printf("Invalid input!\n");
    }

    return 0;
}

void encrypt(char txt[], char key[]) {
    int len_txt, len_key, i;

    len_txt = strlen(txt);
    len_key = strlen(key);

    if(len_key < len_txt) {
        printf("Key is shorter than message. The key will be repeated.\n");
        while(len_key != len_txt) {
            strcat(key, key);
            len_key = strlen(key);
        }
    }

    for(i = 0; i < len_txt; i++) {
        if(isalpha(txt[i])) {
            txt[i] = toupper(txt[i]);
            int x = txt[i] - 'A';
            int y = key[i] - 'A';
            int z = (x + y) % 26;
            txt[i] = z + 'A';
        }
    }

    printf("Encrypted message: %s\n", txt);
}

void decrypt(char txt[], char key[]) {
    int len_txt, len_key, i;

    len_txt = strlen(txt);
    len_key = strlen(key);

    if(len_key < len_txt) {
        printf("Key is shorter than message. The key will be repeated.\n");
        while(len_key != len_txt) {
            strcat(key, key);
            len_key = strlen(key);
        }
    }

    for(i = 0; i < len_txt; i++) {
        if(isalpha(txt[i])) {
            txt[i] = toupper(txt[i]);
            int x = txt[i] - 'A';
            int y = key[i] - 'A';
            int z = ((x - y) + 26) % 26;
            txt[i] = z + 'A';
        }
    }

    printf("Decrypted message: %s\n", txt);
}

int getRandomNumber() {
    srand(time(0));
    int num = (rand() % 26) + 1;
    return num;
}

void shift(char str[], int num) {
    int len, i;
    char temp[MAX_SIZE];

    len = strlen(str);

    for(i = 0; i < len; i++) {
        if(isalpha(str[i])) {
            int x = str[i] - 'A';
            int y = (x + num) % 26;
            temp[i] = y + 'A';
        } else {
            temp[i] = str[i];
        }
    }

    strcpy(str, temp);
}