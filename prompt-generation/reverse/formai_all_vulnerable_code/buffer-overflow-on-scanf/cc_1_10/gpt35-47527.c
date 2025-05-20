//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *s1, char *s2) {
    int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    int matrix[s1len+1][s2len+1];
    
    matrix[0][0] = 0;
    
    for (x = 1; x <= s1len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    
    for (y = 1; y <= s2len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    
    for (x = 1; x <= s1len; x++)
        for (y = 1; y <= s2len; y++)
            matrix[x][y] = 
                minimum(matrix[x-1][y] + 1,         
                        matrix[x][y-1] + 1,         
                        matrix[x-1][y-1] + (s1[x-1] == s2[y-1] ? 0 : 1)); 
  
    return matrix[s1len][s2len];
}

int minimum(int a,int b,int c) {
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    if(c<=a && c<=b) return c;
}

int main()
{
    char player1[100], player2[100];
    int score1=0, score2=0, round=1;
    while(round<=10) // Play 10 rounds of game
    {
        printf("Round %d:\n", round);
        printf("Player 1, enter a word: ");
        scanf("%s", player1);
        printf("Player 2, enter a word: ");
        scanf("%s", player2);
        int distance = levenshtein_distance(player1, player2);
        if(distance <= 3) // Words are close enough
        {
            if(distance == 0)
            {
                score1 += 2;
                score2 += 2;
                printf("It's a tie! Both players scored 2 points.\n");
            }
            else
            {
                score1 += 1;
                score2 += 1;
                printf("Words are close! Both players scored 1 point.\n");
            }
        }
        else // Words are not close enough
        {
            if(distance < strlen(player1)) 
            {
                score1 += 2;
                printf("Player 1 wins! Score: %d\n", score1);
            }
            else if(distance < strlen(player2))
            {
                score2 += 2;
                printf("Player 2 wins! Score: %d\n", score2);
            }
            else 
            {
                printf("No one wins this round.\n");
            }
        }
        round++;
    }
    if(score1 > score2) printf("Player 1 is the winner!");
    else if(score2 > score1) printf("Player 2 is the winner!");
    else printf("It's a tie!");
    return 0;
}