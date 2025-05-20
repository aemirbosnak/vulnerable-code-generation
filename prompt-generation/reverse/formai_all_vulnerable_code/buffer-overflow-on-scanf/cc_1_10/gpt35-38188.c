//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Alan Touring
#include<stdio.h> 
#include<string.h> 

struct student { 
    int id; 
    char name[20]; 
    char address[50]; 
}; 

void insert(struct student arr[], int n) { 
    int i; 
    for(i=0; i<n; i++) { 
        printf("Enter details of Student %d: \n",i+1); 
        printf("ID: "); 
        scanf("%d", &arr[i].id); 
        printf("Name: "); 
        scanf("%s", arr[i].name); 
        printf("Address: "); 
        scanf("%s", arr[i].address); 
    } 
} 

void display(struct student arr[], int n) { 
    int i; 
    printf("\nID\t\tName\t\tAddress\n"); 
    for(i=0; i<n; i++) { 
        printf("%d\t\t%s\t\t%s\n",arr[i].id,arr[i].name,arr[i].address); 
    } 
} 

void search(struct student arr[], int n, int key) { 
    int i; 
    for(i=0; i<n; i++) { 
        if(arr[i].id==key) { 
            printf("\nThe Details of the Student with ID %d are: \n",key); 
            printf("ID: %d\n",arr[i].id); 
            printf("Name: %s\n",arr[i].name); 
            printf("Address: %s\n",arr[i].address); 
            break; 
        } 
    } 
    if(i==n) { 
        printf("\nThe Student with ID %d does not exist in the Database!\n",key); 
    } 
} 

void main() { 
    int n, key; 
    struct student arr[100]; 
    int choice; 
    do { 
        printf("Database Indexing System - Main Menu:\n"); 
        printf("1. Insert Details\n"); 
        printf("2. Display Details\n"); 
        printf("3. Search Details\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch(choice) { 
            case 1: 
                printf("Enter the number of students that you want to insert: "); 
                scanf("%d", &n); 
                insert(arr, n); 
                break; 
            case 2: 
                display(arr, n); 
                break; 
            case 3: 
                printf("Enter the ID of the Student that you want to search: "); 
                scanf("%d", &key); 
                search(arr, n, key); 
                break; 
            case 4: 
                printf("\nThank you for using the Database Indexing System!\n"); 
                break; 
            default: 
                printf("Invalid Choice! Please try again.\n"); 
        } 
    } while(choice!=4); 
}