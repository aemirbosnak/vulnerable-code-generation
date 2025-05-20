//Falcon-180B DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char username[50];
    char password[50];
} account;

int main() {
    int choice, row = 0;
    FILE *fp;
    account user;

    fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%s", user.username);

    while (fscanf(fp, "%s %s", user.username, user.password)!= EOF) {
        if (strcmp(user.username, user.username) == 0) {
            printf("Password: %s\n", user.password);
            break;
        }
        row++;
    }

    fclose(fp);

    if (strcmp(user.username, user.username)!= 0) {
        printf("Error: Username not found\n");
        exit(1);
    }

    printf("1. Change password\n");
    printf("2. View password\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new password: ");
            scanf("%s", user.password);
            row = 0;
            fp = fopen("accounts.txt", "r+");
            while (fscanf(fp, "%s %s", user.username, user.password)!= EOF) {
                if (strcmp(user.username, user.username) == 0) {
                    fprintf(fp, "%s %s\n", user.username, user.password);
                    break;
                }
                row++;
            }
            fclose(fp);
            printf("Password changed successfully\n");
            break;
        case 2:
            printf("Password: %s\n", user.password);
            break;
        case 3:
            exit(0);
        default:
            printf("Error: Invalid choice\n");
            break;
    }

    return 0;
}