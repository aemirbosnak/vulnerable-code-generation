//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int numPlanets = 4;
    int numAsteroids = 10;
    int choice;
    int i, j;
    int planetVisited[4] = {0,0,0,0};
    int totalAsteroids = 0;
    int totalCredits = 0;
    int credits[4] = {1500,2000,2500,3000};
    srand(time(0));

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of the spaceship Zephyr.\n");
    printf("Your mission is to collect resources from the planets and asteroids\n\n");

    while(1){
        printf("Choose from the following options:\n");
        printf("1. Visit a planet\n");
        printf("2. Search an asteroid belt\n");
        printf("3. Check status\n");
        printf("4. Quit game\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Select a planet to visit:\n");
                printf("1. Aldebaran\n");
                printf("2. Betelgeuse\n");
                printf("3. Deneb\n");
                printf("4. Rigel\n");
                scanf("%d",&choice);
                if(choice>0 && choice<=numPlanets){
                    if(planetVisited[choice-1] == 0){
                        printf("Travelling to planet %d...\n",choice);
                        int resource = credits[choice-1]*rand()%5 + credits[choice-1]*3;
                        printf("Collected %d credits from planet %d\n",resource,choice);
                        planetVisited[choice-1] = 1;
                        totalCredits += resource;
                    }
                    else{
                        printf("You have already visited planet %d\n",choice);
                    }
                }
                else{
                    printf("Invalid choice\n");
                }
                break;

            case 2:
                printf("Searching asteroid belt...\n");
                int resources = 0;
                for(i=0;i<numAsteroids;i++){
                    int resource = rand()%2500+500;
                    resources += resource;
                    totalAsteroids++;
                }
                printf("Found %d asteroids and collected %d credits\n",numAsteroids,resources);
                totalCredits += resources;
                break;

            case 3:
                printf("Zephyr Status:\n");
                printf("%d total asteroids collected\n",totalAsteroids);
                printf("%d total credits collected\n",totalCredits);
                for(i=0;i<numPlanets;i++){
                    if(planetVisited[i] == 1){
                        printf("Visited planet %d\n",i+1);
                    }
                    else{
                        printf("Haven't visited planet %d\n",i+1);
                    }
                }
                break;

            case 4:
                printf("Thanks for playing Procedural Space Adventure!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}