//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    char* name;
    char* email;
    char* subject;
    char* message;
} Message;

typedef struct {
    int id;
    char* name;
    char* email;
    char* password;
    Message messages[5];
} User;

User users[100];
int numUsers = 0;

int main() {
    srand(time(NULL));
    int user_id, choice;
    char choice_string[50];

    while (1) {
        printf("\n\nWelcome to the Mailing List Manager! \n");
        printf("Enter the option you want to perform:\n1. Add a new user\n2. Add a new message\n3. Display all users\n4. Display all messages\n5. Search for a user\n6. Search for a message\n7. Exit\n\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the user's name: ");
                scanf("%s", users[numUsers].name);
                printf("Enter the user's email: ");
                scanf("%s", users[numUsers].email);
                printf("Enter the user's password: ");
                scanf("%s", users[numUsers].password);
                users[numUsers].id = numUsers;
                printf("User %d added successfully!\n", numUsers);
                break;
            case 2:
                printf("Enter the user's name: ");
                scanf("%s", users[numUsers].name);
                printf("Enter the user's email: ");
                scanf("%s", users[numUsers].email);
                printf("Enter the user's password: ");
                scanf("%s", users[numUsers].password);
                users[numUsers].id = numUsers;
                printf("User %d found!\n", numUsers);
                break;
            case 3:
                printf("Displaying all users:\n");
                for(int i=0; i<numUsers; i++) {
                    printf("User %d: %s\n", i+1, users[i].name);
                }
                break;
            case 4:
                printf("Displaying all messages:\n");
                for(int i=0; i<numUsers; i++) {
                    printf("User %d: %s\n", i+1, users[i].name);
                }
                break;
            case 5:
                printf("Enter the user's name: ");
                scanf("%s", choice_string);
                for(int i=0; i<numUsers; i++) {
                    if(strcmp(users[i].name, choice_string) == 0) {
                        printf("User %d found!\n", i+1);
                        break;
                    }
                }
                break;
            case 6:
                printf("Enter the user's name: ");
                scanf("%s", choice_string);
                for(int i=0; i<numUsers; i++) {
                    if(strcmp(users[i].name, choice_string) == 0) {
                        printf("User %d found!\n", i+1);
                        break;
                    }
                }
                printf("Enter the user's name: ");
                scanf("%s", choice_string);
                for(int i=0; i<numUsers; i++) {
                    if(strcmp(users[i].name, choice_string) == 0) {
                        printf("User %d found!\n", i+1);
                        break;
                    }
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
        printf("\n\n");
    }
    return 0;
}