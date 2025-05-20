//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    FILE* file;
    char filename[50];
    int choice, data;
    struct Node* head = NULL;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL){
        printf("File not found!\n");
        exit(0);
    }

    while(1){
        printf("\n1. Add node\n2. Print list\n3. Save to file\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;

            case 2:
                printf("List: ");
                printList(head);
                printf("\n");
                break;

            case 3:
                file = fopen(filename, "w");

                if(file == NULL){
                    printf("Error in saving to file!\n");
                    exit(0);
                }

                while(head!= NULL){
                    fprintf(file, "%d ", head->data);
                    head = head->next;
                }

                fclose(file);
                printf("Saved to file successfully!\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}