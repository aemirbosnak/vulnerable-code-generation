//FormAI DATASET v1.0 Category: Poker Game ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate a random card
int generateRandomCard(){
    return rand()%13+1;
}

//function to display the card symbol based on card number
void displayCardSymbol(int card){
    switch(card){
        case 1:
            printf("A");
            break;
        case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            printf("%d", card);
            break;
        case 10:
            printf("T");
            break;
        case 11:
            printf("J");
            break;
        case 12:
            printf("Q");
            break;
        case 13:
            printf("K");
            break;
    }
}

//function to display the card type based on card number
void displayCardType(int card){
    int type = rand()%4+1;
    switch(type){
        case 1:
            printf("H");
            break;
        case 2:
            printf("S");
            break;
        case 3:
            printf("C");
            break;
        case 4:
            printf("D");
            break;
    }
}

//function to calculate the score based on the cards
int calculateScore(int card1, int card2, int card3){
    int score = 0;
    if(card1==1)
        score += 11;
    else if(card1>=10)
        score += 10;
    else
        score += card1;
    if(card2==1)
        score += 11;
    else if(card2>=10)
        score += 10;
    else
        score += card2;
    if(card3==1)
        score += 11;
    else if(card3>=10)
        score += 10;
    else
        score += card3;
    return score;
}

int main(){

    srand(time(NULL)); //to generate different set of cards each time we run the program

    int playerScore, computerScore;
    int playerCard1, playerCard2, playerCard3;
    int computerCard1, computerCard2, computerCard3;
    char playerAction;

    printf("Welcome to C Poker Game!\n");
    printf("You will be dealt 3 cards. Your goal is to get a score close to 21 without going over it.\n");
    printf("Type 'h' to hit and 's' to stand.\n");

    playerCard1 = generateRandomCard();
    playerCard2 = generateRandomCard();
    playerCard3 = generateRandomCard();
    computerCard1 = generateRandomCard();
    computerCard2 = generateRandomCard();
    computerCard3 = generateRandomCard();

    printf("\nYour cards are: ");
    displayCardSymbol(playerCard1);
    displayCardType(playerCard1);
    printf(" ");
    displayCardSymbol(playerCard2);
    displayCardType(playerCard2);
    printf(" ");
    displayCardSymbol(playerCard3);
    displayCardType(playerCard3);
    playerScore = calculateScore(playerCard1, playerCard2, playerCard3);
    printf("\nYour current score is: %d\n", playerScore);

    printf("\nComputer's cards are: ");
    printf("XX ");
    displayCardSymbol(computerCard2);
    displayCardType(computerCard2);
    printf(" XX");
    computerScore = calculateScore(computerCard1, computerCard2, computerCard3);

    while(playerAction!='s'){
        printf("\n\nType 'h' to hit or 's' to stand: ");
        scanf(" %c", &playerAction);
        if(playerAction=='h'){
            int newCard = generateRandomCard();
            printf("\nYou were dealt: ");
            displayCardSymbol(newCard);
            displayCardType(newCard);
            playerScore += newCard;
            if(playerScore>21){
                printf("\nYour current score is: %d\n", playerScore);
                printf("You lose!\n");
                return 0;
            }
            printf("\nYour current score is: %d\n", playerScore);
        }
    }

    printf("\nComputer's cards are: ");
    displayCardSymbol(computerCard1);
    displayCardType(computerCard1);
    printf(" ");
    displayCardSymbol(computerCard2);
    displayCardType(computerCard2);
    printf(" ");
    displayCardSymbol(computerCard3);
    displayCardType(computerCard3);
    printf("\nComputer's current score is: %d\n", computerScore);

    while(computerScore<=16){
        printf("\nComputer hits.");
        int newCard = generateRandomCard();
        printf("\nComputer was dealt: ");
        displayCardSymbol(newCard);
        displayCardType(newCard);
        computerScore += newCard;
        printf("\nComputer's current score is: %d\n", computerScore);
    }

    if(computerScore>21){
        printf("\nComputer loses!\n");
        return 0;
    }

    if(playerScore>computerScore){
        printf("\nYou win!\n");
    }else if(playerScore==computerScore){
        printf("\nIt's a tie!\n");
    }else{
        printf("\nYou lose!\n");
    }

    return 0;
}