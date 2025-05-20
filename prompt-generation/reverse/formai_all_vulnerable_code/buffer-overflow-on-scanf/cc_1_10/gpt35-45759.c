//FormAI DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

Node* head = NULL;

void display(){
    Node* temp = head;

    if(temp == NULL){
        printf("Mailing list is empty.\n");
        return;
    }

    printf("Mailing list:\n");
    while(temp != NULL){
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

void addEmail(char input_email[]){
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->email, input_email);

    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
        printf("Email [%s] has been added to the mailing list.\n", input_email);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(strcmp(temp->email, input_email) == 0){
            printf("Email [%s] already exists in the mailing list.\n", input_email);
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    if(strcmp(temp->email, input_email) == 0){
        printf("Email [%s] already exists in the mailing list.\n", input_email);
        free(new_node);
        return;
    }

    temp->next = new_node;
    new_node->next = NULL;

    printf("Email [%s] has been added to the mailing list.\n", input_email);
}

void deleteEmail(char input_email[]){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL && strcmp(temp->email, input_email) != 0){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Email [%s] does not exist in the mailing list.\n", input_email);
        return;
    }

    if(prev == NULL){
        head = temp->next;
        free(temp);
        printf("Email [%s] has been deleted from the mailing list.\n", input_email);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Email [%s] has been deleted from the mailing list.\n", input_email);
}

int main(){
    char input_email[50];
    int choice;

    printf("Welcome to Mailing List Manager!\n");

    while(1){
        printf("\n=======================================\n");
        printf("[1] Display mailing list\n");
        printf("[2] Add email to the mailing list\n");
        printf("[3] Delete email from the mailing list\n");
        printf("[4] Exit program\n");
        printf("=======================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display();
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", input_email);
                addEmail(input_email);
                break;
            case 3:
                printf("Enter email: ");
                scanf("%s", input_email);
                deleteEmail(input_email);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}