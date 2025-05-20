//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define structure to store passwords
struct Password {
    char title[50];
    char username[50];
    char password[50];
};

//Define function to display menu
void display_menu() {
    printf("\nPassword Manager\n");
    printf("----------------\n");
    printf("1. Add a Password\n");
    printf("2. View Passwords\n");
    printf("3. Search Passwords\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n\n");
}

int main() {
    int choice;
    int count = 0;
    int i;
    char search_title[50];
    struct Password passwords[50]; //maximum 50 passwords can be stored

    display_menu();

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Details:\n");
                printf("Title: ");
                scanf("%s", passwords[count].title);
                printf("Username: ");
                scanf("%s", passwords[count].username);
                printf("Password: ");
                scanf("%s", passwords[count].password);
                printf("Password added successfully!\n");
                count++;
                break;
            case 2:
                printf("\nList of saved passwords:\n");
                printf("------------------------\n");
                for (i = 0; i < count; i++) {
                    printf("Title: %s\n", passwords[i].title);
                    printf("Username: %s\n", passwords[i].username);
                    printf("Password: %s\n", passwords[i].password);
                    printf("------------------------\n");
                }
                break;
            case 3:
                printf("\nEnter the title of the password to search: ");
                scanf("%s", search_title);
                for (i = 0; i < count; i++) {
                    if (strcmp(search_title, passwords[i].title) == 0) {
                        printf("\nTitle: %s\n", passwords[i].title);
                        printf("Username: %s\n", passwords[i].username);
                        printf("Password: %s\n", passwords[i].password);
                        break;
                    }
                }
                if (i == count) {
                    printf("\nPassword not found!\n");
                }
                break;
            case 4:
                printf("\nEnter the title of the password to delete: ");
                scanf("%s", search_title);
                for (i = 0; i < count; i++) {
                    if (strcmp(search_title, passwords[i].title) == 0) {
                        strcpy(passwords[i].title, "");
                        strcpy(passwords[i].username, "");
                        strcpy(passwords[i].password, "");
                        printf("\nPassword deleted!\n");
                        break;
                    }
                }
                if (i == count) {
                    printf("\nPassword not found!\n");
                }
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}