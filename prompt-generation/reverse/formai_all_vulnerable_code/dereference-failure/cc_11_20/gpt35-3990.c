//FormAI DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; 
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    //Creating a distributed array to store the pattern
    int **arr = (int **) malloc(n * sizeof(int *));
    for(int i=0; i<n; i++) {
        arr[i] = (int *) malloc(n * sizeof(int));
    }
    
    //Initializing the array with 0's
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }
    
    //Creating the pattern
    int i = 0, j = 0;
    while(i<n && j<n) {
        for(int k=j; k<n; k++) {
            arr[i][k] = 1;
        }
        i++;
        
        for(int k=i; k<n; k++) {
            arr[k][j] = 1;
        }
        j++;
    }
    
    //Printing the pattern
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    //Freeing up the memory allocated to the array
    for(int i=0; i<n; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}