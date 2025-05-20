//FormAI DATASET v1.0 Category: System administration ; Style: random
/*
 * This program demonstrates the use of system administration commands in C.
 * It asks the user for a command to run and executes it using the system() function.
 * It can also display the contents of a file and write to a file using the relevant commands.
 * Written by Random Coder on a whim.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int choice;
    char command[100], filename[20], content[1000];

    printf("Welcome to System Administration with C!\n");

    do {
        printf("\nChoose an action:\n"
               "1. Run a command\n"
               "2. Display the contents of a file\n"
               "3. Write to a file\n"
               "4. Exit\n"
               "Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the command to run: ");
                scanf("%s", command);
                system(command);
                break;
            case 2:
                printf("\nEnter the name of the file: ");
                scanf("%s", filename);
                sprintf(command, "cat %s", filename);
                system(command);
                break;
            case 3:
                printf("\nEnter the name of the file: ");
                scanf("%s", filename);
                printf("Enter the content to write: ");
                getchar();
                fgets(content, sizeof content, stdin);
                sprintf(command, "echo '%s' > %s", content, filename);
                system(command);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 4);

    return EXIT_SUCCESS;
}