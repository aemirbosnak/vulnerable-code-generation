//Code Llama-13B DATASET v1.0 Category: System administration ; Style: scientific
// C System administration example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_USERS 100
#define MAX_FILES 100

// Define structures
struct user {
    char name[100];
    int user_id;
    int age;
    char email[100];
};

struct file {
    char name[100];
    int file_id;
    char type[100];
    int size;
};

// Define functions
void add_user(struct user* users, int* num_users) {
    // Prompt user for information
    printf("Enter user name: ");
    scanf("%s", users[*num_users].name);
    printf("Enter user ID: ");
    scanf("%d", &users[*num_users].user_id);
    printf("Enter user age: ");
    scanf("%d", &users[*num_users].age);
    printf("Enter user email: ");
    scanf("%s", users[*num_users].email);

    // Increment number of users
    *num_users += 1;
}

void add_file(struct file* files, int* num_files) {
    // Prompt user for information
    printf("Enter file name: ");
    scanf("%s", files[*num_files].name);
    printf("Enter file ID: ");
    scanf("%d", &files[*num_files].file_id);
    printf("Enter file type: ");
    scanf("%s", files[*num_files].type);
    printf("Enter file size: ");
    scanf("%d", &files[*num_files].size);

    // Increment number of files
    *num_files += 1;
}

void print_users(struct user* users, int num_users) {
    // Print header
    printf("User Name\tUser ID\tAge\tEmail\n");

    // Print each user
    for (int i = 0; i < num_users; i++) {
        printf("%s\t%d\t%d\t%s\n", users[i].name, users[i].user_id, users[i].age, users[i].email);
    }
}

void print_files(struct file* files, int num_files) {
    // Print header
    printf("File Name\tFile ID\tType\tSize\n");

    // Print each file
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%d\t%s\t%d\n", files[i].name, files[i].file_id, files[i].type, files[i].size);
    }
}

int main() {
    // Initialize variables
    struct user users[MAX_USERS];
    struct file files[MAX_FILES];
    int num_users = 0;
    int num_files = 0;

    // Add users and files
    add_user(users, &num_users);
    add_file(files, &num_files);
    add_user(users, &num_users);
    add_file(files, &num_files);

    // Print users and files
    print_users(users, num_users);
    print_files(files, num_files);

    return 0;
}