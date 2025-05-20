//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include<stdio.h>
#include<string.h>

//function prototypes
void intro();
void game(char name[]);
int continueGame();
int gameOver();

int main(){
    char name[20];
    intro();
    printf("Enter your name: ");
    scanf("%s", name);
    game(name);
    return 0;
}

void intro(){
    printf("Welcome to 'The Dark Forest' Text-Based Adventure Game!\n");
    printf("You wake up in the middle of a dark forest and have no\n");
    printf("idea how you got there. Your goal is to find a way out of\n");
    printf("the forest and into civilization. However, be careful\n");
    printf("as there are many dangers lurking in the woods!\n");
}

void game(char name[]){
    char choice, move;
    int health = 100, gold = 0;
    printf("\n%s, your starting health is 100 and gold is 0.\n", name);
    printf("You have 3 choices:\n");
    printf("a) Look for shelter.\n");
    printf("b) Search for food and water.\n");
    printf("c) Attempt to navigate out of the forest.\n");
    printf("\nEnter your choice (a/b/c): ");
    scanf(" %c", &choice);
    switch(choice){
        case 'a':
            printf("\nYou search and find an abandoned cabin.\n");
            printf("Do you want to enter the cabin (y/n)? ");
            scanf(" %c", &move);
            if(move == 'y'){
                printf("\nYou find a bed to rest on and recover 20 health.\n");
                health += 20;
            }
            else if(move == 'n'){
                printf("\nYou decide to keep searching.\n");
            }
            else{
                printf("\nInvalid input! Ending game.\n");
                gameOver();
                return;
            }
            break;
        case 'b':
            printf("\nYou come across a stream and drink some water.\n");
            printf("While searching for food, you encounter a wild hog.\n");
            printf("Do you choose to fight it (y/n)? ");
            scanf(" %c", &move);
            if(move == 'y'){
                printf("\nYou found a sharp stick and successfully killed the hog.\n");
                printf("You gain 30 gold and recover 20 health.\n");
                gold += 30;
                health += 20;
            }
            else if(move == 'n'){
                printf("\nThe hog runs away unharmed and you continue searching.\n");
            }
            else{
                printf("\nInvalid input! Ending game.\n");
                gameOver();
                return;
            }
            break;
        case 'c':
            printf("\nYou attempt to navigate out of the forest but get lost.\n");
            printf("You come across a pack of wolves. Do you choose to fight (y/n)? ");
            scanf(" %c", &move);
            if(move == 'y'){
                printf("\nYou found a sturdy branch and successfully fend off the wolves.\n");
                printf("You gain 40 gold and recover 30 health.\n");
                gold += 40;
                health += 30;
            }
            else if(move == 'n'){
                printf("\nThe wolves attack you and you lose 40 health.\n");
                health -= 40;
            }
            else{
                printf("\nInvalid input! Ending game.\n");
                gameOver();
                return;
            }
            break;
        default:
            printf("\nInvalid input! Ending game.\n");
            gameOver();
            return;
    }
    printf("\n%s, your current health is %d and gold is %d.\n", name, health, gold);
    //ask user to continue playing or end game
    int continueGameChoice = continueGame();
    if(continueGameChoice == 0){
        printf("\nThank you for playing!\n");
        gameOver();
    }
    else if(continueGameChoice == 1){
        game(name);
    }
}

//function to ask user if they want to continue playing
int continueGame(){
    char choice;
    printf("\nDo you want to continue playing (y/n)? ");
    scanf(" %c", &choice);
    if(choice == 'y'){
        return 1;
    }
    else if(choice == 'n'){
        return 0;
    }
    else{
        printf("\nInvalid input! Ending game.\n");
        gameOver();
        return -1;
    }
}

//function to display game over message
int gameOver(){
    printf("\nGame over!\n");
    return 0;
}