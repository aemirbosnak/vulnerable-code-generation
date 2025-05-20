//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 5
#define COL 5

// Function to display the menu
void displayMenu() {
    printf("Welcome to Bingo Simulator\n");
    printf("1. Play Game\n");
    printf("2. Bingo Rule\n");
    printf("3. Exit\n");
}

// Function to display the rules of bingo
void displayRule() {
    printf("Bingo is a game of chance in which each player matches numbers printed in different arrangements on 5x5 cards with the numbers the game host draws at random.\n");
    printf("The first player to complete a row, column, diagonal, or all four corners of the card and shout 'Bingo!' wins.\n");
    printf("Each card has 25 numbers on it arranged in a 5 by 5 grid. The numbers in the B column are between 1 and 15, in the I column 16 to 30, in the N column (containing four numbers and the free space) 31 to 45, in the G column 46 to 60, and in the O column 61 to 75.\n");
}

// Function to generate the random number from 1 to 75
int generateRandomNumber() {
    int num = (rand() % 75) + 1;
    return num;
}

// Function to check if the number is already present in the given array
int checkNumber(int num, int* arr, int len) {
    for(int i=0; i<len; i++) {
        if(num == *(arr+i)) return 1;
    }
    return 0;
}

// Function to fill the bingo card with random numbers
void fillCard(int arr[][COL]) {
    int num;
    int randomNumbers[25] = {0};
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            do {
                num = generateRandomNumber();
            } while(checkNumber(num, randomNumbers, 25));
            randomNumbers[i*COL+j] = num;
            arr[i][j] = num;
        }
    }
}

// Function to display the bingo card
void displayCard(int arr[][COL]) {
    printf("\n");
    printf("B\tI\tN\tG\tO\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the card is completely marked
int checkComplete(int arr[][COL]) {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(arr[i][j] != -1) return 0;
        }
    }
    return 1;
}

// Function to check if any row of the card is marked
int checkRow(int arr[][COL]) {
    for(int i=0; i<ROW; i++) {
        int marked = 1;
        for(int j=0; j<COL; j++) {
            if(arr[i][j] != -1) {
                marked = 0;
                break;
            }
        }
        if(marked) return 1;
    }
    return 0;
}

// Function to check if any column of the card is marked
int checkColumn(int arr[][COL]) {
    for(int i=0; i<COL; i++) {
        int marked = 1;
        for(int j=0; j<ROW; j++) {
            if(arr[j][i] != -1) {
                marked = 0;
                break;
            }
        }
        if(marked) return 1;
    }
    return 0;
}

// Function to check if any diagonal of the card is marked
int checkDiagonal(int arr[][COL]) {
    int marked = 1;
    for(int i=0; i<ROW; i++) {
        if(arr[i][i] != -1) {
            marked = 0;
            break;
        }
    }
    if(marked) return 1;
    marked = 1;
    for(int i=0; i<ROW; i++) {
        if(arr[i][(ROW-1)-i] != -1) {
            marked = 0;
            break;
        }
    }
    if(marked) return 1;
    return 0;
}

// Function to play the bingo game
void playGame() {
    int card[ROW][COL];
    int num, count=0;
    char choice;
    fillCard(card);
    displayCard(card);
    do {
        printf("Press any key to draw a number\n");
        scanf(" %c", &choice);
        num = generateRandomNumber();
        count++;
        printf("Number drawn is %d\n", num);
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                if(num == card[i][j]) card[i][j] = -1;
            }
        }
        displayCard(card);
        if(checkComplete(card)) {
            printf("Congratulations! You have won the game in %d turns.\n", count);
            break;
        } else if(checkRow(card) || checkColumn(card) || checkDiagonal(card)) {
            printf("BINGO!\n");
        }
    } while(1);
}

// Main function
int main() {
    srand(time(NULL));
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayRule();
                break;
            case 3:
                printf("Thank you for playing Bingo Simulator\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(1);
    return 0;
}