//FormAI DATASET v1.0 Category: Sorting ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, temp;
    int n;
    //take input from the user
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);
    int a[n];
    srand(time(NULL)); //for Generating Random numbers

    printf("\nUnsorted Array:\n");
    for(i = 0; i < n; i++){
        a[i] = rand()%100;  //Random Numbers between 0 to 99
        printf("%d ", a[i]);
    }

    //Bubble Sort Implementation
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("\n\nSorted Array using Bubble Sort:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    //Selection Sort Implementation
    for(i = 0; i < n - 1; i++){
        int min_idx = i;
        for(j = i+1; j < n; j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }

    printf("\n\nSorted Array using Selection Sort:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    //Insertion Sort Implementation
    for(i = 1; i < n; i++){
        int key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    printf("\n\nSorted Array using Insertion Sort:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}