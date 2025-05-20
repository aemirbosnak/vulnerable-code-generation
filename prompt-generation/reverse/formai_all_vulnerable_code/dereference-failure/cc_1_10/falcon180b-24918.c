//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct password {
    char password[MAX_PASSWORD_LENGTH];
    int id;
    struct password* next;
};

struct password* create_password(char* password, int id) {
    struct password* new_password = (struct password*)malloc(sizeof(struct password));
    strcpy(new_password->password, password);
    new_password->id = id;
    new_password->next = NULL;
    return new_password;
}

struct password* add_password(struct password* head, char* password, int id) {
    struct password* new_password = create_password(password, id);
    if (head == NULL) {
        head = new_password;
        return head;
    }
    struct password* current_password = head;
    while (current_password->next!= NULL) {
        current_password = current_password->next;
    }
    current_password->next = new_password;
    return head;
}

void remove_password(struct password** head, int id) {
    if (*head == NULL) {
        return;
    }
    struct password* current_password = *head;
    if (current_password->id == id) {
        *head = current_password->next;
        free(current_password);
        return;
    }
    while (current_password->next!= NULL && current_password->next->id!= id) {
        current_password = current_password->next;
    }
    if (current_password->next == NULL) {
        return;
    }
    struct password* temp_password = current_password->next;
    current_password->next = current_password->next->next;
    free(temp_password);
}

void print_passwords(struct password* head) {
    if (head == NULL) {
        printf("No passwords found.\n");
        return;
    }
    struct password* current_password = head;
    while (current_password!= NULL) {
        printf("ID: %d, Password: %s\n", current_password->id, current_password->password);
        current_password = current_password->next;
    }
}

int main() {
    struct password* head = NULL;
    head = add_password(head, "password1", 1);
    head = add_password(head, "password2", 2);
    head = add_password(head, "password3", 3);
    print_passwords(head);
    remove_password(&head, 2);
    print_passwords(head);
    return 0;
}