//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define FILE_NAME "users.dat"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} User;

void write_user_to_file(FILE *file, User user) {
    fwrite(&user, sizeof(User), 1, file);
}

void read_user_from_file(FILE *file, User *user) {
    fread(user, sizeof(User), 1, file);
}

void show_user(User user) {
    printf("ID: %d\nName: %s\nAge: %d\n", user.id, user.name, user.age);
}

void create_user() {
    User user;
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    
    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);
    
    write_user_to_file(file, user);
    fclose(file);
    printf("User created successfully!\n");
}

void display_all_users() {
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }
    
    printf("List of Users:\n");
    while (fread(&user, sizeof(User), 1, file)) {
        show_user(user);
        printf("\n");
    }
    fclose(file);
}

void search_user() {
    int id, found = 0;
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }
    
    printf("Enter User ID to search: ");
    scanf("%d", &id);
    
    while (fread(&user, sizeof(User), 1, file)) {
        if (user.id == id) {
            show_user(user);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("User with ID %d not found.\n", id);
    }
    
    fclose(file);
}

void update_user() {
    int id, found = 0;
    User user;
    FILE *file = fopen(FILE_NAME, "rb+"); // Open for reading and writing
    
    if (!file) {
        perror("Failed to open file for reading");
        return;
    }
    
    printf("Enter User ID to update: ");
    scanf("%d", &id);
    
    while (fread(&user, sizeof(User), 1, file)) {
        if (user.id == id) {
            printf("Enter new Name: ");
            scanf("%s", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
            
            fseek(file, -sizeof(User), SEEK_CUR); // Move file pointer back to update
            write_user_to_file(file, user);
            found = 1;
            printf("User updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("User with ID %d not found.\n", id);
    }
    
    fclose(file);
}

void delete_user() {
    int id, found = 0;
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *temp_file = fopen("temp.dat", "wb");
    
    if (!file || !temp_file) {
        perror("Failed to open files");
        return;
    }
    
    printf("Enter User ID to delete: ");
    scanf("%d", &id);
    
    while (fread(&user, sizeof(User), 1, file)) {
        if (user.id == id) {
            found = 1;
            printf("User with ID %d deleted successfully!\n", id);
        } else {
            write_user_to_file(temp_file, user);
        }
    }
    
    fclose(file);
    fclose(temp_file);
    
    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
    } else {
        remove("temp.dat");
        printf("User with ID %d not found.\n", id);
    }
}

void display_menu() {
    printf("\nUser Management System\n");
    printf("1. Create User\n");
    printf("2. Display All Users\n");
    printf("3. Search User\n");
    printf("4. Update User\n");
    printf("5. Delete User\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                display_all_users();
                break;
            case 3:
                search_user();
                break;
            case 4:
                update_user();
                break;
            case 5:
                delete_user();
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}