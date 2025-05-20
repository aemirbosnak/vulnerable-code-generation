//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to encrypt message
void encrypt(char message[], int key)
{
    int i;
    for(i=0; message[i]!='\0'; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] + key - 65;
            }
            else
            {
                message[i] = message[i] + key - 97;
            }
        }
    }
}

//Function to decrypt message
void decrypt(char message[], int key)
{
    int i;
    for(i=0; message[i]!='\0'; i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] - key - 65;
            }
            else
            {
                message[i] = message[i] - key - 97;
            }
        }
    }
}

int main()
{
    int num_players, i, j, key;
    char player_name[100][50];
    char message[100];

    //Get number of players
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    //Get player names
    printf("Enter player names:\n");
    for(i=0; i<num_players; i++)
    {
        scanf("%s", player_name[i]);
    }

    //Get message to be encrypted
    printf("Enter message to be encrypted:\n");
    scanf("%s", message);

    //Encrypt message
    srand(time(NULL));
    key = rand() % 26 + 1;
    encrypt(message, key);

    //Print encrypted message
    printf("\nEncrypted message: %s\n", message);

    //Decrypt message
    decrypt(message, key);

    //Print decrypted message
    printf("\nDecrypted message: %s\n", message);

    return 0;
}