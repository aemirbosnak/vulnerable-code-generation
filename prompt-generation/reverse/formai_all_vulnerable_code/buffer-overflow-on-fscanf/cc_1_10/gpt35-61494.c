//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure of a Node in the Linked List */
struct Node{
    char* data;
    int frequency;
    struct Node* next;
};

/* Function to Insert a New Node into the Linked List */
void insertNode(struct Node** head, char* data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = (char*)malloc(strlen(data)+1);
    strcpy(newNode->data, data);
    newNode->frequency = 1;
    newNode->next = *head;
    *head = newNode;
}

/* Function to Update the Frequency of an Existing Node */
void updateNode(struct Node* head, char* data){
    while(head != NULL){
        if(strcmp(head->data, data) == 0){
            head->frequency++;
            return;
        }
        head = head->next;
    }
}

/* Function to Process Input File and Extract Tokens */
void processInputFile(char* fileName, struct Node** head){
    FILE* fp = fopen(fileName, "r");

    if(fp == NULL){
        printf("Error Reading File %s.\n", fileName);
        exit(EXIT_FAILURE);
    }

    char word[100];

    while(fscanf(fp, "%s", word) != EOF){
        char* token = strtok(word, " ,.!?\n\t");
        while(token != NULL){
            if(*head == NULL){
                insertNode(head, token);
            }
            else{
                updateNode(*head, token);
                if(!isTokenExists(*head, token)){
                    insertNode(head, token);
                }
            }
            token = strtok(NULL, " ,.!?\n\t");
        }
    }

    fclose(fp);
}

/* Function to Check If a Token Already Exists in the Linked List */
int isTokenExists(struct Node* head, char* data){
    while(head != NULL){
        if(strcmp(head->data, data) == 0){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

/* Driver Code */
int main(){
    struct Node* head = NULL;

    processInputFile("input.txt", &head);

    // Display the List of Tokens and Their Frequencies
    struct Node* curr = head;
    while(curr != NULL){
        printf("%s : %d\n", curr->data, curr->frequency);
        curr = curr->next;
    }

    return 0;
}