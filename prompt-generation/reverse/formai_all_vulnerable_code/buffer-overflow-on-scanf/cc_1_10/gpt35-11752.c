//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random temperature
float getTemperature(){
    float temp;
    temp = (float)rand()/(float)(RAND_MAX/120);
    return temp;
}

int main(){
    srand(time(0)); //seed random generator with current time

    float temperature[5]; //temperature array to store temperature of 5 sensors
    int i, j;
    char player[5][20] = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5"}; //array to store player names
    int scores[5] = {0}; //array to store scores of players
    int highestScoreIndex = -1; //index of player with the highest score
    float highestTemperature = 0.0; //highest temperature among all sensors

    //loop to take temperature of all sensors and find highest temperature
    for(i=0; i<5; i++){
        temperature[i] = getTemperature();
        if(temperature[i] > highestTemperature){
            highestTemperature = temperature[i];
        }
    }

    printf("\nTemperature of the sensors\n");
    printf("----------------------------\n");
    for(i=0; i<5; i++){
        printf("Sensor %d: %.2f\n", i+1, temperature[i]);
    }

    //loop to ask players to guess which sensor has the highest temperature
    printf("\nGuess the sensor with highest temperature\n");
    printf("---------------------------------------\n");
    for(i=0; i<5; i++){
        printf("%s: ", player[i]);
        scanf("%d", &j);
        if(j<1 || j>5){ //check if input is valid
            printf("Invalid input! Try again.\n");
            i--;
            continue;
        }
        //check if guess is correct and increase score of player accordingly
        if(temperature[j-1] == highestTemperature){
            printf("Correct!\n");
            scores[i]++;
        } else {
            printf("Incorrect!\n");
        }
    }

    //loop to find player with highest score
    for(i=0; i<5; i++){
        if(scores[i] > highestScoreIndex){
            highestScoreIndex = i;
        }
    }

    printf("\nScores\n");
    printf("------\n");
    for(i=0; i<5; i++){
        printf("%s: %d\n", player[i], scores[i]);
    }

    printf("\n%s wins!\n", player[highestScoreIndex]);
    return 0;
}