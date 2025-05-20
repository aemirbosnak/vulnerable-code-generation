//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER 100
#define MAX_PASSWORD 100
#define MAX_LOGIN 100
#define MAX_EMAIL 100
#define MAX_PHONE 100

struct user {
    char username[MAX_USER];
    char password[MAX_PASSWORD];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
};

void create_user(struct user *user) {
    printf("Enter username: ");
    scanf("%s", user->username);
    printf("Enter password: ");
    scanf("%s", user->password);
    printf("Enter email: ");
    scanf("%s", user->email);
    printf("Enter phone: ");
    scanf("%s", user->phone);
}

void print_user(struct user user) {
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
    printf("Email: %s\n", user.email);
    printf("Phone: %s\n", user.phone);
}

int main() {
    FILE *file;
    struct user user;
    char filename[MAX_USER];
    int choice;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "a+");
    if (file == NULL) {
        printf("File does not exist. Creating new file.\n");
        file = fopen(filename, "w+");
    }

    while (1) {
        printf("\n1. Create user\n2. Print users\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_user(&user);
                fseek(file, 0, SEEK_END);
                fwrite(&user, sizeof(struct user), 1, file);
                printf("User created successfully.\n");
                break;
            case 2:
                fseek(file, 0, SEEK_SET);
                while (fread(&user, sizeof(struct user), 1, file) == 1) {
                    print_user(user);
                }
                break;
            case 3:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}