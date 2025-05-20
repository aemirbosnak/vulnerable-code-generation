//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
} user;

int main() {
    int choice, i = 0;
    char filename[30] = "users.txt";
    user users[100];
    FILE *fp;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File does not exist!\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", users[i].username, users[i].password)!= EOF) {
        i++;
    }

    fclose(fp);

    do {
        printf("\n\nWelcome to Password Manager!\n");
        printf("1. Add a new user\n");
        printf("2. Edit an existing user\n");
        printf("3. Delete a user\n");
        printf("4. View all users\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a new username: ");
                scanf("%s", users[i].username);
                printf("Enter a new password: ");
                scanf("%s", users[i].password);
                fprintf(fp, "%s %s\n", users[i].username, users[i].password);
                printf("\nUser added successfully!\n");
                break;

            case 2:
                printf("Enter the username to edit: ");
                scanf("%s", users[i].username);
                printf("Enter a new password: ");
                scanf("%s", users[i].password);
                fprintf(fp, "%s %s\n", users[i].username, users[i].password);
                printf("\nUser edited successfully!\n");
                break;

            case 3:
                printf("Enter the username to delete: ");
                scanf("%s", users[i].username);
                fprintf(fp, "%s %s\n", users[i].username, " ");
                printf("\nUser deleted successfully!\n");
                break;

            case 4:
                printf("\nList of all users:\n");
                rewind(fp);
                while (fscanf(fp, "%s %s", users[i].username, users[i].password)!= EOF) {
                    printf("%s - %s\n", users[i].username, users[i].password);
                    i++;
                }
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

        fclose(fp);
        fp = fopen(filename, "w");
        for (int j = 0; j < i; j++) {
            fprintf(fp, "%s %s\n", users[j].username, users[j].password);
        }
        fclose(fp);
    } while (choice!= 5);

    return 0;
}