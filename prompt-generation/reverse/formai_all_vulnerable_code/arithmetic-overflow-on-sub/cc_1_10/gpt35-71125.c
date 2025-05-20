//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
//Imagine that we have a group of cities connected by roads, and we need to color them in a way that no two cities that are directly connected have the same color. 
//Let's create a program that solves this problem using graph coloring algorithm.

#include<stdio.h>
#include<stdlib.h>
#define MAX_CITIES 20

int cities[MAX_CITIES][MAX_CITIES], colors[MAX_CITIES], numberOfCities;

int isSafe(int city, int color) {
    for(int i=0;i<numberOfCities;i++) {
        if(cities[city][i]==1 && colors[i]==color)
            return 0;
    }
    return 1;
}

void assignColor(int city) {
    if(city==numberOfCities) {
        printf("\nColor Assigned Successfully!!\n");
        for(int i=0;i<numberOfCities;i++) {
            printf("City %d is colored with color %d\n", i+1, colors[i]+1);
        }
        exit(0);
    }

    for(int color=0;color<3;color++) {
        if(isSafe(city, color)) {
            colors[city]=color;

            printf("\nCity %d is colored with color %d\n", city+1, colors[city]+1);

            assignColor(city+1);

            colors[city]=-1;
        }
    }
}

int main() {
    int edges, source, destination;

    printf("Enter the number of cities (max %d): ",MAX_CITIES);
    scanf("%d",&numberOfCities);

    for(int i=0;i<numberOfCities;i++) {
        colors[i]=-1;
    }

    printf("\nEnter the number of edges: ");
    scanf("%d",&edges);

    for(int i=0;i<edges;i++) {
        printf("\nEnter edge %d (source destination): ",i+1);
        scanf("%d%d",&source,&destination);

        cities[source-1][destination-1]=1;
        cities[destination-1][source-1]=1;
    }

    assignColor(0);
    return 0;
}