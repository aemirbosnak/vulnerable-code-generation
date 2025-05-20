//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Structure for Galaxies
struct galaxy{
    int id;
    char name[20];
    int numPlanets;
    int **planets;
};

//Function for creating Galaxies
void createGalaxy(int id, char name[], int numPlanets){
    struct galaxy *galaxy = (struct galaxy*)malloc(sizeof(struct galaxy));
    galaxy->id = id;
    strcpy(galaxy->name, name);
    galaxy->numPlanets = numPlanets;
    galaxy->planets = (int**)malloc(numPlanets*sizeof(int*));
    for(int i=0; i<numPlanets; i++){
        galaxy->planets[i] = (int*)malloc(3*sizeof(int));
        galaxy->planets[i][0] = rand()%100;
        galaxy->planets[i][1] = rand()%100;
        galaxy->planets[i][2] = rand()%100;
    }
}

//Function for displaying Galaxies
void displayGalaxy(struct galaxy *galaxy){
    printf("Galaxy ID: %d\n", galaxy->id);
    printf("Galaxy Name: %s\n", galaxy->name);
    printf("Number of Planets: %d\n", galaxy->numPlanets);
    for(int i=0; i<galaxy->numPlanets; i++){
        printf("Planet %d: (%d, %d, %d)\n", i+1, galaxy->planets[i][0], galaxy->planets[i][1], galaxy->planets[i][2]);
    }
}

//Function for exploring Planets
void explorePlanet(int *planet){
    int x = planet[0];
    int y = planet[1];
    int z = planet[2];
    printf("Exploring Planet at (%d, %d, %d)\n", x, y, z);
}

//Function for recursively exploring all Planets in a Galaxy
void exploreGalaxy(struct galaxy *galaxy){
    for(int i=0; i<galaxy->numPlanets; i++){
        explorePlanet(galaxy->planets[i]);
    }
}

//Main function
int main(){
    srand(time(0));
    struct galaxy *galaxy1 = (struct galaxy*)malloc(sizeof(struct galaxy));
    createGalaxy(1, "Milky Way", 10);
    displayGalaxy(galaxy1);
    exploreGalaxy(galaxy1);
    return 0;
}