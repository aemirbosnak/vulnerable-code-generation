//Falcon-180B DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_USER_NAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 64
#define MAX_GROUP_NAME_LENGTH 64
#define MAX_GROUP_MEMBERS 100

typedef struct {
    char name[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int uid;
    int gid;
    char groups[MAX_GROUP_MEMBERS][MAX_GROUP_NAME_LENGTH];
    int num_groups;
} user_t;

typedef struct {
    char name[MAX_GROUP_NAME_LENGTH];
    int gid;
    int num_users;
    char users[MAX_GROUP_MEMBERS][MAX_USER_NAME_LENGTH];
} group_t;

int main() {
    char username[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int uid;
    int gid;
    char groups[MAX_GROUP_MEMBERS][MAX_GROUP_NAME_LENGTH];
    int num_groups;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter UID: ");
    scanf("%d", &uid);

    printf("Enter GID: ");
    scanf("%d", &gid);

    printf("Enter number of groups: ");
    scanf("%d", &num_groups);

    for (int i = 0; i < num_groups; i++) {
        printf("Enter group name: ");
        scanf("%s", groups[i]);
    }

    user_t user = {
       .name = username,
       .password = password,
       .uid = uid,
       .gid = gid,
       .num_groups = num_groups,
    };

    for (int i = 0; i < num_groups; i++) {
        strcat(user.groups[i], ",");
        strcat(user.groups[i], groups[i]);
    }

    printf("User created successfully.\n");

    return 0;
}