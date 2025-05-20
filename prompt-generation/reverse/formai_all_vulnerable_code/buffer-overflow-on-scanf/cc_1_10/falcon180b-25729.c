//Falcon-180B DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[50];
    char email[100];
    time_t reg_time;
} User;

int main() {
    User users[100];
    int num_users = 0;
    char choice;
    int id;
    FILE *fp;

    do {
        system("clear");
        printf("Welcome to the Email Client!\n");
        printf("Please choose an option:\n");
        printf("1. Sign up\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (num_users >= 100) {
                    printf("Sorry, the system is full.\n");
                } else {
                    printf("Enter your name:\n");
                    scanf("%s", users[num_users].name);
                    printf("Enter your email:\n");
                    scanf("%s", users[num_users].email);
                    time(&users[num_users].reg_time);
                    num_users++;
                    printf("Registration successful!\n");
                }
                break;
            case '2':
                printf("Enter your email:\n");
                scanf("%s", users[0].email);
                for (int i = 1; i < num_users; i++) {
                    if (strcmp(users[i].email, users[0].email) == 0) {
                        printf("Welcome back, %s!\n", users[i].name);
                        id = i;
                        break;
                    }
                }
                if (id == 0) {
                    printf("Invalid email.\n");
                }
                break;
            case '3':
                printf("Thank you for using the Email Client.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}