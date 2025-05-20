//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to display game map
void displayMap(char map[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char map[3][3] = {{'A', 'B', 'C'},
                      {'D', 'E', 'F'},
                      {'G', 'H', 'I'}};
    
    int row, col;
    char option;
    
    printf("Welcome to the Shape Shifting Adventure Game!\n\n");
    
    while(1)
    {
        printf("You are currently in the shape of %c.\n", map[1][1]);
        displayMap(map);
        printf("Choose your next move:\n");
        printf("Up (U), Down (D), Left (L), Right (R), or Quit (Q): ");
        scanf(" %c", &option);
        
        switch(option)
        {
            case 'U':
                row = 0;
                col = 1;
                break;
            case 'D':
                row = 2;
                col = 1;
                break;
            case 'L':
                row = 1;
                col = 0;
                break;
            case 'R':
                row = 1;
                col = 2;
                break;
            case 'Q':
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n\n");
                continue;
        }
        
        char temp = map[row][col];
        map[row][col] = map[1][1];
        map[1][1] = temp;
        
        // Check if player has won
        if(map[0][0] == 'X' && map[0][1] == 'X' && map[0][2] == 'X'
           && map[1][0] == 'X' && map[1][1] == 'X' && map[1][2] == 'X'
           && map[2][0] == 'X' && map[2][1] == 'X' && map[2][2] == 'X')
        {
            printf("Congratulations! You've won the game!\n");
            exit(0);
        }
    }
    return 0;
}