//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node{
    int data;
    int index;
    struct node* next;
};

struct node* create(int data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->index = -1;
    new->next = NULL;
    return new;
}

void insert(struct node** start_ref, int data){
    struct node* new = create(data);
    struct node* last = *start_ref;
    if(*start_ref == NULL){
        *start_ref = new;
        return;
    }
    while(last->next!= NULL){
        last = last->next;
    }
    last->next = new;
}

void delete(struct node** start_ref, int data){
    struct node* temp = *start_ref;
    struct node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *start_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void search(struct node* start, int data){
    struct node* current = start;
    while(current!= NULL){
        if(current->data == data){
            printf("Data found at index %d\n", current->index);
            return;
        }
        current = current->next;
    }
    printf("Data not found\n");
}

void display(struct node* start){
    struct node* temp = start;
    printf("Linked List: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* start = NULL;
    int choice, data;

    while(1){
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&start, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(&start, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(start, data);
                break;
            case 4:
                display(start);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}