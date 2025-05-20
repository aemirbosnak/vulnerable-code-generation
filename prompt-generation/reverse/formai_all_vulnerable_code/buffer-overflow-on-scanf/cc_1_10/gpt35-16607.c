//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_VERTICES 100 

// Function to print the network topology map 
void printTopologyMap(int G[MAX_VERTICES][MAX_VERTICES], int n) 
{ 
    printf("\nVillage Network Topology Map:\n\n"); 
    printf("-----------------------------------------------\n"); 
    printf("|  Village  |   Connected Villages  |  Status  |\n"); 
    printf("-----------------------------------------------\n"); 

    for (int i = 0; i < n; i++) 
    { 
        printf("|      %d    |          ", i+1); 

        for (int j = 0; j < n; j++) 
        { 
            if (G[i][j] == 1) 
                printf("%d ", j+1); 
        } 

        printf("|    Online    |\n"); 
    } 

    printf("-----------------------------------------------\n"); 

    printf("\n"); 
} 

int main() 
{ 
    int n, G[MAX_VERTICES][MAX_VERTICES];

    printf("Welcome to the Village Network Topology Mapper!\n\n");
    printf("Please enter the number of villages in the network: "); 
    
    scanf("%d", &n); 

    // Initializing the network topology map 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            if (i == j) 
                G[i][j] = 0; 
            else 
                G[i][j] = rand() % 2;
        } 
    } 

    printTopologyMap(G, n);

    printf("\nThe network topology map has been successfully generated!\n"); 

    return 0; 
}