//Code Llama-13B DATASET v1.0 Category: System administration ; Style: decentralized
/*
 * Program: decentralized_admin.c
 * Author: [Your Name]
 * Description: A decentralized system administration program in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the nodes in the system
struct Node {
    char name[100];
    char ip_address[100];
    char mac_address[100];
    struct Node *next;
};

// Define the struct for the users in the system
struct User {
    char username[100];
    char password[100];
    struct User *next;
};

// Define the struct for the system administration
struct SystemAdministration {
    struct Node *nodes;
    struct User *users;
};

// Function to add a node to the system
void addNode(struct SystemAdministration *admin, char *name, char *ip_address, char *mac_address) {
    struct Node *node = malloc(sizeof(struct Node));
    strcpy(node->name, name);
    strcpy(node->ip_address, ip_address);
    strcpy(node->mac_address, mac_address);
    node->next = admin->nodes;
    admin->nodes = node;
}

// Function to remove a node from the system
void removeNode(struct SystemAdministration *admin, char *name) {
    struct Node *node = admin->nodes;
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            struct Node *temp = node;
            node = node->next;
            free(temp);
            continue;
        }
        node = node->next;
    }
}

// Function to add a user to the system
void addUser(struct SystemAdministration *admin, char *username, char *password) {
    struct User *user = malloc(sizeof(struct User));
    strcpy(user->username, username);
    strcpy(user->password, password);
    user->next = admin->users;
    admin->users = user;
}

// Function to remove a user from the system
void removeUser(struct SystemAdministration *admin, char *username) {
    struct User *user = admin->users;
    while (user != NULL) {
        if (strcmp(user->username, username) == 0) {
            struct User *temp = user;
            user = user->next;
            free(temp);
            continue;
        }
        user = user->next;
    }
}

// Function to print the nodes in the system
void printNodes(struct SystemAdministration *admin) {
    struct Node *node = admin->nodes;
    while (node != NULL) {
        printf("%s (%s, %s)\n", node->name, node->ip_address, node->mac_address);
        node = node->next;
    }
}

// Function to print the users in the system
void printUsers(struct SystemAdministration *admin) {
    struct User *user = admin->users;
    while (user != NULL) {
        printf("%s (%s)\n", user->username, user->password);
        user = user->next;
    }
}

// Main function
int main() {
    // Create the system administration
    struct SystemAdministration admin;
    admin.nodes = NULL;
    admin.users = NULL;

    // Add some nodes and users to the system
    addNode(&admin, "Node1", "192.168.1.1", "00:00:00:00:00:01");
    addNode(&admin, "Node2", "192.168.1.2", "00:00:00:00:00:02");
    addNode(&admin, "Node3", "192.168.1.3", "00:00:00:00:00:03");
    addUser(&admin, "User1", "password1");
    addUser(&admin, "User2", "password2");
    addUser(&admin, "User3", "password3");

    // Print the nodes and users in the system
    printNodes(&admin);
    printUsers(&admin);

    // Remove a node and a user from the system
    removeNode(&admin, "Node2");
    removeUser(&admin, "User2");

    // Print the nodes and users in the system again
    printNodes(&admin);
    printUsers(&admin);

    return 0;
}