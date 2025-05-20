//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define QR_SIZE 21
#define MAX_PLAYERS 8
#define MAX_CODE_LENGTH 16

char* generateCode()
{
    char* code = (char*) malloc(MAX_CODE_LENGTH * sizeof(char));
    srand(time(0));
    for(int i = 0; i < MAX_CODE_LENGTH; i++)
    {
        code[i] = (rand() % 10) + '0';
    }
    return code;
}

void generateQRCode(char qrCode[QR_SIZE][QR_SIZE], char* code)
{
    // fill qrCode with random characters
    for(int i = 0; i < QR_SIZE; i++)
    {
        for(int j = 0; j < QR_SIZE; j++)
        {
            qrCode[i][j] = (rand() % 2 == 0) ? 'X' : 'O';
        }
    }

    // add the code to the qrCode
    int code_index = 0;
    for(int i = 4; i < 17; i += 4)
    {
        qrCode[10][i] = code[code_index];
        code_index++;
    }
}

int main()
{
    // initialize the players array
    char players[MAX_PLAYERS][MAX_CODE_LENGTH];
    int numPlayers = 0;

    while(true)
    {
        printf("Welcome to the QR code generator!\n");
        printf("1) Generate new QR code\n");
        printf("2) Add player to game\n");
        printf("3) Play game\n");
        printf("4) Exit\n");

        int choice = 0;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            char* code = generateCode();
            char qrCode[QR_SIZE][QR_SIZE];
            generateQRCode(qrCode, code);
            printf("QR code:\n");
            for(int i = 0; i < QR_SIZE; i++)
            {
                for(int j = 0; j < QR_SIZE; j++)
                {
                    printf("%c", qrCode[i][j]);
                }
                printf("\n");
            }
            printf("Code: %s\n", code);
        }
        else if(choice == 2)
        {
            if(numPlayers >= MAX_PLAYERS)
            {
                printf("Max number of players reached!\n");
            }
            else
            {
                char code[MAX_CODE_LENGTH];
                printf("Enter player code: ");
                scanf("%s", code);
                strcpy(players[numPlayers], code);
                numPlayers++;
                printf("Player added!\n");
            }
        }
        else if(choice == 3)
        {
            if(numPlayers < 2)
            {
                printf("Need at least two players to play!\n");
            }
            else
            {
                // randomly select two players to play game
                int player1_index = rand() % numPlayers;
                int player2_index = rand() % numPlayers;
                while(player2_index == player1_index)
                {
                    player2_index = rand() % numPlayers;
                }
                char* player1_code = players[player1_index];
                char* player2_code = players[player2_index];

                // generate two qr codes for the players
                char qrCode1[QR_SIZE][QR_SIZE];
                generateQRCode(qrCode1, player1_code);
                char qrCode2[QR_SIZE][QR_SIZE];
                generateQRCode(qrCode2, player2_code);

                // print out the qr codes for the players
                printf("Player 1 code:\n");
                for(int i = 0; i < QR_SIZE; i++)
                {
                    for(int j = 0; j < QR_SIZE; j++)
                    {
                        printf("%c", qrCode1[i][j]);
                    }
                    printf("\n");
                }
                printf("Player 1 code: %s\n", player1_code);

                printf("Player 2 code:\n");
                for(int i = 0; i < QR_SIZE; i++)
                {
                    for(int j = 0; j < QR_SIZE; j++)
                    {
                        printf("%c", qrCode2[i][j]);
                    }
                    printf("\n");
                }
                printf("Player 2 code: %s\n", player2_code);
            }
        }
        else if(choice == 4)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}