//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROWS 5
#define COLS 5

int main()
{
    char name[20];
    int i, j, k, n, m, call, option, bingo1, bingo2, flag;
    int nums[ROWS][COLS], call_num[76];
    srand(time(0));
    
    printf("Welcome to the post-apocalyptic Bingo Simulator\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome %s!\n", name);
    
    // Initialize nums array with -1
    for(i=0; i<ROWS; i++)
        for(j=0; j<COLS; j++)
            nums[i][j] = -1;
    
    // Generate the call_num array
    for(i=0; i<76; i++)
        call_num[i] = i;
        
    // Shuffle the call_num array
    for(i=0; i<76; i++)
    {
        j = rand() % 76;
        k = call_num[i];
        call_num[i] = call_num[j];
        call_num[j] = k;
    }
    
    // Main game loop
    bingo1 = bingo2 = 0;
    flag = 1;
    while(flag == 1)
    {
        printf("\nOptions:\n1. Print Bingo Card\n2. Call Number\n3. Quit Game\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                // Print Bingo Card
                printf("\n");
                for(i=0; i<ROWS; i++)
                {
                    for(j=0; j<COLS; j++)
                    {
                        if(nums[i][j] == -1)
                            printf("__ ");
                        else
                            printf("%2d ", nums[i][j]); 
                    }
                    printf("\n");
                }
                break;
                
            case 2:
                // Call Number
                if(call_num[call] > -1)
                {
                    printf("\nCalling Number: %d\n", call_num[call]);
                    for(i=0; i<ROWS; i++)
                    {
                        for(j=0; j<COLS; j++)
                        {
                            if(nums[i][j] == call_num[call])
                            {
                                nums[i][j] = -2;
                                break;
                            }
                        }
                        if(j<COLS)
                            break;
                    }
                    call++;
                }
                else
                    printf("\nAll numbers called!\n");
                break;
                
            case 3:
                // Quit Game
                flag = 0;
                break;
                
            default:
                printf("\nInvalid Option!\n");
        }
        
        // Check if Bingo
        for(i=0; i<ROWS; i++)
        {
            for(j=0; j<COLS; j++)
            {
                if(nums[i][j] != -2)
                    break;
            }
            if(j == COLS)
            {
                printf("\n%s BINGO!\n", name);
                bingo1 = 1;
            }
        }
        
        for(i=0; i<COLS; i++)
        {
            for(j=0; j<ROWS; j++)
            {
                if(nums[j][i] != -2)
                    break;
            }
            if(j == ROWS)
            {
                printf("\n%s BINGO!\n", name);
                bingo2 = 1;
            }
        }
        
        if(bingo1 == 1 && bingo2 == 1)
        {
            printf("\n%s WINS!\n", name);
            flag = 0;
        }
    }
    
    printf("\nThanks for playing the post-apocalyptic Bingo Simulator!\n");
    return 0;
}