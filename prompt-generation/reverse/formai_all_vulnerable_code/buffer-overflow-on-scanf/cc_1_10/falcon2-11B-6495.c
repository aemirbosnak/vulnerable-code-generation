//Falcon2-11B DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char username[20];
    char password[20];
    char email[50];
} User;

int main() {
    User users[10];
    int numUsers = 0;
    int i;

    printf("Enter the number of users: ");
    scanf("%d", &numUsers);

    if (numUsers > 10) {
        printf("Number of users exceeds maximum allowed.\n");
        return 1;
    }

    for (i = 0; i < numUsers; i++) {
        printf("User %d:", i + 1);
        fflush(stdout);

        users[i].id = i + 1;

        printf("Username: ");
        fflush(stdout);
        scanf("%s", users[i].username);

        printf("Password: ");
        fflush(stdout);
        scanf("%s", users[i].password);

        printf("Email: ");
        fflush(stdout);
        scanf("%s", users[i].email);
    }

    printf("\nUser Details:\n");
    for (i = 0; i < numUsers; i++) {
        printf("%d - %s (%s) %s\n", users[i].id, users[i].username, users[i].email, users[i].password);
    }

    return 0;
}