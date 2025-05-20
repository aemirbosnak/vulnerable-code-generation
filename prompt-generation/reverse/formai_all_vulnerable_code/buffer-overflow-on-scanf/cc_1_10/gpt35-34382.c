//FormAI DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    struct node* next;
} Node;

Node* head = NULL;

void add_contact() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter phone number: ");
    scanf("%s", phone_number);
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    strcpy(new_node->phone_number, phone_number);
    new_node->next = head;
    head = new_node;
    printf("Contact added successfully!\n");
}

void search_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", name);
    Node* current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            printf("Name: %s\nEmail: %s\nPhone number: %s\n", current_node->name, current_node->email, current_node->phone_number);
            return;
        }
        current_node = current_node->next;
    }
    printf("Contact not found.\n");
}

void display_list() {
    Node* current_node = head;
    if (current_node == NULL) {
        printf("List is empty.\n");
    } else {
        printf("List of contacts:\n");
        while (current_node != NULL) {
            printf("Name: %s\nEmail: %s\nPhone number: %s\n\n", current_node->name, current_node->email, current_node->phone_number);
            current_node = current_node->next;
        }
    }
}

void delete_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    Node* current_node = head;
    Node* previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            printf("Contact deleted successfully!\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    printf("Contact not found.\n");
}

void save_list_to_file() {
    char filename[50];
    printf("Enter filename to save to: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error in opening file.\n");
        return;
    }
    Node* current_node = head;
    while (current_node != NULL) {
        fprintf(fp, "%s,%s,%s\n", current_node->name, current_node->email, current_node->phone_number);
        current_node = current_node->next;
    }
    fclose(fp);
    printf("List saved to file successfully!\n");
}

void load_list_from_file() {
    char filename[50];
    printf("Enter filename to load from: ");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error in opening file.\n");
        return;
    }
    char line[150];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* token;
        char* name;
        char* email;
        char* phone_number;
        token = strtok(line, ",");
        name = token;
        token = strtok(NULL, ",");
        email = token;
        token = strtok(NULL, ",");
        phone_number = token;
        Node* new_node = (Node*) malloc(sizeof(Node));
        strcpy(new_node->name, name);
        strcpy(new_node->email, email);
        strcpy(new_node->phone_number, phone_number);
        new_node->next = head;
        head = new_node;
    }
    fclose(fp);
    printf("List loaded from file successfully!\n");
}

int main() {
    int action = 0;
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add contact\n");
        printf("2. Search for contact\n");
        printf("3. Display list of contacts\n");
        printf("4. Delete contact\n");
        printf("5. Save list to file\n");
        printf("6. Load list from file\n");
        printf("7. Quit\n");
        printf("Enter action: ");
        scanf("%d", &action);
        switch (action) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_list();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                save_list_to_file();
                break;
            case 6:
                load_list_from_file();
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid action.\n");
        }
        printf("\n");
    }
    return 0;
}