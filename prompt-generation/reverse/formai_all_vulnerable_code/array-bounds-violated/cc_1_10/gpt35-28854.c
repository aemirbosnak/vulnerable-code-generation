//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 5      // Size of the bingo card
#define BINGO_SIZE 25   // Number of total spaces on the bingo card
#define MIN_NUM 1       // Minimum number that can be called
#define MAX_NUM 75      // Maximum number that can be called

// Function to initialize bingo card with random numbers
void initialize_card(int card[][SIZE])
{
    bool used_nums[BINGO_SIZE] = {false};   // Array to keep track of used numbers
    srand(time(NULL));
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            int num;
            do
            {
                num = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;   // Generate random number
            }
            while(used_nums[num]);      // Make sure number hasn't been used yet
            
            card[i][j] = num;           // Assign number to card space
            used_nums[num] = true;      // Mark number as used
        }
    }
}

// Function to print the bingo card
void print_card(int card[][SIZE])
{
    printf("--------------------\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("|");
        for(int j = 0; j < SIZE; j++)
        {
            printf(" %2d |", card[i][j]);
        }
        printf("\n--------------------\n");
    }
}

// Function to check if a bingo card has a bingo
bool check_bingo(int card[][SIZE])
{
    bool bingo = false;
    int spaces_covered = 0;
    
    // Check rows for bingo
    for(int i = 0; i < SIZE; i++)
    {
        spaces_covered = 0;
        for(int j = 0; j < SIZE; j++)
        {
            if(card[i][j] == -1)
            {
                spaces_covered++;
            }
        }
        if(spaces_covered == SIZE)
        {
            bingo = true;
            break;
        }
    }
    
    // Check columns for bingo
    if(!bingo)
    {
        for(int i = 0; i < SIZE; i++)
        {
            spaces_covered = 0;
            for(int j = 0; j < SIZE; j++)
            {
                if(card[j][i] == -1)
                {
                    spaces_covered++;
                }
            }
            if(spaces_covered == SIZE)
            {
                bingo = true;
                break;
            }
        }
    }
    
    // Check diagonals for bingo
    if(!bingo)
    {
        spaces_covered = 0;
        for(int i = 0; i < SIZE; i++)
        {
            if(card[i][i] == -1)
            {
                spaces_covered++;
            }
        }
        if(spaces_covered == SIZE)
        {
            bingo = true;
        }
    }
    
    if(!bingo)
    {
        spaces_covered = 0;
        for(int i = 0; i < SIZE; i++)
        {
            if(card[i][SIZE - 1 - i] == -1)
            {
                spaces_covered++;
            }
        }
        if(spaces_covered == SIZE)
        {
            bingo = true;
        }
    }
    
    return bingo;
}

int main()
{
    int card[SIZE][SIZE];
    initialize_card(card);
    int nums_called[MAX_NUM] = {0};
    int num_calls = 0;
    int num;
    bool bingo = false;
    
    printf("Welcome to the Bingo Simulator!\n");
    printf("Here is your card:\n");
    print_card(card);
    
    while(!bingo)
    {
        printf("Please enter the next number called (between %d and %d): ", MIN_NUM, MAX_NUM);
        scanf("%d", &num);
        
        // Check if number has already been called
        if(nums_called[num] == 1)
        {
            printf("Number already called, please enter a different number.\n");
        }
        else
        {
            nums_called[num] = 1;      // Mark number as called
            num_calls++;
            printf("Number called: %d\n", num);
            
            // Check if number is on the bingo card
            bool found_num = false;
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = 0; j < SIZE; j++)
                {
                    if(card[i][j] == num)
                    {
                        found_num = true;
                        card[i][j] = -1;        // Mark card space as covered
                        break;
                    }
                }
                if(found_num)
                {
                    break;
                }
            }
            
            if(found_num)
            {
                printf("Number %d is on your card!\n", num);
                printf("Here is your updated card:\n");
                print_card(card);
                
                bingo = check_bingo(card);  // Check if bingo has been achieved
                if(bingo)
                {
                    printf("Congratulations, you have achieved a BINGO! It only took %d calls.\n", num_calls);
                }
            }
            else
            {
                printf("Number %d is not on your card.\n", num);
            }
        }
    }
    
    return 0;
}