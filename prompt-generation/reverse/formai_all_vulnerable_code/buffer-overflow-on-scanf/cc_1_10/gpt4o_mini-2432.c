//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define MAX_USERS 100

typedef struct User {
    char name[NAME_LENGTH];
    int age;
} User;

typedef struct UserList {
    User *users;
    int count;
} UserList;

UserList* createUserList() {
    UserList *list = malloc(sizeof(UserList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for UserList\n");
        exit(EXIT_FAILURE);
    }
    list->users = malloc(MAX_USERS * sizeof(User));
    if (!list->users) {
        fprintf(stderr, "Memory allocation failed for users array\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->count = 0;
    return list;
}

void freeUserList(UserList *list) {
    if (list) {
        free(list->users);
        free(list);
    }
}

void addUser(UserList *list, const char *name, int age) {
    if (list->count >= MAX_USERS) {
        fprintf(stderr, "User list is full, cannot add more users\n");
        return;
    }
    strncpy(list->users[list->count].name, name, NAME_LENGTH - 1);
    list->users[list->count].name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    list->users[list->count].age = age;
    list->count++;
}

void printUsers(const UserList *list) {
    printf("User List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Age: %d\n", list->users[i].name, list->users[i].age);
    }
}

void readUserData(UserList *list) {
    char name[NAME_LENGTH];
    int age;
    
    while (list->count < MAX_USERS) {
        printf("Enter name (or type 'exit' to finish): ");
        fgets(name, NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        
        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        if (scanf("%d", &age) != 1) {
            fprintf(stderr, "Invalid age entered, please enter a number.\n");
            // Clear the input buffer
            while(getchar() != '\n');
            continue;
        }
        getchar(); // Clear the newline character after scanf
        addUser(list, name, age);
    }
}

int main() {
    UserList *myUsers = createUserList();
    
    readUserData(myUsers);
    
    printUsers(myUsers);
    
    freeUserList(myUsers);
    
    return 0;
}