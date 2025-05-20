//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    int age;
} User;

FILE *fp;

int login(User *users, int count);
void registerUser(User *users, int count);
int saveData(User *users, int count);
int loadData(User *users);

int main() {
    User users[MAX_SIZE];
    int count = loadData(users);

    int choice = 0;
    do {
        printf("\nWelcome to MySecureApp\n");
        printf("Please choose an option:\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login(users, count);
                break;
            case 2:
                registerUser(users, count);
                count++;
                break;
            case 3:
                saveData(users, count);
                printf("Thank you for using MySecureApp. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (1);

    return 0;
}

int login(User *users, int count) {
    char username[MAX_SIZE];
    char password[MAX_SIZE];

    printf("Please enter your username: ");
    scanf("%s", username);

    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Please enter your password: ");
            scanf("%s", password);

            if (strcmp(users[i].password, password) == 0) {
                printf("Welcome, %s!\n", users[i].username);
                return 1;
            } else {
                printf("Incorrect password. Please try again.\n");
                return 0;
            }
        }
    }

    printf("Username not found. Please register first.\n");
    return 0;
}

void registerUser(User *users, int count) {
    printf("Please enter your username: ");
    scanf("%s", users[count].username);
    printf("Please enter your password: ");
    scanf("%s", users[count].password);
    printf("Please enter your age: ");
    scanf("%d", &users[count].age);
}

int saveData(User *users, int count) {
    fp = fopen("users.txt", "w");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%d\n", users[i].username, users[i].password, users[i].age);
    }

    fclose(fp);
    printf("Data saved to file.\n");
    return 1;
}

int loadData(User *users) {
    fp = fopen("users.txt", "r");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return 0;
    }

    int count = 0;
    char line[MAX_SIZE];
    char *token;
    while (fgets(line, MAX_SIZE, fp) != NULL) {
        token = strtok(line, ",");
        strcpy(users[count].username, token);
        token = strtok(NULL, ",");
        strcpy(users[count].password, token);
        token = strtok(NULL, ",");
        users[count].age = atoi(token);
        count++;
    }

    fclose(fp);
    printf("%d users loaded from file.\n", count);
    return count;
}