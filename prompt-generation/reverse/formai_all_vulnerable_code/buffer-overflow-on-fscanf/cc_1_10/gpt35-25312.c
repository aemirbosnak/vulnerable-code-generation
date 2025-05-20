//FormAI DATASET v1.0 Category: File handling ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20

void createFile(char[20]);
void addPointsToFile(char[20], int);
void displayScores(char[20]);
int rollDice(void);

int main(void){
    char filename[MAX_NAME_LENGTH];
    int numPlayers, option;

    printf("Enter the name of the file you want to create: ");
    scanf("%s", filename);

    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    createFile(filename);

    do{
        printf("\n1. Add points\n2. Display scores\n3. Quit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                for(int i=1;i<=numPlayers;i++){
                    int points = rollDice();
                    printf("Enter points for player %d: %d\n", i, points);
                    addPointsToFile(filename, points);
                }
                break;
            case 2:
                displayScores(filename);
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option. Please try again!\n");
        }
    }while(option!=3);
    
    return 0;
}

void createFile(char fileName[20]){
    FILE *fptr = fopen(fileName, "w");
    if(fptr == NULL){
        printf("Unable to create file\n");
        exit(1);
    }
    fclose(fptr);
}

void addPointsToFile(char fileName[20], int points){
    FILE *fptr = fopen(fileName, "a");
    if(fptr == NULL){
        printf("Unable to open file\n");
        exit(1);
    }
    fprintf(fptr, "%d\n", points);
    fclose(fptr);
}

void displayScores(char fileName[20]){
    FILE *fptr = fopen(fileName, "r");
    if(fptr == NULL){
        printf("Unable to open file\n");
        exit(1);
    }
    int score;
    int totalScore[MAX_PLAYERS] = {0};
    int playerNumber = 1;
    printf("\nScores:\n");
    while(fscanf(fptr, "%d", &score)!=EOF){
        printf("Player %d: %d\n",playerNumber,score);
        totalScore[playerNumber-1] += score;
        playerNumber++;
        if(playerNumber > MAX_PLAYERS) playerNumber = 1;
    }
    printf("\nTotal Scores:\n");
    for(int i=0; i<MAX_PLAYERS; i++){
        printf("Player %d: %d\n", i+1, totalScore[i]);
    }
    fclose(fptr);
}

int rollDice(){
    srand(time(NULL));
    int dice = rand()%6 + 1;
    return dice;
}