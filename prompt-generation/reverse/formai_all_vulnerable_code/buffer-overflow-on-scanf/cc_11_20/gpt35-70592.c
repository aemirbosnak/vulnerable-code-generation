//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    float prob, prob_aliens, prob_dropzone, prob_defenders;
    int i, j, k;
    srand(time(NULL)); //initialize random number generator

    //determine probability of alien invasion
    printf("Enter the probability of an Alien Invasion (0-1): ");
    scanf("%f", &prob_aliens);

    if((prob_aliens<=0)||(prob_aliens>=1)){
        printf("Invalid input!\n");
        return 0;
    }

    //determine probability of drop zone location being in a certain area
    printf("Enter the probability of the Alien Drop Zone being in a Northern area (0-1): ");
    scanf("%f", &prob_dropzone);

    if((prob_dropzone<=0)||(prob_dropzone>=1)){
        printf("Invalid input!\n");
        return 0;
    }

    //determine probability of defenders successfully repelling aliens
    printf("Enter the probability of Defenders successfully repelling an Alien Invasion (0-1): ");
    scanf("%f", &prob_defenders);

    if((prob_defenders<=0)||(prob_defenders>=1)){
        printf("Invalid input!\n");
        return 0;
    }

    //calculate probability of successful alien invasion
    prob = prob_aliens*prob_dropzone*prob_defenders;

    //output the estimated probability of an alien invasion
    printf("Based on the input probabilities, the estimated probability of an Alien Invasion is %.2f%%.\n\n", prob*100);

    //initialize the 3D grid of area
    int area[10][10][10];

    //populate the area with either 0 (no alien activity) or 1 (alien activity)
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            for(k=0; k<10; k++){
                if((float)rand()/RAND_MAX < prob_aliens){
                    area[i][j][k] = 1;
                }
                else{
                    area[i][j][k] = 0;
                }
            }
        }
    }

    //locate the drop zone based on the input probability
    int dropzone_x, dropzone_y, dropzone_z;
    dropzone_x = rand()%10;
    dropzone_y = rand()%10;

    if((float)rand()/RAND_MAX < prob_dropzone){
        dropzone_z = rand()%5;
    }
    else{
        dropzone_z = rand()%6+4;
    }

    //output the location of the drop zone
    printf("The Alien Drop Zone is located at (%d, %d, %d).\n", dropzone_x, dropzone_y, dropzone_z);

    //initialize variables for counting aliens and defenders
    int total_aliens = 0, total_defenders = 0;
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            for(k=0; k<10; k++){
                if(area[i][j][k] == 1){ //count total number of aliens
                    total_aliens++;
                }
                if((i+j+k)%2 == 0){ //count total number of defenders
                    total_defenders++;
                }
            }
        }
    }

    //calculate the number of defenders needed to successfully repel the invasion
    int defenders_needed = (int) (total_aliens/prob_defenders);

    //output the required number of defenders
    printf("In order to have a %.2f%% chance of successfully repelling the Alien Invasion, we would need %d defenders.\n", prob_defenders*100, defenders_needed);

    return 0;

}