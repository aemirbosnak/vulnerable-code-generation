//Falcon-180B DATASET v1.0 Category: Password management ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char username[50];
    char password[100];
    int age;
    char gender;
}User;

void createUser(User *user) {
    printf("Enter the username: ");
    scanf("%s", user->username);
    printf("Enter the password: ");
    scanf("%s", user->password);
    printf("Enter the age: ");
    scanf("%d", &user->age);
    printf("Enter the gender (M/F): ");
    scanf(" %c", &user->gender);
}

void displayUser(User user) {
    printf("\nUsername: %s", user.username);
    printf("\nPassword: %s", user.password);
    printf("\nAge: %d", user.age);
    printf("\nGender: %c", user.gender);
}

int main() {
    User user;
    char choice;
    int flag = 0;

    do {
        printf("\n\n*********PASSWORD MANAGER*********\n");
        printf("\n1. Create User\n2. Display User\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createUser(&user);
                printf("\nUser created successfully!\n");
                break;
            case 2:
                if(flag == 1) {
                    displayUser(user);
                } else {
                    printf("\nNo user created yet!\n");
                }
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}