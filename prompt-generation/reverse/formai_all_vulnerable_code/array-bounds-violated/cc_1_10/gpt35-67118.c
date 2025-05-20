//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to check whether a site is open or not
int isOpen(int n, int *grid){
    return *(grid+n);
}

//Function to open a site
void openSite(int n, int *grid){
    *(grid+n) = 1;
}

//Function to determine a random integer between a and b
int randomInt(int a, int b){
    return (rand() % (b-a+1) + a);
}

int main(){
    srand(time(0)); //Seed for random numbers
    int size;
    printf("Enter the size of the grid: ");
    scanf("%d", &size);

    int grid[size*size];
    for(int i=0; i<size*size; i++){
        *(grid+i) = 0; //Initialise all sites as closed
    }

    //Open the top row of sites
    for(int i=0; i<size; i++){
        openSite(i, grid);
    }

    //Simulate percolation
    int lastRow[size];
    for(int i=0; i<size; i++){
        *(lastRow+i) = isOpen(size*(size-1)+i, grid);
    }

    while(!lastRow[0]){ //While the bottom row is not open
        int randSite = randomInt(0, size-1);
        if(isOpen(size*(size-2)+randSite, grid)){ //If the site directly above is open
            openSite(size*(size-1)+randSite, grid); //Open the current site
            lastRow[randSite] = 1; //Update the last row
        }
    }

    //Print the final grid
    printf("Final Grid:\n");
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(isOpen(size*i+j, grid)){
                printf("O ");
            }
            else{
                printf("X ");
            }
        }
        printf("\n");
    }

    return 0;
}