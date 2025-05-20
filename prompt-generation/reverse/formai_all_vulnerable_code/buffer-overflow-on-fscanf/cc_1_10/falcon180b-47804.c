//Falcon-180B DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define MAX_ITEMS 100
#define MAX_TRANSACTIONS 1000
#define MAX_CATEGORIES 10

typedef struct{
    char name[50];
    int price;
    int quantity;
    int reorderLevel;
    int category;
}Item;

typedef struct{
    int itemID;
    int quantity;
}Transaction;

Item items[MAX_ITEMS];
Transaction transactions[MAX_TRANSACTIONS];
int numItems, numTransactions;
int categoryCounts[MAX_CATEGORIES];

void readItems(){
    FILE *fp;
    fp = fopen("items.txt", "r");
    if(fp == NULL){
        printf("Error opening items file\n");
        exit(1);
    }
    fscanf(fp, "%d", &numItems);
    for(int i=0; i<numItems; i++){
        fscanf(fp, "%s %d %d %d %d", items[i].name, &items[i].price, &items[i].quantity, &items[i].reorderLevel, &items[i].category);
    }
    fclose(fp);
}

void readTransactions(){
    FILE *fp;
    fp = fopen("transactions.txt", "r");
    if(fp == NULL){
        printf("Error opening transactions file\n");
        exit(1);
    }
    fscanf(fp, "%d", &numTransactions);
    for(int i=0; i<numTransactions; i++){
        fscanf(fp, "%d %d", &transactions[i].itemID, &transactions[i].quantity);
    }
    fclose(fp);
}

void calculateCategoryCounts(){
    for(int i=0; i<numTransactions; i++){
        categoryCounts[items[transactions[i].itemID-1].category]++;
    }
}

void displayCategoryCounts(){
    for(int i=0; i<MAX_CATEGORIES; i++){
        if(categoryCounts[i] > 0){
            printf("%s: %d\n", "Category "+i, categoryCounts[i]);
        }
    }
}

int main(){
    srand(time(0));
    readItems();
    readTransactions();
    calculateCategoryCounts();
    displayCategoryCounts();
    return 0;
}