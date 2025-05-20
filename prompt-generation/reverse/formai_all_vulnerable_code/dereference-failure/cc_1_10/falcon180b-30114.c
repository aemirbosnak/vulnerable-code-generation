//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct node{
    char name[MAX];
    int size;
    struct node* next;
};

struct node* create_node(char name[], int size){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

struct node* add_node(struct node* head, char name[], int size){
    struct node* new_node = create_node(name, size);
    if(head == NULL){
        head = new_node;
        return head;
    }
    struct node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct node* search_node(struct node* head, char name[]){
    struct node* temp = head;
    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void display_list(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%s %d\n", temp->name, temp->size);
        temp = temp->next;
    }
}

void backup_file(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        char source[100], destination[100];
        strcpy(source, temp->name);
        strcat(source, ".bak");
        strcpy(destination, temp->name);
        rename(source, destination);
        strcpy(source, temp->name);
        strcat(source, ".bak");
        rename(destination, source);
        temp = temp->next;
    }
}

void restore_file(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        char source[100], destination[100];
        strcpy(source, temp->name);
        strcat(source, ".bak");
        strcpy(destination, temp->name);
        rename(source, destination);
        temp = temp->next;
    }
}

int main(){
    char name[MAX];
    int size;
    struct node* head = NULL;
    while(1){
        printf("Enter file name: ");
        scanf("%s", name);
        printf("Enter file size in bytes: ");
        scanf("%d", &size);
        head = add_node(head, name, size);
    }
    return 0;
}