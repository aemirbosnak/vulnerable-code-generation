//FormAI DATASET v1.0 Category: Mailing list manager ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Person {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Person *next;
} Person;

Person *head = NULL;

void add_person(char *name, char *email) {
    Person *new_person = malloc(sizeof(Person));
    if (new_person == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    strncpy(new_person->name, name, MAX_NAME_LENGTH);
    strncpy(new_person->email, email, MAX_EMAIL_LENGTH);
    new_person->next = NULL;
    if (head == NULL) {
        head = new_person;
    } else {
        Person *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_person;
    }
}

void delete_person(char *name, char *email) {
    if (head == NULL) {
        fprintf(stderr, "Error: List is empty\n");
        return;
    }
    if (strcmp(head->name, name) == 0 && strcmp(head->email, email) == 0) {
        Person *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Person *temp = head;
    while (temp->next != NULL) {
        if (strcmp(temp->next->name, name) == 0 && strcmp(temp->next->email, email) == 0) {
            Person *to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
            return;
        }
        temp = temp->next;
    }
    fprintf(stderr, "Error: Person not found\n");
}

void print_list() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List of people:\n");
    Person *temp = head;
    while (temp != NULL) {
        printf("%s - %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

void save_list(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        return;
    }
    Person *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s,%s\n", temp->name, temp->email);
        temp = temp->next;
    }
    fclose(file);
}

void load_list(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file\n");
        return;
    }
    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *comma = strchr(line, ',');
        if (comma == NULL || comma == line) {
            fprintf(stderr, "Error: Invalid data format\n");
            continue;
        }
        char name[MAX_NAME_LENGTH];
        char email[MAX_EMAIL_LENGTH];
        strncpy(name, line, comma - line);
        name[comma - line] = '\0';
        strncpy(email, comma + 1, MAX_EMAIL_LENGTH);
        email[strcspn(email, "\r\n")] = '\0'; // remove trailing newline
        add_person(name, email);
    }
    fclose(file);
}

int main() {
    char command;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char filename[MAX_NAME_LENGTH];
    while (1) {
        printf("Enter a command (a: add, d: delete, p: print, s: save, l: load, q: quit): ");
        scanf(" %c", &command);
        switch (command) {
            case 'a':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_person(name, email);
                break;
            case 'd':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                delete_person(name, email);
                break;
            case 'p':
                print_list();
                break;
            case 's':
                printf("Enter filename: ");
                scanf("%s", filename);
                save_list(filename);
                break;
            case 'l':
                printf("Enter filename: ");
                scanf("%s", filename);
                load_list(filename);
                break;
            case 'q':
                return 0;
            default:
                printf("Unknown command\n");
        }
    }
    return 0;
}