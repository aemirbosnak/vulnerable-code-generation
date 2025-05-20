//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_P 1000 /*Maximum number of planets on the database*/

int main(void) 
{
    int pcount; /*Number of planets on the database*/
    char pname[MAX_P][32]; /*Name of the planets on the database*/
    double pcoords[MAX_P][3]; /*Coordinates of the planets on the database*/
    double invaders[3]; /*Coordinates of the alien invaders*/
    int i, j;
    int prob = 0; /*Probability of alien invasion*/
    srand(time(NULL)); /*Initialize the random number generator*/
    
    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("Please enter the number of planets on the database: ");
    scanf("%d", &pcount);
    /*Validate the input*/
    while(getchar()!='\n');
    
    if(pcount > MAX_P) {
        printf("Error: Maximum number of planets exceeded.\n");
        return 1;
    }
    /*Fill the database*/
    for(i = 0; i < pcount; ++i) {
        printf("Please enter planet #%d name: ", i+1);
        fgets(pname[i], 32, stdin);
        pname[i][strlen(pname[i])-1] = '\0';
        /*Generate random coordinates*/
        pcoords[i][0] = (double)rand()/RAND_MAX*100.0;
        pcoords[i][1] = (double)rand()/RAND_MAX*100.0;
        pcoords[i][2] = (double)rand()/RAND_MAX*100.0;
    }
    /*Generate random coordinates for the alien invaders*/
    invaders[0] = (double)rand()/RAND_MAX*100.0;
    invaders[1] = (double)rand()/RAND_MAX*100.0;
    invaders[2] = (double)rand()/RAND_MAX*100.0;
    /*Calculate the probability of invasion*/
    for(i = 0; i < pcount; ++i) {
        double dist = 0.0;
        for(j = 0; j < 3; ++j) {
            dist += (pcoords[i][j] - invaders[j])*(pcoords[i][j] - invaders[j]);
        }
        dist = sqrt(dist);
        if(dist < 30.0) {
            prob += (int)(100.0*(30.0-dist)/30.0);
        }
    }    
    prob = prob/pcount;
    /*Print the results*/
    printf("Probability of alien invasion: %d%%\n", prob);
    return 0;
}