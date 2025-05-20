//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: dynamic
/*
 * Mailing list manager example program in a dynamic style
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a mailing list
typedef struct {
    char name[50];
    char email[50];
    int id;
} MailingList;

// Function to add a new member to the mailing list
void addMember(MailingList *list, int *size, char *name, char *email) {
    // Check if the list is full
    if (*size == 50) {
        printf("The mailing list is full.\n");
        return;
    }

    // Allocate memory for the new member
    MailingList *newMember = malloc(sizeof(MailingList));

    // Initialize the new member
    strcpy(newMember->name, name);
    strcpy(newMember->email, email);
    newMember->id = *size;

    // Add the new member to the list
    list[*size] = *newMember;

    // Increment the size of the list
    *size += 1;
}

// Function to remove a member from the mailing list
void removeMember(MailingList *list, int *size, int id) {
    // Check if the list is empty
    if (*size == 0) {
        printf("The mailing list is empty.\n");
        return;
    }

    // Check if the member exists
    if (id >= *size) {
        printf("Member not found.\n");
        return;
    }

    // Remove the member from the list
    for (int i = id; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }

    // Decrement the size of the list
    *size -= 1;
}

// Function to display all members of the mailing list
void displayMembers(MailingList *list, int *size) {
    // Check if the list is empty
    if (*size == 0) {
        printf("The mailing list is empty.\n");
        return;
    }

    // Display all members of the list
    for (int i = 0; i < *size; i++) {
        printf("%s (%s) - ID: %d\n", list[i].name, list[i].email, list[i].id);
    }
}

int main() {
    // Initialize the mailing list
    MailingList list[50];
    int size = 0;

    // Add members to the list
    addMember(list, &size, "John Doe", "johndoe@example.com");
    addMember(list, &size, "Jane Doe", "janedoe@example.com");
    addMember(list, &size, "Bob Smith", "bobsmith@example.com");

    // Display all members of the list
    displayMembers(list, &size);

    // Remove a member from the list
    removeMember(list, &size, 2);

    // Display all members of the list
    displayMembers(list, &size);

    return 0;
}