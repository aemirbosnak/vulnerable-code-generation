//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 20
#define COLS 80
#define BRICK_ROWS 5
#define BRICK_COLS 7

int kbhit(void);
void set_mode(void);

int main()
{
    int x = COLS/2, y = ROWS-1, dx = 1, dy = -1;
    int bricks[BRICK_ROWS][BRICK_COLS];
    int i, j, k, c, input;
    
    set_mode();
    
    for(i=0;i<BRICK_ROWS;i++)
        for(j=0;j<BRICK_COLS;j++)
            bricks[i][j] = 1;
            
    while(1)
    {
        system("clear");
        
        for(i=0;i<ROWS;i++)
        {
            for(j=0;j<COLS;j++)
            {
                if(i == y && j == x)
                    printf("O");
                else if(i == ROWS-1 || bricks[i/(ROWS/BRICK_ROWS)][j/(COLS/BRICK_COLS)] == 0)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
        
        if(kbhit())
        {
            input = getchar();
            
            if(input == 'a')
                dx = -1;
            else if(input == 'd')
                dx = 1;
        }
        
        y += dy;
        x += dx;
        
        if(y < 0)
            dy = 1;
        else if(y == ROWS-1 && x >= x/(COLS/BRICK_COLS)*(COLS/BRICK_COLS) && x <= x/(COLS/BRICK_COLS)*(COLS/BRICK_COLS)+BRICK_COLS-1)
            dy = -1;
        else if(x < 0 || x >= COLS)
        {
            printf("GAME OVER\n");
            exit(1);
        }
        
        for(i=0;i<BRICK_ROWS;i++)
        {
            for(j=0;j<BRICK_COLS;j++)
            {
                if(bricks[i][j] == 1 && x >= j*(COLS/BRICK_COLS) && x <= j*(COLS/BRICK_COLS) + COLS/BRICK_COLS -1 && y >= i*(ROWS/BRICK_ROWS) && y <= i*(ROWS/BRICK_ROWS) + ROWS/BRICK_ROWS-1)
                {
                    bricks[i][j] = 0;
                    dy = 1;
                }
            }
        }
        
        for(i=0;i<BRICK_ROWS;i++)
        {
            for(j=0;j<BRICK_COLS;j++)
            {
                if(bricks[i][j] == 1)
                    break;
            }
            
            if(j != BRICK_COLS)
                break;
        }
        
        if(i == BRICK_ROWS)
        {
            printf("YOU WIN!\n");
            exit(0);
        }
        
        usleep(100000);
    }
    
    return 0;
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}

void set_mode(void)
{
    struct termios ttystate;
    
    tcgetattr(STDIN_FILENO, &ttystate);
    ttystate.c_lflag &= ~(ICANON | ECHO);
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}