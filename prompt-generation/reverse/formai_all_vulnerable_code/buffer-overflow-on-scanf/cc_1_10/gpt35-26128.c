//FormAI DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
#define TABLE_SIZE 10

struct student{
    int reg_no;
    char name[30];
    int age;
};

struct node{
    int key;
    struct student data;
    struct node* next;
};

struct node* table[TABLE_SIZE];

void insert(int key, struct student data){
    int index = key % TABLE_SIZE;

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->data = data;
    new_node->next = NULL;

    if(table[index] == NULL){
        table[index] = new_node;
    }
    else{
        struct node* temp = table[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search(int key){
    int index = key % TABLE_SIZE;
    int flag = 0;

    struct node* temp = table[index];

    while(temp != NULL){
        if(temp->key == key){
            flag = 1;
            printf("Registration Number: %d\n", temp->data.reg_no);
            printf("Name: %s\n", temp->data.name);
            printf("Age: %d\n", temp->data.age);
            break;
        }
        temp = temp->next;
    }

    if(flag == 0){
        printf("Record not found!\n");
    }
}

int main(){
    int option;
    int key;
    struct student data;
    while(1){
        printf("\n**************************************\n");
        printf("Enter option:\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("\n**************************************\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter registration number: ");
                scanf("%d", &data.reg_no);

                printf("Enter name: ");
                scanf("%s", data.name);

                printf("Enter age: ");
                scanf("%d", &data.age);

                key = data.reg_no;

                insert(key, data);
                break;
            
            case 2:
                printf("Enter registration number to be searched: ");
                scanf("%d", &key);

                search(key);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option!\n");
                break;
        }
    }
    return 0;
}