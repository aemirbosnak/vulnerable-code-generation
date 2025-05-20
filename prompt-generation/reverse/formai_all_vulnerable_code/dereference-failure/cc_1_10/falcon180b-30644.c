//Falcon-180B DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data;
    struct node *next;
}node;

void create(node **head, char data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }else{
        node *temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print(node *head){
    if(head == NULL){
        printf("Empty Linked List\n");
    }else{
        node *temp = head;
        while(temp!= NULL){
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void reverse(node **head){
    node *prev = NULL;
    node *current = *head;
    while(current!= NULL){
        node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void recursive_reverse(node **head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }
    node *temp = (*head)->next;
    (*head)->next = NULL;
    recursive_reverse(&temp);
    node *prev = *head;
    while(temp!= NULL){
        node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}

int main(){
    node *head = NULL;
    char str[] = "Hello, World!";
    int i = 0;
    while(str[i]!= '\0'){
        create(&head, str[i]);
        i++;
    }
    printf("Original Linked List:\n");
    print(head);
    recursive_reverse(&head);
    printf("Reversed Linked List:\n");
    print(head);
    return 0;
}