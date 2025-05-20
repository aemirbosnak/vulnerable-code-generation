//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Function to encrypt the message
void encrypt(char plain[], int key){
    int length=strlen(plain);
    int rows=ceil(length/(double)key);
    char grid[rows][key];
    int count=0;

    //Populating the grid
    for(int i=0;i<rows;i++){
        for(int j=0;j<key;j++){
            if(count<length){
                grid[i][j]=plain[count++];
            }
            else{
                grid[i][j]='*';
            }
        }
    }

    //Printing the encrypted message
    printf("Encrypted message: ");
    for(int i=0;i<key;i++){
        for(int j=0;j<rows;j++){
            printf("%c", grid[j][i]);
        }
    }
    printf("\n");
}

int main(){
    char message[1000];
    int key;

    //Taking message and key as input
    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    //Removing newline character from message
    if(message[strlen(message)-1]=='\n'){
        message[strlen(message)-1]='\0';
    }

    encrypt(message, key);

    return 0;
}