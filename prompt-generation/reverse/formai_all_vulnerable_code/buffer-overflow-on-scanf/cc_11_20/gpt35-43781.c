//FormAI DATASET v1.0 Category: Poker Game ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random card number
int generate_card(){
    return rand() % 13 + 2; //cards numbered from 2 to Ace (14)
}

int main(){
    srand(time(NULL)); //seed for random number generator
    int player[5]; //array to store player cards
    int dealer[5]; //array to store dealer cards
    int i, j; //iteration variables
    
    //initialize player and dealer card arrays
    for(i=0; i<5; i++){
        player[i] = 0;
        dealer[i] = 0;
    }
    
    //deal cards to player and dealer
    printf("Dealing cards...\n");
    for(i=0; i<2; i++){ //player and dealer get 2 cards each
        player[i] = generate_card();
        dealer[i] = generate_card();
    }
    printf("Player's cards: ");
    for(i=0; i<2; i++){
        printf("%d ", player[i]);
    }
    printf("\nDealer's cards: %d *\n", dealer[0]); //only show dealer's first card
    
    //player's turn
    char choice = 'h';
    while(choice == 'h'){
        printf("Enter 'h' to hit or 's' to stand: ");
        scanf(" %c", &choice);
        if(choice == 'h'){
            for(j=0; j<5; j++){
                if(player[j] == 0){ //find first empty slot in player's card array
                    player[j] = generate_card();
                    printf("Player's cards: ");
                    for(i=0; i<j+1; i++){
                        printf("%d ", player[i]);
                    }
                    printf("\nDealer's cards: %d *\n", dealer[0]);
                    break;
                }
            }
        }
    }
    
    //dealer's turn
    printf("\nDealer's turn...\n");
    while(1){
        int sum = 0;
        for(i=0; i<5; i++){
            if(dealer[i] > 1 && dealer[i] < 11){ //cards numbered 2 to 10
                sum += dealer[i];
            }
            else if(dealer[i] >= 11 && dealer[i] <= 13){ //face cards
                sum += 10;
            }
            else if(dealer[i] == 14){ //Ace
                sum += 11; //assume Ace is worth 11 points
            }
            else{
                break; //empty card slot
            }
        }
        if(sum < 17){ //dealer has to hit if hand value is less than 17
            for(j=0; j<5; j++){
                if(dealer[j] == 0){ //find first empty slot in dealer's card array
                    dealer[j] = generate_card();
                    break;
                }
            }
        }
        else{ //dealer stands
            break;
        }
    }
    
    //calculate winner
    int player_sum = 0;
    int dealer_sum = 0;
    for(i=0; i<5; i++){
        if(player[i] > 1 && player[i] < 11){ //cards numbered 2 to 10
            player_sum += player[i];
        }
        else if(player[i] >= 11 && player[i] <= 13){ //face cards
            player_sum += 10;
        }
        else if(player[i] == 14){ //Ace
            player_sum += 11; //assume Ace is worth 11 points
        }
        else{
            break; //empty card slot
        }
    }
    for(i=0; i<5; i++){
        if(dealer[i] > 1 && dealer[i] < 11){ //cards numbered 2 to 10
            dealer_sum += dealer[i];
        }
        else if(dealer[i] >= 11 && dealer[i] <= 13){ //face cards
            dealer_sum += 10;
        }
        else if(dealer[i] == 14){ //Ace
            dealer_sum += 11; //assume Ace is worth 11 points
        }
        else{
            break; //empty card slot
        }
    }
    printf("\nPlayer's hand value: %d\n", player_sum);
    printf("Dealer's hand value: %d\n\n", dealer_sum);
    
    if(player_sum > 21){ //check for player bust
        printf("Player busts! Dealer wins!\n");
    }
    else if(dealer_sum > 21){ //check for dealer bust
        printf("Dealer busts! Player wins!\n");
    }
    else if(player_sum > dealer_sum){ //player has higher hand value
        printf("Player wins!\n");
    }
    else if(player_sum < dealer_sum){ //dealer has higher hand value
        printf("Dealer wins!\n");
    }
    else{ //tie
        printf("It's a tie!\n");
    }
    
    return 0;
}