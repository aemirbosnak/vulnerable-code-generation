//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct node{
    int data;
    struct node *next;
};

struct node *hash_table[MAX_SIZE];

void insert(int value){
    int index = value % MAX_SIZE;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if(hash_table[index] == NULL){
        hash_table[index] = ptr;
    }else{
        struct node *temp = hash_table[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void search(int value){
    int index = value % MAX_SIZE;
    struct node *ptr = hash_table[index];
    while(ptr != NULL){
        if(ptr->data == value){
            printf("Value %d found at index %d\n", value, index);
            return;
        }
        ptr = ptr->next;
    }
    printf("Value %d not found in the hash table\n", value);
}

void display(){
    for(int i=0;i<MAX_SIZE;i++){
        printf("[%d] -> ", i);
        struct node *ptr = hash_table[i];
        while(ptr != NULL){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int option, value;
    do{
        printf("\nSelect an option:\n");
        printf("1. Insert a value\n");
        printf("2. Search for a value\n");
        printf("3. Display the hash table\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter a value to search for: ");
                scanf("%d", &value);
                search(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }while(option != 4);
    return 0;
}