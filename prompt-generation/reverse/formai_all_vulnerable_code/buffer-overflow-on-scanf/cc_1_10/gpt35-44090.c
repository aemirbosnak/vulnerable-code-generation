//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {             //define a struct named node
    char name[50];
    char email[50];
    struct node *next;
};

void add_contact(struct node **head_ref) {  //add_contact function to add a new node/contact
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter name: ");
    scanf("%s", new_node -> name);
    printf("Enter email: ");
    scanf("%s", new_node -> email);
    new_node -> next = *head_ref;
    *head_ref = new_node;
}

void delete_contact(struct node **head_ref) {  //delete_contact function to delete a node/contact
    struct node *temp = *head_ref, *prev_node;
    char input_name[50];
    printf("\nEnter contact name to delete: ");
    scanf("%s", input_name);
    if (temp != NULL && strcmp(temp -> name, input_name) == 0) {
        *head_ref = temp -> next;
        free(temp);
        printf("\nThe contact has been deleted successfully.\n");
        return;
    }
    while (temp != NULL && strcmp(temp -> name, input_name) != 0) {
        prev_node = temp;
        temp = temp -> next;
    }
    if (temp == NULL) {
        printf("\nThe contact does not exist.\n");
        return;
    }
    prev_node -> next = temp -> next;
    free(temp);
    printf("\nThe contact has been deleted successfully.\n");
}

void display_contacts(struct node *node) {  //display_contacts function to display all the contacts
    if (node == NULL) {
        printf("There are no contacts to display.\n");
        return;
    }
    printf("\nContacts:\n");
    while (node != NULL) {
        printf("\n%s -> %s", node -> name, node -> email);
        node = node -> next;
    }
}

void save_contacts(struct node *node) {  //save_contacts function to save the contacts in a file
    FILE *fp;
    fp = fopen("contacts.txt", "w");
    if (node == NULL) {
        fprintf(fp, "There are no contacts to display.");
        fclose(fp);
        return;
    }
    fprintf(fp, "Contacts:\n");
    while (node != NULL) {
        fprintf(fp, "%s -> %s\n", node -> name, node -> email);
        node = node -> next;
    }
    fclose(fp);
    printf("\nThe contacts have been saved successfully.\n");
}

int main() {
    int choice;
    struct node *head_node = NULL;
    do {
        printf("\nMenu:\n");
        printf("1) Add contact\n");
        printf("2) Delete contact\n");
        printf("3) Display contacts\n");
        printf("4) Save contacts\n");
        printf("5) Exit\n");
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(&head_node);
                break;
            case 2:
                delete_contact(&head_node);
                break;
            case 3:
                display_contacts(head_node);
                break;
            case 4:
                save_contacts(head_node);
                break;
            case 5:
                printf("\nThank you for using the mailing list manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}