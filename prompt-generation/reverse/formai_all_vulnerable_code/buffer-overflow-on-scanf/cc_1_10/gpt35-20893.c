//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a maximum size for the network topology */
#define MAX_TOPOLOGY 256

/* Define an array of structures to represent the switches and their connections */
struct switch_connection {
    char switch_name[32];
    int num_connections;
    char connections[32][32];
} switches[MAX_TOPOLOGY];

/* Define a function to add a switch to the network topology */
void add_switch() {
    int i, j;
    char name[32];
    int num_connections;

    /* Ask for the switch name */
    printf("Enter the switch name:\n");
    scanf("%s", name);

    /* Ask for the number of connections */
    printf("Enter the number of connections:\n");
    scanf("%d", &num_connections);

    /* Add the switch and its connections to the topology */
    for (i = 0; i < MAX_TOPOLOGY; i++) {
        /* If the current element is empty, add the switch here */
        if (strlen(switches[i].switch_name) == 0) {
            /* Copy the name of the switch */
            strcpy(switches[i].switch_name, name);

            /* Set the number of connections */
            switches[i].num_connections = num_connections;

            /* Ask for each connection */
            printf("Enter the name of connection %d:\n", j+1);
            for (j = 0; j < num_connections; j++) {
                scanf("%s", switches[i].connections[j]);
            }

            /* Stop adding switches */
            break;
        }
    }
}

/* Define a function to remove a switch from the network topology */
void remove_switch() {
    int i;
    char name[32];

    /* Ask for the switch name */
    printf("Enter the switch name:\n");
    scanf("%s", name);

    /* Remove the switch and its connections from the topology */
    for (i = 0; i < MAX_TOPOLOGY; i++) {
        /* If we found the switch, remove it */
        if (strcmp(switches[i].switch_name, name) == 0) {
            /* Clear the switch name */
            switches[i].switch_name[0] = '\0';

            /* Clear the number of connections */
            switches[i].num_connections = 0;

            /* Clear the connections */
            memset(switches[i].connections, 0, sizeof(switches[i].connections));

            /* Stop removing switches */
            break;
        }
    }
}

/* Define a function to display the network topology */
void display_topology() {
    int i, j;

    printf("Switch\tConnections\n");

    /* Iterate over each switch */
    for (i = 0; i < MAX_TOPOLOGY; i++) {
        /* If the current element is not empty, display the switch and its connections */
        if (strlen(switches[i].switch_name) != 0) {
            printf("%s\t", switches[i].switch_name);

            for (j = 0; j < switches[i].num_connections; j++) {
                printf("%s ", switches[i].connections[j]);
            }

            printf("\n");
        }
    }
}

int main()
{
    int choice;

    /* Display the menu */
    printf("Network Topology Mapper\n");
    printf("1. Add Switch\n");
    printf("2. Remove Switch\n");
    printf("3. Display Topology\n");
    printf("4. Exit\n");

    do {
        /* Ask for the user's choice */
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        /* Call the appropriate function based on the user's choice */
        switch (choice) {
            case 1:
                add_switch();
                break;
            case 2:
                remove_switch();
                break;
            case 3:
                display_topology();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}