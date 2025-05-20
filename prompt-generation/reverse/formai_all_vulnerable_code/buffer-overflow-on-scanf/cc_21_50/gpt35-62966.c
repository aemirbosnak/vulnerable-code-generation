//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number
int getRandomNum(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    int num_balls = 75; //total number of balls in the game
    int num_players; //number of players in the game
    int player_cards[10][5]; //player cards array
    int bingo_card[5][5]; //bingo card array
    int ball_drawn; //last ball drawn
    char play_again; //play again flag
    
    //Cyberpunk-style welcome message
    printf("CyberBingo V1.0\n");
    printf("Welcome to the neon-lit world of CyberBingo!\n\n");
    
    do
    {
        //Get number of players
        printf("How many players (1-10)? ");
        scanf("%d", &num_players);
        printf("\n");
        
        //Check if number of players is within range
        if(num_players < 1 || num_players > 10)
        {
            printf("Invalid number of players!\n");
            continue;
        }
        
        //Generate player cards
        printf("Generating player cards...\n\n");
        for(int i = 0; i < num_players; i++)
        {
            printf("Player %d card:\n", i+1);
            for(int j = 0; j < 5; j++)
            {
                for(int k = 0; k < 5; k++)
                {
                    if(j == 2 && k == 2)
                    {
                        player_cards[i][j*5+k] = 0; //mark center square as free
                        printf("B  ");
                    }
                    else
                    {
                        player_cards[i][j*5+k] = getRandomNum((j*15)+1, (j*15)+15); //generate random number for square
                        printf("%d  ", player_cards[i][j*5+k]);
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
         
        //Generate bingo card
        printf("Generating CyberBingo card...\n\n");
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(j == 2 && i == 2)
                {
                    bingo_card[i][j] = 0; //mark center square as free
                    printf("B  ");
                }
                else
                {
                    bingo_card[i][j] = getRandomNum((j*15)+1, (j*15)+15);
                    printf("%d  ", bingo_card[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
        
        //Begin game loop
        printf("Begin CyberBingo game!\n\n");
        int winner_found = 0; //flag to indicate winner found
        int card_index; //index of player card with winning number
        int row_counter[5] = {0}; //array to keep track of number of marked squares in each row
        int col_counter[5] = {0}; //array to keep track of number of marked squares in each column
        int diag_counter = 0; //counter to keep track of number of marked squares in diagonal
        
        while(!winner_found)
        {
            //Draw a new ball
            ball_drawn = getRandomNum(1, num_balls);
            
            //Cyberpunk-style ball drawing message
            printf("Drawing a ball...\n");
            printf("Ball %d!\n\n", ball_drawn);
            
            //Check player cards for winning number
            for(int i = 0; i < num_players; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    for(int k = 0; k < 5; k++)
                    {
                        if(player_cards[i][j*5+k] == ball_drawn)
                        {
                            player_cards[i][j*5+k] = -1; //mark square as called
                            printf("Player %d found %d!\n\n", i+1, ball_drawn);
                            
                            //check for winner
                            card_index = i;
                            for(int n = 0; n < 5; n++)
                            {
                                //check rows
                                if(player_cards[card_index][n*5] == -1 && player_cards[card_index][n*5+1] == -1 && player_cards[card_index][n*5+2] == -1 && player_cards[card_index][n*5+3] == -1 && player_cards[card_index][n*5+4] == -1)
                                {
                                    winner_found = 1;
                                    break;
                                }
                                //check columns
                                if(player_cards[card_index][n] == -1 && player_cards[card_index][n+5] == -1 && player_cards[card_index][n+10] == -1 && player_cards[card_index][n+15] == -1 && player_cards[card_index][n+20] == -1)
                                {
                                    winner_found = 1;
                                    break;
                                }
                            }
                            //check diagonal
                            if(player_cards[card_index][0] == -1 && player_cards[card_index][6] == -1 && player_cards[card_index][12] == -1 && player_cards[card_index][18] == -1 && player_cards[card_index][24] == -1)
                            {
                                winner_found = 1;
                                break;
                            }
                            if(player_cards[card_index][4] == -1 && player_cards[card_index][8] == -1 && player_cards[card_index][12] == -1 && player_cards[card_index][16] == -1 && player_cards[card_index][20] == -1)
                            {
                                winner_found = 1;
                                break;
                            }
                            break;
                        }
                    }
                    if(winner_found) break;
                }
                if(winner_found) break;
            }
            
            //If winner is found, print Cyberpunk-style winner message and end game
            if(winner_found)
            {
                printf("Winning number: %d\n", ball_drawn);
                printf("Player %d wins CyberBingo!\n\n", card_index+1);
                break;
            }
        }
        
        //Prompt user to play again
        printf("Play again (y/n)? ");
        scanf(" %c", &play_again);
        printf("\n");
        
    } while(play_again == 'y' || play_again == 'Y');
    
    printf("Goodbye from CyberBingo!\n");
    
    return 0;
}