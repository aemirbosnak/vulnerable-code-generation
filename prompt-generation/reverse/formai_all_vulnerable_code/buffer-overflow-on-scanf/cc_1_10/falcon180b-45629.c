//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define MAX 100

//Structure for a single stock
struct stock{
    char name[20];
    float price;
    int quantity;
};

//Function to compare two stocks based on their prices
int compare(const void *a, const void *b){
    struct stock *p = (struct stock *)a;
    struct stock *q = (struct stock *)b;

    if(p->price > q->price)
        return -1;
    else if(p->price < q->price)
        return 1;
    else
        return 0;
}

//Function to sort an array of stocks based on their prices
void sort(struct stock arr[], int n){
    qsort(arr, n, sizeof(struct stock), compare);
}

//Function to display the current state of the market
void display(struct stock arr[], int n){
    printf("\nCurrent Market State:\n");
    printf("------------------------\n");
    for(int i=0; i<n; i++){
        printf("%-20s %-10.2f %d\n", arr[i].name, arr[i].price, arr[i].quantity);
    }
}

//Function to simulate the stock market
void market(struct stock arr[], int n, float change[], int m){
    int i, j;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            arr[j].price += change[i]*arr[j].price;
        }
        display(arr, n);
        sleep(1);
    }
}

int main(){
    struct stock arr[MAX];
    float change[MAX];
    int n, m;

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    printf("Enter the names of the stocks:\n");
    for(int i=0; i<n; i++){
        scanf("%s", arr[i].name);
    }

    printf("Enter the initial prices of the stocks:\n");
    for(int i=0; i<n; i++){
        scanf("%f", &arr[i].price);
    }

    printf("Enter the initial quantities of the stocks:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i].quantity);
    }

    printf("Enter the number of changes in the market: ");
    scanf("%d", &m);

    printf("Enter the changes in the market:\n");
    for(int i=0; i<m; i++){
        scanf("%f", &change[i]);
    }

    sort(arr, n);
    market(arr, n, change, m);

    return 0;
}