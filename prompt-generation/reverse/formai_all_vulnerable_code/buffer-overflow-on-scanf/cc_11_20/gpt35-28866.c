//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include<stdio.h>

void main() {
    printf("Hello there! I am a Graph Representation Program!\n");

    //Declaration of variables
    int n, i, j, k, temp, G[50][50], T[50][2];

    //Get number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    //Loop to get the adjacency matrix values
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Enter the weight for vertices %d to %d: ", i+1, j+1);
            scanf("%d", &G[i][j]);
        }
    }

    //Displaying the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    //Creating a list of edges
    k = 0;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(G[i][j] != 0){
                T[k][0] = i;
                T[k][1] = j;
                k++;
            }
        }
    }

    //Sorting the list of edges according to weight
    for(i=0; i<k-1; i++){
        for(j=i+1; j<k; j++){
            if(G[T[i][0]][T[i][1]] > G[T[j][0]][T[j][1]]){
                temp = G[T[i][0]][T[i][1]];
                G[T[i][0]][T[i][1]] = G[T[j][0]][T[j][1]];
                G[T[j][0]][T[j][1]] = temp;

                temp = T[i][0];
                T[i][0] = T[j][0];
                T[j][0] = temp;

                temp = T[i][1];
                T[i][1] = T[j][1];
                T[j][1] = temp;
            }
        }
    }

    //Displaying the sorted list of edges
    printf("\nSorted List of Edges:\n");
    for(i=0; i<k; i++){
        printf("(%d,%d) - %d\n", T[i][0]+1, T[i][1]+1, G[T[i][0]][T[i][1]]);
    }

    printf("\nThank you for using me! Goodbye :)");
}