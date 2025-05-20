//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} User;

void handle_memory_error(void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void handle_file_error(FILE* file, const char* filepath) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s.\n", filepath);
        exit(EXIT_FAILURE);
    }
}

void read_users(User* users, int* count) {
    FILE* file = fopen("users.txt", "r");
    handle_file_error(file, "users.txt");

    *count = 0;
    while (*count < MAX_USERS && fscanf(file, "%d %49s %d", 
                                          &users[*count].id, 
                                          users[*count].name, 
                                          &users[*count].age) == 3) {
        (*count)++;
    }

    fclose(file);
}

void write_users(User* users, int count) {
    FILE* file = fopen("users.txt", "w");
    handle_file_error(file, "users.txt");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d\n", users[i].id, users[i].name, users[i].age);
    }

    fclose(file);
}

void add_user(User* users, int* count) {
    if (*count >= MAX_USERS) {
        fprintf(stderr, "User limit reached. Cannot add more users.\n");
        return;
    }

    User new_user;
    printf("Enter ID: ");
    scanf("%d", &new_user.id);
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter age: ");
    scanf("%d", &new_user.age);

    users[*count] = new_user;
    (*count)++;
    write_users(users, *count);
}

void delete_user(User* users, int* count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (users[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                users[j] = users[j + 1];
            }
            (*count)--;
            break;
        }
    }
    if (found) {
        write_users(users, *count);
    } else {
        fprintf(stderr, "User with ID %d not found.\n", id);
    }
}

void list_users(User* users, int count) {
    printf("User List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", users[i].id, users[i].name, users[i].age);
    }
}

int main() {
    User* users = (User*)malloc(MAX_USERS * sizeof(User));
    handle_memory_error(users);

    int user_count = 0;
    read_users(users, &user_count);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user(users, &user_count);
                break;
            case 2: {
                int id;
                printf("Enter ID of user to delete: ");
                scanf("%d", &id);
                delete_user(users, &user_count, id);
                break;
            }
            case 3:
                list_users(users, user_count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    free(users);
    return 0;
}