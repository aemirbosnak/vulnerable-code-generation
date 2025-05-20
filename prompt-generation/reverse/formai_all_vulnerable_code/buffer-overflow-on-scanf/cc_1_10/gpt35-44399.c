//FormAI DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *msg, int key){
    int len = strlen(msg), i;
    for(i = 0; i < len; i++){
        if(msg[i]>= 'a' && msg[i]<= 'z'){
            msg[i] = ((msg[i]-'a'+key)%26)+'a';
        }
        else if(msg[i]>= 'A' && msg[i]<= 'Z'){
            msg[i] = ((msg[i]-'A'+key)%26)+'A';
        }
    }
}

void decrypt(char *msg, int key){
    int len = strlen(msg), i;
    for(i = 0; i < len; i++){
        if(msg[i]>= 'a' && msg[i]<= 'z'){
            msg[i] = ((msg[i]-'a'-key+26)%26)+'a';
        }
        else if(msg[i]>= 'A' && msg[i]<= 'Z'){
            msg[i] = ((msg[i]-'A'-key+26)%26)+'A';
        }
    }
}

int main(){
    char message[100], choice;
    int key;

    printf("Enter a message to encrypt (max 100 characters):\n");
    fgets(message, sizeof(message), stdin);

    printf("Enter an encryption key:\n");
    scanf("%d", &key);

    printf("Do you want to (e)ncrypt or (d)ecrypt the message? Enter 'e' or 'd':\n");
    getchar(); //clear the input buffer
    scanf("%c", &choice);

    if(choice == 'e'){
        encrypt(message, key);
        printf("Encrypted message: %s", message);
    }
    else if(choice == 'd'){
        decrypt(message, key);
        printf("Decrypted message: %s", message);
    }
    else{
        printf("Invalid choice.");
    }

    return 0;
}