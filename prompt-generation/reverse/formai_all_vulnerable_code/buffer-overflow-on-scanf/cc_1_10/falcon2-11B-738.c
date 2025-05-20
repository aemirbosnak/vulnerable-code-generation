//Falcon2-11B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* password;
    struct password* next;
} Node;

Node* createNode(char* password) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->password = password;
    node->next = NULL;
    return node;
}

void addPassword(Node** head, char* password) {
    Node* newNode = createNode(password);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while(current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printPassword(Node* node) {
    while(node!= NULL) {
        printf("%s\n", node->password);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    char password[20];
    int n;
    
    printf("Enter the number of passwords to be stored: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("Enter password %d: ", i+1);
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        addPassword(&head, password);
    }
    
    printPassword(head);
    return 0;
}