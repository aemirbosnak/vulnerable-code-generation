//Falcon-180B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USER 100
#define MAX_PASSWORD 100
#define MAX_LENGTH 100

struct user {
    char name[MAX_USER];
    char password[MAX_PASSWORD];
};

int main() {
    int num_users, i;
    char filename[MAX_USER];
    struct user users[MAX_USER];
    FILE *fp;

    printf("Enter the number of users: ");
    scanf("%d", &num_users);

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    for (i = 0; i < num_users; i++) {
        fscanf(fp, "%s %s", users[i].name, users[i].password);
    }

    fclose(fp);

    printf("Enter the username: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("User not found.\n");
        exit(1);
    }

    fscanf(fp, "%s %s", users[0].name, users[0].password);

    fclose(fp);

    printf("Enter the password: ");
    scanf("%s", users[0].password);

    if (strcmp(users[0].password, users[0].password)!= 0) {
        printf("Incorrect password.\n");
        exit(1);
    }

    printf("Welcome, %s.\n", users[0].name);

    return 0;
}