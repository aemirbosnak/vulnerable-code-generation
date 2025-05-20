//FormAI DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4 //Size of the card matrix

typedef struct Card{ //Card structure for storing each card's data
    int data;
    int matched;
    int flipped;
}Card;

void generateCards(Card cards[SIZE][SIZE]){ //Function for generating card data
    int count = 0;
    for(int i=0 ; i<SIZE ; i++){
        for(int j=0 ; j<SIZE ; j++){
            cards[i][j].data = count;
            cards[i][j].matched = 0;
            cards[i][j].flipped = 0;
            count++;
        }
    }
}

void shuffleCards(Card cards[SIZE][SIZE]){ //Function for shuffling card data
    srand(time(0));
    for(int i=0 ; i<SIZE ; i++){
        for(int j=0 ; j<SIZE ; j++){
            int rand_i = rand() % SIZE;
            int rand_j = rand() % SIZE;
            
            //Swap card data
            int temp = cards[i][j].data;
            cards[i][j].data = cards[rand_i][rand_j].data;
            cards[rand_i][rand_j].data = temp;
        }
    }
}

void printCards(Card cards[SIZE][SIZE], int row, int col){ //Function for printing card matrix
    for(int i=0 ; i<SIZE ; i++){
        for(int j=0 ; j<SIZE ; j++){
            if(i == row && j == col){ //Skip printing flipped card
                printf("[ ] ");
            }
            else if(cards[i][j].matched){ //If card is already matched, print 'X'
                printf("[X] ");
            }
            else{ //Print card data
                printf("[%d] ", cards[i][j].data);
            }
        }
        printf("\n");
    }
}

int main(){
    Card cards[SIZE][SIZE];
    int attempts = 0;
    int prev_row = -1, prev_col = -1;
    generateCards(cards);
    shuffleCards(cards);
    
    while(1){ //Game loop
        printf("\n---ATTEMPT %d---\n", attempts+1);
        printCards(cards, prev_row, prev_col);
        int row1, col1, row2, col2;
        printf("Enter Card 1's Row : ");
        scanf("%d", &row1);
        printf("Enter Card 1's Column : ");
        scanf("%d", &col1);
        printf("Enter Card 2's Row : ");
        scanf("%d", &row2);
        printf("Enter Card 2's Column : ");
        scanf("%d", &col2);
        
        if(cards[row1][col1].matched || cards[row2][col2].matched){ //If any card is already matched, skip attempt
            printf("Both cards can't be already matched.\n");
            continue;
        }
        else if(cards[row1][col1].flipped || cards[row2][col2].flipped){ //If any card is already flipped, skip attempt
            printf("Both cards can't be already flipped.\n");
            continue;
        }
        else if(row1 == row2 && col1 == col2){ //If both cards are same, skip attempt
            printf("Both cards can't be same.\n");
            continue;
        }
        else if(cards[row1][col1].data != cards[row2][col2].data){ //If both cards don't match, flip back
            cards[row1][col1].flipped = 0;
            cards[row2][col2].flipped = 0;
            printf("Wrong match. Flip back.\n");
        }
        else{ //If both cards match, mark as matched
            cards[row1][col1].matched = 1;
            cards[row2][col2].matched = 1;
            printf("Correct match. Marked as matched.\n");
        }
        
        prev_row = row2;
        prev_col = col2;
        attempts++;
        
        int matched_count = 0;
        for(int i=0 ; i<SIZE ; i++){
            for(int j=0 ; j<SIZE ; j++){
                if(cards[i][j].matched){
                    matched_count++;
                }
            }
        }
        if(matched_count == SIZE*SIZE){ //If all cards are matched, game over
            printf("\n---GAME OVER---\n");
            printf("You completed the game in %d attempts.\n", attempts);
            break;
        }
    }
    
    return 0;
}