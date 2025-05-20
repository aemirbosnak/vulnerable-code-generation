//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000

void shift(char* text, int key) {
    int i;

    for(i = 0; text[i] != '\0'; ++i) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
    }
}

void substitution(char* text, char* key) {
    char table[26];
    int i, j;

    for(i = 0; i < 26; ++i) {
        table[i] = ' ';
    }

    for(i = 0; key[i] != '\0'; ++i) {
        if(key[i] >= 'a' && key[i] <= 'z') {
            key[i] -= 'a' - 'A';
        }

        if(table[key[i] - 'A'] == ' ') {
            table[key[i] - 'A'] = 'a' + i;
        }
    }

    for(i = 0; text[i] != '\0'; ++i) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = table[text[i] - 'a'];
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = table[text[i] - 'A'] - ('a' - 'A');
        }
    }
}

int main() {
    char text[MAX_LEN];
    char key[MAX_LEN];
    int choice, keyVal = 0;
    printf("Enter the text: ");
    fgets(text, MAX_LEN, stdin);
    strtok(text, "\n");

    printf("\n1. Shift Cipher\n2. Substitution Cipher\nEnter Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter key value: ");
            scanf("%d", &keyVal);
            shift(text, keyVal);
            printf("\nEncrypted Text: %s\n", text);
            shift(text, 26 - keyVal);
            printf("Decrypted Text: %s\n", text);
            break;
        case 2:
            printf("\nEnter key value: ");
            scanf("%s", key);
            substitution(text, key);
            printf("\nEncrypted Text: %s\n", text);
            substitution(text, key);
            printf("Decrypted Text: %s\n", text);
            break;
        default:
            printf("\nInvalid Choice!\n");
    }

    return 0;
}