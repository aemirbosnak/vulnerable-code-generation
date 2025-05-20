//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_FILENAME_LENGTH 100

struct Person {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct Node {
    struct Person person;
    struct Node *next;
};

void display_menu();
void add_person(struct Node **head);
void delete_person(struct Node **head);
void view_all(struct Node **head);
void save_list(struct Node **head, const char *filename);
void load_list(struct Node **head, const char *filename);
void free_list(struct Node **head);

int main() {
    struct Node *head = NULL;
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    while (choice != 6) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_person(&head);
                break;
            case 2:
                delete_person(&head);
                break;
            case 3:
                view_all(&head);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", filename);
                save_list(&head, filename);
                break;
            case 5:
                printf("Enter file name: ");
                scanf("%s", filename);
                load_list(&head, filename);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free_list(&head);
    return 0; 
}

void display_menu() {
    printf("\n1. Add person\n");
    printf("2. Delete person\n");
    printf("3. View all\n");
    printf("4. Save list\n");
    printf("5. Load list\n");
    printf("6. Exit\n");
}

void add_person(struct Node **head) {
    struct Person new_person;
    struct Node *new_node = malloc(sizeof(struct Node));
    
    printf("\nEnter person's name: ");
    scanf("%s", new_person.name);
    printf("Enter person's email: ");
    scanf("%s", new_person.email);

    if (!new_node) {
        printf("\nError: memory allocation failed\n");
        return;
    }

    strcpy(new_node->person.name, new_person.name);
    strcpy(new_node->person.email, new_person.email);
    new_node->next = *head;
    *head = new_node;
}

void delete_person(struct Node **head) {
    char name_to_delete[MAX_NAME_LENGTH];
    struct Node *temp = *head;
    struct Node *prev_node = NULL;

    printf("\nEnter person's name to delete: ");
    scanf("%s", name_to_delete);

    while (temp) {
        if (strcmp(temp->person.name, name_to_delete) == 0) {
            if (prev_node) {
                prev_node->next = temp->next;
            } else {
                *head = temp->next;
            }

            free(temp);
            printf("%s has been successfully deleted from the list.\n", name_to_delete);
            return;
        }
        prev_node = temp;
        temp = temp->next;
    }
    printf("%s not found in the list.\n", name_to_delete);
}

void view_all(struct Node **head) {
    struct Node *temp = *head;

    printf("\nNAME\t\tEMAIL\n");
    while (temp) {
        printf("%s\t\t%s\n", temp->person.name, temp->person.email);
        temp = temp->next;
    }
}

void save_list(struct Node **head, const char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (!fp) {
        printf("\nError: could not open the file\n");
        return;
    }

    struct Node *temp = *head;
    while (temp) {
        fwrite(&(temp->person), sizeof(struct Person), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
    printf("\nList saved successfully to file %s.\n", filename);
}

void load_list(struct Node **head, const char *filename) {
    FILE *fp = fopen(filename, "rb");

    if (!fp) {
        printf("\nError: could not open the file\n");
        return;
    }

    struct Person new_person;
    struct Node *new_node = NULL;
    *head = NULL;

    while (fread(&new_person, sizeof(struct Person), 1, fp) == 1) {
        new_node = malloc(sizeof(struct Node));
        if (!new_node) {
            printf("\nError: memory allocation failed\n");
            fclose(fp);
            free_list(head);
            return;
        }
        strcpy(new_node->person.name, new_person.name);
        strcpy(new_node->person.email, new_person.email);
        new_node->next = *head;
        *head = new_node;
    }

    fclose(fp);
    printf("\nList loaded successfully from file %s.\n", filename);
}

void free_list(struct Node **head) {
    struct Node *temp = *head;

    while (temp) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}