//FormAI DATASET v1.0 Category: Funny ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    printf("Welcome to the super sophisticated C program!\n\n");
    printf("Please enter the number of times you want to play the game: ");
    
    int num_plays;
    scanf("%d", &num_plays);
    printf("\n");
    
    srand(time(0));
    int player_score = 0, cpu_score = 0;
    
    for(int i = 0; i < num_plays; i++){
        int player_choice, cpu_choice;
        
        printf("Round %d:\n", i+1);
        printf("Enter your move: (rock=0, paper=1, scissors=2): ");
        scanf("%d", &player_choice);
        
        while(player_choice < 0 || player_choice > 2){
            printf("Invalid move. Enter again: ");
            scanf("%d", &player_choice);
        }
        
        cpu_choice = rand()%3;
        
        if(player_choice == cpu_choice){
            printf("It's a tie!\n\n");
            continue;
        }
        
        if((player_choice == 0 && cpu_choice == 2) || 
           (player_choice == 1 && cpu_choice == 0) || 
           (player_choice == 2 && cpu_choice == 1)){
            printf("You win!\n\n");
            player_score++;
        }
        else{
            printf("You lose!\n\n");
            cpu_score++;
        }
    }
    
    printf("Thanks for playing. Here's the final score:\n");
    printf("Player: %d\tCPU: %d\n", player_score, cpu_score);
    
    if(player_score > cpu_score){
        printf("Congratulations! You have won the game!\n");
    }
    else if(cpu_score > player_score){
        printf("Sorry, you have lost the game :(\n");
    }
    else{
        printf("It's a tie game!\n");
    }
    
    return 0;
}