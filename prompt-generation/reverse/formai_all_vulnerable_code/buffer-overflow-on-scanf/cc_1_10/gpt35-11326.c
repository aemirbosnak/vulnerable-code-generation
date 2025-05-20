//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MEMBERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} member_t;

int num_members = 0;
member_t members[MAX_MEMBERS];

int add_member() {
    if (num_members >= MAX_MEMBERS) {
        printf("Error: Maximum number of members reached.\n");
        return 0;
    }
    printf("Enter member name: ");
    fgets(members[num_members].name, MAX_NAME_LENGTH, stdin);
    members[num_members].name[strcspn(members[num_members].name, "\n")] = 0; // remove newline character
    printf("Enter member email: ");
    fgets(members[num_members].email, MAX_EMAIL_LENGTH, stdin);
    members[num_members].email[strcspn(members[num_members].email, "\n")] = 0; // remove newline character
    num_members++;
    printf("Member added successfully.\n");
    return 1;
}

int remove_member() {
    char name[MAX_NAME_LENGTH];
    printf("Enter member name to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character

    int removed = 0;
    for (int i = 0; i < num_members; i++) {
        if (strcmp(name, members[i].name) == 0) {
            // shift elements to fill gap
            for (int j = i; j < num_members - 1; j++) {
                strcpy(members[j].name, members[j + 1].name);
                strcpy(members[j].email, members[j + 1].email);
            }
            num_members--;
            removed = 1;
            printf("Member removed successfully.\n");
            break;
        }
    }
    if (!removed) {
        printf("Error: Member not found.\n");
    }
    return removed;
}

int print_members() {
    printf("Members (%d total):\n", num_members);
    for (int i = 0; i < num_members; i++) {
        printf("%s (%s)\n", members[i].name, members[i].email);
    }
    return 1;
}

int main() {
    int choice;
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. Print members\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // consume newline character from buffer

        switch (choice) {
            case 1:
                add_member();
                break;
            case 2:
                remove_member();
                break;
            case 3:
                print_members();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}