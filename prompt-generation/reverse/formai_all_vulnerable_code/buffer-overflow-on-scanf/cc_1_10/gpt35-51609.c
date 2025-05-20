//FormAI DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct User {
    char name[MAX_SIZE];
    int age;
    float balance;
};

struct User_list {
    struct User users[MAX_SIZE];
    int count;
};

void add_user(struct User_list* list, char* name, int age, float balance) {
    if (list->count < MAX_SIZE) {
        struct User user;
        strncpy(user.name, name, MAX_SIZE);
        user.age = age;
        user.balance = balance;
        list->users[list->count++] = user;
        printf("User added!\n");
    } else {
        printf("List is full, cannot add more users.\n");
    }
}

void remove_user(struct User_list* list, char* name) {
    int index = -1;
    for (int i = 0; i < list->count; i++) {
        if (strncmp(list->users[i].name, name, MAX_SIZE) == 0) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        for (int i = index; i < list->count - 1; i++) {
            list->users[i] = list->users[i+1];
        }
        list->count--;
        printf("User removed!\n");
    } else {
        printf("User not found.\n");
    }
}

void print_user(struct User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Balance: %.2f\n", user.balance);
}

void print_users(struct User_list* list) {
    printf("User list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. ", i+1);
        print_user(list->users[i]);
        printf("\n");
    }
}

int main() {
    struct User_list list;
    list.count = 0;

    printf("Welcome to the User Database Simulation Program.\n");
    printf("Please enter the command 'add', 'remove', or 'print'.\n");

    char command[MAX_SIZE];
    while (1) {
        printf("\n> ");
        scanf("%s", command);

        if (strncmp(command, "add", MAX_SIZE) == 0) {
            char name[MAX_SIZE];
            int age;
            float balance;
            printf("Enter the name of the user: ");
            scanf("%s", name);
            printf("Enter the age of the user: ");
            scanf("%d", &age);
            printf("Enter the balance of the user: ");
            scanf("%f", &balance);
            add_user(&list, name, age, balance);
        } else if (strncmp(command, "remove", MAX_SIZE) == 0) {
            char name[MAX_SIZE];
            printf("Enter the name of the user to remove: ");
            scanf("%s", name);
            remove_user(&list, name);
        } else if (strncmp(command, "print", MAX_SIZE) == 0) {
            print_users(&list);
        } else {
            printf("Invalid command. Please enter 'add', 'remove', or 'print'.\n");
        }
    }

    return 0;
}