//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to add new email to mailing list
void add_email(char *email, char **mailing_list, int *size) {
    // Allocate memory for new email
    char *new_email = malloc(sizeof(char) * strlen(email));
    strcpy(new_email, email);
   // Make space for new email
    char **new_list = malloc(sizeof(char *) * (*size+1));
    // Copy old list to new list
    for(int i=0; i<*size; i++) {
        new_list[i] = malloc(sizeof(char) * strlen(mailing_list[i]));
        strcpy(new_list[i], mailing_list[i]);
    }
    new_list[*size] = new_email; // Add new email to new list
    // Free old list
    for(int i=0; i<*size; i++) {
        free(mailing_list[i]);
    }
    free(mailing_list);
    mailing_list = new_list; // Update mailing list pointer
    *size += 1; // Update size
    printf("Email added to mailing list!\n");
}

// Function to remove email from mailing list
void remove_email(char *email, char **mailing_list, int *size) {
    int found = 0;
    for(int i=0; i<*size; i++) {
        if(strcmp(email, mailing_list[i]) == 0) { // If email found
            found = 1;
            free(mailing_list[i]); // Free email
            for(int j=i; j<*size-1; j++) { // Move all other emails up
                mailing_list[j] = mailing_list[j+1];
            }
            // Make space for new list
            char **new_list = malloc(sizeof(char *) * (*size-1));
            // Copy old list to new list
            for(int k=0; k<*size-1; k++) {
                new_list[k] = malloc(sizeof(char) * strlen(mailing_list[k]));
                strcpy(new_list[k], mailing_list[k]);
            }
            free(mailing_list); // Free old list
            mailing_list = new_list; // Update mailing list pointer
            *size -= 1; // Update size
            printf("Email removed from mailing list!\n");
            break;
        }
    }
    if(!found) {
        printf("Email not found in mailing list!\n");
    }
}

// Function to print mailing list
void print_mailing_list(char **mailing_list, int size) {
    if(size == 0) {
        printf("Mailing list is empty!\n");
    }
    for(int i=0; i<size; i++) {
        printf("%s\n", mailing_list[i]);
    }
}

int main() {
    int size = 0; // Initialize size
    char **mailing_list = malloc(sizeof(char *)); // Initialize empty list
    char command[50];
    char email[50];
    printf("Welcome to the Mailing List Manager!\n");
    printf("Type 'add' to add email to mailing list, 'remove' to remove email from mailing list, 'print' to print mailing list, and 'exit' to exit program.\n");
    while(1) {
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0) { // Add email command
            printf("Enter email to add: ");
            scanf("%s", email);
            add_email(email, mailing_list, &size);
        } else if(strcmp(command, "remove") == 0) { // Remove email command
            printf("Enter email to remove: ");
            scanf("%s", email);
            remove_email(email, mailing_list, &size);
        } else if(strcmp(command, "print") == 0) { // Print mailing list command
            print_mailing_list(mailing_list, size);
        } else if(strcmp(command, "exit") == 0) { // Exit program command
            printf("Goodbye!\n");
            return 0;
        } else { // Invalid command
            printf("Invalid command!\n");
        }
    }
    return 0;
}