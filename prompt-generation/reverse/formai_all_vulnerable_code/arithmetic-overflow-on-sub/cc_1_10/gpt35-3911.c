//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    srand(time(NULL)); 

    int players; 
    int total_probability = 0; 
    int i, j; 

    printf("Enter number of players: "); 
    scanf("%d", &players); 

    int player_array[players]; 

    for (i = 0; i < players; i++) 
    { 
        printf("Enter player %d's probability: ", i+1); 
        scanf("%d", &player_array[i]); 
        total_probability += player_array[i]; 
    } 

    if (total_probability > 100) 
    { 
        printf("Invalid probability values entered. Total probability cannot exceed 100. Exiting program.\n"); 
        return 0; 
    } 
    else if (total_probability < 100) 
    { 
        printf("Total probability is less than 100. Adjusting values to account for remaining probability.\n"); 
        player_array[players - 1] += (100 - total_probability); 
    } 

    printf("\nCalculating results...\n"); 

    for (i = 0; i < players; i++) 
    { 
        int roll = rand() % 100 + 1; 

        printf("Player %d's roll: %d\n", i+1, roll); 

        if (roll <= player_array[i]) 
        { 
            printf("Player %d's invasion probability: %d%%\n", i+1, player_array[i]); 
            printf("Player %d's planet has been invaded by aliens!\n", i+1); 

            for (j = 0; j < players; j++) 
            { 
                if (j != i) 
                { 
                    printf("Player %d has lost a battle unit to player %d.\n", j+1, i+1); 
                } 
            } 

            printf("\n"); 
        } 
        else 
        { 
            printf("Player %d's invasion probability: %d%%\n", i+1, player_array[i]); 
            printf("Player %d's planet has successfully defended against the alien invasion.\n\n", i+1); 
        } 
    } 

    return 0; 
}