//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random lowercase letter
char getRandomLower(){
    return rand() % 26 + 'a';
}

//Function to generate random uppercase letter
char getRandomUpper(){
    return rand() % 26 + 'A';
}

//Function to generate random digit
char getRandomDigit(){
    return rand() % 10 + '0';
}

//Function to generate random special character
char getRandomSpecialChar(){
    char specialChars[] = "!@#$%^&*()_+";
    return specialChars[rand() % 11];
}

//Function to generate secure password
char* generatePassword(int length){
    srand(time(NULL)); //Set the seed for random number generator
    char* password = (char*)malloc((length+1)*sizeof(char)); //Allocate memory for password
    int i;
    for(i=0;i<length;i++){
        int choice = rand() % 4; //Choose a random character type
        switch(choice){
            case 0:
                password[i] = getRandomLower();
                break;
            case 1:
                password[i] = getRandomUpper();
                break;
            case 2:
                password[i] = getRandomDigit();
                break;
            case 3:
                password[i] = getRandomSpecialChar();
                break;
        }
    }
    password[length] = '\0'; //Add null character to end of password
    return password;
}

int main(){
    int n, i;
    printf("Enter the number of players: ");
    scanf("%d", &n);
    char** passwords = (char**)malloc(n*sizeof(char*)); //Allocate memory for passwords of all players
    int* scores = (int*)calloc(n,sizeof(int)); //Initialize scores of all players to 0
    for(i=0;i<n;i++){
        printf("Player %d: ", i+1);
        int length = rand() % 6 + 10; //Choose a random password length between 10 and 15
        passwords[i] = generatePassword(length);
        printf("Your password is: %s\n", passwords[i]);
    }
    printf("Password Game Begins!\n");
    for(i=0;i<3;i++){ //Play three rounds of game
        printf("Round %d:\n", i+1);
        int player1, player2;
        do{ //Choose two random players and make sure they are not same
            player1 = rand() % n;
            player2 = rand() % n;
        }while(player1 == player2);
        printf("Player %d's password: %s\n", player1+1, passwords[player1]);
        printf("Player %d's password: %s\n", player2+1, passwords[player2]);
        getchar(); //Clear input buffer
        char guess1[20], guess2[20];
        printf("Player %d's guess: ", player1+1);
        fgets(guess1, 20, stdin); //Get guess from player 1
        printf("Player %d's guess: ", player2+1);
        fgets(guess2, 20, stdin); //Get guess from player 2
        if(strcmp(guess1,passwords[player1]) == 0){ //If player 1's guess is correct
            printf("Player %d guessed correctly!\n", player1+1);
            scores[player1] += 2;
        }
        else{ //If player 1's guess is incorrect
            printf("Player %d's guess is incorrect. The password is: %s\n", player1+1, passwords[player1]);
            scores[player2] += 1;
        }
        if(strcmp(guess2,passwords[player2]) == 0){ //If player 2's guess is correct
            printf("Player %d guessed correctly!\n", player2+1);
            scores[player2] += 2;
        }
        else{ //If player 2's guess is incorrect
            printf("Player %d's guess is incorrect. The password is: %s\n", player2+1, passwords[player2]);
            scores[player1] += 1;
        }
    }
    printf("Final Scores:\n");
    for(i=0;i<n;i++){
        printf("Player %d: %d\n", i+1, scores[i]);
    }
    return 0;
}