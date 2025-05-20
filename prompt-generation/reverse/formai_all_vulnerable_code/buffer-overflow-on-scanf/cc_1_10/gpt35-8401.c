//FormAI DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    char name[50];
    int age;
    float height;
    char gender[10];
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int id, char name[], int age, float height, char gender[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->height = height;
    strcpy(newNode->gender, gender);
    newNode->next = head;
    head = newNode;
}

void displayDB() {
    struct Node* p = head;
    printf("ID\tName\tAge\tHeight\tGender\n");
    while(p != NULL) {
        printf("%d\t%s\t%d\t%.2f\t%s\n", p->id, p->name, p->age, p->height, p->gender);
        p = p->next;
    }
}

void searchDB(int id) {
    struct Node* p = head;
    while(p != NULL) {
        if(p->id == id) {
            printf("ID\tName\tAge\tHeight\tGender\n");
            printf("%d\t%s\t%d\t%.2f\t%s\n", p->id, p->name, p->age, p->height, p->gender);
            return;
        }
        p = p->next;
    }
    printf("Record not found!\n");
}

void deleteNode(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    while(temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Record not found!\n");
        return;
    }
    
    if(prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp);
    printf("Record deleted successfully!\n");
}

int main() {
    int choice, id, age;
    char name[50], gender[10];
    float height;
    
    while(1) {
        printf("\n\nDATABASE SIMULATION\n");
        printf("1. Insert Data\n");
        printf("2. Display Database\n");
        printf("3. Search Database\n");
        printf("4. Delete Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Height: ");
                scanf("%f", &height);
                printf("Enter Gender: ");
                scanf("%s", gender);
                insertNode(id, name, age, height, gender);
                printf("Record inserted successfully!\n");
                break;
            
            case 2:
                displayDB();
                break;
                
            case 3:
                printf("\nEnter ID to search: ");
                scanf("%d", &id);
                searchDB(id);
                break;
                
            case 4:
                printf("\nEnter ID to delete: ");
                scanf("%d", &id);
                deleteNode(id);
                break;
            
            case 5:
                exit(0);
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}