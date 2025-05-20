#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define DATABASE_SIZE 1000

typedef struct {
    char name[100];
    char email[200];
} User;

int main() {
    User users[DATABASE_SIZE];
    int i, num_users;

    printf("Enter the number of users:\n");
    scanf("%d", &num_users);

    for (i = 0; i < num_users; i++) {
        printf("Enter user %d's name and email:\n", i + 1);
        scanf("%s %s", users[i].name, users[i].email);
    }

    // Invalid pointer dereference
    printf("%s %s\n", users[num_users].name, users[num_users].email);

    return 0;
}
