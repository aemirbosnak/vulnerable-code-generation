//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50

typedef struct user {
    int id;
    char name[50];
    int age;
} User;

int count = 0;
User users[MAX_USERS];

void insert_user() {
    User new_user;
    printf("Enter user name: ");
    scanf("%s", new_user.name);
    printf("Enter user age: ");
    scanf("%d", &new_user.age);

    new_user.id = ++count;
    users[count - 1] = new_user;
    printf("User added with id: %d\n", new_user.id);
}

void view_user() {
    printf("Enter user id: ");
    int id;
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Invalid user id\n");
        return;
    }

    printf("ID  | Name      | Age\n");
    printf("%-3d | %-9s | %d\n", users[id-1].id, users[id-1].name, users[id-1].age);
}

void list_users() {
    if (count == 0) {
        printf("No users found\n");
        return;
    }
    printf("ID  | Name      | Age\n");
    for (int i = 0; i < count; i++) {
        printf("%-3d | %-9s | %d\n", users[i].id, users[i].name, users[i].age);
    }
}

void search_user() {
    printf("Enter search query: ");
    char query[50];
    scanf("%s", query);

    int results[MAX_USERS];
    int results_count = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(users[i].name, query)) {
            results[results_count++] = i;
        }
    }

    if (results_count == 0) {
        printf("No results found\n");
        return;
    }

    printf("ID  | Name      | Age\n");
    for (int i = 0; i < results_count; i++) {
        printf("%-3d | %-9s | %d\n", users[results[i]].id, users[results[i]].name, users[results[i]].age);
    }
}

void delete_user() {
    printf("Enter user id: ");
    int id;
    scanf("%d", &id);

    if (id < 1 || id > count) {
        printf("Invalid user id\n");
        return;
    }

    User deleted_user = users[id - 1];
    for (int i = id - 1; i < count - 1; i++) {
        users[i] = users[i + 1];
        users[i].id--;
    }
    count--;

    printf("User with id %d deleted\n", id);
}

int main() {
    int option;
    do {
        printf("\nChoose option:\n");
        printf("1. Insert user\n");
        printf("2. View user\n");
        printf("3. List users\n");
        printf("4. Search users\n");
        printf("5. Delete user\n");
        printf("0. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1: insert_user(); break;
            case 2: view_user(); break;
            case 3: list_users(); break;
            case 4: search_user(); break;
            case 5: delete_user(); break;
            case 0: break;
            default: printf("Invalid option\n");
        }
    } while (option != 0);

    return 0;
}