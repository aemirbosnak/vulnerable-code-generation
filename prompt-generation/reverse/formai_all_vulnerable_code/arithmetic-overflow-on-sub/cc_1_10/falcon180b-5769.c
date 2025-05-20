//Falcon-180B DATASET v1.0 Category: Sorting ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the maximum size of the array
#define MAX_SIZE 100

//Defining the structure of the record to be sorted
struct Record{
    int id;
    char name[50];
};

//Function to compare two records based on their id
int compare(struct Record* a, struct Record* b){
    if(a->id < b->id)
        return -1;
    else if(a->id > b->id)
        return 1;
    else
        return 0;
}

//Function to swap two records
void swap(struct Record* a, struct Record* b){
    struct Record temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform bubble sort on the array of records
void bubbleSort(struct Record* arr, int n){
    int i, j, flag;
    for(i=0; i<n-1; i++){
        flag = 0;
        for(j=0; j<n-i-1; j++){
            if(compare(arr+j, arr+j+1) > 0){
                swap(arr+j, arr+j+1);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

//Function to display the sorted array of records
void display(struct Record* arr, int n){
    int i;
    for(i=0; i<n; i++){
        printf("ID: %d\tName: %s\n", arr[i].id, arr[i].name);
    }
}

//Main function to read the array of records from the user and display the sorted array
int main(){
    int n, i;
    struct Record arr[MAX_SIZE];
    printf("Enter the number of records: ");
    scanf("%d", &n);
    printf("Enter the records:\n");
    for(i=0; i<n; i++){
        printf("ID: ");
        scanf("%d", &arr[i].id);
        printf("Name: ");
        scanf("%s", arr[i].name);
    }
    bubbleSort(arr, n);
    printf("Sorted array:\n");
    display(arr, n);
    return 0;
}