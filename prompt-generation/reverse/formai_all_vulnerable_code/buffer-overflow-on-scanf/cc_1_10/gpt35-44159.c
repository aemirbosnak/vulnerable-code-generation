//FormAI DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct linkedList{
    struct node* head;
    int count;
};

void addNode(struct linkedList* list, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void deleteNode(struct linkedList* list, int data){
    if(list->count == 0){
        printf("List is Empty\n");
        return;
    }
    struct node* currentNode = list->head;
    struct node* previousNode = NULL;
    while(currentNode != NULL){
        if(currentNode->data == data){
            if(previousNode == NULL){
                list->head = currentNode->next;
            }else{
                previousNode->next = currentNode->next;
            }
            free(currentNode);
            list->count--;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("Value not Found\n");
}

void display(struct linkedList* list){
    if(list->count == 0){
        printf("List is Empty\n");
        return;
    }
    struct node* currentNode = list->head;
    while(currentNode != NULL){
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main(){
    struct linkedList* list = (struct linkedList*)malloc(sizeof(struct linkedList));
    list->head = NULL;
    list->count = 0;

    printf("Welcome to the Linked List Puzzle!\n");
    printf("You will have to guess the correct number to add to the linked list\n");
    printf("The list will be displayed after each guess\n");

    addNode(list, 2);
    addNode(list, 5);
    addNode(list, 7);

    printf("First Guess: ");
    int guess1;
    scanf("%d", &guess1);
    addNode(list, guess1);
    display(list);

    printf("Second Guess: ");
    int guess2;
    scanf("%d", &guess2);
    addNode(list, guess2);
    display(list);

    printf("Third Guess: ");
    int guess3;
    scanf("%d", &guess3);
    addNode(list, guess3);
    display(list);

    printf("You have done well so far!\n");
    printf("Now, you have to guess the number to delete from the linked list\n");
    printf("The list will be displayed after each guess\n");

    deleteNode(list, 5);
    display(list);

    printf("Final Guess: ");
    int guess4;
    scanf("%d", &guess4);
    deleteNode(list, guess4);
    display(list);

    printf("Congratulations! You have completed the Linked List Puzzle!\n");
    free(list);
    
    return 0;
}