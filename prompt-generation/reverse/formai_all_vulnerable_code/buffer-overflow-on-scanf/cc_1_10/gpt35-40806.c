//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: recursive
#include<stdio.h>
#include<string.h>

void game();
void displayMenu();
void displayTable(int i, int j);

int main(){
    displayMenu();
    return 0;
}

void displayMenu(){
    int choice=0;
    printf("\t PERIODIC TABLE QUIZ GAME\n\n");
    printf("1. Start game\n");
    printf("2. Instructions\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            game();
            break;
        case 2:
            printf("\nInstructions: ");
            printf("Guess the symbols of the given elements. Enter your guess in all capital letters.\n");
            printf("You have 3 chances to guess the element correctly.\n\n");
            displayMenu();
            break;
        case 3:
            printf("Thanks for playing!\n");
            break;
        default:
            printf("Invalid input! Try again.\n");
            displayMenu();
            break;
    }
}

void game(){
    char table[9][18] = {"H","He","Li","Be","B","C","N","O","F",
                        "Ne","Na","Mg","Al","Si","P","S","Cl","Ar"};
    char guess[18];
    int row=0, col=0, chances=3;
    
    printf("\nGuess the symbol of the element at row 1 and column 1\n");
    displayTable(row, col);
    printf("Enter guess: ");
    scanf("%s",guess);
    if(strcmp(guess, table[0])==0){
        printf("Correct!\n");
        row=1;
        col=1;
        printf("\nGuess the symbol of the element at row 2 and column 4\n");
        displayTable(row, col);
        printf("Enter guess: ");
        scanf("%s",guess);
        if(strcmp(guess, table[13])==0){
            printf("Correct!\n");
            printf("\nYou won the game!\n");
            displayMenu();
        }
        else{
            chances--;
            printf("Incorrect! You have %d chances left.\n", chances);
            if(chances>0)
                game();
            else{
                printf("Game over! You lost.\n");
                displayMenu();
            }
        }
    }
    else{
        chances--;
        printf("Incorrect! You have %d chances left.\n", chances);
        if(chances>0)
            game();
        else{
            printf("Game over! You lost.\n");
            displayMenu();
        }
    }
}

void displayTable(int i, int j){
    char table[9][18] = {"H","He","Li","Be","B","C","N","O","F",
                        "Ne","Na","Mg","Al","Si","P","S","Cl","Ar"};
    int x, y;
    for(x=0; x<3; x++){
        for(y=0; y<6; y++){
            if(x==i && y==j)
                printf("[ %s ]",table[(x*6)+y]);
            else
                printf("   %s   ",table[(x*6)+y]);
        }
        printf("\n\n");
    }
}