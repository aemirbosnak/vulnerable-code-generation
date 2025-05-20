//FormAI DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char email[70];
    struct node* next;
};

// Function prototypes
struct node* insertAtEnd(struct node*, char[]);
struct node* deleteNode(struct node*, char[]);
struct node* searchNode(struct node*, char[]);
void displayList(struct node*);
void saveListToFile(struct node*);

int main() {
    struct node* head = NULL;
    int option;
    char email[70];

    do {
        // Display menu
        printf("\n\nMailing List Manager\n\n");
        printf("1. Add an email address to the list\n");
        printf("2. Delete an email address from the list\n");
        printf("3. Search for an email address\n");
        printf("4. Display the mailing list\n");
        printf("5. Save the mailing list to a file\n");
        printf("6. Exit\n\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                // Add an email address to the list
                printf("\nEnter an email address: ");
                scanf("%s", email);
                head = insertAtEnd(head, email);
                printf("\nEmail address added to the list!");
                break;

            case 2:
                // Delete an email address from the list
                printf("\nEnter an email address to delete: ");
                scanf("%s", email);
                head = deleteNode(head, email);
                printf("\nEmail address deleted from the list!");
                break;

            case 3:
                // Search for an email address
                printf("\nEnter an email address to search: ");
                scanf("%s", email);
                if(searchNode(head, email) == NULL) {
                    printf("\nEmail address not found in the list!");
                }
                else {
                    printf("\nEmail address found in the list!");
                }
                break;

            case 4:
                // Display the mailing list
                displayList(head);
                break;

            case 5:
                // Save the mailing list to file
                saveListToFile(head);
                printf("\nMailing list saved to file!");
                break;

            case 6:
                // Exit
                printf("\nGoodbye!\n\n");
                break;

            default:
                printf("\nInvalid option. Please try again!");
        }
    }while(option != 6);

    return 0;
}

// Function to insert a node at the end of the list
struct node* insertAtEnd(struct node* head, char email[]) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    struct node* p = head;

    strcpy(temp->email, email);
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
    }
    else {
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }

    return head;
}

// Function to delete a node from the list
struct node* deleteNode(struct node* head, char email[]) {
    struct node* p = head;
    struct node* q = head->next;

    if(head == NULL) {
        printf("\nList is empty!");
        return head;
    }

    if(strcmp(head->email, email) == 0) {
        head = head->next;
        free(p);
        return head;
    }

    while(q != NULL) {
        if(strcmp(q->email, email) == 0) {
            p->next = q->next;
            free(q);
            return head;
        }
        p = q;
        q = q->next;
    }

    printf("\nEmail address not found in the list!");
    return head;
}

// Function to search for a node in the list
struct node* searchNode(struct node* head, char email[]) {
    struct node* p = head;

    while(p != NULL) {
        if(strcmp(p->email, email) == 0) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

// Function to display the list
void displayList(struct node* head) {
    struct node* p = head;

    if(head == NULL) {
        printf("\nList is empty!");
        return;
    }

    while(p != NULL) {
        printf("%s\n", p->email);
        p = p->next;
    }
}

// Function to save the list to file
void saveListToFile(struct node* head) {
    struct node* p = head;
    FILE* fp;

    fp = fopen("mailing_list.txt", "w");

    while(p != NULL) {
        fprintf(fp, "%s\n", p->email);
        p = p->next;
    }

    fclose(fp);
}