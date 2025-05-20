//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE_LENGTH 100

//Node structure for linked list
typedef struct node{
    char *data;
    struct node *next;
}Node;

//Function to create a new node with given data
Node* create_node(char *data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Function to add a word to the linked list
void add_word(Node** head, char *word){
    Node *new_node = create_node(word);
    Node *temp = *head;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

//Function to read words from a file and add them to the linked list
void read_file(FILE* fp, Node** head){
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp)!= NULL){
        int i, j;
        for(i=0, j=0; line[i]!= '\0'; i++){
            if(isalnum(line[i])){
                line[j++] = tolower(line[i]);
            }
        }
        line[j] = '\0';
        add_word(head, line);
    }
}

//Function to print the linked list
void print_list(Node* head){
    Node *temp = head;
    while(temp!= NULL){
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main function
int main(){
    FILE *fp;
    char filename[20];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File not found\n");
        exit(0);
    }
    Node *head = NULL;
    read_file(fp, &head);
    fclose(fp);
    printf("Linked list:\n");
    print_list(head);
    return 0;
}