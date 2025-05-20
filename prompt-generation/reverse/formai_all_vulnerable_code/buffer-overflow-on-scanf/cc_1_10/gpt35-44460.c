//FormAI DATASET v1.0 Category: Poker Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate a random number between 1 and 13
int generate_card(){
    int num = (rand() % 13) + 1;
    return num;
}

//Function to assign a suit to the card based on the input parameter
char* assign_suit(int suit){
    char* s;
    if(suit == 1){
        s = "Hearts";
    }
    else if(suit == 2){
        s = "Diamonds";
    }
    else if(suit == 3){
        s = "Clubs";
    }
    else{
        s = "Spades";
    }
    return s;
}

//Function to assign a face value to the card based on the input parameter
char* assign_face(int face){
    char* f;
    if(face == 1){
        f = "Ace";
    }
    else if(face == 11){
        f = "Jack";
    }
    else if(face == 12){
        f = "Queen";
    }
    else if(face == 13){
        f = "King";
    }
    else{
        char buffer[2];
        sprintf(buffer, "%d", face);
        f = buffer;
    }
    return f;
}

//Function to print the card
void print_card(int card){
    int face = card % 13;
    if(face == 0){
        face = 13;
    }
    int suit = (card-1) / 13 + 1;
    char* s = assign_suit(suit);
    char* f = assign_face(face);
    printf("%s of %s\n", f, s);
}

//Function to print the player's hand
void print_hand(int* hand){
    printf("\nYour hand:\n");
    for(int i=0; i<5; i++){
        print_card(hand[i]);
    }
}

//Function to evaluate the hand of the player and return the score
int evaluate_hand(int* hand){
    int score = 0;
    int faces[13] = {0};
    int suits[4] = {0};
    int straight = 0;
    int flush = 0;
    int pairs = 0;
    int set = 0;
    for(int i=0; i<5; i++){
        int face = hand[i] % 13;
        if(face == 0){
            face = 13;
        }
        int suit = (hand[i]-1) / 13 + 1;
        faces[face-1]++;
        suits[suit-1]++;
    }
    for(int i=0; i<13; i++){
        if(faces[i] == 4){
            score = 7;
            set = i+1;
            break;
        }
        else if(faces[i] == 3){
            if(set != 0){
                score = 6;
                break;
            }
            else{
                score = 3;
                set = i+1;
            }
        }
        else if(faces[i] == 2){
            if(set != 0){
                score = 6;
                break;
            }
            else if(pairs != 0){
                score = 2;
            }
            else{
                pairs = i+1;
            }
        }
        if(i<=8 && faces[i] == 1 && faces[i+1] == 1 && faces[i+2] == 1 && faces[i+3] == 1 && faces[i+4] == 1){
            straight = 1;
            break;
        }
    }
    for(int i=0; i<4; i++){
        if(suits[i] == 5){
            flush = 1;
            break;
        }
    }
    if(straight == 1 && flush == 1){
        score = 8;
    }
    else if(set != 0 && flush == 1){
        score = 5;
    }
    else if(straight == 1){
        score = 4;
    }
    else if(flush == 1){
        score = 3;
    }
    else if(set != 0){
        score = 1;
    }
    else if(pairs != 0){
        score = 0;
    }
    return score;
}

int main(){
    srand(time(0));
    int chips = 50;
    printf("Welcome to C Poker Game!\n");
    while(chips > 0){
        printf("\nYou have %d chips.\n", chips);
        printf("How many chips would you like to bet? (minimum 1, maximum 10)\n");
        int bet;
        scanf("%d", &bet);
        if(bet < 1 || bet > 10){
            printf("Invalid bet! Please place a valid bet.\n");
            continue;
        }
        chips -= bet;
        int hand[5];
        for(int i=0; i<5; i++){
            hand[i] = generate_card();
        }
        print_hand(hand);
        printf("\nWhich cards do you want to hold? (1-5)\n");
        int held[5] = {0};
        for(int i=0; i<5; i++){
            int h;
            scanf("%d", &h);
            if(h>=1 && h<=5){
                held[h-1] = 1;
            }
        }
        for(int i=0; i<5; i++){
            if(held[i] == 0){
                hand[i] = generate_card();
            }
        }
        print_hand(hand);
        int score = evaluate_hand(hand);
        if(score == 0){
            printf("\nYou have a pair!\n");
            chips += bet*2;
        }
        else if(score == 1){
            printf("\nYou have two pairs!\n");
            chips += bet*3;
        }
        else if(score == 2){
            printf("\nYou have a three of a kind!\n");
            chips += bet*5;
        }
        else if(score == 3){
            printf("\nYou have a flush!\n");
            chips += bet*6;
        }
        else if(score == 4){
            printf("\nYou have a straight!\n");
            chips += bet*8;
        }
        else if(score == 5){
            printf("\nYou have a full house!\n");
            chips += bet*9;
        }
        else if(score == 6){
            printf("\nYou have a four of a kind!\n");
            chips += bet*20;
        }
        else if(score == 7){
            printf("\nYou have a straight flush!\n");
            chips += bet*50;
        }
        else{
            printf("\nYou have a high card!\n");
        }
    }
    printf("\nYou have run out of chips! Better luck next time!\n");
    return 0;
}