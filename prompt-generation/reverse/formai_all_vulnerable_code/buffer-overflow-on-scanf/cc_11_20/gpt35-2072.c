//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <string.h>
#define MAX 100

struct mailing_list {
    char name[50];
    char email[50];
};

int main() {
    struct mailing_list list[MAX];
    int num_of_members = 0;
    int i, choice;

    while (1) {
        printf("\nWelcome to our cheerful Mailing List Manager! What would you like to do?\n ");
        printf("1. Add member\n");
        printf("2. Delete member\n");
        printf("3. View all members\n");
        printf("4. Exit\n ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add member
                printf("\nEnter name: ");
                scanf("%s", list[num_of_members].name);
                printf("Enter email: ");
                scanf("%s", list[num_of_members].email);
                num_of_members++;
                printf("\nAdded to mailing list!\n");
                break;

            case 2: // Delete member
                if (num_of_members == 0) {
                    printf("\nThe mailing list is currently empty.\n");
                } else {
                    char del_email[50];
                    int found = 0;
                    printf("\nEnter email to delete: ");
                    scanf("%s", del_email);

                    for (i = 0; i < num_of_members; i++) {
                        if (strcmp(del_email, list[i].email) == 0) {
                            printf("\n%s has been removed from the mailing list.\n", list[i].name);
                            found = 1;
                            for (int j = i; j < num_of_members - 1; j++) {
                                strcpy(list[j].name, list[j+1].name);
                                strcpy(list[j].email, list[j+1].email);
                            }
                            num_of_members--;
                            break;
                        }
                    }
                    if (found == 0) {
                        printf("\nEmail not found in mailing list.\n");
                    }
                }
                break;

            case 3: // View all members
                if (num_of_members == 0) {
                    printf("\nThe mailing list is currently empty.\n");
                } else {
                    printf("\nMailing list members:\n");
                    printf("----------------------------\n");
                    for (i = 0; i < num_of_members; i++) {
                        printf("%s (%s)\n", list[i].name, list[i].email);
                    }
                    printf("----------------------------\n");
                }
                break;

            case 4: // Exit program
                printf("\nThanks for using our cheerful Mailing List Manager!\n");
                return 0;

            default: // Invalid input
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}