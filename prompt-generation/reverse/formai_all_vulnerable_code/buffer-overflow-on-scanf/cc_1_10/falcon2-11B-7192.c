//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char roll_no[10];
    char password[10];
};

int main() {
    struct Student students[5] = {
        {"John", "1234", "password1"},
        {"Mark", "5678", "password2"},
        {"Lisa", "9101", "password3"},
        {"Tom", "6543", "password4"},
        {"Jane", "7890", "password5"}
    };

    int choice;
    char user_name[50];
    char user_password[10];

    do {
        printf("Welcome to the Online Examination System!\n");
        printf("Enter your name: ");
        scanf("%s", user_name);
        printf("Enter your password: ");
        scanf("%s", user_password);

        int i;
        for (i = 0; i < 5; i++) {
            if (strcmp(students[i].name, user_name) == 0 && strcmp(students[i].password, user_password) == 0) {
                printf("Welcome back, %s!\n", students[i].name);
                break;
            }
        }

        if (i == 5) {
            printf("Invalid username or password!\n");
        }

        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                printf("Thank you for using the Online Examination System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}