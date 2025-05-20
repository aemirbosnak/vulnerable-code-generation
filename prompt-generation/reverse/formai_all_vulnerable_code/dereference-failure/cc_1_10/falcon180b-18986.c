//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Node{
    char data[MAX];
    struct Node* next;
};

struct Node* createNode(char data[MAX]){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, char data[MAX]){
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* head = NULL;
    FILE* file = fopen("resume.txt", "r");
    if(file == NULL){
        printf("File Not Found\n");
        exit(0);
    }
    char ch;
    while((ch = fgetc(file))!= EOF){
        if(ch == '\n'){
            char name[100];
            int i = 0;
            while(i < strlen(head->data)){
                name[i] = head->data[i];
                i++;
            }
            name[i] = '\0';
            printf("%s\n", name);
            head = head->next;
        }else{
            strcat(head->data, &ch);
        }
    }
    fclose(file);
    return 0;
}