//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    /* create temp arrays */
    int L[n1], R[n2];
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}


int main(){
    int i,j,option;
    srand(time(0));
    int option2, num_players;

    printf("Welcome to this sorting game!\n");
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    int players[num_players][100];

    for(i=0;i<num_players;i++){
        printf("\nPLAYER %d: Enter the length of the array: ", i+1);
        scanf("%d", &option);
        printf("PLAYER %d Enter an array of length %d: ", i+1, option);

        for(j=0;j<option;j++){
            players[i][j]=rand()%100; //number between 0-99
            printf("%d ",players[i][j]);
        }
    }
    printf("\n\nSorting game begins!\n");
    printf("Choose an option:\n");
    printf("1. Player with smallest number wins\n");
    printf("2. Player with largest number wins\n");

    scanf("%d",&option2);

    printf("Sorting...\n");

    //sorting algorithm for each player's array
    for(i=0;i<num_players;i++){
        mergeSort(players[i], 0, option-1);
    }

    if(option2==1){
        int min_player, global_min=100;

        for(i=0;i<num_players;i++){
            if(players[i][0]<global_min){
                global_min=players[i][0];
                min_player=i;
            }
        }

        printf("PLAYER %d wins with the smallest number %d\n", min_player+1, global_min);
    }

    else if(option2==2){
        int max_player, global_max=-1;

        for(i=0;i<num_players;i++){
            if(players[i][option-1]>global_max){
                global_max=players[i][option-1];
                max_player=i;
            }
        }

        printf("PLAYER %d wins with the largest number %d\n", max_player+1, global_max);
    }

    else{
        printf("Invalid option chosen!");
        exit(0);
    }

    return 0;
}