//FormAI DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//Function Declaration
void encrypt(char *str, int key);
void decrypt(char *str, int key);

int main()
{
    char str[MAX_SIZE];
    int key, choice;
    
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    printf("Enter a key (between 1 and 25): ");
    scanf("%d", &key);

    printf("Enter 1 for Encryption or 2 for Decryption: ");
    scanf("%d", &choice);

    if(choice == 1){
        encrypt(str, key);
        printf("Encrypted string: %s\n", str);
    }
    else if(choice == 2){
        decrypt(str, key);
        printf("Decrypted string: %s\n", str);
    }
    else{
        printf("Invalid Choice! Try again.\n");
    }
    return 0;
}

//Function Definition for Encryption
void encrypt(char *str, int key)
{
    int i=0;
    char c;
    while(str[i] != '\0'){

        c = str[i];

        if(c >= 'a' && c <= 'z'){
            c += key;
            if(c > 'z'){
                c = c - 'z' + 'a' - 1;
            }
            str[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c += key;
            if(c > 'Z'){
                c = c - 'Z' + 'A' - 1;
            }
            str[i] = c;
        }
        i++;
    }
}

//Function Definition for Decryption
void decrypt(char *str, int key)
{
    int i=0;
    char c;

    while(str[i] != '\0'){

        c = str[i];

        if(c >= 'a' && c <= 'z'){
            c -= key;
            if(c < 'a'){
                c = c + 'z' - 'a' + 1;
            }
            str[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c -= key;
            if(c < 'A'){
                c = c + 'Z' - 'A' + 1;
            }
            str[i] = c;
        }
        i++;
    }
}