//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

//Node structure for linked list
struct Node{
    char *data;
    struct Node *next;
};

//Function to create a new node
struct Node* createNode(char *data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

//Function to check if a string is a number
bool isNumber(char *str){
    int i;
    for(i=0;i<strlen(str);i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

//Function to parse the resume and return a linked list of skills
struct Node* parseResume(char *resume){
    struct Node *head = NULL;
    char *token;
    char *saveptr = NULL;
    char *line = strtok_r(resume, "\n", &saveptr);

    while(line!= NULL){
        token = strtok_r(line, " ", &saveptr);
        while(token!= NULL){
            if(isNumber(token)){
                //Add number as skill
                struct Node *newnode = createNode(token);
                newnode->next = head;
                head = newnode;
            }else{
                //Add string as skill
                struct Node *newnode = createNode(token);
                newnode->next = head;
                head = newnode;
            }
            token = strtok_r(NULL, " ", &saveptr);
        }
        line = strtok_r(NULL, "\n", &saveptr);
    }
    return head;
}

//Function to print the linked list
void printList(struct Node *head){
    while(head!= NULL){
        printf("%s ", head->data);
        head = head->next;
    }
}

//Main function
int main(){
    char resume[10000];
    printf("Enter resume:\n");
    fgets(resume, 10000, stdin);
    struct Node *skills = parseResume(resume);
    printf("Skills:\n");
    printList(skills);
    return 0;
}