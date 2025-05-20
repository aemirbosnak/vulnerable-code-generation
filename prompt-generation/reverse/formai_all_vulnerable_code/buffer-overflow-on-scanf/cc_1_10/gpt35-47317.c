//FormAI DATASET v1.0 Category: Database Indexing System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_KEYS 5
#define MAX_DATA 50

typedef struct record{
    int key[MAX_KEYS];
    char data[MAX_DATA];
    struct record *next;
}Record;

Record *head[MAX_KEYS];

void insert(int key[], char data[]){
    int i;
    Record *newRecord, *temp;

    newRecord = (Record*)malloc(sizeof(Record));
    if(newRecord == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    for(i=0; i<MAX_KEYS; i++){
        newRecord->key[i] = key[i];
    }
    strcpy(newRecord->data, data);
    newRecord->next = NULL;

    if(head[key[0]] == NULL){
        head[key[0]] = newRecord;
    }
    else{
        temp = head[key[0]];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newRecord;
    }
}

void search(int key[]){
    Record *temp = head[key[0]];
    int flag;
    while(temp != NULL){
        flag = 1;
        for(int i=0; i<MAX_KEYS; i++){
            if(temp->key[i]!=key[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("Key found. Data: %s\n", temp->data);
            return;
        }
        temp=temp->next;
    }
    printf("Key not found.\n");
}

int main(){
    int choice, key[MAX_KEYS];
    char data[MAX_DATA];
    while(1){
        printf("1. Insert\n2. Search\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter keys (Maximum 5): ");
                for(int i=0; i<MAX_KEYS; i++){
                    scanf("%d", &key[i]);
                }
                printf("Enter data: ");
                scanf("%s", data);
                insert(key, data);
                break;
            case 2:
                printf("Enter keys (Maximum 5): ");
                for(int i=0; i<MAX_KEYS; i++){
                    scanf("%d", &key[i]);
                }
                search(key);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}