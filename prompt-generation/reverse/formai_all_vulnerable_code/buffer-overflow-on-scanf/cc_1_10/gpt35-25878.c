//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to initialize the pixel art with random colors
void init_art(char art[8][8])
{
    //Seed the random number generator with time
    srand(time(NULL));
    
    //Assign random colors to each pixel
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int color = rand()%7 + 1; //Randomly generate a color between 1 and 7
            switch(color)
            {
                case 1: art[i][j] = 'R'; break; //Red
                case 2: art[i][j] = 'O'; break; //Orange
                case 3: art[i][j] = 'Y'; break; //Yellow
                case 4: art[i][j] = 'G'; break; //Green
                case 5: art[i][j] = 'B'; break; //Blue
                case 6: art[i][j] = 'P'; break; //Purple
                case 7: art[i][j] = 'W'; break; //White
            }
        }
    }
}

//Function to display the pixel art
void display_art(char art[8][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            printf("%c ", art[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char art[8][8];
    
    //Initialize the pixel art
    init_art(art);
    
    //Display the pixel art
    printf("Initial Pixel Art:\n");
    display_art(art);
    
    //Let the user modify the pixel art
    char choice;
    int row, col;
    do
    {
        printf("Do you want to modify the Pixel Art? (Y/N) ");
        scanf(" %c", &choice);
        if(choice == 'Y' || choice == 'y')
        {
            printf("Enter row and column numbers (0-7) of the pixel you want to modify: ");
            scanf("%d %d", &row, &col);
            printf("Enter a new color (R/O/Y/G/B/P/W) for the pixel: ");
            scanf(" %c", &art[row][col]);
            printf("Modified Pixel Art:\n");
            display_art(art);
        }
    }while(choice == 'Y' || choice == 'y');
    
    return 0;
}