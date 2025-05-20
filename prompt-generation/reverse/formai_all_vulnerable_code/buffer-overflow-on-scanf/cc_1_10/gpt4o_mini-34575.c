//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define EMAIL_LENGTH 50

typedef struct {
    char email[EMAIL_LENGTH];
} Member;

// Function to add a member to the mailing list
void add_member(Member *members, int *num_members) {
    if (*num_members >= MAX_MEMBERS) {
        printf("Mailing list is full! Can't add more members.\n");
        return;
    }
    
    printf("Enter email to add: ");
    scanf("%s", members[*num_members].email);
    (*num_members)++;
    printf("Member added: %s\n", members[*num_members - 1].email);
}

// Function to remove a member from the mailing list
void remove_member(Member *members, int *num_members) {
    char email[EMAIL_LENGTH];
    printf("Enter email to remove: ");
    scanf("%s", email);
    
    for (int i = 0; i < *num_members; i++) {
        if (strcmp(members[i].email, email) == 0) {
            // Shift members down in the list
            for (int j = i; j < *num_members - 1; j++) {
                members[j] = members[j + 1];
            }
            (*num_members)--;
            printf("Member removed: %s\n", email);
            return;
        }
    }
    printf("Email not found: %s\n", email);
}

// Function to display the mailing list
void display_members(Member *members, int num_members) {
    printf("Mailing List Members:\n");
    for (int i = 0; i < num_members; i++) {
        printf("%d: %s\n", i + 1, members[i].email);
    }
}

// Main program logic
int main() {
    Member members[MAX_MEMBERS];
    int num_members = 0;
    int choice;

    printf("Welcome to the Mailing List Manager!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_member(members, &num_members);
                break;
            case 2:
                remove_member(members, &num_members);
                break;
            case 3:
                display_members(members, num_members);
                break;
            case 4:
                printf("Exiting the Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}