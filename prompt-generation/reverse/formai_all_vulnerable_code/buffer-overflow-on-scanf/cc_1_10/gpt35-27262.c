//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char email[50];
    struct node* next;
} Node;

Node* createNode(char email[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

Node* addNodeToList(Node* head, char email[]) {
    Node* newNode = createNode(email);
    if(head == NULL) {
        return newNode;
    }
    else {
        Node* ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        return head;
    }
}

Node* deleteNodeFromList(Node* head, char email[]) {
    if(head == NULL) {
        return NULL;
    }
    else if(strcmp(head->email, email) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else {
        Node* ptr = head;
        while((ptr->next != NULL) && (strcmp(ptr->next->email, email) != 0)) {
            ptr = ptr->next;
        }
        if(ptr->next == NULL) {
            return head;
        }
        else {
            Node* temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return head;
        }
    }
}

void printList(Node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
    }
    else {
        printf("Email List:\n");
        while(head != NULL) {
            printf("%s\n", head->email);
            head = head->next;
        }
    }
}

int main() {
    Node* head = NULL;
    char email[50];
    int choice;

    do {
        printf("\n1. Add Email\n2. Delete Email\n3. View Email List\n4. Exit");
        printf("\nEnter your choice(1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the email: ");
                scanf("%s", email);
                head = addNodeToList(head, email);
                printf("Email added successfully.");
                break;

            case 2:
                printf("Enter the email: ");
                scanf("%s", email);
                head = deleteNodeFromList(head, email);
                printf("Email deleted successfully.");
                break;

            case 3:
                printList(head);
                break;

            case 4:
                printf("Exiting program...");
                exit(0);
                break;

            default:
                printf("Invalid choice.");
        }
    } while(choice != 4);

    return 0;
}