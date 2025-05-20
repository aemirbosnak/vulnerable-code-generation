//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/* This C program simulates a basic system administration tool for managing user accounts */

/* Define a struct to represent a user account */
struct user {
    char name[20];
    int uid;
    int gid;
};

/* Define an array to store the users */
struct user users[100];

/* Define a function to add a new user */
void add_user(char name[], int uid, int gid) {
    int i;
    /* Find the first empty slot in the array */
    for (i = 0; i < 100; i++) {
        if (users[i].uid == 0) {
            /* Copy the information into the new slot */
            strncpy(users[i].name, name, 20);
            users[i].uid = uid;
            users[i].gid = gid;
            printf("User %s added!\n", name);
            return;
        }
    }
    /* If the array is full, print an error message */
    printf("Error: no more room for users!\n");
}

/* Define a function to remove a user by name */
void remove_user(char name[]) {
    int i;
    /* Find the user with the given name and remove them */
    for (i = 0; i < 100; i++) {
        if (strcmp(users[i].name, name) == 0) {
            /* Reset their information */
            strcpy(users[i].name, "");
            users[i].uid = 0;
            users[i].gid = 0;
            printf("User %s removed!\n", name);
            return;
        }
    }
    /* If the user is not found, print an error message */
    printf("Error: user not found!\n");
}

/* Define a function to display the list of users */
void list_users() {
    int i;
    /* Print the header row */
    printf("%-20s\t%-10s\t%-10s\n", "Name", "UID", "GID");
    /* Loop through the users and print their information */
    for (i = 0; i < 100; i++) {
        if (users[i].uid != 0) {
            printf("%-20s\t%-10d\t%-10d\n", users[i].name, users[i].uid, users[i].gid);
        }
    }
}

/* Define the main function */
int main() {
    char command[20], name[20];
    int uid, gid;
    /* Loop indefinitely to accept user input */
    while (1) {
        /* Print the prompt */
        printf("admin> ");
        /* Read the command and parse it */
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            /* Read the arguments and call the add_user function */
            scanf("%s %d %d", name, &uid, &gid);
            add_user(name, uid, gid);
        } else if (strcmp(command, "remove") == 0) {
            /* Read the argument and call the remove_user function */
            scanf("%s", name);
            remove_user(name);
        } else if (strcmp(command, "list") == 0) {
            /* Call the list_users function */
            list_users();
        } else if (strcmp(command, "exit") == 0) {
            /* Exit the program */
            printf("Goodbye!\n");
            exit(0);
        } else {
            /* If the command is not recognized, print an error message */
            printf("Error: unknown command \"%s\".\n", command);
        }
    }
    /* Return success */
    return 0;
}